#include "file_storage.h"
#include "file_edit.h"

void init_file_storage(filestorage *fs)
{
	fs->file_st_node = (Node *)malloc(sizeof(Node));
	fs->file_st_node = NULL;
	fs->numberoffiles = 0;
	fs->head = NULL;
	return;
}


Node *create_new_node(char *filename)   
{
	Node *newfile = (Node *)malloc(sizeof(Node));
	newfile->previous = NULL;
	newfile->next = NULL;
	newfile->ver = 0;
	strcpy(newfile->filename,filename);
	
	return newfile;
}




void newfile(filestorage *f,node *n,char *filename)  
{
       
        if(f->file_st_node == NULL)
        {
		n = create_new_node(filename);
	       	f->file_st_node = n;
	       	f -> file_st_node -> next = NULL;
		//f -> head = ;
	       	f->numberoffiles += 1;
       		        
        }    
       return;   	
}



void edit(filestorage *f,FILE *fp,char *filen)
{
	       node n2,n;
	       newfile(f,&n,filen);
	       FILE *f1;
	       FILE *f2;
	       FILE *f3;
	       char file[100],version[5];
	       int i1=0;
       	       f2 = fopen("Mysql.txt","a+");
       	       f3 = fopen("FIND.txt","a+");
       	       	
	       if(f->file_st_node != NULL && strcmp(f->file_st_node->filename,filen) == 0)
	       {    
				       	           
	       	                               if(f->file_st_node->ver == 0)
					       {      
					
						       while(filen[i1] != '.') {
								file[i1] = filen[i1];
								i1 += 1;
						       }
						        file[i1] = '\0';
							
							strcat(file, "_v");
							f->file_st_node->ver += 1;
							itoa(f->file_st_node->ver, version);
		    					strcat(file,version);
		    					
		    					strcat(file, ".txt");
							newfile(f,&n2,file);
							f->file_st_node->next = n2;
							strcpy(f->file_st_node->filename,file);
							
							printf("|%s\n",filen);
							printf("--|%s\n",file);
							
							fprintf(f2,"|%s\n",filen); 
				       	       		fseek(f2,0,SEEK_END);
							
							fprintf(f2,"--|%s\n",file); 
				       	       		fseek(f2,0,SEEK_END);
				       	       		
				       	       		fprintf(f3,"%s\n",filen); 
				       	       		fseek(f3,0,SEEK_END);
							
							fprintf(f3,"%s\n",file); 
				       	       		fseek(f3,0,SEEK_END);
				       	       		
							edit(f,fp,filen);
					       }
					       
					       else if(f->file_st_node->ver >= 1)
					       {
						       	while(filen[i1] != '_') {
								file[i1] = filen[i1];
								i1 += 1;
							}
							
							file[i1] = '\0';
							
							strcat(file, "_v");
							f->file_st_node->ver += 1;
							itoa(f->file_st_node->ver, version);
		    					strcat(file,version);
		    					
		    					strcat(file, ".txt");
							newfile(f,&n2,file);
							f->file_st_node->next = n2;
							strcpy(f->file_st_node->filename,file);
							
							printf("--|%s\n",file);
							
							fprintf(f2,"--|%s\n",file); 
				       	       		fseek(f2,0,SEEK_END);
				       	       		
				       	       		fprintf(f3,"%s\n",file); 
				       	       		fseek(f3,0,SEEK_END);
							
							edit(f,fp,filen); 
						} 
						
		  }        
                  return;
}

