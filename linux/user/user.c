#include "user.h"

char*affect(char*dest,const char*scr){
	return strcpy(dest,scr);
}

int str2_len(char**t){
	int l=0;
	while(t[l] !=NULL) l++;
	return l;
}

void echotab(char**t){
	for(int i=0 ; i<str2_len(t) ;i++)
		printf("%s",t[i]);
    /* == [fonction de verification] ==*/
}

char**tab_user(){
	FILE*f=NULL;
	char**tab=(char**)malloc(1000*sizeof(char*));
	for(int i = 0 ; i < 1000 ;  i++) tab[i]=(char*)malloc(256*sizeof(char));
	char*tmp=(char*)malloc(256*sizeof(char));
	int i=0;

	f=fopen("/etc/passwd","r");
	while(fgets(tmp,256,f) !=NULL){
		affect(tab[i],tmp);
		i++;
	}

	tab[i]=NULL;
	fclose(f);
	free(tmp);
	return tab;
}