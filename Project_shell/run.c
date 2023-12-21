#include "main.h"

void run(char space[1000][100], int k, int j)
{
    int a, b, index[3] = {0, 0, 0}, pi[1000];
    a = k;
    b = j;
    int boo[3] = {0, 0, 0}, f = 1;

    {
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

        if (!strcmp(space[k], "echo"))
        {
            while (a + 1 < b)
            {
                if (a > k)
                {
                    printf(" ");
                }
                echo(space[a + 1]);
                a++;
            }
            return;
        }
        if (!strcmp(space[k], "pwd") || !strcmp(space[k], "pwd\n"))
        {
            pwd();
            return;
        }
        if (!strcmp(space[k], "cd"))
        {
            if (k == j - 1)
            {
                cd(space[k]);
                return;
            }
            if (j - k > 2)
            {
                printf("ERROR:Too many arguments in cd\n");
                return;
            }
            cd(space[k + 1]);
            return;
        }
        if (!strcmp(space[k], "ls"))
        {
            lscall(space, k, j);
            return;
        }
        if (!strcmp(space[k], "pinfo"))
        {
            if (space[k + 1][0])
            {
                pinfo(space, k, j, 1);
                return;
            }
            else
            {
                pinfo(space, k, j, 0);
                return;
            }
        }
        if (!strcmp(space[k], "repeat"))
        {
            for (int keep = 0; keep < (space[k + 1][0] - '0'); keep++)
            {
                run(space, k + 2, j);
            }
            return;
        }
        if (!strcmp(space[k], "jobs"))
        {
            jobs(space, k, j);
            return;
        }
        if (!strcmp(space[k], "sig"))
        {
            int jno;
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
            int signo;
            if (strlen(space[k + 2]) == 1)
            {
                signo = space[k + 2][0] - '0';
            }
            else
            {
                int tens = space[k + 2][0] - '0';
                int ones = space[k + 2][1] - '0';
                signo = (tens * 10) + ones;
            }
            int jop, lu = 0;
            for (int i = 0; i < jc; i++)
            {
                if (jid[i] == jno)
                {
                    jop = jpid[i];
                    lu = 1;
                    break;
                }
            }
            if (lu == 1)
            { 
                if (kill(jop, signo) < 0)
                {
                    perror("Error in kill");
                }
                return;
            }
            else
            {
                printf("\nJob doesnt exist");
                return;
            }
        }
        if (!strcmp(space[k], "fg"))
        {
            fore(space, k);
            return;
        }
        if (!strcmp(space[k], "bg"))
        {
            back(space, k);
            return;
        }
        else
        {
            if (space[j - 1][0] == '&')
            {
                char p[100][100];
                for (int ms = 0; ms < j - k; ms++)
                {
                    strcpy(p[ms], space[k + ms]);
                }
                //printf("%s\n",p[0]);
                bg(p, j - k);
                for (int ms = 0; ms < j - k; ms++)
                {
                    strcpy(p[ms], "\0");
                }
                //space[k+1][0]='\0';
                return;
            }
            else
            {
                char p[100][100];
                for (int ms = 0; ms < j - k; ms++)
                {
                    strcpy(p[ms], space[k + ms]);
                }
                //printf("%s\n",p[0]);
                fg(p, j - k);
                for (int ms = 0; ms < j - k; ms++)
                {
                    strcpy(p[ms], "\0");
                }
                return;
            }
        }
    }
}