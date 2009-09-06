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
    FILE *xsl,*xml;
	unsigned x,y;
	double contentLength;
	char *temp1;
	char *temp2;
	char edita[10240];
	char remove[10240];
	char originalString[10240];
	char processedString[10240];
	char hexa[3];
	const char *length;
	chainType *form, *aux, *first;
	
	
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
	aux = (chainType*)malloc(sizeof(chainType));
	first = (chainType*)malloc(sizeof(chainType));
	aux=first=NULL;
		
	for (temp2=strsep(&temp1,"&"); temp2!=NULL; temp2=strsep(&temp1,"&"))
	{
        	form = (chainType*)malloc(sizeof(chainType));
		form->option=strsep(&temp2,"=");
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
	xml = fopen(PATH_XML_PACIENTE_ADICIONADO,"r");
	if(xml == NULL)
	{
		printf("Content-type: text/html\n\n");
		printf("<html>\n");
		printf("<head>\n");
		printf("<title>N&atilde;o h&aacute; pacientes cadastrados.</title>\n");
		printf("</head>\n");
		printf("<body>\n");
		printf("N&atilde;o h&aacute; pacientes cadastrados.");
		printf("</body>\n");
		printf("</html>");
		exit(OK);
	}
	else
	{
	
		fclose(xml);
//		xsl = fopen(LOCAL_PATH_FILE_MORRYS_BUSCA_XSL, "r");
		xsl = fopen(PATH_XSL_BUSCA, "w");
		fprintf(xsl, "<?xml version=\"1.0\" encoding=\"iso-8859-1\"?>\n");
		fprintf(xsl, "<xsl:stylesheet version=\"1.0\" xmlns:xsl=\"http://www.w3.org/1999/XSL/Transform\">\n");
		fprintf(xsl, "<xsl:template match=\"/\">\r\n");
		fprintf(xsl, "<xsl:variable name=\"contador\">\r\n");
        fprintf(xsl, "0\r\n");
        fprintf(xsl, "<xsl:for-each select=\"doc/paciente\">\r\n");
        fprintf(xsl, "<xsl:if test=\"%s = '%s'\">\r\n",form->option,form->value);
        fprintf(xsl, "<xsl:number count=\"paciente\" />\r\n");
        fprintf(xsl, "</xsl:if>\r\n");
        fprintf(xsl, "</xsl:for-each>\r\n");
        fprintf(xsl, "</xsl:variable>\r\n");
		fprintf(xsl,"<html>\n");
		fprintf(xsl,"<head>\n");
		fprintf(xsl,"<title>.:. Pacientes Encontrados .:. Projeto Neural TB .:.</title>\n");
		fprintf(xsl,"</head>\n");
		fprintf(xsl,"<body>\n");
		fprintf(xsl,"<xsl:choose>\n");
        fprintf(xsl,"<xsl:when test=\"$contador != 0\">\n");
		fprintf(xsl, "<xsl:for-each select=\"doc/paciente[%s='%s']\">\n",form->option,form->value);
//editado
//		fprintf(xsl, "<xsl:choose>\n");
//		fprintf(xsl, "<xsl:when test=\"%s = '%s'\">\n",form->option,form->value);
//fim do editado
//removido o if test
//		fprintf(xsl, "<xsl:if test=\"%s = '%s'\">\n",form->option,form->value);
		fprintf(xsl, "<table border=\"2\" cellspacing=\"0\" width=\"50%%\">");	
		fprintf(xsl, "<tr>\n");
		fprintf(xsl, "  <td>editar</td>\n");
		fprintf(xsl, "  <td>remover</td>\n");
		fprintf(xsl, "	<td>Numero Paciente</td>\n");
		fprintf(xsl, "	<td>Endereço</td>\n");
		fprintf(xsl, "</tr>\n");
		fprintf(xsl, "<tr>\n");

		///strcat(edita,PATH_CGI_APOS_BUSCA_EDITA_PACIENTE);
		///strcat(edita,form->value);
		//strcat(edita,"&id=");
		///strcat(remove,PATH_CGI_APOS_BUSCA_REMOVE_PACIENTE);
		///strcat(remove,form->value);
		//strcat(remove,"&id=");
		/*para lembrar a primeira linha é a posicao 0
		*/
		
		fprintf(xsl, "<xsl:variable name=\"posicaoPacienteBusca\" select=\"(position()-1)\" />\n");
		
		//alterar !!!
		//fprintf(xsl,"<xsl:variable name=\"edita\" select=\"concat('%s',$posicaoPacienteBusca)\"/>\n",edita);
		fprintf(xsl,"<xsl:variable name=\"edita\" select=\"'%s'\"/>\n",edita);
		//fprintf(xsl,"<xsl:variable name=\"remove\" select=\"concat('%s',$posicaoPacienteBusca)\"/>\n",remove);
		fprintf(xsl,"<xsl:variable name=\"remove\" select=\"'%s'\"/>\n",remove);
		//fim !!
		//fprintf(xsl, "<td> <a href=\"{$edita}\">editar</a></td>\n");
		//fprintf(xsl, "<td> <a href=\"{$remove}\">remover</a></td>\n");
		fprintf(xsl, "<td> <a>editar</a></td>\n");
		fprintf(xsl, "<td> <a>remover</a></td>\n");
		fprintf(xsl, "<td> <xsl:value-of select=\"numeroPaciente\"/> </td>\n");
		fprintf(xsl, "<xsl:choose>\n");
		fprintf(xsl, "<xsl:when test=\"logradouro != ''\">\n");
		fprintf(xsl, "	<td> <xsl:value-of select=\"logradouro\"/> </td>\n");
		fprintf(xsl, "</xsl:when>\n");
		fprintf(xsl, "<xsl:otherwise>\n");
		fprintf(xsl, "	<td> não possui endereço</td>\n");
		fprintf(xsl, "</xsl:otherwise>\n");
		fprintf(xsl, "</xsl:choose>\n");
		fprintf(xsl, "</tr>\n");
//		fprintf(xsl, "</xsl:if>\n");
		fprintf(xsl, "</table>\n");
//		fprintf(xsl, "</xsl:when>\n");
//		fprintf(xsl, "<xsl:otherwise>\n");
//		fprintf(xsl, "Não possui paciente %s\n",form->value);
//		fprintf(xsl, "</xsl:otherwise>\n");
//		fprintf(xsl, "</xsl:choose>\n");
		fprintf(xsl, "</xsl:for-each>\n");
		fprintf(xsl, "</xsl:when>\n");
		fprintf(xsl, "<xsl:otherwise>\n");
		fprintf(xsl, "Não possui paciente %s\n",form->value);
        fprintf(xsl, "</xsl:otherwise>\n");
		fprintf(xsl, "</xsl:choose>\n");
//		fprintf(xsl, "</table>\n");
		fprintf(xsl,"</body>\n");
		fprintf(xsl,"</html>\n");
		fprintf(xsl, "</xsl:template>\n");
		fprintf(xsl, "</xsl:stylesheet>\n");
		fclose(xsl);
		
		printf("Content-type: text/html\n\n");
		printf("<html>\n");
		printf("<head>\n");
		printf("<title>Busca Concluida</title>\n");	
		printf("</head>\n");
		printf("<script type=\"text/javascript\">\n");

/*		
	/////////////////////// load xml ///////////////////////
	
		printf("var xml = new ActiveXObject(\"Microsoft.XMLDOM\");\n");
		printf("xml.async = false;\n");
		printf("xml.load(\"%s\");\n",PATH_XML_PACIENTE_ADICIONADO);
	
	/////////////////////// load xsl ///////////////////////
	
		printf("var xsl = new ActiveXObject(\"Microsoft.XMLDOM\");\n");
		printf("xsl.async = false;\n");
		printf("xsl.load(\"%s\");\n",PATH_XSL_BUSCA);
	
	/////////////////////// show xhtml ///////////////////////
	
		printf("document.write(xml.transformNode(xsl));\n");
		printf("</script>\n");
		printf("</body>\n");
		printf("</html>");
*/		
		printf("function loadXMLDoc(fname)\n");
		printf("{\n");
			printf("var xmlDoc;\n");
			// code for IE
			printf("if (window.ActiveXObject)\n");
			printf("{\n");
				printf("xmlDoc = new ActiveXObject(\"Microsoft.XMLDOM\");\n");
			printf("}\n");
				// code for Mozilla, Firefox, Opera, etc.
			printf("else if (document.implementation && document.implementation.createDocument)\n");
			printf("{\n");
				printf("xmlDoc = document.implementation.createDocument(\"\",\"\",null);\n");
			printf("}\n");
			printf("else\n");
			printf("{\n");
				printf("alert('O seu navegador n&atilde;o tem suporte a este script');\n");
			printf("}\n");
			printf("xmlDoc.async = false;\n");
			printf("xmlDoc.load(fname);\n");
			printf("return(xmlDoc);\n");
		printf("}\n");
		printf("function displayResult()\n");
		printf("{\n");
			printf("xml = loadXMLDoc(\"%s\");\n",PATH_XML_PACIENTE_ADICIONADO);
			printf("xsl = loadXMLDoc(\"%s\");\n",PATH_XSL_BUSCA);
			printf("\n");
			// code for IE
			printf("if (window.ActiveXObject)\n");
			printf("{\n");
				printf("x = xml.transformNode(xsl);\n");
				printf("document.getElementById(\"result\").innerHTML = x;\n");
			printf("}\n");
			// code for Mozilla, Firefox, Opera, etc.
			printf("else if (document.implementation && document.implementation.createDocument)\n");
			printf("{\n");
			printf("	xsltProcessor = new XSLTProcessor();\n");
			printf("	xsltProcessor.importStylesheet(xsl);\n");
			printf("	resultDocument = xsltProcessor.transformToFragment(xml,document);\n");
			printf("	document.getElementById(\"result\").appendChild(resultDocument);\n");
			printf("}\n");
		printf("}\n");
		printf("</script>\n");
		printf("</head>\n");
		printf("<body bgcolor=\"white\" id=\"result\" onLoad=\"displayResult()\">\n");
		printf("</body>\n");
		printf("</html>");
	}
	for (aux=form=first; aux!=NULL; form=aux)
	{	
		aux = form->next;
		free (form);
	}
	return(OK);
}
