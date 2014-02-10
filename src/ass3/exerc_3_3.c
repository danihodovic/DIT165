/* ==================================== 
File name: exerc_3_3.c
Date: Feb 6, 2014 
Group Number: 13
Members that contributed: 
Dani Hodovic
Sinan Alazzawi
Yazen Raad
Demonstration code: [<Ass code 1‐4> <abc>]
====================================== */ 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 15

typedef struct node{
	int number;
	struct node* next;
	struct node* prev;
} NODE;

NODE* random_list();
void add_first(NODE** temp, int data);

//int main(int argc, char *argv[])
//{
//	srand(time(0));  //   Random seed
//	int nr = 0;
//	NODE *cur_pos, *head = NULL;
//
//	srand(time(0));  //   Random seed
//	head = random_list();
//	cur_pos = head;
//
//	puts("---Printing list---");
//	while(cur_pos != NULL){
//		printf("Post nr %d : %d\n" , nr++, cur_pos->number);
//		cur_pos = cur_pos->next;
//	}
//
//
//	// ‐‐‐ Free of allocated memory  ‐‐‐
//	//	while((cur_pos = head) !=NULL ){
//	////		head = akt_post‐>next;
//	//		puts("Looping");
//	//		free(cur_pos);
//	//	}
//
//	puts("---Adding item---");
//	add_first(&head, 999);
//	nr = 0;
//	printf("Post nr %d : %d\n" , nr++, head->number);
//	while((head = head->next) != NULL){
//		printf("Post nr %d : %d\n" , nr++, head->number);
//	}
//
//	puts("---In reverse---");
//	nr = 0;
//	while(head != NULL){
//		printf("Post nr %d : %d\n" , nr++, head->number);
//		if(head->prev != NULL)	{
//			head = head->prev;
//		}else break;
//	}
//	return 0;
//}

NODE* random_list(){
	int i;
	NODE *root, *list;
	list = malloc(sizeof(NODE));
	list->number = rand() % 100;
	root = list;

	for(i = 0; i < MAX - 1; i++)	{
		list->next = malloc(sizeof(NODE));
		list->next->prev = list;
		list->next->number = rand() % 100;
		list = list->next;
	}
	//	printf("Last added number : %d\n", list->number);

	return(root);
}

void add_first(NODE** cur_head, int data){
	NODE* new_head = malloc(sizeof(NODE));
	new_head->number = data;
	new_head->next = *cur_head;
	//	(*cur_head)->prev = new_head;
	*cur_head = new_head;
}

