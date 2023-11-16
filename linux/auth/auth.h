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

TAB_L file_to_tab(FILE* f);
void echo_tab(TAB_L t);

#endif