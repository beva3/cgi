#ifndef __CLAVARO__
#define __CLAVARO__
	
	#include <stdio.h>
	#include <string.h>
	#include <stdbool.h>

	typedef struct CAR_i{
		char* car_i; // <spam> car[i] </spam>
		char i; //position
	}CAR_i;
	
	
	bool est_egal(char c1, char c2);
	
	bool est_egal_str(char* mot1, char* mot2);
	

#endif
