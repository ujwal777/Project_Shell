#include "main.h"

void echo(char *smcol)
{
    char *space = smcol;
    while ((*space) != '\0')
    {
        printf("%c", *space);
        space++;
    }
}