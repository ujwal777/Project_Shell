#include "main.h"

void bg(char p[100][100], int dif)
{

    pid_t pid = fork();
    if (pid == -1)
    {
        return;
    }
    else if (pid == 0)
    {
        char *garb[100];
        for (int i = 0; strcmp(p[i], "&"); i++)
        {
            garb[i] = (char *)malloc(100 * sizeof(char));
            strcpy(garb[i], p[i]);
        }
        for (int x = dif - 1; x < 100; x++)
        {
            garb[x] = NULL;
        }
        setpgid(0, 0);
        if (execvp(p[0], garb) < 0)
        {
            printf("\nCould not execute command..");
        }
        exit(0);
    }
    else
    {
        strcpy(jname[jc], p[0]);
        jpid[jc] = pid;
        jid[jc] = fc + 1;
        jc++, fc++;
        char *comp = (char *)malloc(100 * sizeof(char));
        int ind, temp;
        for (int i = 0; i < jc - 1; i++)
        {
            ind = i;
            for (int j = i + 1; j < jc; j++)
            {
                if (strcmp(jname[j], jname[ind]) < 0)
                {
                    ind = j;
                }
            }
            strcpy(comp, jname[i]);
            strcpy(jname[i], jname[ind]);
            strcpy(jname[ind], comp);
            temp = jpid[i];
            jpid[i] = jpid[ind];
            jpid[ind] = temp;
            temp = jid[i];
            jid[i] = jid[ind];
            jid[ind] = temp;
        }
        printf("%d\n", pid);
        return;
    }
}