#include <stdio.h>
#include <stdlib.h>

struct linkedlist	{
	int value;
	struct linkedlist * next;
};

typedef struct linkedlist item;

int main(int argc, char **argv) {
	item * root;
	item * current;

	root = malloc(sizeof(item));
	root->value = 500;

	current = root;

	int i;
	for(i = 0; i <= 20; i++)	{
		current->next = malloc(sizeof(item));
		current = current->next;
		current->value = i;
	}

	while(root->next != NULL)	{
		printf("This is NEVER EXECUTED\n");
		printf("[%d]\n", root->value);
		root = root->next;
	}
	printf("Hello\n");
	return 0;
}

