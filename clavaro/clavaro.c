#include "clavaro.h"

char* corrigez(char* correct, char* reponse){
    
    char* correction = (char*)malloc(strlen(correct) + 1);

    for (int i = 0; i < strlen(correct); i++){
        if(reponse[i] != correct[i] ){
                correction[i] = '#';
        }else{
            correction[i] = reponse[i];
        }
    }
    
    return correction;
}

bool est_egal_str(char* mot1, char* mot2){
	
	return strcmp(mot1, mot2) == 0 ? true : false;
}