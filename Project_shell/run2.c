#include "main.h"

void run2(char pipec[100])
{
    int k = 0, j = 0;
    char *cpsmcol, *sp;
    char space[1000][100];
    cpsmcol = pipec;
    k = j;
    while (sp = strtok_r(cpsmcol, " ", &cpsmcol))
    {
        for (int x = 0; x < 11; x++)
        {
            space[j][x] = '\0';
        }
        strcpy(space[j], sp);
        j++;
    }
    int index[3] = {0, 0, 0};
    int boo[3] = {0, 0, 0}, f = 1;
    for (int i = k; i < j; i++)
    {
        if (!strcmp(space[i], ">"))
        {
            boo[1] = 1;
            index[1] = i;
        }
        if (!strcmp(space[i], "<"))
        {
            boo[0] = 1;
            index[0] = i;
        }
        if (!strcmp(space[i], ">>"))
        {
            boo[2] = 1;
            index[2] = i;
        }
    }
    if (boo[0] || boo[1] || boo[2])
    {
        redir(boo, space, k, j, index);
        return;
    }
    else
    {
        pid_t pid = fork();
        if (pid == -1)
        {
            return;
        }
        else if (pid == 0)
        {
            char *garb[1000];
            for (int i = 0; i < 10; i++)
            {
                garb[i] = NULL;
            }
            for (int i = 0; i < j; i++)
            {
                garb[i] = (char *)malloc(100 * sizeof(char));
                strcpy(garb[i], space[i]);
            }
            for (int c = j; c < 1000; c++)
            {
                garb[c] = NULL;
            }
            if (execvp(garb[0], garb) < 0)
            {
                printf("\nCould not execute command..");
            }

            exit(0);
        }
        else
        {
            int status;
            waitpid(pid, &status, 0);
            return;
        }
    }
}