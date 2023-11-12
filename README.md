pour activer cgi sous linux :

	==> installer apache2 : sudo spt-get install apache2
	==> a2enmod cgi 
	ex : hello.c
		#include <stdio.h>

		int main(){

			printf("Content-Type: text/html\n\n");

			printf("hello World");

			return 0;
		}
	==> gcc hello.c -o hello_bin.exe
	==> mv hello_bin.exe /usr/lib/usr-bin/
