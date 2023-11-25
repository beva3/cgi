#include "auth.h"

int main(){

    printf("Content-Type: text/html\n\n");

    FILE* f = fopen("/var/log/auth.log","r");
    
    echo_tab(file_to_tab(f),0);
    
    fclose(f);

    return 0;
}