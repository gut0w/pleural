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


typedef struct chain
{
	char *option;
	char *value;
	struct chain *next;
} chainType;

int main (void)
{
	

	char *queryString;
	char *paciente;

	if(!(queryString = getenv("QUERY_STRING")))
	{

		printf("Content-type: text/html\n\n");
		printf("<html>\n");
		printf("<head>\n");
		printf("<title>Resultado1</title>\n");
		printf("</head>\n");
		printf("<body>\n");
		printf("erro ao repassar os argumentos");
		printf("</body>\n");
		printf("</html>\n");
		exit(OK);
	}

	paciente=(char*)malloc(sizeof(char));
	
	if(!paciente)
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
	if(strcmp("paciente",strsep(&queryString,"=")))
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

	paciente = strsep(&queryString,"\0");

	printf("Content-type: text/html\n\n");
	printf("<html>\n");
	printf("<head>\n");
	printf("<title>Motivo</title>\n");
	printf("<script language=\"javascript\" src=\"../habilitaCampos.js\" charset=\"UTF-8\"></script>\n");
	printf("</head>\n");
	printf("<body>\n");
	printf("<form name = \"motivoRemove\" method = \"post\" action = \"%s\" onSubmit=\"return sendFieldMotivo(motivo)\">\n",WEB_PATH_FILE_DOENTES_NOVOS_REMOVE_PACIENTE_CGI);
	printf("<table align = \"center\">\n");
	printf("<tr>\n");
	printf("<td align=\"center\">Para continuar digite o motivo do apagamento do paciente <b>%s</b></td>\n",paciente);
	printf("<input type = \"hidden\" name=\"paciente\" value = \"%s\">\n",paciente);
	printf("</tr>\n");
	printf("<tr>\n");
	printf("<td align = \"left\">motivo:</td>\n");
	printf("<td> <TEXTAREA COLS=50 ROWS=6 name = \"motivo\" MAXLENGTH=500 onFocus=\"this.className = 'CSS_FOCUS_IN'\" onblur=\"validarCampoMotivo(this);  this.className = 'CSS_FOCUS_OUT';\"></TEXTAREA></td>\n");
	printf("</tr>\n");
	printf("<tr>\n");
	printf("<td><a href = \"%s\">Voltar</a></td>\n",WEB_PATH_DOENTES_NOVOS_INICIO);
	printf("<td><input type = \"submit\" value = \"remover\"</td>\n");
	printf("</tr>\n");
	printf("</table>\n");
	printf("</form>\n");
	printf("</body>\n");
	printf("</html>\n");
	exit(OK);
}
