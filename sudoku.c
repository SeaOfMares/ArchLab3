#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

extern int trycell(int*, int);

void write_file(char*str, char* file_name);
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

void show(int *x)
{
    int i, j;
    for (i = 0; i < 9; i++) {
        if (!(i % 3)) putchar('\n');
        for (j = 0; j < 9; j++)
            printf(j % 3 ? "%2d" : "%3d", *x++);
        putchar('\n');
    }
}

void solve(const char *s)
{
    int i, x[81];
    for (i = 0; i < 81; i++)
        x[i] = s[i] >= '1' && s[i] <= '9' ? s[i] - '0' : 0;

    puts("Puzzle to solve\n");
    show(x);
    if (trycell(x, 0)) {
        puts("\nSolution:\n");
        show(x);
    }
    else
        puts("No solution\n");
}

int main(void)
{
    write_file("Hello World\n","test.txt");
    solve(    "5...7...."
        "6..195..."
        ".98....6."
        "8...6...3"
        "4..8.3..1"
        "7...2...6"
        ".6....28."
        "...419..5"
        "....8..79"    );

    return 0;
}
