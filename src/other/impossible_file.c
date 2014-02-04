#include <stdlib.h>
#include <stdio.h>

struct bin_tree	{
	int data;
	struct bin_tree * left;
	struct bin_tree * right;
};

typedef struct bin_tree node;

node* insert(node * tree, int val)	{
	if(!tree)	{
		tree = (node *)malloc(sizeof(node));
		tree->left = NULL;
		tree->right = NULL;
		tree->data = val;
		return tree;
	}else if(val < (tree)->data)	{
		printf("Adding to the left : %d\n", tree->data);
		insert(tree->left, val);
	}else if(val > (tree)->data)	{
		printf("Adding to the right : %d\n", tree->data);
		insert(tree->right, val);
	}
	return tree;
}

void print_inorder(node *tree)	{
	if(tree)	{
		print_inorder(tree->right);
		printf("%d\n", tree->data);
		print_inorder(tree->left);
	}
}
int main()	{
	node *root = NULL;
	root = insert(root, 9);
	root = insert(root, 4);
	root = insert(root, 15);
	print_inorder(root);
	return 0;
}
