#include "main.h"

void fg(char p[100][100], int dif)
{
    pid_t pid = fork();
    if (pid == -1)
    {
        return;
    }
    else if (pid == 0)
    {
        char *garb[100];
        for (int i = 0; strcmp(p[i], "\0"); i++)
        {
            garb[i] = (char *)malloc(100 * sizeof(char));
            strcpy(garb[i], p[i]);
        }
        for (int x = dif; x < 100; x++)
        {
            garb[x] = NULL;
        }
        if (execvp(garb[0], garb) < 0)
        {
            printf("\nCould not execute command..");
        }
        exit(0);
    }
    else
    {
        fj = fc + 1;
        fpid = pid;
        strcpy(fname, p[0]);
        int status;
        waitpid(pid, &status, WUNTRACED);
        fj = 0, fpid = 0;
        return;
    }
}