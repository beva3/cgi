#include "isa_mlg.h"

char* manisa(int i){

    const char* isa[] = {
        "ray","roa","telo","efatra","dimy","enina","fito","valo","sivy"
    };
    return (char*) isa[i-1];
}

