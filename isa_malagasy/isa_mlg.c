#include "isa_mlg.h"

char* manisa(int i){

    const char* isa[] = {
        "ray","roa","telo","efatra","dimy","enina","fito","valo","sivy"
    };
    const char* ampolo[] = {
        "folo","roapolo","telopolo","efapolo","dimapolo","enimpolo","fitopolo","valopolo","sivifolo"
    };
    if(i<10)
        return (char*) isa[i-1];

    else if (i >=10 && i <100){
        if(i%10 == 0)
            return (char*)ampolo[i/10 -1];
    }
    
    else
        return "NULL";
}
