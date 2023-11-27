#include "user.h"
void conf_html(){
    printf("<head>");

    printf("<title>user linux</title>");
    printf("<link rel=\"stylesheet\" href=\"style.css\">");
    printf("<style>");
        tout();
    printf("</style>");
    printf("</head>");
}

void tout(){
    printf("*{\
        margin: 0;\
        padding: 0;\
        background-color: rgb(24, 26, 25);\
    }");
}