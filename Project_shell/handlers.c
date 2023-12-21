#include "main.h"

void handler()
{
    int status, store;
    int pid;
    while ((pid = waitpid(-1, &status, WNOHANG)) > 0)
    {
        for (int k = 0; k < jc; k++)
        {
            if (jpid[k] == pid)
            {
                if (WIFEXITED(status))
                {
                    printf("\n%s with pid %d Exited Normally", jname[k], jpid[k]);
                    store = jid[k];
                    for (int i = k; i < jc - 1; i++)
                    {
                        strcpy(jname[i], jname[i + 1]);
                        jid[i] = jid[i + 1];
                        jpid[i] = jpid[i + 1];
                    }
                    strcpy(jname[jc - 1], "\0");
                    jid[jc - 1] = 0;
                    jpid[jc - 1] = 0;
                    jc--;
                }
                else
                {
                    printf("\n%s with pid %d Exited abnormally", jname[k], jpid[k]);
                    for (int i = k; i < jc - 1; i++)
                    {
                        strcpy(jname[i], jname[i + 1]);
                        jid[i] = jid[i + 1];
                        jpid[i] = jpid[i + 1];
                    }
                    strcpy(jname[jc - 1], "\0");
                    jid[jc - 1] = 0;
                    jpid[jc - 1] = 0;
                    jc--;
                }
            }
        }
    }
    fflush(stdout);
}

void handler2()
{
    if (fpid && fj)
    {
        kill(fpid, SIGINT);
        fpid = 0, fj = 0;
        strcpy(fname, "\0");
        return;
    }
    else
    {
        display();
        ss = 1;
        return;
    }
}

void handler3()
{
    if (fj && fpid)
    {
        if (kill(fpid, SIGTSTP) < 0)
        {
            perror("\nError in stopping process");
        }
        strcpy(jname[jc], fname);
        jpid[jc] = fpid;
        jid[jc] = fc + 1;
        fj = 0, fpid = 0;
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
    }
    else
    {
        display();
        ss = 1;
    }
    return;
}