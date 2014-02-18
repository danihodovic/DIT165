/* ==================================== 
File name: exerc_4_3.c
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
//http://www.mathsisfun.com/binary-decimal-hexadecimal-converter.html

char* button = 0x400;
char* outport = 0x402;

void sleep()	{
for(i = 0; i < 50; i++){
//Sleeps
}
}

void main(void){
int i;
char increment = 0x01;
puts("Started");

while(1){
//If the 8th button is pressed
if (*button & 0x80){
    	puts("Button pressed\n");
    	//Writes increment to outport
    	*outport = increment;

        if (increment & 0x80) {
			//Reset if at the 8th bit, reset to first bit
			puts("Enters if!!\n");
			increment = 0x01;
        }else	{
			//Otherwise move 1 step to left
			increment = increment << 0x01;
        }
}
sleep();
}
}
