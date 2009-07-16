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
		
	if ((xml=fopen(PATH_XML_PACIENTE_ADICIONADO, "r")) == NULL)
	{
		printf("Content-type: text/html\n\n");
		printf("<html>\n");
		printf("<head>\n");
		printf("<title>Sem Pacientes Removidos</title>\n");
		printf("</head>\n");
		printf("<body>\n");
		printf("Sem Pacientes Removidos\n");
		printf("</body>\n");
		printf("</html>");
	}
	else
	{
        	fclose(xml);
			printf("Content-type: text/html\n\n");
    printf("<html>\n");
	printf("<head>\n");
	printf("<title>Pacientes removidos</title>\n");	
    printf("<script type=\"text/javascript\">\n");
/*	

	printf("var xml=null\n");
	printf("var xsl=null\n");
	printf("if (window.ActiveXObject)\n");
	printf("{\n");

/////////////////////// load xml ///////////////////////

	printf("xml = new ActiveXObject(\"Microsoft.XMLDOM\");\n");
	printf("xml.async = false;\n");
    printf("xml.load(\"%s\");\n",WEB_PATH_MORRYS_PACIENTE_ADICIONADO_XML);

/////////////////////// load xsl ///////////////////////

	printf("xsl = new ActiveXObject(\"Microsoft.XMLDOM\");\n");
	printf("xsl.async = false;\n");
	printf("xsl.load(\"/~pleural/dev/xml/test.xsl\");\n");

/////////////////////// show xhtml ///////////////////////

    printf("document.write(xml.transformNode(xsl));\n");
	printf("}\n");
	printf("else if (document.implementation.createDocument)\n");
	printf("{\n");

/////////////////////// load xml ///////////////////////

	printf("xml = document.implementation.createDocument(\"\",\"\",null);\n");
	printf("xml.async = false;\n");
    printf("xml.load(\"%s\");\n",LOCAL_PATH_FILE_MORRYS_PACIENTE_ADICIONADO_XML);

/////////////////////// load xsl ///////////////////////

	printf("xsl = document.implementation.createDocument(\"\",\"\",null);\n");
	printf("xsl.async = false;\n");
    printf("xsl.load(\"~/public_html/dev/xsl/test.xsl\");\n");
    printf("document.write(xml.transformNode(xsl));\n");
	printf("}\n");
	printf("else\n");
	printf("{\n");
	printf("alert(\'erro javascript( Browser nao roda js )\');\n");
	printf("}\n");
	
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
			printf("xml = loadXMLDoc(\"%s\");\n",PATH_XML_PACIENTES_REMOVIDOS);
			printf("xsl = loadXMLDoc(\"%s\");\n",PATH_XSL_LISTA_PACIENTES_REMOVIDOS);
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
	exit (OK);
}
