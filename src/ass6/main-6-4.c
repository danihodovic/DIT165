/* ====================================
File name: main-6-2.c
Date: Mar 4, 2014
Group Number: 13
Members that contributed:
Dani Hodovic
Sinan Alazzawi
Yazen Raad
Demonstration code: [<Ass code 1‐4> <34798>]
====================================== */
#include <_rtk.h>
#include <stdio.h>

#define TIMESLICE 5 // 5 for simulator mode and 100 for 
#define ID_1 1
#define ID_2 2
#define ID_3 3
#define ID_4 4

void AtInterrupt(void); 

void P1(void);
void P2(void); 
void P3(void); 
void P4(void); 

int count = 0;


void main()	{
InitKernel(TIMESLICE, AtInterrupt);
initsem(ID_1, 0);
initsem(ID_2, 0);
initsem(ID_3, 0);
initsem(ID_4, 0);


if( CreateProcess("P1", P1) == -1){
	printl("\nCan't create process");
	exit();
}

if( CreateProcess("P2", P2) == -1){
	printl("\nCan't create process");
	exit();
}
if( CreateProcess("P3", P3) == -1){
	printl("\nCan't create process");
	exit();
}
if( CreateProcess("P4", P4) == -1){
	printl("\nCan't create process");
	exit();
}
StartKernelForSim();
}


void P1()
{
	signalsem(ID_1);
	while(1)	{
		waitsem(ID_1);
		_outchar('1');
		signalsem(ID_2);
	}
	TerminateProcess(0);
}

void P2(){
	while(1)	{
		waitsem(ID_2);
		_outchar('2');
		signalsem(ID_3);
	}
	TerminateProcess(0);
}

void P3(){
	while(1)	{
		waitsem(ID_3);
		_outchar('3');
		signalsem(ID_4);
	}
	TerminateProcess(0);
}

void P4(){
	while(1)	{
		waitsem(ID_4);
		_outchar('4');
		signalsem(ID_1);
	}
	TerminateProcess(0);
}

void AtInterrupt(void){
	insert_last(Running, &ReadyQ);
	Running= remque(&ReadyQ);
}
