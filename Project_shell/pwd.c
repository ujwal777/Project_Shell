#include "main.h"

void pwd()
{
    char prescd[10000];
    printf("%s", getcwd(prescd, sizeof(prescd)));
    return;
}