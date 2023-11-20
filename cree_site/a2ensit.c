#include "a2ensit.h"

int main(){
	char* t[] ={\
		"VirtualHost *:80>\n",\
			"\tServerName rapha_admin.com",\
			"\tServerAdmin mizabienvenu@gmail.com",\
        	"\tServerAlias  www.test_client.com",\
        	"\tDocumentRoot /home/raphael/www/site_client/\n",\
        	"\t<Directory /home/raphael/www/site_client/>",\
        		"\t\tOptions Indexes FollowSymLinks",\
        		"\t\tAllowOverride None",\
        		"\t\tRequire all granted",\
        	"\t</Directory>\n",\
        	"\tErrorLog ${APACHE_LOG_DIR}/error.log",\
        	"\tCustomLog ${APACHE_LOG_DIR}/access.log combined\n",\
		"</VirtualHost>",\
		NULL\
	};
	
	int i = 0;

	while(t[i] != NULL){
		printf("%s\n",t[i]);
		i++;
	}


	return 0;
}
