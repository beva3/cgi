#ifndef __USER__
#define __USER__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct USER
{
    char name[30];
    int uid;
    int gid;
    char rep[100];
    char shell[100];
}USER;

char*affect(char*dest,const char*scr);
void echotab(char**t,int i);
int str2_len(char**t);
char**tab_user();
char** split(char*str);
void conf_html();
void tronc();
void link(int index);
int index_(char* query_string);
char**tab_user_needl(char* needl);
void recherch();

#endif