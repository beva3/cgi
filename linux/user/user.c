#include "user.h"

char*affect(char*dest,const char*scr){
	return strcpy(dest,scr);
}

int str2_len(char**t){
	int l=0;
	while(t[l] !=NULL) l++;
	return l;
}

void echotab(char**t,int j){
	if(j >= 0 && j + 5<str2_len(t)){
		printf("<table>");
			printf("\
			<tr>\
				<th class = \"h-user		\">user</th>\
				<th class = \"h-uid			\">uid</th>\
				<th class = \"h-gid			\">gid</th>\
				<th class = \"h-repository	\">repository</th>\
				<th class = \"h-shell		\">shell</th>\
			</tr>");
			for(int i=j ; i< j + 5 ;i++){
				printf("%s",t[i]);
			}
		printf("</table>");
	}
	else printf("\
	<tr>\
		<td><h1>Tsy Misy</h1></td>\
	</tr>");
}

char**tab_user(){
	FILE*f=NULL;
    USER u={"root",0,0,"/root/root","shell"};/*user - uid - gid - rep - shell*/

    char**sp=(char**)malloc(5*sizeof(char*));
    for(int i=0; i<5; i++) sp[i]=(char*)malloc(50*sizeof(char));

	char**tab=(char**)malloc(1000*sizeof(char*));
	for(int i = 0 ; i < 1000 ;  i++) tab[i]=(char*)malloc(256*sizeof(char));

	char line[256];
    char tmp[256];
	int i=0;

	f=fopen("/etc/passwd","r");
	while(fgets(line,256,f) !=NULL){
        sscanf(line,"%[^:]:x:%d:%d:%[^\n]",u.name,&u.uid,&u.gid,tmp);
        sp=split(tmp);

        sprintf(tab[i],"\
		<tr>\
			<td class = \"user\">%s</td>\
			<td class = \"uid\">%d</td>\
			<td class = \"gid\">%d</td>\
			<td class = \"repository\">%s</td>\
			<td class = \"shell\">%s</td>\
		</tr>",u.name,u.uid,u.gid,sp[1],sp[2]);
		//affect(tab[i],line);
		i++;
	}
    tab[i]=NULL;

	fclose(f);
	return tab;
}

char** split(char*str){
    char**sp=(char**)malloc(5*sizeof(char*));
    for(int i=0; i<5; i++) sp[i]=(char*)malloc(50*sizeof(char));

    int i=0;/*pour la string*/
    int j=0;/*controle dans sp*/
    int k=0;/*controle le numereau de ligne */

    while (str[i]!='\0')
    {
        if(str[i]!=':'){
			sp[j][k]=str[i];
			k++;
		}
        else{
			j++;k=0;
		}
		i++;
    }
    return sp;
}
void link(int index){

	printf("<div class = \"pagination\">");

		if (index > 0 )
			printf("\
			<div>\
				<a href = \"http://localhost/cgi-bin/user_linux?index=%d\"> < </a>\
			</div>",index - 1);
		else
			printf("\
			<div>\
				<input type=\"button\" value=\"<\" disabled>\
			</div>");

		for (int i = index; i < index + 5; i++){
			printf("\
			<div>\
				<a href = \"http://localhost/cgi-bin/user_linux?index=%d\">%d</a>\
			</div>",i,i + 1);
			if (i+ 7 > str2_len(tab_user()))
				break;	
		}

		if (index + 9< str2_len(tab_user()) )
			printf("\
			<div>\
				<a href = \"http://localhost/cgi-bin/user_linux?index=%d\"> > </a>\
			</div>",index + 1);
		else
			printf("\
			<div>\
				<input type=\"button\" value=\">\" disabled>\
			</div>");
	printf("</div>");
	
}

int index_(char* query_string){
	int index = 0;
	sscanf(query_string,"index=%d",&index);
	return index;
}

void tronc(){
	char* query_string = getenv("QUERY_STRING");
	int i = index_(query_string);
	//recherch();
	echotab(tab_user(),i);
	link(i);
}

/*chercher un mot*/
char**tab_user_needl(char* needl){
	FILE*f=NULL;
    USER u={"root",0,0,"/root/root","shell"};/*user - uid - gid - rep - shell*/

    char**sp=(char**)malloc(5*sizeof(char*));
    for(int i=0; i<5; i++) sp[i]=(char*)malloc(50*sizeof(char));

	char**tab=(char**)malloc(1000*sizeof(char*));
	for(int i = 0 ; i < 1000 ;  i++) tab[i]=(char*)malloc(256*sizeof(char));

	char line[256];
    char tmp[256];
	char mot_chercher[256];
	int i=0;

	f=fopen("/etc/passwd","r");
	while(fgets(line,256,f) !=NULL){
		if(strstr(line,needl) != NULL){
			strcpy(mot_chercher,line);
        	sscanf(mot_chercher,"%[^:]:x:%d:%d:%[^\n]",u.name,&u.uid,&u.gid,tmp);
		}
        sp=split(tmp);

        sprintf(tab[i],"\
		<tr>\
			<td class = \"user\">%s</td>\
			<td class = \"uid\">%d</td>\
			<td class = \"gid\">%d</td>\
			<td class = \"repository\">%s</td>\
			<td class = \"shell\">%s</td>\
		</tr>",u.name,u.uid,u.gid,sp[1],sp[2]);
		//affect(tab[i],line);
		i++;
	}
    tab[i]=NULL;

	fclose(f);
	return tab;
}

void recherch(){
	printf("\
	<div class = \"recherch\">");
		printf("\
		<a href = \"#\">[chercher]</a>");
	printf("\
	</div>");
}
/**/
char* tab_i(char** t, int i){
	return t[i];
}

char** result_recherche(char* needel){
	char**tab=(char**)malloc(1000*sizeof(char*));
	for(int i = 0 ; i < 1000 ;  i++) tab[i]=(char*)malloc(256*sizeof(char));
	int i = 0;
	while (tab_i(tab_user(), i) != NULL){
		if (strstr(tab_i(tab_user(), i),needel) != NULL){
			affect(tab[i],tab_i(tab_user(), i));
		}
		
		i++;
	}
			
	return tab;
}