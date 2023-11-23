#include "user.h"

int main(){
    char* env = getenv("QUERY_STRING");


    printf("Content-type: text/html\n\n");
    printf("<html>");
    conf_html();

    tronc();

    printf("</html>");

    return 0;
}