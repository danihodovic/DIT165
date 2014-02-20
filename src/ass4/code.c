/* ==================================== 
File name: code.c
Date: Feb 17, 2014 
Group Number: 13
Members that contributed: 
Dani Hodovic
Sinan Alazzawi
Yazen Raad
Demonstration code: [<Ass code 1‐4> <55766>]
====================================== */ 


int main(int argc, char **argv) {
	if(argc != 6)	{
		puts("Wrong input");
		return 6;
	}
    char engine_on = atoi(argv[1]);
    char gear_pos = atoi(argv[2]);
    char key_pos = atoi(argv[3]);
    char brake1 = atoi(argv[4]);
    char brake2 = atoi(argv[5]);

    unsigned char byte = 0;

    byte = engine_on << 7 | gear_pos << 4 |
    key_pos << 2 | brake1 << 1 | brake2 << 0;

    printf("%x\n", byte);
	return 0;
}


