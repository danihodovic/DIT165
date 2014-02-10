/*
 * exerc_2_6.c

 *
 *Code: 37353
 *Contributors: Dani Hodovic
 *Contributors: Sinan Alazzawi
 *Contributors: Yazen Raad
 *
 */


#include <stdlib.h>
#include <stdio.h>
#define FIVE 5

int input (int list [], int number);
void initQue (int list[]);
int removeInt(int* list);

int input(int* list, int number)	{
	//	return if full
	if(*(list + FIVE - 1) != -1)	{
		return 0;
	}

	int tmp;
	int i;
	//	for(i = 0; i < FIVE; i++)	{
	//		tmp = *(list + i);
	//		*(list + i) = number;
	//		number = tmp;
	//	}
	for(i = 0; i < FIVE; i++)	{
		if(list[i] == -1)	{
			list[i] = number;
			break;
		}
	}

	return 1;
}

int removeInt(int* list)	{
	int i;
	for(i = FIVE - 1; i >= 0; i--)	{
		if(list[i] != -1)	{
			list[i] = -1;
			return 1;
		}
	}
	return 0;
}

void initQue(int* list)	{
	int i;
	for(i = 0; i < FIVE + 1; i++)	{
		*(list + i) = -1;
	}
}


int main(int argc, char **argv) {
	int array[FIVE];

	//	Fill it with -1's'
	initQue(array);

	int c;
	for(c = 0; c < FIVE; c++)	{
		printf("%d\t", array[c]);
	}

	puts("");

	input(array, 5);
	input(array, 3);
	input(array, 10);
	input(array, 14);
	input(array, 3);
	removeInt(array);
	input(array, 25);

	for(c = 0; c < FIVE; c++)	{
		printf("%d\t", array[c]);
	}

	puts("");

	return 0;
}
