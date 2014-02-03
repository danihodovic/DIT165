#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 20
#define MAXNUMBER 20
// ------ Function declaration ----------
void create_random( int *number);
void count_frequensy(int *number);
void draw_histogram(int *number);

int main ( void){
  int table[MAX];
  int frequensy[MAXNUMBER];

create_random(table);
count_frequensy(table);
draw_histogram(table);
}

void create_random( int *number){
  int i;
  
  srand(time(0));
  for( i = 0 ; i < MAX ; i++ ) {
    number[i] = rand()%MAXNUMBER;
    printf("%d,",number[i]);
  }
  printf("\n");
}

void count_frequensy(int *number){
  int count = 0;
  int i,j,z,w;
  int array [MAX];

  for (j = 0; j < MAX; j++)
    {
      array[j]= j;
    }
  for (i = 0; i < MAX; i++)
    {
      for (z = 0; z<MAX; z++)
	{
	  if ( number[z]==array[i])
	    {
	      count++;
	    }
	}
      array[i] = count;
      count = 0;
    }
  for (w = 0; w < MAX; w++)
    {
      number[w]= array[w];
    }
}

void draw_histogram(int *number ){
  int i,j;
  
  for( i = 0; i<MAX; i++){
      if ( number[i]!=0){
	printf("%d ",i);
	for (j = 0; j<number[i]; j++){
	  printf("x");
	}
	printf("\n");
      } 
  }
}