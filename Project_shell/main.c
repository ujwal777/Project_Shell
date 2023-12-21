#include "main.h"
#include "fg.c"
#include "bg.c"
#include "echo.c"
#include "ls.c"
#include "ls2.c"
#include "lscall.c"
#include "pinfo.c"
#include "run.c"
#include "cd.c"
#include "pwd.c"
#include "redir.c"
#include "pip.c"
#include "jobs.c"
#include "handlers.c"
#include "fore.c"
#include "back.c"
#include "display.c"
#include "run2.c"

int main()
{
    spid = getpid();
    char cuf[1000];
    char *cmd, *cpsmcol, *cpcmd, *s, *sp;
    char smcol[100][100], space[1000][100];
    int i, j = 0, k;
    getcwd(buf, sizeof(buf));
    getcwd(cuf, sizeof(cuf));
    signal(SIGCHLD, handler);
    signal(SIGINT, handler2);
    signal(SIGTSTP, handler3);
    while (1)
    {
        if (ss == 0)
        {
            display();
        }
        ss = 0;
        ssize_t size = 0;
        for (int index = 0; index < 1000; index++)
        {
            strcpy(smcol[index], "\0");
            strcpy(space[index], "\0");
        }
        if (getline(&cmd, &size, stdin) < 0)
        {
            exit(0);
        }
        //scanf("%[^\n]%*c",cmd);
        cmd[strlen(cmd) - 1] = '\0';
        //printf("%s\n",cmd);
        cpcmd = cmd;
        char *pipep = (char *)malloc(100 * sizeof(char));
        i = 0, j = 0;
        int br = 0;
        while (s = strtok_r(cmd, ";", &cmd))
        {
            
            strcpy(smcol[i], s);
            cpsmcol = smcol[i];
            k = j;
            while (sp = strtok_r(cpsmcol, " ", &cpsmcol))
            {
               // printf("%s\n",sp);
                strcpy(space[j], sp);
                //printf("%s\n",sp);
                j++;
            } //printf("%d %d\n",k,j);
            int jon = 0;
            for (int x = k; x < j; x++)
            {
                for (int xy = 0; xy < strlen(space[x]); xy++, jon++)
                {
                    pipep[jon] = space[x][xy];
                }
                pipep[jon] = ' ';
                jon++;
            }
            pipep[jon] = '\0';
            for (int x = k; x < j; x++)
            {
                if (!strcmp(space[x], "|"))
                {
                    pip(pipep);
                    br = 1;
                    break;
                }
            }
            if (!br)
            {
                run(space, k, j);
            }
            br = 0;
            i++;
        }
    }
    return 0;
}