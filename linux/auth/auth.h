#ifndef __AUTH__
#define __AUTH__

#define MAX 10000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct TAB_L
{
    char** tab;
    int l;
}TAB_L;

typedef struct DATE{
        char a[10];
        char m[10];
        char j[10];
}DATE;

typedef struct MOMENT
{
    char date[50];
    char time[50];
}MOMENT;

typedef struct AUTH
{
    MOMENT moment;
    char srvc_prgrm[50];/*service ou programme*/
    char pam_unix[50];
    char sesion[50];
    char user[50];
}AUTH;


TAB_L auth_log_tab();
void echo_tab(TAB_L t,int index);
char* tab_data(char line[]);
void tronc();
int index_(char* query_string);
void link(int index,TAB_L t);

#endif
