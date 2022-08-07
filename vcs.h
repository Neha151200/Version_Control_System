#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void printhelp();

void newRepository(filestorage *s,FILE *fp, char *filename);

void changeRepository(filestorage *s,FILE *fp, char *filename);

void vcs(FILE *fp1,char *file1, FILE *fp2,char *file2);

void Search(char *filename,char *search); 

void SearchFile(char *search);	


