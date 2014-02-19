/* ==================================== 
File name: exerc_4_4.c
Date: Feb 18, 2014 
Group Number: 13
Members that contributed: 
Dani Hodovic
Sinan Alazzawi
Yazen Raad
Demonstration code: [<Ass code 1‐4> <abc>]
====================================== */ 
#include <stdio.h>
#include <stdlib.h>

unsigned char* address = 0x09C0;
//http://www.mathsisfun.com/binary-decimal-hexadecimal-converter.html
int is_key_pressed()	{
	int bool = *address & 0x80;
	return !bool;
}

void print_character()	{
	char c;
	char source = *address & 0xF; //filter out what we need
	sscanf(&source, "%x", &c);
	printf("Key pressed: %x\n", c);
}
void main(){

while(1)	{
	if(is_key_pressed())	{
		print_character();
	}
}
}
