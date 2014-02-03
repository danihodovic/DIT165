#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	char* first_letter = *(argv + 1);
	char* last_letter = *(argv + 1) + (strlen(*(argv + 1)) - 1);

	while(*first_letter == *last_letter)	{
		if(first_letter == last_letter)	{
			puts("Palindrome");
			exit(1);
		}
		first_letter++;
		last_letter--;
	}
	puts("Not palindrome");


	return 0;
}
