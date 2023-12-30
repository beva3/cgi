#include "isa_mlg.h"

char* manisa(int n){
    char tmp[255];
    const char* isa[] = {
        "ray","roa","telo","efatra","dimy","enina","fito","valo","sivy"
    };

    const char* ampolo[] = {
        "folo","roapolo","telopolo","efapolo","dimapolo","enimpolo","fitopolo","valopolo","sivifolo"
    };
    
    if(n<10)
        return (char*) isa[n-1];

    else if (n >=10 && n <100){
        if(n%10 == 0)
            return (char*)ampolo[n/10 -1];
        else{
            char* isa_malagasy = (char*)malloc(255);
            (n % 10 == 1) ? strcpy(isa_malagasy,"iraika"): strcpy(isa_malagasy,isa[n%10 -1]);
            strcat(isa_malagasy,amby_(n));
            strcat(isa_malagasy,ampolo[n/10 -1]);
            return isa_malagasy;
        }
    }
    
    else
        return "NULL";
}

char* amby_(int n){
    return (n > 20) ? " amby " : " ambin 'ny ";
}
