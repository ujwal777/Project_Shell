#ifndef main_h
#define main_h

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <pwd.h>
#include <sys/types.h>
#include <grp.h>
#include <time.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <signal.h>

void echo(char* smcol);
void pwd();
void fg(char p[100][100],int dif);
void bg(char p[100][100],int dif);
void run(char space[1000][100],int k,int j);
void cd(char *space);
void lscall(char space[1000][100],int k,int j);
void ls(char* str,int a,int l);
char buf[1000],bxp[1000],pxp[1000];
int jpid[100],jid[100],jc=0,fc=0,fj=0,fpid=0,input=-1,output=-1,ss=0,output2=-1;
char jname[100][100],fname[100];
void ls2(char* str,int a,int l,char *name,char *fin);
void pinfo(char s[100][100],int k,int j,int l);
void redir(int boo[3],char space[1000][100],int k,int j,int index[3]);
void jobs(char space[1000][100],int k,int j);
void handler();
void fore(char space[1000][100],int k);
void back(char space[1000][100],int k);
void pip(char str[100]);
void handler2();
void handler3();
void run2(char pipec[100]);
int spid;
void display();

#endif