#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void create_new_file(FILE *fptr,char* filename);

bool IsfileEmpty(FILE *fptr,char* filename);

void openToedit(FILE *fptr,char *filename);

void openToAppend(FILE *fptr,char* filename);

void itoa(int n, char s[]);

void display(char *filename);

