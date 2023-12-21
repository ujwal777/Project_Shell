#include "main.h"

void fore(char space[1000][100], int k)
{
    int jno, bo = 0, i, jopid, status;
    if (strlen(space[k + 1]) == 1)
    {
        jno = space[k + 1][0] - '0';
    }
    else
    {
        int tens = space[k + 1][0] - '0';
        int ones = space[k + 1][1] - '0';
        jno = (tens * 10) + ones;
    }
    for (i = 0; i < jc; i++)
    {
        if (jid[i] == jno)
        {
            bo = 1;
            break;
        }
    }
    if (bo == 0)
    {
        printf("\nJob doesnt exist");
        return;
    }
    else
    {
        jopid = jpid[i];
        strcpy(fname, jname[i]);
        char data[100];
        sprintf(data, "/proc/%d/status", jpid[i]);
        FILE *x = fopen(data, "r");
        if (x == NULL)
        {
            perror("File pointer is null");
            strcpy(fname, "\0");
            return;
        }
        else
        {
            char str[100][100];
            fscanf(x, "%s %s %s %s %s %s", str[0], str[1], str[2], str[3], str[4], str[5]);
            {

                if (str[5][0] == 'T')
                {
                    signal(SIGTTOU, SIG_IGN);
                    signal(SIGTTIN, SIG_IGN);
                    tcsetpgrp(0, getpgid(jopid));
                    if (kill(jpid[i], 18) < 0)
                    {
                        printf("\nCouldnt run the sleeping process");
                        strcpy(fname, "\0");
                        fclose(x);
                        return;
                    }
                    for (int j = i; j < jc - 1; j++)
                    {
                        strcpy(jname[j], jname[j + 1]);
                        jid[j] = jid[j + 1];
                        jpid[j] = jpid[j + 1];
                    }
                    strcpy(jname[jc - 1], "\0");
                    jid[jc - 1] = 0;
                    jpid[jc - 1] = 0;
                    jc--;

                    fpid = jopid, fj = jno;
                    waitpid(jopid, &status, WUNTRACED);
                    tcsetpgrp(0, getpgid(spid));
                    signal(SIGTTOU, SIG_DFL);
                    signal(SIGTTIN, SIG_DFL);
                    fclose(x);
                    fpid = 0, fj = 0;
                    return;
                }
                else if (str[5][0] == 'R' || str[5][0] == 'S')
                {
                    signal(SIGTTOU, SIG_IGN);
                    signal(SIGTTIN, SIG_IGN);
                    tcsetpgrp(0, getpgid(jopid));
                    for (int j = i; j < jc - 1; j++)
                    {
                        strcpy(jname[j], jname[j + 1]);
                        jid[j] = jid[j + 1];
                        jpid[j] = jpid[j + 1];
                    }
                    strcpy(jname[jc - 1], "\0");
                    jid[jc - 1] = 0;
                    jpid[jc - 1] = 0;
                    jc--;

                    fpid = jopid, fj = jno;
                    waitpid(jopid, &status, WUNTRACED);
                    tcsetpgrp(0, getpgid(spid));
                    signal(SIGTTOU, SIG_DFL);
                    signal(SIGTTIN, SIG_DFL);
                    fclose(x);
                    fpid = 0, fj = 0;
                    return;
                }
            }
        }
    }
}