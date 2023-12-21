#include "main.h"

void pip(char str[100])
{
    int ind = 0;
    char *pipec[100];
    char *tokenc = strtok(str, "|");
    if (tokenc != NULL)
    {
        pipec[ind] = (char *)malloc(100 * sizeof(char));
        pipec[ind++] = tokenc;
    }
    while (tokenc != NULL)
    {
        tokenc = strtok(NULL, "|");
        if (tokenc != NULL)
        {
            pipec[ind] = (char *)malloc(100 * sizeof(char));
            pipec[ind++] = tokenc;
        }
    }
    int fd[ind - 1][2];
    for (int i = 0; i < ind - 1; i++)
    {
        if (pipe(fd[i]) < 0)
        {
            perror("\nError while piping");
        }
        if (!i)
        {
            int b = dup(STDOUT_FILENO);
            dup2(fd[i][1], STDOUT_FILENO);
            close(fd[i][1]);
            run2(pipec[i]);
            dup2(b, STDOUT_FILENO);
            close(b);
        }
        else
        {
            int a = dup(STDIN_FILENO);
            int b = dup(STDOUT_FILENO);
            dup2(fd[i][1], STDOUT_FILENO);
            dup2(fd[i - 1][0], STDIN_FILENO);
            close(fd[i][1]);
            close(fd[i - 1][0]);
            run2(pipec[i]);
            dup2(a, STDIN_FILENO);
            dup2(b, STDOUT_FILENO);
            close(a);
            close(b);
        }
    }
    int a = dup(STDIN_FILENO);
    dup2(fd[ind - 2][0], STDIN_FILENO);
    close(fd[ind - 2][0]);
    run2(pipec[ind - 1]);
    dup2(a, STDIN_FILENO);
    close(a);
}