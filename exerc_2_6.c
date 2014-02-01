/*
 * exerc_2_6.c
 *
 *  Created on: Feb 1, 2014
 *      Author: dani
 */

#include <stdlib.h>
#include <stdio.h>
#define MAX 5

void fill(int* p)	{
	int i;
	for(i = 0; i < MAX; i++)	{
		p[i] = -1;
	}
}

int push(int* p, int num)	{
	if(p[MAX - 1] != -1)	{
		return 0;
	}
	int tmp;
	int i;
	for (i = 0; i < MAX; ++i) {
		tmp = p[i];
		p[i] = num;
		num = tmp;
	}
	return 1;
}


int main(int argc, char **argv) {
	int array[MAX];
	fill(array);

	push(array, 5);
	push(array, 7);
	push(array, 5);
	push(array, 7);
	push(array, 13);
	push(array, 19);

	int i;
	for (i = 0; i < MAX; ++i) {
		printf("%d\t", array[i]);
	}
	puts("");

	return 0;
}

