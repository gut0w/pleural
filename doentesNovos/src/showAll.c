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
/* falta o test.xsl */
int main ()
{
FILE *xml;

	//if ((xml=fopen(LOCAL_PATH_FILE_DOENTES_NOVOS_PACIENTE_ADICIONADO_XML, "r")) == NULL)
	if ((xml=fopen("../xml/pacienteAdicionado.xml", "r")) == NULL)
	{
		printf("Content-type: text/html\n\n");
		printf("<html>\n");
		printf("<head>\n");
		printf("<title>Sem Pacientes Cadastrados</title>\n");
		printf("</head>\n");
		printf("<body>\n");
		printf("Sem Pacientes Cadastrados\n");
		printf("</body>\n");
		printf("</html>");
	}
	else

	{
        	fclose(xml);
			printf("Content-type: text/html\n\n");
    printf("<html>\n");
	printf("<head>\n");
	printf("<title>Pacientes adicionados</title>\n");	
	printf("</head>\n");
	printf("<body bgcolor=\"white\">\n");	
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
	printf("xsl.load(\"../xml/test.xsl\");\n");

/////////////////////// show xhtml ///////////////////////
	//printf("xsltProcessor=new XSLTProcessor();\n");
	//printf("xsltProcessor.importStylesheet(xsl);\n");
	//printf("resultDocument = xsltProcessor.transformToFragment(xml,document);\n");
	//printf("document.getElementById(id).appendChild(resultDocument);\n");

    printf("document.write(xml.transformNode(xsl));\n");
	printf("}\n");
	printf("else if (document.implementation.createDocument)\n");
	printf("{\n");

/////////////////////// load xml ///////////////////////

	printf("xml = document.implementation.createDocument(\"\",\"\",null);\n");
	printf("xml.async = false;\n");
    printf("xml.load(\"%s\");\n",LOCAL_PATH_FILE_DOENTES_NOVOS_PACIENTE_ADICIONADO_XML);

/////////////////////// load xsl ///////////////////////

	printf("xsl = document.implementation.createDocument(\"\",\"\",null);\n");
	printf("xsl.async = false;\n");
    printf("xsl.load(\"../xml/test.xsl\");\n");
    printf("document.write(xml.transformNode(xsl));\n");
	printf("}\n");
	printf("else\n");
	printf("{\n");
	printf("alert(\'erro javascript( Browser nao roda js )\');\n");
	printf("}\n");
	
	printf("</script>\n");
    printf("</body>\n");
	printf("</html>");
	}
	exit (OK);
}
