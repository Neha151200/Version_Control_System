#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct Node{
      struct Node *next, *previous;
      int ver;
      char filename[100];
      
}Node;

typedef Node* node;

typedef struct filestorage{
	Node *file_st_node;
	struct filestorage *head;
	char filename[100];
	int numberoffiles; 	
}filestorage;


void init_file_storage(filestorage *fs);

void newfile(filestorage *f,node *n,char *filename);

void edit(filestorage *f,FILE *fp, char *filename);

