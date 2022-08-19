#include "file_storage.h"
#include "file_edit.h"
#include "file_diff.h"
#include "vcs.h"

void printhelp()
{  
	printf("------| Commands for Version Control System |------\n");
	printf("newrepo:		creates new file system\n");
	printf("changerepo:		changes current file system\n");
	printf("displaycontent:		diplays contents of file\n");
	printf("checksystem:		displays file system created\n");
	printf("filediff:		To find out difference between two files\n");
	printf("search:			To find out word in file\n");
	printf("searchfile:		To find out if the file exists or not\n");
	printf("edit:			Append the file\n");
	printf("write:			overwrite the file\n");
	printf("help:			Displays commands\n");
	printf("exit:			Exits program\n");
	
	return;
}


void newRepository(filestorage *s,FILE *fp, char *filename)
{	
	FILE *f1;
	
	create_new_file(fp,filename);
	edit(s,fp,filename);
	
	char File[100];
	
	do {
		scanf("%s",File);
	
		if(strcmp(File, "stop") == 0)
			break;
		
		else{
			create_new_file(f1,File);
			edit(s,f1,File);
		}	
	} while(1);
       
	return;

}


void changeRepository(filestorage *s,FILE *fp, char *filename)
{
	
	FILE *f1;
	
	create_new_file(fp,filename);
	edit(s,fp,filename);
	
	char File[100];

	do {
		scanf("%s",File);
	
		if(strcmp(File, "stop") == 0)
			break;
		
		else{
			create_new_file(f1,File);
			
			edit(s,f1,File);
		}	
	} while(1);
        
	return;

}


void vcs(FILE *fp1,char *file1, FILE *fp2,char *file2)
{
	if(IsfileEmpty(fp1,file1) && IsfileEmpty(fp2,file2))
	{
		printf("Both files are empty\n");
	}
	
	else{
		printf("Comparing two files:\n \n");
		
	   	compareFiles(fp1,file1,fp2,file2);
	}   	
   	
   	return;
   
}  


void Search(char *filename,char *search) 	
{
        search_file(filename,search);

	return;
}   

void SearchFile(char *search) 	
{
        search_file("FIND.txt",search);

	return;
}   
