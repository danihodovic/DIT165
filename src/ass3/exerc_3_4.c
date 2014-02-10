/* ==================================== 
File name: exerc_3_4.c
Date: Feb 7, 2014 
Group Number: 13
Members that contributed: 
Dani Hodovic
Sinan Alazzawi
Yazen Raad
Demonstration code: [<Ass code 1‐4> <abc>]
====================================== */ 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 100
const char* filename = "myfile.bin";

typedef struct {
	char firstname[20];
	char lastname[20];
	char persnr[13]; // yyyymmddnnnc
}PERSON;


PERSON input_record();//reads in person
void write_new_file(PERSON* inrecord);//creates new file w pers
void printfile();//print all
void search_by_firstname(char *name);//print person
void append_file(PERSON *inrecord);//appends person

void print_options();

PERSON input_record()	{
	PERSON local_pers;

	puts("Enter the firstname");
	fgets(local_pers.firstname, 20, stdin);

	puts("Enter the lastname");
	fgets(local_pers.lastname, 20, stdin);

	puts("Enter the persnr");
	fgets(local_pers.persnr, 13, stdin);

	FILE* fileptr = fopen(filename, "a+");
	fwrite(&local_pers, sizeof(PERSON), 1, fileptr);
	fclose(fileptr);

	return local_pers;
}

void write_new_file(PERSON* person)	{
	FILE* fileptr = fopen(filename, "w+");
	fwrite(person, sizeof(PERSON), 1, fileptr);
	fclose(fileptr);
}

void append_file(PERSON* person)	{
	FILE* fileptr = fopen(filename, "a+");
	fwrite(person, sizeof(PERSON), 1, fileptr);
	fclose(fileptr);
}

void search_by_firstname(char* name)	{
	FILE* fileptr = fopen(filename, "r");
	PERSON* local_pers = malloc(sizeof(PERSON));
	puts("-------------Similar firstname found------------");
	while(fread(local_pers, sizeof(PERSON), 1, fileptr))	{
		if(strcmp(local_pers->firstname, name) == 0)	{
			puts("--------------");
			printf("Firstname: %sLastname: %sPersnr: %s\n",
					local_pers->firstname, local_pers->lastname,
					local_pers->persnr);
			puts("--------------");
		}
	}
	free(local_pers);
	fclose(fileptr);
}

void printfile()	{
	FILE* fileptr = fopen(filename, "r");
	PERSON* local_pers = malloc(sizeof(PERSON));
	while(fread(local_pers, sizeof(PERSON), 1, fileptr))	{
		puts("--------------");
		printf("Firstname: %sLastname: %sPersnr: %s",
				local_pers->firstname, local_pers->lastname,
				local_pers->persnr);
		puts("--------------");
	}
	free(local_pers);
	fclose(fileptr);
}

void print_options()	{
	puts("Enter numbers 1 - 5. Enter anything but 1-5 "
			"and the program will exit.\n");
	puts("1 Create a new file and delete the old.");
	puts("2 Add a new person to the file.");
	puts("3 Search for a person .");
	puts("4 Print out all in list.");
	puts("5 Exit the program.");

}



int main(){
	char option[10];
	char temp_name[20];
	PERSON local_pers;

	print_options();
	while(fgets(option, 10, stdin))	{
		switch (option[0]) {
		case '1' :
			local_pers = input_record();
			write_new_file(&local_pers);
			break;
		case '2':
			input_record();
			break;
		case '3':
			puts("Enter the name to search for");
			fgets(temp_name, 100, stdin);
			search_by_firstname(temp_name);
			break;
		case '4':
			printfile();
			break;
		case '5':
			exit(1);
			break;
		default:
			break;
		}
		print_options();

	}
	return 0;
}
