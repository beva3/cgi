#include "auth_log.h"

char**tab_auth(){
	
    char line[256];
    char moment[100];
    char for_user[256];
    int compt=0;
    AUTH auth = {{"date","time"},"srvc_prg ","pan","ses","user"};
    /*Nov 13 15:30:02 raphael-HP-ProBook-450-G2 CRON[30388]: pam_unix(cron:session): session closed for user root*/
	FILE*f=fopen("/var/log/auth.log","r");
    char**tab=(char**)malloc(1000*sizeof(char*));
	for(int i = 0 ; i < 1000 ;  i++) tab[i]=(char*)malloc(256*sizeof(char));

	while (fgets(line,256,f)!=NULL){
                if (strstr(line,"for user")!=NULL)
                {   
                    strcpy(for_user,line);/*zay misy user ihany no lalaoviko*/
                    compt++;
                    printf("%s",line);
                    //sscanf(line,"%[^r]raphael-HP-ProBook-450-G2 %[^:]: pam_unix(%[^:]:session): session %[^ ] for user %[^(]",moment,auth.srvc_prgrm,auth.pam_unix,auth.sesion,auth.user);
                }
            }

	fclose(f);
	return tab;
}