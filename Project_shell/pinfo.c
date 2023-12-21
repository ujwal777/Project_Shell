#include "main.h"

void pinfo(char s[100][100], int k, int j, int l)
{
    char data[100], t[100], puf[100];
    int p = getpid();
    int a = 0, b = 0, i;
    if (l == 0)
    {
        sprintf(data, "/proc/%d/status", p);
    }
    else
    {
        sprintf(data, "/proc/%s/status", s[k + 1]);
    }
    FILE *x = fopen(data, "r");
    if (x == NULL)
    {
        perror("File pointer is null");
        return;
    }
    printf("pid -- %d\n", getpid());
    for (int c = 0; fscanf(x, "%s", t) != EOF; c++)
    {
        if (!strcmp(t, "State:"))
        {
            a = 1;
            continue;
        }
        if (!strcmp(t, "VmSize:"))
        {
            b = 1;
            continue;
        }
        if (a == 1)
        {
            printf("Process Status -- %s\n", t);
            a = 10;
        }
        if (b == 1)
        {
            printf("memory -- %s kb\n", t);
            b = 10;
            break;
        }
    }
    if (a != 10)
    {
        printf("Process Status --  No access\n");
    }
    if (b != 10)
    {
        printf("memory --  No access\n");
    }
    if (l == 0)
    {
        sprintf(data, "/proc/%d/exe", p);
    }
    else
    {
        sprintf(data, "/proc/%s/exe", s[k + 1]);
    }
    int ind;
    ind = readlink(data, t, sizeof(t));
    if (ind)
    {
        if (strcmp(buf, t) == 0)
        {
            printf("Executable path -- ~\n");
        }
        if (strcmp(buf, t) < 0)
        {
            for (i = 0; i < strlen(buf); i++)
            {
                if (buf[i] != t[i])
                {
                    printf("Executable path -- %s\n", t);
                    break;
                }
            }
            if (i == strlen(buf))
            {
                for (i = 0; i < strlen(t) - strlen(buf); i++)
                {
                    puf[i] = t[strlen(buf) + 1 + i];
                }
                printf("Executable path -- ~/%s\n", puf);
            }
        }
        if (strcmp(buf, t) > 0)
        {
            printf("Executable path -- %s\n", t);
        }
    }
    else
    {
        printf("Executable path -- No access\n");
    }
    return;
}