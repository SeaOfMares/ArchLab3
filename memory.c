#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_32bit 4294967295; // 32 bits of all 1s

// Write 32-bit int into mem file
void write_file(char* str, char* file_name){
	FILE* mem_file;
	FILE* temp_file;
 	// open file with relative address
	mem_file = fopen(file_name, "r");
	temp_file = fopen("replace.tmp", "w");

	/* fopen() return NULL if unable to open file in given mode. */
   	 if (mem_file == NULL || temp_file == NULL){
		/* Unable to open file hence exit */
		printf("\nUnable to open file.\n");
		printf("Please check whether file exists and you have read/write privilege.\n");
		return -1;
    	}

	fputs(str,temp_file);
    	// release resources back to OS
    	fclose(mem_file);
    	fclose(temp_file);

	rename("replace.tmp", file_name);

}
