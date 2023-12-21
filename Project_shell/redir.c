#include "main.h"

void redir(int boo[3], char space[1000][100], int k, int j, int index[3])
{
    int fd, fd1;

    if (boo[0] && !boo[1] && !boo[2])
    {
        int status;
        input = dup(STDIN_FILENO);
        int pid = fork();
        if (pid < 0)
        {
            return;
        }
        if (pid == 0)
        {
            fd = open(space[index[0] + 1], O_RDONLY);
            fd1 = fd;
            if (fd < 0)
            {
                perror("Input file doesnt exist");
                return;
            }
            if (dup2(fd, STDIN_FILENO) < 0)
            {
                perror("Couldn't duplicate fd");
                return;
            }
            int data;
            char *str[1000];
            int mn;
            for (mn = 0; mn != index[0]; mn++)
            {
                str[mn] = (char *)malloc(100 * sizeof(char));
                strcpy(str[mn], space[k + mn]);
            }
            for (int x = index[0]; x < 1000; x++)
            {
                str[x] = NULL;
            }
            if (execvp(str[0], str) < 0)
            {
                printf("\nCould not execute command..");
            }
            for (int x = 0; x < 100; x++)
            {
                strcpy(str[x], "\0");
            }
            close(fd);
            exit(0);
        }
        if (pid > 0)
        {
            waitpid(pid, &status, 0);
            //return;
            if (dup2(input, STDIN_FILENO) < 0)
            {
                perror("Couldn't duplicate input fd");
                return;
            }
            close(input);
        }
    }
    if (boo[1] && !boo[2])
    {
        int status;
        if (!boo[0])
        {
            output = dup(STDOUT_FILENO);
            int pid = fork();
            if (pid < 0)
            {
                perror("pid negative error");
            }
            if (pid == 0)
            {
                char *p[1000];
                for (int i = 0; i < index[1] - k; i++)
                {
                    p[i] = (char *)malloc(100 * sizeof(char));
                    strcpy(p[i], space[k + i]);
                }
                fd = open(space[index[1] + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
                if (fd < 0)
                {
                    perror("Output file error");
                    return;
                }
                if (dup2(fd, STDOUT_FILENO) < 0)
                {
                    perror("Couldn't duplicate fd");
                    return;
                }
                for (int x = index[1] - k; x < 1000; x++)
                {
                    p[x] = NULL;
                }
                if (execvp(p[0], p) < 0)
                {
                    printf("\nCould not execute command..");
                }
                for (int x = 0; x < 100; x++)
                {
                    strcpy(p[x], "\0");
                }
                close(fd);
                exit(0);
            }
            if (pid > 0)
            {
                waitpid(pid, &status, 0);
            }
        }
        else
        {
            output = dup(STDOUT_FILENO);
            int pid = fork();
            if (pid < 0)
            {
                perror("pid negative error");
            }
            if (pid == 0)
            {
                char *p[1000];
                for (int i = 0; i < index[1] - k; i++)
                {
                    p[i] = (char *)malloc(100 * sizeof(char));
                    strcpy(p[i], space[k + i]);
                }
                fd = open(space[index[1] + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
                if (fd < 0)
                {
                    perror("Output file error");
                    return;
                }

                if (dup2(fd, STDOUT_FILENO) < 0)
                {
                    perror("Couldn't duplicate fd");
                    return;
                }
                int poo[3] = {1, 0, 0};
                redir(poo, space, k, index[0] + 1, index);
                for (int x = 0; x < 100; x++)
                {
                    strcpy(p[x], "\0");
                }
                close(fd);
                exit(0);
            }
            if (pid > 0)
            {
                waitpid(pid, &status, 0);
            }
        }
    }
    if (boo[2])
    {
        int status;
        output2 = dup(STDOUT_FILENO);
        if (!boo[0])
        {

            int pid = fork();
            if (pid < 0)
            {
                perror("pid negative error");
            }
            if (pid == 0)
            {
                char *p[1000];
                for (int i = 0; i < index[2] - k; i++)
                {
                    p[i] = (char *)malloc(100 * sizeof(char));
                    strcpy(p[i], space[k + i]);
                }
                fd = open(space[index[2] + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
                if (fd < 0)
                {
                    perror("Output file error");
                    return;
                }

                if (dup2(fd, STDOUT_FILENO) < 0)
                {
                    perror("Couldn't duplicate fd");
                    return;
                }
                for (int x = index[2] - k; x < 1000; x++)
                {
                    p[x] = NULL;
                }
                if (execvp(p[0], p) < 0)
                {
                    printf("\nCould not execute command..");
                }
                for (int x = 0; x < 100; x++)
                {
                    strcpy(p[x], "\0");
                }
                close(fd);
                exit(0);
            }
            if (pid > 0)
            {
                waitpid(pid, &status, 0);
            }
        }
        else
        {
            int pid = fork();
            if (pid < 0)
            {
                perror("pid negative error");
            }
            if (pid == 0)
            {
                char *p[1000];
                for (int i = 0; i < index[2] - k; i++)
                {
                    p[i] = (char *)malloc(100 * sizeof(char));
                    strcpy(p[i], space[k + i]);
                }
                fd = open(space[index[2] + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
                if (fd < 0)
                {
                    perror("Output file error");
                    return;
                }

                if (dup2(fd, STDOUT_FILENO) < 0)
                {
                    perror("Couldn't duplicate fd");
                    return;
                }
                int poo[3] = {1, 0, 0};
                redir(poo, space, k, index[0] + 1, index);
                for (int x = 0; x < 100; x++)
                {
                    strcpy(p[x], "\0");
                }
                close(fd);
                exit(0);
            }
            if (pid > 0)
            {
                waitpid(pid, &status, 0);
            }
        }
    }
    if (boo[1])
    {
        if (dup2(output, STDOUT_FILENO) < 0)
        {
            perror("Couldn't duplicate output fd");
            return;
        }
        close(output);
    }
    if (boo[2])
    {
        if (dup2(output2, STDOUT_FILENO) < 0)
        {
            perror("Couldn't duplicate output fd");
            return;
        }
        close(output2);
    }
}
