#include "main.h"

void ls2(char *str, int a, int l, char *name, char *fin)
{
    struct dirent *d;
    struct stat file;
    struct passwd *usr;
    struct group *g;
    if (opendir(str) == NULL)
    {
        {
            printf("Directory doesnt exist");
        }
        return;
    }
    DIR *dh = opendir(str);
    int len = strlen(str);
    char usrname[100], grpname[100], day[100], stringy[100];
    int total = 0;
    strcpy(stringy, str);
    //printf("%s\n%d",str,strlen(str));
    if (!dh)
    {
        printf("ERROR! Couldn't open directory");
    }
    if (a && l)
    {

        while ((d = readdir(dh)) != NULL)
        {
            if (strcmp(d->d_name, name) == 0)
            {
                stringy[len] = '/';
                for (int i = len + 1, j = 0; j <= strlen(d->d_name); i++, j++)
                {
                    {
                        stringy[i] = d->d_name[j];
                    }
                } //printf("%s ",stringy);
                stat(stringy, &file);
                total += file.st_blocks;
            }
        }
        strcpy(stringy, str);
        // printf("total %d\n",total/2);
        total = 0;
        dh = opendir(stringy);
        while ((d = readdir(dh)) != NULL)
        {
            if (strcmp(d->d_name, name) == 0)
            {
                stringy[len] = '/';
                for (int i = len + 1, j = 0; j <= strlen(d->d_name); i++, j++)
                {
                    {
                        stringy[i] = d->d_name[j];
                    }
                }
                //printf("%s",str);
                stat(stringy, &file);
                printf((S_ISDIR(file.st_mode)) ? "d" : "-");
                printf((file.st_mode & S_IRUSR) ? "r" : "-");
                printf((file.st_mode & S_IWUSR) ? "w" : "-");
                printf((file.st_mode & S_IXUSR) ? "x" : "-");
                printf((file.st_mode & S_IRGRP) ? "r" : "-");
                printf((file.st_mode & S_IWGRP) ? "w" : "-");
                printf((file.st_mode & S_IXGRP) ? "x" : "-");
                printf((file.st_mode & S_IROTH) ? "r" : "-");
                printf((file.st_mode & S_IWOTH) ? "w" : "-");
                printf((file.st_mode & S_IXOTH) ? "x " : "- ");
                printf("%ld ", file.st_nlink);
                usr = getpwuid(file.st_uid);
                g = getgrgid(file.st_gid);
                printf("%s ", usr->pw_name);
                printf("%s ", g->gr_name);
                printf("%ld ", file.st_size);
                strcpy(day, ctime(&file.st_mtime));
                for (int i = 4; i < 16; i++)
                {
                    printf("%c", day[i]);
                }
                printf(" %s ", fin);
                {
                    printf("\n");
                }
            }
        }
    }
    else if (a)
    {
        while ((d = readdir(dh)) != NULL)
        {
            if (strcmp(d->d_name, name) == 0)
            {
                printf("%s ", fin);
            }
        }
    }
    else if (l)
    {
        while ((d = readdir(dh)) != NULL)
        {
            if (strcmp(d->d_name, name) == 0)
            { //printf("%s %s\n",d->d_name,name);
                if (!a && d->d_name[0] == '.')
                {
                    continue;
                }
                stringy[len] = '/';
                for (int i = len + 1, j = 0; j <= strlen(d->d_name); i++, j++)
                {
                    {
                        stringy[i] = d->d_name[j];
                    }
                } //printf("%s ",stringy);
                stat(stringy, &file);
                total += file.st_blocks;
            }
        }
        strcpy(stringy, str);
        //printf("total %d\n",total/2);
        total = 0;
        dh = opendir(stringy);
        while ((d = readdir(dh)) != NULL)
        {
            if (strcmp(d->d_name, name) == 0)
            {
                if (!a && d->d_name[0] == '.')
                {
                    continue;
                }
                stringy[len] = '/';
                for (int i = len + 1, j = 0; j <= strlen(d->d_name); i++, j++)
                {
                    {
                        stringy[i] = d->d_name[j];
                    }
                }
                //printf("%s",str);
                stat(stringy, &file);
                printf((S_ISDIR(file.st_mode)) ? "d" : "-");
                printf((file.st_mode & S_IRUSR) ? "r" : "-");
                printf((file.st_mode & S_IWUSR) ? "w" : "-");
                printf((file.st_mode & S_IXUSR) ? "x" : "-");
                printf((file.st_mode & S_IRGRP) ? "r" : "-");
                printf((file.st_mode & S_IWGRP) ? "w" : "-");
                printf((file.st_mode & S_IXGRP) ? "x" : "-");
                printf((file.st_mode & S_IROTH) ? "r" : "-");
                printf((file.st_mode & S_IWOTH) ? "w" : "-");
                printf((file.st_mode & S_IXOTH) ? "x " : "- ");
                printf("%ld ", file.st_nlink);
                usr = getpwuid(file.st_uid);
                g = getgrgid(file.st_gid);
                printf("%s ", usr->pw_name);
                printf("%s ", g->gr_name);
                printf("%ld ", file.st_size);
                strcpy(day, ctime(&file.st_mtime));
                for (int i = 4; i < 16; i++)
                {
                    printf("%c", day[i]);
                }
                printf(" %s ", fin);
                {
                    printf("\n");
                }
            }
        }
    }
    else
    {
        while ((d = readdir(dh)) != NULL)
        {
            if (strcmp(d->d_name, name) == 0)
            {
                if (d->d_name[0] != '.')
                {
                    printf("%s", fin);
                }
            }
        }
    }
}