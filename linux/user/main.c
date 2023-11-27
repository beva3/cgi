#include "user.h"

int main(){
    char* env = getenv("QUERY_STRING");


    printf("Content-type: text/html\n\n");
    printf("<html>");
    conf_html();
    
    printf("<body>");
        printf("\
	    <div class=\"user-linux\">\
            <h1>user linux</h1>\
        </div>");

        printf("<div class=\"tableau\">");
            tronc();
        printf("</div>");
    printf("</body>");
    printf("</html>");

    return 0;
}