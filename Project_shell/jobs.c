#include "main.h"

void jobs(char space[1000][100], int k, int j)
{
    char data[100];
    for (int i = 0; i < jc; i++)
    {
        sprintf(data, "/proc/%d/status", jpid[i]);
        FILE *x = fopen(data, "r");
        if (x == NULL)
        {
            perror("File pointer is null");
            return;
        }
        else
        {
            char str[100][100];
            int bo = 0;
            fscanf(x, "%s %s %s %s %s %s", str[0], str[1], str[2], str[3], str[4], str[5]);
            {
                /* if(!strcmp(str,"State:"))
				{
					bo = 1;
					continue;
				}*/
                // if(bo==1)
                {
                    // bo =10;

                    if (j == (k + 2))
                    {
                        if (space[k + 1][0] == '-' && space[k + 1][1] == 'r')
                        {
                            // printf("%s",space[k+1]);
                            if (str[5][0] == 'R' || str[5][0] == 'S')
                            {
                                printf("[%d] Running %s [%d]\n", jid[i], jname[i], jpid[i]);
                                //break;
                            }
                        }
                        else if (space[k + 1][0] == '-' && space[k + 1][1] == 's')
                        {
                            //printf("%s",space[k+1]);
                            if (str[5][0] == 'T')
                            {
                                printf("[%d] Stopped %s [%d]\n", jid[i], jname[i], jpid[i]);
                                //break;
                            }
                        }
                    }
                    else
                    {
                        if (str[5][0] == 'T')
                        {
                            printf("[%d] Stopped %s [%d]\n", jid[i], jname[i], jpid[i]);
                            //break;
                        }
                        else if (str[5][0] == 'R' || str[5][0] == 'S')
                        {
                            printf("[%d] Running %s [%d]\n", jid[i], jname[i], jpid[i]);
                            //break;
                        }
                    }
                }
            }
        }
        fclose(x);
    }
    return;
}