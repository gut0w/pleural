#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <math.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "config.h"

#define OK 0

typedef struct users
{
	char *login;
	char *password1;
	char *password2;
	char *project;
	struct users *next;
}usersType;

int main (void)
{
//FILE *xml;
	unsigned x,y;
	double contentLength;
	char* temp1;
	char* temp2;
	char originalString[10240];
	char processedString[10240];
	char hexa[3];
	const char *length;
	usersType *user;
	
	if(!(length= getenv("CONTENT_LENGTH"))) 
	{

		printf("Content-type: text/html\n\n");
		printf("<html>\n");
		printf("<head>\n");
		printf("<title>Resultado</title>\n");
		printf("</head>\n");
		printf("<body>\n");
		printf("erro ao repassar os argumentos");
		printf("</body>\n");
		printf("</html>\n");
		exit(OK);
	}
	
	//converte string com o tamanho em long int
	contentLength=strtol(length, NULL, 10);
    //le linha das informacoes 1 vez com o tamanho de contentLength do stdin
    //e armazena em originalString
    	fread(originalString, contentLength, 1, stdin);
	    
    //le char por char da url substituindo os carac especiais
	for (x = 0, y = 0; x < strlen(originalString); x++, y++)
	{
		switch (originalString[x])
		{
            /* Convert all + chars to space chars */
			case '+':
				processedString[y] = ' ';
				break;

			/* Convert all %xy hex codes into ASCII chars */
	 	    case '%':
				/* Copy the two bytes following the % */
				strncpy(hexa, &originalString[x + 1], 2);
				/* Skip over the hex */
				x = x + 2;
				/* Convert the hex to ASCII */
				/* Prevent user from altering URL delimiter sequence */
				if( ((strcmp(hexa,"26")==0)) || ((strcmp(hexa,"3D")==0)) )
				{
					processedString[y]='%';
					y++;
					strcpy(processedString,hexa);
					y+=2;
					break;
				}
				processedString[y] = (char)strtol(hexa, NULL, 16);
				break;

			/* Make an exact copy of anything else */
			 default:
				processedString[y] = originalString[x];
				break;
		}
	}

	temp1 = (char*)&processedString;
	/*printf("Content-type: text/html\n\n");
		printf("<html>\n");
		printf("<head>\n");
		printf("<title>Resultado</title>\n");
		printf("</head>\n");
		printf("<body>\n");
		printf("%s\n",temp1);
		printf("</body>\n");
		printf("</html>\n");
		exit(OK);
		*/
	user = (usersType*)malloc(sizeof(usersType));
	for (temp2=strsep(&temp1,"&"); temp2!=NULL; temp2=strsep(&temp1,"&"))
	{
        if (!user->login)
		{
			if (!strcmp("login",strsep(&temp2,"=")))
				user->login=strsep(&temp2,"\0");
			else
			{
				user->login=strsep(&temp2,"\0");
				printf("Content-type: text/html\n\n");
				printf("<html>\n");
				printf("<head>\n");
				printf("<title>Resultado</title>\n");
				printf("</head>\n");
				printf("<body>\n");
				printf("erro ao repassar os argumentos aqui1");
				printf("%s\n",user->login);
				printf("</body>\n");
				printf("</html>\n");
				exit(OK);
			}
		}
		else
		{
			if (!user->password1)
			{
				if (!strcmp("password",strsep(&temp2,"=")))
					user->password1=strsep(&temp2,"\0");
				else
				{
					printf("Content-type: text/html\n\n");
					printf("<html>\n");
					printf("<head>\n");
					printf("<title>Resultado</title>\n");
					printf("</head>\n");
					printf("<body>\n");
					printf("erro ao repassar os argumentos aqui2");
					printf("</body>\n");
					printf("</html>\n");
					exit(OK);
				}
			}
			else
			{
				if  (!user->project)
				{
					if ( !strcmp("projeto",strsep(&temp2,"=")))
						user->project=strsep(&temp2,"\0");
					else
					{	
						printf("Content-type: text/html\n\n");
						printf("<html>\n");
						printf("<head>\n");
						printf("<title>Resultado</title>\n");
						printf("</head>\n");
						printf("<body>\n");
						printf("erro ao repassar os argumentos");
						printf("</body>\n");
						printf("</html>\n");
						exit(OK);
					}
				}
				else
				{	
						printf("Content-type: text/html\n\n");
						printf("<html>\n");
						printf("<head>\n");
						printf("<title>Resultado</title>\n");
						printf("</head>\n");
						printf("<body>\n");
						printf("erro ao repassar os argumentos");
						printf("</body>\n");
						printf("</html>\n");
						exit(OK);
				}
			}
		}
	}
	user->next = NULL;
	if(!user)
	{
		printf("Content-type: text/html\n\n");
		printf("<html>\n");
		printf("<head>\n");
		printf("<title>Resultado</title>\n");
		printf("</head>\n");
		printf("<body>\n");
		printf("erro");
		printf("</body>\n");
		printf("</html>");
		exit(OK);
	}
	if((!strcmp(user->login,"medico"))&&(!strcmp(user->password1,"1qaz")))
	{
		printf("Content-type: text/html\n\n");
		printf("<html>\n");
		printf("<head>\n");
		if(!strcmp(user->project,"Morrys"))
			printf("<META HTTP-EQUIV=\"Refresh\" CONTENT=\"0 ; URL=%s\">\n ",WEB_PATH_FILE_MORRYS_INDEX_SISTEMA_2);
		else
			printf("<META HTTP-EQUIV=\"Refresh\" CONTENT=\"0 ; URL=%s\">\n ",WEB_PATH_FILE_DOENTES_NOVOS_INDEX_SISTEMA_2);
		printf("<title>Resultado</title>\n");
		printf("</head>\n");
		printf("<body>\n");
		printf("login.... OK<BR>\n");
		printf("redirecionando...\n");
		//printf("%s\n %s\n %s\n",user->login,user->password1,user->project);
		printf("</body>\n");
		printf("</html>");		
	}
	else
	{
		printf("Content-type: text/html\n\n");
		printf("<html>\n");
		printf("<head>\n");		
		printf("<title>Resultado</title>\n");
		printf("</head>\n");
		printf("<body>\n");
		printf("LOGIN OU SENHA INVÁLIDOS\n");
		printf("</body>\n");
		printf("</html>");
		exit(OK);
	}
	exit(OK);
}
