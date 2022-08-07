#include "file_edit.h"

#define BUFFER_SIZE 1024

void create_new_file(FILE *fptr,char* filename)
{
	fptr = fopen(filename,"w");
	
	if(fptr==NULL)
	{
  		printf("Unable to open\n");
  		return;
	}
	fclose(fptr);
}


bool IsfileEmpty(FILE *fptr,char* filename)
{
		fptr = fopen(filename,"r");
		
		fseek(fptr,0,SEEK_END);
		int size = ftell(fptr);
		
		if(size == 0)
		{
			return true;
		}
		
		else{
			return false;
		}
	
	        fclose(fptr);
}


void openToedit(FILE *fh,char* filename)
{
	  char buffer[BUFFER_SIZE];
	  bool keep_going = true;
	  
	  fh = fopen(filename, "r+");

	  if (fh == NULL)
	  {
	    printf("Error opening file.\n");
	    
	  }
	  
	  while (keep_going)
	  {
	   
		    fgets(buffer, BUFFER_SIZE, stdin);
		    
		    if (strcmp(buffer, "quit\n") == 0)
		    {
		      keep_going = false;
		    }
		      
		    else 
		    {
		    	fputs(buffer, fh);
		    }	
	  }

	  fseek(fh,0,SEEK_END);
	  fclose(fh);

	
}


void openToAppend(FILE *fh,char* filename)
{
	  char buffer[BUFFER_SIZE];
	  bool keep_going = true;
	  
	  fh = fopen(filename, "a+");

	  if (fh == NULL)
	  {
	    printf("Error opening file.\n");
	    
	  }
	  printf("\nEnter file details and to stop enter 'quit':\n");
	  
	  while (keep_going)
	  {
	    // read a line of input into the buffer
		    fgets(buffer, BUFFER_SIZE, stdin);
		    
		    if (strcmp(buffer, "quit\n") == 0)
		    {
		      keep_going = false;
		    }
		      
		    else 
		    {
		    	fputs(buffer, fh);
		    }	
	  }
          fseek(fh,0,SEEK_END); 
	  fclose(fh);

	
}


void display(char *filename)
{
	FILE *fptr;
	
	char ch;
	fptr = fopen(filename,"r");
	
	do{
		ch = fgetc(fptr);
		printf("%c",ch);
	
	}while(ch != EOF);
	
	fclose(fptr);
	return;
}



void reverse(char s[]) {
    int i, j;
    char c;
    for(i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    return;
}


void itoa(int n, char s[]) {
    int i, sign;
    if((sign = n) < 0)  
        n = -n;         
    i = 0;
    do {       
        s[i++] = n % 10 + '0';   
    } while((n /= 10) > 0);   
    if(sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
    return;
}


