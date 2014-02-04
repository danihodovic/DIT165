#include <stdlib.h>
#include <stdio.h>

typedef struct tree tree;

struct tree	{
	int value;
	tree* left;
	tree* right;
};

void insert(tree** treeptr, int value)	{
	if(*treeptr == NULL)	{
		*treeptr = malloc(sizeof(tree));
		(*treeptr)->value = value;
	}else if((*treeptr)->value > value)	{
		insert(&((*treeptr)->left), value);
	}else	{
		insert(&((*treeptr)->right), value);
	}
}

void print(tree* tree)	{
	if(tree != NULL)	{
		print(tree->left);
		print(tree->right);
		printf("Value : %d\n", tree->value);
	}
}

int main(int argc, char **argv) {
	srand(time(NULL)); // Seed the time

	tree* tree;
	int random;
	int i;
	for(i = 0; i < 20; i++)	{
		random = rand()%(100-10)+10;
		insert(&tree, random);
	}
	print(tree);


	return 0;
}
