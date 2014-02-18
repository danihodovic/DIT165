/* ==================================== 
File name: decode.c
Date: Feb 18, 2014 
Group Number: 13
Members that contributed: 
Dani Hodovic
Sinan Alazzawi
Yazen Raad
Demonstration code: [<Ass code 1‐4> <abc>]
====================================== */ 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	if(!(argc == 2 && strlen(argv[1]) == 2))	{
		puts("Invalid input");
		return 6;
	}
	unsigned int byte;
	sscanf(argv[1],"%x", &byte);

	char engine_on = (byte & 0b10000000) >> 7;
	char gear_pos = (byte & 0b01110000) >> 4;
	char key_pos = (byte & 0b00001100) >> 2;
	char brake1 = (byte & 0b000000010) >> 1;
	char brake2 = (byte & 0b00000001);
	printf("Name\t\tValue\n");
	puts("------------------------");
	printf("engine_on\t%u\n", engine_on);
	printf("gear_pos\t%u\n", gear_pos);
	printf("key_pos\t\t%u\n", key_pos);
	printf("brake1\t\t%u\n", brake1);
	printf("brake2\t\t%u\n", brake2);
	//	1,2,2,1,1
	return 0;
}
