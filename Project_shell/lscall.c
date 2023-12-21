#include "main.h"

void lscall(char space[1000][100], int k, int j)
{
    char prescd[10000];
    getcwd(prescd, sizeof(prescd));
    int a = 0, l = 0, x, y, done = 0;
    x = k, y = j;
    if (j == k + 1)
    {
        ls(prescd, 0, 0);
        return;
    }
    else
    {
        for (x = k + 1; x < y; x++)
        {
            if (space[x][0] == '-')
            {
                for (int count = 1; space[x][count] != '\0'; count++)
                {
                    if (space[x][count] == 'l')
                    {
                        l = 1;
                    }
                    if (space[x][count] == 'a')
                    {
                        a = 1;
                    }
                }
            }
        }
        for (x = k + 1; x < y; x++)
        {
            if (space[x][0] == '~')
            {
                ls(buf, a, l);
                
                done = 1;
            }
            if (space[x][0] != '-' && space[x][0] != '~')
            {
                ls(space[x], a, l);
                done = 1;
            }
        }
        if (done != 1)
        {
            ls(prescd, a, l);
        }
        return;
    }
}