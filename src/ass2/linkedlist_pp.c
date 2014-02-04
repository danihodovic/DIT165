#include <stdlib.h>
#include <stdio.h>


struct list{
	int value;
	struct list* next;
};

typedef struct list list;

void insert(list** lpp, int value)	{
	if(*lpp == NULL)	{
		*lpp = malloc(sizeof(list));
		(*lpp)->value = value;
		printf("Inserting : %d\n", value);
	}else	{
		insert(&(*lpp)->next, value);
	}
}

void delete(list** lpp, int value)	{
	list* nextnode;
	if((*lpp)->next != NULL)	{
		puts("Enters 1");
		nextnode = (*lpp)->next;
		printf("Nextnode val : %d, remove val : %d\n", nextnode->value, value);
		if(nextnode->value == value)	{
			puts("Enters 2");
			if(nextnode->next != NULL)	{
				(*lpp)->next = nextnode->next;
			}else	{
				(*lpp)->next = NULL;
			}
		}else	{
			delete(&(nextnode), value);
		}
	}
}

void print_list(list* list)	{
	if(list != NULL)	{
		printf("%d\n", list->value);
		print_list(list->next);
	}
}



int main(int argc, char **argv) {
	list* my_list;

	int i;
	for(i = 5; i < 11; i++)	{
		insert(&my_list, i);
	}
	delete(&my_list, 7);
	print_list(my_list);

	return 0;
}
