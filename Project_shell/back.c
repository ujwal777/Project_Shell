#include "main.h"

void back(char space[1000][100], int k)
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
        char data[100];
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
            fscanf(x, "%s %s %s %s %s %s", str[0], str[1], str[2], str[3], str[4], str[5]);
            {

                if (str[5][0] == 'T')
                {
                    if (kill(jpid[i], 18) < 0)
                    {
                        printf("\nCouldnt run the sleeping process");
                        fclose(x);
                        return;
                    }
                }
            }
        }
        fclose(x);
        return;
    }
}