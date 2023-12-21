#include "main.h"

void display()
{
    char sysnme[50], usrname[50], puf[9000], cuf[1000];
    int i;
    gethostname(sysnme, sizeof(sysnme));
    getlogin_r(usrname, sizeof(usrname));
    getcwd(cuf, sizeof(cuf));
    if (strcmp(buf, cuf) == 0)
    {
        printf("\n<%s@%s:~>", usrname, sysnme);
    }
    if (strcmp(buf, cuf) < 0)
    {
        for (i = 0; i < strlen(buf); i++)
        {
            if (buf[i] != cuf[i])
            {
                printf("\n<%s@%s:%s>", usrname, sysnme, cuf);
                break;
            }
        }
        if (i == strlen(buf))
        {
            for (i = 0; i < strlen(cuf) - strlen(buf); i++)
            {
                puf[i] = cuf[strlen(buf) + 1 + i];
            }
            printf("\n<%s@%s:%s>", usrname, sysnme, puf);
        }
    }
    if (strcmp(buf, cuf) > 0)
    {
        printf("\n<%s@%s:%s>", usrname, sysnme, cuf);
    }
}