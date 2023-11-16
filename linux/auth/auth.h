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


TAB_L file_to_tab(FILE* f);
void echo_tab(TAB_L t);
char* tab_data(char line[]);

#endif