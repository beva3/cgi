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
        else return "NULL";
    }
    
    else
        return "NULL";
}

/* char* manohy(char* teny1,char* teny2){
    char* isa_malagasy = (char*)malloc(strlen(teny1) + strlen(teny2));
    sprintf(isa_malagasy,"%s %s",teny1,teny2);
    return isa_malagasy;
    free(isa_malagasy);
} */
