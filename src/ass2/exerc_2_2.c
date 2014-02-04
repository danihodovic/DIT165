#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define MAX 10


int size_of_array(int** ptr)	{
	return sizeof(*ptr);
}



int main(int argc, char **argv) {
	puts("---------");

	int* array = malloc(sizeof(int) * MAX);
	srand(time(NULL));

	int i = 0;
	while(i++ < MAX)	{
		*array++ = rand()%(100-10)+10;
	}

//	The value of array ( address)
	printf("Array address : %p\n", array);

//	First integer ( array[0]).
	printf("First int : %d\n", *(array - MAX));

//	The size of an integer (number of bytes) and the size of the array.
	printf("Size of an integer : %lu\n", sizeof(*array));
	printf("Size of array : %lu\n\n", sizeof(*array) * MAX);

//	Double all values in the array by using pointers.
	array = array - MAX;
	while(*array)	{
		printf("Original val : %d\t", *array);
		*array++ *= 2;
		printf("Doubled val : %d\t\n", *(array - 1));
	}

	puts("---------");
	return 0;
}
