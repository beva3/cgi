#include "auth.h"

TAB_L auth_log_tab(){
    TAB_L ftt = {NULL,0};
    int i = 0;
    char line[256];
    FILE* f = fopen("/var/log/auth.log","r");
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
    fclose(f);

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
    printf("\
    <div class = \"auth-tab\">");
        if(index >= 0 && index + 5 < t.l){
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
        else printf("\
		<tr>\
			<td><h1>Tsy Misy</h1></td>\
		</tr>");
    printf("\
    </div>");
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

int index_(char* query_string){
	int index = 0;
	sscanf(query_string,"index=%d",&index);
	return index;
}

void link(int index,TAB_L t){
	printf("\
	<div class = \"pagination\">");

		if (index > 0 ){
			printf("<a href = \"http://localhost/cgi-bin/auth_log?index=%d\"><</a>",index - 1);
		}
		else{
			printf("<input type=\"button\" value=\"<\" disabled>");
		}

		for (int i = index; i < index + 5; i++)
		{
			printf("<a href = \"http://localhost/cgi-bin/auth_log?index=%d\">%d</a>",i,i + 1);
			if (i+ 7 > t.l)
			{
				break;
			}	
		}

		if (index + 9< t.l ){
			printf("<a href = \"http://localhost/cgi-bin/auth_log?index=%d\">></a>",index + 1);
		}
		else{
			printf("<input type=\"button\" value=\">\" disabled>");
		}
	printf("\
	</div>");
	
}

void tronc(){
    TAB_L t =auth_log_tab();
	char* query_string = getenv("QUERY_STRING");
	int i = index_(query_string);
	echo_tab(auth_log_tab(),i);
    link(i,t);
	//printf("<h2>%s</h2>",query_string);
}