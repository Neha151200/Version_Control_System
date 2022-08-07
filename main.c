#include "file_storage.h"
#include "file_edit.h"
#include "file_diff.h"
#include "vcs.h"

int main(int argc, char *argv[]) 
{
	FILE fp,f1;
	char command[128],c[128];
	char args[100];
	char args1[100];
	
	do {
		printf("Enter the command or 'help' to view available commands\n>>>");
		scanf("%s", command);
		
		if(strcmp(command, "newrepo") == 0) {
		
		        filestorage f;
			init_file_storage(&f);
			
		        printf("Enter filename:\n");
			scanf("%s", args);
			
			newRepository(&f,&fp,args);
		}
		
		else if(strcmp(command, "changerepo") == 0) {
		
		        filestorage fs;
			init_file_storage(&fs);
		
			printf("Enter filename:\n");
			scanf("%s", args);
			changeRepository(&fs,&f1,args);
		}
		
		else if(strcmp(command, "filediff") == 0) {
			FILE f1,f2;
			
			printf("Enter filename:\n");
			scanf("%s", args);
			
			printf("Enter filename:\n");
			scanf("%s", args1);
			
			vcs(&f1,args,&f2,args1);
		}
		
		else if(strcmp(command, "displaycontent") == 0) {
		        printf("Enter filename:\n");
			scanf("%s", args);
			
			printf("------| Contents of %s |------\n",args);
			display(args);
		}
		
		else if(strcmp(command, "checksystem") == 0) {
			display("Mysql.txt");
		}
		
		else if(strcmp(command, "search") == 0) {
		        printf("Enter filename:\n");
			scanf("%s", args);
			printf("Enter content to search:\n");
			scanf("%s", c);
			Search(args,c);
		}
		
		else if(strcmp(command, "searchfile") == 0) {
		        printf("Enter file name to search:\n");
			scanf("%s", c);
			SearchFile(c);
		}
		
		else if(strcmp(command, "write") == 0) {
			FILE ft;
		        printf("Enter file name:\n");
			scanf("%s", args);
			openToedit(&ft,args);
		}
		
		else if(strcmp(command, "edit") == 0) {
		        FILE ft;
		        printf("Enter file name:\n");
			scanf("%s", args);
			openToAppend(&ft,args);
		}

		else if(strcmp(command, "help") == 0)
			printhelp();
			
		else if(strcmp(command, "exit") == 0)
			exit(1);
			
		else{
			printf("INVALID Command!!!\nEnter help to see command list.\n");
		}	
	} while(1);
	
	
	return 0;
}
