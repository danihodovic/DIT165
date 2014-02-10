/* ==================================== 
File name: exerc_3_2.c
Date: Feb 6, 2014 
Group Number: 13
Members that contributed: 
Dani Hodovic
Sinan Alazzawi
Yazen Raad
Demonstration code: [<Ass code 1‐4> <abc>]
====================================== */ 
#include <stdlib.h>
#include <stdio.h>


int search_number( int number, int array[], int size);
void sort (int size, int array[]);

int search_number(int number, int array[], int size)	{
	int i;
	for(i = 0; i < size; i++)	{
		if(array[i] == number)	{
			return i;
		}
		i++;
	}
	return -1;
}

void sort(int size, int array[])	{
	int i, j, temp;
	for(i = 0; i < size; i++)	{
		temp = array[i];
		j = i - 1;
		while(array[j] > temp && j >= 0)	{
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = temp;
	}
}


//int main(int argc, char **argv) {
//	int test[] = {5, 7, 1, 2, 3, 4},
//			test_size = sizeof(test)/sizeof(test[0]);
//
//
//	//	int pos = search_number(13, test, test_size);
//	//	printf("Index : %d\n", array_size(test));
//
//	int i;
//	for(i = 0; i < test_size; i++)	{
//		printf("%d | ", test[i]);
//	}
//	puts("");
//
//	sort(test_size, test);
//
//	for(i = 0; i < test_size; i++)	{
//		printf("%d | ", test[i]);
//	}
//	puts("");
//
//
//	return 0;
//}
//
