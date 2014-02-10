/*
 * Exerc_2_ 1.c
 *
 *  Created on: Jan 29, 2014
 *      Author: dani
 */
#include <stdlib.h>
#include <stdio.h>

#define MAX 50

int main(int argc, char **argv) {
	if(argc > 1)	{
		char char_array [MAX];
		FILE *f1;
		f1 = fopen("text.txt", "r");
		strncpy(char_array, f1);
		while(fgets(char_array, MAX, f1) != NULL)	{
			printf("%s", char_array);
		}
	}else{

		char char_array [MAX];
		while(fgets(char_array, MAX, stdin) != NULL)	{
			printf("%s", char_array);
		}
	}

	return 0;
}

