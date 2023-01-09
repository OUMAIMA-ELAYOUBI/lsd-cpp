#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

#define MAX 1000
#define BUFFER_SIZE 1
static char  stc[MAX];


void strjoin (char* s1, char* s)
{
	int n= strlen (s);
	int m=strlen (s1);
	for (int i=0;i<n;i++)
		s1[m+i]=s[i];
	return ;
}

int check_endl(char* s)
{
	int i=0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return 1;
		i++;
	}
	return 0;
}

void read_file(int fd )
{
	int k;
	char * buffer= (char*)malloc((BUFFER_SIZE+1) * sizeof(char));
	while(k=read(fd,buffer,BUFFER_SIZE) != 0)
	{
		if (k == -1)
		{
			free(buffer);
			exit(EXIT_FAILURE);
		}
		strjoin(stc,buffer);
    int i=0;
        while ( stc[i] !='\0')
	{
		//printf("%c", stc[i]);
		i++;
	}
   // printf("\n");
		if(check_endl(stc))
			break;
	}
	return ;
}

char* get_line ()
{
	int n=0;
	while (stc[n] != '\n' && stc [n] != '\0')
		n++;
	if (stc[n] == '\n')
		n++;
	char* line =(char*)malloc(sizeof(char) *(n+1));
	for(int i=0;i<n;i++)
	{
		line[i] = stc[i] ;
	}
	line [n]='\0';
	return line;
}

char* save_extra() 
{
	int n=0, m=1;
	while (stc[n] != '\0' )
		n++;
	while (stc[m] != '\n' )
		m++;
	int size= n-m +1 ;
	char* extra = (char*)malloc (sizeof(char) * size );
	for (int i=0; i<size-1 ; i++)
		extra[i]= stc[i+m+1];
	extra[size-1] = '\0';
	return extra;
}


char* get_next_line (int fd)
{
	
	// if fd or buffer_size non valid return null
	read_file (fd);
	if (stc == NULL)
		exit(EXIT_FAILURE);
	char* line = get_line(stc);
	char* extra= save_extra(stc);

	int i=0;
	while ( line[i] !='\0')
	{
		printf("%c", line[i]);
		i++;
	}
    
    memset(stc,0,strlen(stc));
   // strcpy(stc, extra);
	 int j=0;
	while( extra [j]!= '\0')
	{
		stc[j] = extra [j];
        j++;
	} 
    
	return line;
	
}

int main()
{ 
  int fd = open("test2.txt",O_RDONLY );
  while(fd)
   {
    char * s=get_next_line(fd);
    
   }
  

  
}

