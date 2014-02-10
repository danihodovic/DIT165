//Code : 31335


/* exerc_2_3.c
 *
 *Code: 31335
 *Contributors: Dani Hodovic
 *Contributors: Sinan Alazzawi
 *Contributors: Yazen Raad
 *
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


//Enter four or more arguments to use strcmp
//argv[1] and argv[2] are comparison strngs

int main(int argc, char **argv) {
	char* ptr_first = *(argv+1);
	char* ptr_second = *(argv+2);

	if(argc > 3)	{
		if(strcmp(ptr_first, ptr_second) == 0)	{
			puts("strcmp:\tThe strings are the same");
		}
		else	{
			puts("strcmp:\tThe strings are not the same");
		}
	}else	{
		while(*ptr_first == *ptr_second)	{
			if(*(ptr_first) == '\0')	{
				puts("own method:\tThey're the same");
				exit(1);
			}
			ptr_first++;
			ptr_second++;
		}
		puts("own method:\tThey're not the same");
	}
	return 0;
}
