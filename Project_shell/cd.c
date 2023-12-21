#include "main.h"

void cd(char *space)
{
    if (space[0] == '~')
    {
        getcwd(bxp, sizeof(bxp));
        chdir(buf);
        return;
    }
    if (strcmp(space, "cd") == 0)
    {
        getcwd(bxp, sizeof(bxp));
        chdir(buf);
        return;
    }
    if (space[0] == '-')
    {
        getcwd(pxp, sizeof(pxp));
        chdir(bxp);
        strcpy(bxp, pxp);
        pwd();
        return;
    }
    getcwd(bxp, sizeof(bxp));
    if (chdir(space) < 0)
    {
        printf("Path error\n");
    }
    return;
}