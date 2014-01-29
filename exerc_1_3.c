#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 20



int main()
{
	char text[MAX];
	int i;
	int num_chars;

	while(num_chars != EOF)        {

		i = 0;
		num_chars = scanf("%s", text);
			while(1)        {
				if(text[i] == '\0')        {
					puts("\n");
					break;
				}
				if(text[i] > 109)        {
					printf("%c", (char)((int)text[i]) - 13);
				}else        {
					printf("%c", (char)((int)text[i]) + 13);
				}
				i++;
			}
		
	}
}

