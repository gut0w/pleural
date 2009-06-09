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
	
	FILE *xsl;
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

	xsl = fopen(LOCAL_PATH_FILE_DOENTES_NOVOS_VER_PACIENTE_XSL, "w");
	
	fprintf(xsl,"<?xml version=\"1.0\" encoding=\"utf-8\"?>\r\n");
	fprintf(xsl,"\r\n");
	fprintf(xsl,"<xsl:stylesheet xmlns:xsl=\"http://www.w3.org/1999/XSL/Transform\" version=\"1.0\"\r\n");
	fprintf(xsl,"				xmlns:fo=\"http://www.w3.org/1999/XSL/Format\"\r\n");
	fprintf(xsl,"				xmlns=\"http://www.w3.org/1999/xhtml\">\r\n");
	fprintf(xsl,"\r\n");
	fprintf(xsl,"<xsl:include href=\"pacienteDados.xsl\" />\r\n");
	fprintf(xsl,"<xsl:template match=\"/doc\">\r\n");
	fprintf(xsl,"\r\n");
	fprintf(xsl,"	<xsl:for-each select=\"paciente[numeroPaciente='%s']\">\r\n",paciente);
	fprintf(xsl,"			<p align=\"right\"> <a target=\"blank\" href=\"imprimir.cgi?pid=%s\">Versão para Impressão</a></p>\r\n", paciente);
//	fprintf(xsl,"	<xsl:for-each select=\"doc/paciente\">\r\n");
//	fprintf(xsl,"	<xsl:sort select=\"descendant::nomeCompleto\" />\r\n");
//	fprintf(xsl,"		<xsl:if test=\"numeroPaciente = '%s'\">\r\n", paciente);

	fprintf(xsl,"			<center>\r\n");
	fprintf(xsl,"			<table>\r\n");
	fprintf(xsl,"			<tr>\r\n");
	fprintf(xsl,"				<th colspan=\"2\">.:.Projeto Neural TB .:.</th>\r\n");
	fprintf(xsl,"			</tr>\r\n");
	fprintf(xsl,"			<xsl:apply-templates select=\".\" />\r\n");
//	fprintf(xsl,"			<xsl:apply-templates select=\"doc/paciente[numeroPaciente='%s']\">\r\n",paciente);
	fprintf(xsl,"			</table>\r\n");
	fprintf(xsl,"			</center>\r\n");
//	fprintf(xsl,"		</xsl:if>\r\n");
	fprintf(xsl,"	</xsl:for-each>\r\n");
	fprintf(xsl,"	\r\n");
	fprintf(xsl,"</xsl:template>\r\n");
	fprintf(xsl,"\r\n");
	fprintf(xsl,"</xsl:stylesheet>\r\n");
	fclose(xsl);

	printf("Content-type: text/html\n\n");
	printf("<html>\n");
	printf("<head>\n");
	printf("<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"/>\n");
	printf("<title>Paciente %s</title>\n",paciente);
	printf("<link rel=\"stylesheet\" type=\"text/css\" href=\"../css/verPaciente.css\" />\n"); 
	printf("<script type=\"text/javascript\" charset=\"utf-8\">\n");
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
		printf("xml = loadXMLDoc(\"%s\");\n",WEB_PATH_DOENTES_NOVOS_PACIENTE_ADICIONADO_XML);
		printf("xsl = loadXMLDoc(\"%s\");\n",WEB_PATH_DOENTES_NOVOS_VER_PACIENTE_XSL);
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
	exit(OK);
}
