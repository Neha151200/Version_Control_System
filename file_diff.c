#include "file_diff.h"

//functions to change colour of output on console
void red () 
{
  printf("\033[1;31m");
  return;
}

void green () 
{
  printf("\033[1;32m");
  return;
}

void purple() 
{
  printf("\033[0;35m");
  return;
}

void cyan() 
{
  printf("\033[0;36m");
  return;
}

void white () 
{
  printf("\033[0;37m");
  return;
}

void reset() 
{
  printf("\033[0m");
  return;
}


//comparing contains of files
void compareFiles(FILE *fp1,char *file1, FILE *fp2,char *file2)
{

	fp1 = fopen(file1, "r");
        fp2 = fopen(file2, "r");
  
        if (fp1 == NULL || fp2 == NULL)
        {
	       printf("Error : Files not open");
	       exit(0);
    	}
  
	    char ch1 = getc(fp1);
	    char ch2 = getc(fp2);
	  
	    int ch = 0, pos = 0, line = 1;
	    int p;
	  
	    while (ch1 != EOF && ch2 != EOF)
	    {
	    	//if(ch1 != ' ' || ch2 != ' ')
		pos++;
		if (ch1 == '\n' && ch2 == '\n')
		{
		    line++;
		    pos = 0;
		}
		
		if (ch1 != ch2)
		{
		    ch++;

		    if(ch1 == EOF || ch2 != EOF)
		    {
		    	p = 1;
		        cyan();
		    	printf("%c",ch2);
		    		
		    }
		    
		    else if(ch2 == EOF || ch1 != EOF)
		    {
		    	p = 2;
		    	cyan();
		    	printf("%c",ch2);
		    		
		    }
		}
		ch1 = getc(fp1);
		ch2 = getc(fp2);
	    }
	    
	    reset();
	    
	    if(p == 1)
	    {
	    	printf("Above is updated content in %s",file1);
	    }
	    
	    else if(p == 2)
	    {
	    	printf("Above is updated content in %s",file2);
	    }
	    
	    printf("\nTotal Changes Detected : %d", ch);
	    printf("\nTotal number of lines: %d\n", line);
    
       fclose(fp1);
       fclose(fp2);
}


int search_file(char *filename,char *search)
{
   FILE *fp;
   char word[50];
   char ch;
   
   int count = 0;
   int pos[10];
   int pointer = 0;
   int loop;

   
   fp = fopen(filename, "r");

   do 
   {
      ch = fscanf(fp, "%s", word); 
      if(strcmp(word, search) == 0)
        {
         pos[count] = pointer;     
         count++;
        }
      pointer++;
            
   } while (ch != EOF); 


    if(count == 0){  
        printf("\n'%s' not found in %s\n", search, filename);
        return 0;
    }    
    else
        {
		printf("\n'%s' FOUND!!!!!\n", search);
		
		if(strcmp(filename,"Mysql.txt") != 0)
		{
			for(loop = 0; loop<count; loop++)
			{
				printf("%d ", pos[loop]);
			}
			printf("positions.\n");
                }
                
                return 1;
        }
        
   fclose(fp);
   
   return 0;
}

