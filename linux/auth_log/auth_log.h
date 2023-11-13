#ifndef __AUTH__
#define __AUTH__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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


char**tab_auth();
char*no_new_line(char* mot);

#endif