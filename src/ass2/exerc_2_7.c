
/*
 * exerc_2_7.c
 *
 *Code: 33616
 *Contributors: Dani Hodovic
 *Contributors: Sinan Alazzawi
 *Contributors: Yazen Raad
 *
 *
 *
 *  Created on: Feb 3, 2014
 *      Author: dani
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void readPersnr(char* person);
int controlDigit(const char* persnr);
int checkDates(const char* person);

void readPersnr(char* person)	{
	if(checkDates(person))	{
		if(controlDigit(person))
			printf("Valid persnr: %s", person);

		else printf("Invalid persnr: %s", person);

	}
	else puts("Invalid dates");
}

int checkDates(const char* person)	{
	char* month = malloc(sizeof(char) * 2);
	strncpy(month, person+2, 2);
	int monthInt = atoi(month);

	char* day = malloc(sizeof(char) * 2);
	strncpy(day, person+4, 2);
	int dayInt = atoi(day);

	if(12 >= monthInt >= 1 && 31 >= dayInt >= 1)	{
		return 1;
	}
	return 0;
}

int controlDigit(const char* persnr)	{
	int sum = 0;
	char* substr = malloc(sizeof(char) * 2);
	int i;
	for(i = strlen(persnr) - 1; i >= 0; i--)	{
		strncpy(substr, persnr + i, 1);
		int number = atoi(substr);
		if(i % 2 == 0)	{
			number *= 2;
			if(number > 9)	{
				number = (number % 10) + 1;
			}
		}
		sum += number;
	}
	return sum % 10 == 0;
}

int main(int argc, char **argv) {
	char* personnr = malloc(sizeof(char) * 10);
	printf("Enter persnr>");
	while(fgets(personnr, 20, stdin) != NULL)	{
		if(strlen(personnr) == 11)	{
			readPersnr(personnr);
			printf("Enter another persnr>");
		}else	{
			puts("Error : Enter 10 digit personnr");
		}
	}

	return 0;
}
