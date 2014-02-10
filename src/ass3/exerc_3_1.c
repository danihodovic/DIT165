/* ==================================== 
File name: exerc_3_1.c
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


enum DIRECTION {N,O,S,W};
int MAX = 50;

typedef struct {
        int xpos, ypos;
        enum DIRECTION dir;
} ROBOT;

void move(ROBOT* robot)	{
	switch (robot->dir) {
		case N:
			robot->ypos++;
			break;
		case S:
			robot->ypos--;
			break;
		case W:
			robot->xpos--;
			break;
		case O:
			robot->xpos++;
			break;
		default:
			break;
	}
}

void turn(ROBOT* robot)	{
	switch (robot->dir) {
		case N:
			robot->dir = O;
			break;
		case S:
			robot->dir = W;
			break;
		case W:
			robot->dir = N;
			break;
		case O:
			robot->dir = S;
			break;
		default:
			break;
	}
}

ROBOT* init_robot()	{
	ROBOT* robot = malloc(sizeof(ROBOT));
	robot->dir = N;
	robot->xpos = 0;
	robot->ypos = 0;
	return robot;
}

//int main(int argc, char **argv) {
//	ROBOT* robot = init_robot();
//	char command[MAX];
//	int i;
//
//	printf("Enter the command, or x to exit>");
//	while(fgets(command, MAX, stdin) != NULL)	{
//		if(command[0] == 'x')	{
//			break;
//		}
//		for(i = 0; i < MAX; i++)	{
//			if(command[i] == 'm')	{
//				move(robot);
//			}else if (command[i] == 't')	{
//				turn(robot);
//			}
//		}
//		printf("Robot current xpos : %d | robot ypos : %d\n",
//				robot->xpos, robot->ypos);
//		printf("Enter the command, or x to exit>");
//	}
//	printf("Final Robot xpos : %d | robot ypos : %d\n",
//			robot->xpos, robot->ypos);
//	return 0;
//}


