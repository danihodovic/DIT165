#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv) {
	char* word = *(argv + 1);
	char* first_letter = word;
	char* last_letter = word + strlen(word) - 1;

	printf("\n%s is ", word);

	while(*first_letter == *last_letter)	{
		if(last_letter - first_letter <= 1)	{
			printf("palindrome\n");
			exit(1);
		}

		first_letter++;
		last_letter--;
	}
	printf("not palindrome\n");
	return 0;
}
