#include "isa_mlg.h"

char* manisa(int i){

    const char* isa[] = {
        "ray","roa","telo","efatra","dimy","enina","fito","valo","sivy"
    };
    if(i<10)
        return (char*) isa[i-1];
    else
        return "NULL";
}

