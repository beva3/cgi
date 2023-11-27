#include "user.h"
void conf_html(){
    printf("<head>");

    printf("<title>user linux</title>");
    printf("<link rel=\"stylesheet\" href=\"style.css\">");
    printf("<style>");
        tout();
        user_linux();
        tableau();
        table();
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
void user_linux(){
    printf(".user-linux{\
        text-align: center;\
        margin-top: 4vw;\
        font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;\
        color: lightgoldenrodyellow;\
    }");
}

void tableau(){
    char _60[] = "60%c";
    printf(".tableau{\
        border: 2px solid rgba(206, 193, 193, 0.5);\
        width: 60%c;\
        position: absolute;\
        top: 50%c;\
        left: 50%c;\
        transform: translate(-50%c, -50%c);\
        border-radius: 30px;\
        box-shadow: 0px 20px 20px -5px rgb(0, 117, 128), 0 10px 10px -10px darkkhaki;\
    }",37,37,37,37,37);
}
void table(){
    printf("table{\
        margin: auto;\
        margin-top: 20px;\
        margin-bottom: 20px;\
        font-family: 'Courier New', Courier, monospace;\
        font-style: italic;\
        color: rgb(17, 246, 17);\
    }");
}