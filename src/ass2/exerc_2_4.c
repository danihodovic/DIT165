//Code : 36412


/*
 * exerc_2_4.c
 *
 *Code: 36412
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

int isPalindrome(char* first_letter, char* last_letter)	{
	printf("\n%s is ", first_letter);

	while(*first_letter == *last_letter)	{
		if(last_letter - first_letter <= 1)	{
			printf("palindrome\n");
			return 1;
		}

		first_letter++;
		last_letter--;
	}
	printf("not palindrome\n");
	return 0;
}

int main(int argc, char **argv) {
	char* word = *(argv + 1);
	char* first_letter = word;
	char* last_letter = word + strlen(word) - 1;

	isPalindrome(first_letter, last_letter);
	return 0;
}
