#include "auth.h"

TAB_L file_to_tab(FILE* f){
    TAB_L ftt = {NULL,0};
    int i = 0;
    char line[256];
    
    ftt.tab = (char**)malloc(MAX*sizeof(char*));
    for (int i = 0; i < MAX; i++)
    {
        ftt.tab[i] = (char*)malloc(256*sizeof(char));
    }

    while (fgets(line,256,f) != NULL)
    {
        if (strstr(line,"for user") != NULL)
        {
            strcpy(ftt.tab[i] , tab_data(line));
            i++;
        }
    }
    
    ftt.l = i - 1;
    

    return ftt;
}
int n_lfile(char* file){
    FILE* f = fopen(file,"r");
    int l = 0;
    char* line;

    while (fgets(line,256,f) != NULL){
        l++;
    }

    fclose(f);
    return l;
}

void echo_tab(TAB_L t,int index){

    printf("<table>");
    
    printf("\
	<tr>\
		<th class = \"moment	\">MOMENTS</th>\
		<th class = \"srv-prg	\">Service-Programme</th>\
		<th class = \"pam		\">Pam</th>\
		<th class = \"session	\">Session</th>\
		<th class = \"user  	\">User</th>\
	</tr>");
    
    for (int i = index; i < index + 5.l; i++)
    {
        printf("%s",t.tab[i]);
    }
    
    printf("</table>");
}

char* tab_data(char line[]){
    
    char* td = (char*)malloc(256*sizeof(char));
    char moment[100];
    AUTH auth = {{"date","time"},"srvc_prg ","pan","ses","user"};

    sscanf(line,"%[^r]raphael-HP-ProBook-450-G2 %[^:]: pam_unix(%[^:]:session): session %[^ ] for user %[^(]"\
    ,moment,auth.srvc_prgrm,auth.pam_unix,auth.sesion,auth.user);
    sprintf(td,"\
    <tr>\
        <td class = \"\">%s</td>\
        <td class = \"srvc_prog\">%s</td>\
        <td class = \"pam\">%s</td>\
        <td class = \"session\">%s</td>\
        <td class = \"user\">%s</td>\
    </tr>",moment,auth.srvc_prgrm,auth.pam_unix,auth.sesion,auth.user);
    return td;
}