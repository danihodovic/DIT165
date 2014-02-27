/* ====================================
File name: code.c
Date: Feb 27, 2014
Group Number: 13
Members that contributed:
Dani Hodovic
Sinan Alazzawi
Yazen Raad
Demonstration code: [<Ass code 1‐4> <35047>]
====================================== */

#include <stdio.h>
#include <stdlib.h>
#define CLICKOPEN 0x03
#define WIDEOPEN 0x08
char* door = 0xB00;

void sleep()	{
int i;
for(i = 0; i < 2000; i++){}
}

void open_door()	{
*door = 0x01;
while(1)	{
	puts("Opening doors");
	if(*door & WIDEOPEN)	{
		sleep();
		break;
	}
}
}

void close_door()	{
	puts("Closing doors");
	*door = 0x02;
}

void main(void){

puts("Started");
while(1)	{
	if(*door & CLICKOPEN)	{
		open_door();		
	}else if(*door & WIDEOPEN){
		close_door();
	}
}
}
