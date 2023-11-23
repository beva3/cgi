#include "user.h"

int main(){

    printf("Content-type: text/html\n\n");
    printf("<html>");
    
    conf_html();

    echotab(tab_user(),3);

    printf("</html>");

    return 0;
}