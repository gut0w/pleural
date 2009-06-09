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
	char *attribute;
	char *value;
	struct chain *next;
} chainType;

void errorMsgCgi(char *title, char*msg)
{
    printf("Content-type: text/html\n\n");
	printf("<html>\n");
	printf("<head>\n");
	printf("<title>%s</title>\n",title);
	printf("</head>\n");
	printf("<body>\n");
	printf("%s",msg);
	printf("</body>\n");
	printf("</html>\n");
}


int main (void)
{
	FILE *xml,*xml_temp;
    	unsigned x,y;
	double contentLength;
	char* temp1;
	char* temp2;
	char temp[1024];
	char originalString[10240];
	char processedString[10240];
	char hexa[3];
	const char *length;
	chainType *form, *aux, *first;

    	if(!(length= getenv("CONTENT_LENGTH"))) //verifica se string lida é null
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

	
	/* pega a stringprecessada e separa os campos **
	** &atributo=valor"\0" */

	temp1 = (char*)&processedString;
	aux = (chainType*)malloc(sizeof(chainType));
	first = (chainType*)malloc(sizeof(chainType));
	aux=first=NULL;

	for (temp2=strsep(&temp1,"&"); temp2!=NULL; temp2=strsep(&temp1,"&"))
	{
        	form = (chainType*)malloc(sizeof(chainType));
		form->attribute=strsep(&temp2,"=");
		form->value=strsep(&temp2,"\0");
		if (aux == NULL)
		{
			first = form;
		}
		else
		{
			aux->next = form;
		}

		aux = form;
	}
	form->next = NULL;
	if(!form)
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

///////////////////////ve se existe arquivo pacientes.xml///////////////////////

	if ((xml=fopen(LOCAL_PATH_FILE_DOENTES_NOVOS_PACIENTE_ADICIONADO_XML, "r")) == NULL)
	{
		xml = fopen(LOCAL_PATH_FILE_DOENTES_NOVOS_PACIENTE_ADICIONADO_XML, "w");
		fprintf(xml, "<?xml version=\"1.0\" encoding=\"iso-8859-1\"?>\n");		
		fprintf(xml, "<doc>\n");
		fprintf(xml, "    <paciente>\n");
		for (aux=first; aux!=NULL; aux=aux->next)
		{
			fprintf(xml, "      <%s>%s</%s>\n",aux->attribute,aux->value,aux->attribute);
		}
    		fprintf(xml, "    </paciente>\n");
		fprintf(xml, "</doc>");
		fclose(xml);
	}
	else
	{
		xml_temp = fopen(LOCAL_PATH_FILE_DOENTES_NOVOS_PACIENTE_ADICIONADO_TEMP_XML, "w");
		fgets(temp, 1024, xml);
		while(strcmp(temp, "</doc>") != 0 && strcmp(temp, "</doc>\n") != 0)
		{
			fputs(temp, xml_temp);
			fgets(temp, 1024, xml);	
		}
		fprintf(xml_temp,"    <paciente>\n");
		for (aux=first; aux!=NULL; aux=aux->next)
		{
			fprintf(xml_temp, "      <%s>%s</%s>\n",aux->attribute,aux->value,aux->attribute);
		}
	    	fprintf(xml_temp, "    </paciente>\n");
		fprintf(xml_temp, "</doc>");
		fclose(xml);
		fclose(xml_temp);
		remove(LOCAL_PATH_FILE_DOENTES_NOVOS_PACIENTE_ADICIONADO_XML);
		rename(LOCAL_PATH_FILE_DOENTES_NOVOS_PACIENTE_ADICIONADO_TEMP_XML,LOCAL_PATH_FILE_DOENTES_NOVOS_PACIENTE_ADICIONADO_XML);
	}
	printf("Content-type: text/html\n\n");
    	printf("<html>\n");
	printf("<head>\n");
	printf("<title>Formulário adicionado</title>\n");	
	printf("</head>\n");
	printf("<body bgcolor=\"white\">\n");
	printf("<div align=center>Paciente inserido!</div><br><br>\n");
    printf("<script type=\"text/javascript\">\n");
	printf("var xml=null\n");
	printf("var xsl=null\n");
	printf("if (window.ActiveXObject)\n");
	printf("{\n");

/////////////////////// load xml ///////////////////////

	printf("xml = new ActiveXObject(\"Microsoft.XMLDOM\");\n");
	printf("xml.async = false;\n");
    printf("xml.load(\"%s\");\n",WEB_PATH_DOENTES_NOVOS_PACIENTE_ADICIONADO_XML);

/////////////////////// load xsl ///////////////////////

	printf("xsl = new ActiveXObject(\"Microsoft.XMLDOM\");\n");
	printf("xsl.async = false;\n");
	printf("xsl.load(\"%s\");\n",WEB_PATH_FILE_DOENTES_NOVOS_PACIENTE_ADICIONADO_XSL);

/////////////////////// show xhtml ///////////////////////

    printf("document.write(xml.transformNode(xsl));\n");
	printf("}\n");
	printf("else if (document.implementation.createDocument)\n");
	printf("{\n");

/////////////////////// load xml ///////////////////////

	printf("xml = document.implementation.createDocument(\"\",\"\",null);\n");
	printf("xml.async = false;\n");
    printf("xml.load(\"%s\");\n",WEB_PATH_DOENTES_NOVOS_PACIENTE_ADICIONADO_XML);

/////////////////////// load xsl ///////////////////////

	printf("xsl = document.implementation.createDocument(\"\",\"\",null);\n");
	printf("xsl.async = false;\n");
    printf("xsl.load(\"%s\");\n",WEB_PATH_FILE_DOENTES_NOVOS_PACIENTE_ADICIONADO_XSL);
	printf("}\n");
	printf("else\n");
	printf("{\n");
	printf("alert(\'Your browser cannot handle this script\');\n");
	printf("}\n");
	
	printf("</script>\n");
    printf("</body>\n");
	printf("</html>");



	for (aux=form=first; aux!=NULL; form=aux)
	{
		aux = form->next;
		free (form);
	}
	exit(OK);

}
