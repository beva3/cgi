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

	if(j >= 0 && j + 5<str2_len(t))
	{
		printf("<table>");
		printf("\
		<tr>\
			<th class = \"h-user		\">user</th>\
			<th class = \"h-uid			\">uid</th>\
			<th class = \"h-gid			\">gid</th>\
			<th class = \"h-repository	\">repository</th>\
			<th class = \"h-shell		\">shell</th>\
		</tr>\
		");
			
		for(int i=j ; i< j + 5 ;i++){
			printf("%s",t[i]);
		}
		printf("</table>");
	}
	else printf("\
	<tr>\
		<td><h1>Tsy Misy</h1></td>\
	</tr>");
	

    /* == [fonction de verification] ==*/
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

	if (index > 0 ){
		printf("<a href = \"http://localhost/cgi-bin/user_linux?index=%d\"><</a>",index - 1);
	}
	else{
		printf("<input type=\"button\" value=\"<\" disabled>");
	}

	for (int i = index; i < index + 5; i++)
	{
		printf("<a href = \"http://localhost/cgi-bin/user_linux?index=%d\">%d</a>",i,i + 1);
		if (i+ 7 > str2_len(tab_user()))
		{
			break;
		}	
	}

	if (index + 9< str2_len(tab_user()) ){
		printf("<a href = \"http://localhost/cgi-bin/user_linux?index=%d\">></a>",index + 1);
	}
	else{
		printf("<input type=\"button\" value=\">\" disabled>");
	}
	
}

int index_(char* query_string){
	int index = 0;
	sscanf(query_string,"index=%d",&index);
	return index;
}

void tronc(){
	char* query_string = getenv("QUERY_STRING");
	int i = index_(query_string);
	echotab(tab_user(),i);
	link(i);
	//printf("<h2>%s</h2>",query_string);
}
