#include "auth.h"

TAB_L file_to_tab(FILE* f){
    TAB_L ftt = {NULL,0};
    int i = 0;
    char line[256];
    
    ftt.tab = (char**)malloc(MAX*sizeof(char*));
    for (int i = 0; i < MAX; i++)
    {
        ftt.tab[i] = (char*)malloc(256*sizeof(char));
    }

    while (fgets(line,256,f) != NULL)
    {
        if (strstr(line,"for user") != NULL)
        {
            strcpy(ftt.tab[i] , line);
            i++;
        }
    }
    
    ftt.l = i - 1;
    

    return ftt;
}
int n_lfile(char* file){
    FILE* f = fopen(file,"r");
    int l = 0;
    char* line;

    while (fgets(line,256,f) != NULL){
        l++;
    }

    fclose(f);
    return l;
}

void echo_tab(TAB_L t){
    
    for (int i = 0; i < t.l; i++)
    {
        printf("%s",t.tab[i]);
    }
    
}