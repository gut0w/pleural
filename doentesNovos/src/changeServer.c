#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/* DEFINE DO MORRYS */
#define PATH_FILE_MORRYS_CONFIG_H "/users/balabram/public_html/desenvolvimento/src/config.h"
#define PATH_FILE_MORRYS_CONFIG_TEMP_H "/users/balabram/public_html/desenvolvimento/src/temp.h"

#define WEB_SERVER_MORRYS "http://www04.lps.ufrj.br/~balabram/desenvolvimento"
#define LOCAL_PATH_MORRYS "/users/balabram/public_html/desenvolvimento"

#define WEB_STORAGE_MORRYS "http://www04.lps.ufrj.br/~balabram/desenvolvimento"
#define STORAGE_PATH_MORRYS "/users/balabram/public_html/desenvolvimento"

/*#define PATH_FILE_MORRYS_PACIENTE_ADICIONADO_XML "/xml/pacienteAdicionado.xml"
#define PATH_FILE_MORRYS_PACIENTE_ADICIONADO_TEMP_XML "/xml/pacienteAdicionadoTemp.xml"
#define PATH_FILE_MORRYS_PACIENTE_REMOVIDO_XML "/xml/removed.xml"
#define PATH_FILE_MORRYS_PACIENTE_HISTORICO_XML "/xml/historic.xml"
#define PATH_FILE_MORRYS_BACKUP_PACIENTE_ADICIONADO "/backup/"

#define PATH_FILE_MORRYS_PACIENTE_ADICIONADO_XSL "/xml/pacienteAdicionado.xsl"
#define PATH_FILE_MORRYS_BUSCA_XSL "/xml/busca.xsl"

#define PATH_FILE_MORRYS_REMOVE_PACIENTE_CGI "/cgi-bin/removePatient.cgi"
#define PATH_FILE_MORRYS_APOS_BUSCA_EDITA_PACIENTE_CGI "/cgi-bin/editaPaciente.cgi?paciente="
#define PATH_FILE_MORRYS_APOS_REMOVE_PACIENTE_CGI "/cgi-bin/motivoRemove.cgi?paciente="
*/
//#define PATH_FILE_DOENTES_NOVOS_INDEX_SISTEMA_2_HTML "/doentesNovos/indexSistema2.html"
//#define PATH_MORRYS_INICIO "/inicio.html"


/* FIM DEFINE DO MORRYS */


/* DEFINE DE DOENTES NOVOS */
#define PATH_FILE_DOENTES_NOVOS_CONFIG_H "/users/balabram/public_html/desenvolvimento/doentesNovos/src/config.h"
#define PATH_FILE_DOENTES_NOVOS_CONFIG_TEMP_H "/users/balabram/public_html/desenvolvimento/doentesNovos/src/temp.h"

#define WEB_SERVER_DOENTES_NOVOS "http://www04.lps.ufrj.br/~balabram/desenvolvimento/doentesNovos"
#define LOCAL_PATH_DOENTES_NOVOS "/users/balabram/public_html/desenvolvimento/doentesNovos"

#define WEB_STORAGE_DOENTES_NOVOS "http://www04.lps.ufrj.br/~balabram/desenvolvimento/doentesNovos"
#define STORAGE_PATH_DOENTES_NOVOS "/users/balabram/public_html/desenvolvimento/doentesNovos"

/*#define PATH_FILE_DOENTES_NOVOS_PACIENTE_ADICIONADO_XML "/xml/pacienteAdicionado.xml"
#define PATH_FILE_DOENTES_NOVOS_PACIENTE_ADICIONADO_TEMP_XML "/xml/pacienteAdicionadoTemp.xml"
#define PATH_FILE_DOENTES_NOVOS_PACIENTE_REMOVIDO_XML "/xml/removed.xml"
#define PATH_FILE_DOENTES_NOVOS_PACIENTE_HISTORICO_XML "/xml/historic.xml"
#define PATH_FILE_DOENTES_NOVOS_BACKUP_PACIENTE_ADICIONADO "/backup/"

#define PATH_FILE_DOENTES_NOVOS_PACIENTE_ADICIONADO_XSL "/xml/pacienteAdicionado.xsl"
#define PATH_FILE_DOENTES_NOVOS_BUSCA_XSL "/xml/busca.xsl"


#define PATH_FILE_DOENTES_NOVOS_REMOVE_PACIENTE_CGI "/cgi-bin/removePatient.cgi"
#define PATH_FILE_DOENTES_NOVOS_APOS_BUSCA_EDITA_PACIENTE_CGI "/cgi-bin/editaPaciente.cgi?paciente="
#define PATH_FILE_DOENTES_NOVOS_APOS_REMOVE_PACIENTE_CGI "/cgi-bin/motivoRemove.cgi?paciente="
*/
//#define PATH_FILE_MORRYS_INDEX_SISTEMA_2_HTML "/indexSistema2.html"
//#define PATH_DOENTES_NOVOS_INICIO "/inicio.html"


/* FIM DE DOENTES NOVOS */


/* define comum entre os dois */

#define PATH_FILE_PACIENTE_ADICIONADO_XML "/xml/pacienteAdicionado.xml"
#define PATH_FILE_PACIENTE_ADICIONADO_TEMP_XML "/xml/pacienteAdicionadoTemp.xml"
#define PATH_FILE_PACIENTE_REMOVIDO_XML "/xml/removed.xml"
#define PATH_FILE_PACIENTE_HISTORICO_XML "/xml/historic.xml"
#define PATH_FILE_BACKUP "/backup/"

#define PATH_FILE_PACIENTE_ADICIONADO_XSL "/xml/pacienteAdicionado.xsl"
#define PATH_FILE_LISTA_PACIENTES_XSL "/xml/listaPacientes.xsl"
#define PATH_FILE_BUSCA_XSL "/xml/busca.xsl"


#define PATH_FILE_REMOVE_PACIENTE_CGI "/cgi-bin/removePatient.cgi"
#define PATH_FILE_APOS_BUSCA_EDITA_PACIENTE_CGI "/cgi-bin/editaPaciente.cgi?paciente="
#define PATH_FILE_APOS_REMOVE_PACIENTE_CGI "/cgi-bin/motivoRemove.cgi?paciente="
#define PATH_FILE_APOS_BUSCA_VER_PACIENTE_CGI "/cgi-bin/verPaciente.cgi?paciente="

#define PATH_INICIO "/inicio.html"
#define PATH_FILE_INDEX_SISTEMA_2_HTML "/indexSistema2.html"

/* fim dos defines comuns */

int main ()
{
	FILE *arq,*tempArq;
	char name[1024],buffer[1024+3],*firstPart,opBuffer[1024+3];
	int found=0;

	/* inicio config.h para morrys */
	
	arq=fopen(PATH_FILE_MORRYS_CONFIG_H,"r");	
	if(!arq)
	{
		printf("erro abrir arquivo config.h\n");
		exit(0);
	}
	tempArq=fopen(PATH_FILE_MORRYS_CONFIG_TEMP_H,"w");
	if(!tempArq)
	{
		printf("erro abrir arquivo arquivo temporario.h\n");
		exit(0);
	}
	fgets(buffer, 1024, arq);
	while(!feof(arq))
	{
		strcpy(opBuffer,buffer);
		firstPart = strtok(opBuffer," ");
		if(!strcmp(firstPart,"#define"))
		{
			firstPart = strtok(NULL," ");
		
			if(!strcmp("WEB_SERVER",firstPart))
			{
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,WEB_SERVER_MORRYS);
				found=1;
			}

			/* compara com o esperado escrito no config.h e depois concatena com as macros definidas nesse programa(
				obs: note que os nomes sao diferentes.
			*/
			
			if(!strcmp("LOCAL_PATH_FILE_MORRYS_PACIENTE_ADICIONADO_XML",firstPart))
			{
				strcpy(name,STORAGE_PATH_MORRYS);
				strcat(name,PATH_FILE_PACIENTE_ADICIONADO_XML);
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,name);
				found=1;
			}
			
			if(!strcmp("LOCAL_PATH_FILE_MORRYS_PACIENTE_ADICIONADO_TEMP_XML",firstPart))
			{
				strcpy(name,STORAGE_PATH_MORRYS);
				strcat(name,PATH_FILE_PACIENTE_ADICIONADO_TEMP_XML);
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,name);
				found=1;
			}
			
			if(!strcmp("WEB_PATH_MORRYS_PACIENTE_ADICIONADO_XML",firstPart))
			{
				strcpy(name,WEB_STORAGE_MORRYS);
				strcat(name,PATH_FILE_PACIENTE_ADICIONADO_XML);
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,name);
				found=1;
			}
			
			if(!strcmp("LOCAL_PATH_FILE_MORRYS_BUSCA_XSL",firstPart))
			{
				strcpy(name,LOCAL_PATH_MORRYS);
				strcat(name,PATH_FILE_BUSCA_XSL);
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,name);
				found=1;
			}
			
			if(!strcmp("WEB_PATH_FILE_MORRYS_BUSCA_XSL",firstPart))
			{
				strcpy(name,WEB_SERVER_MORRYS);
				strcat(name,PATH_FILE_BUSCA_XSL);
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,name);
				found=1;
			}
			
			if(!strcmp("WEB_PATH_FILE_MORRYS_APOS_BUSCA_EDITA_PACIENTE_CGI",firstPart))
			{
				strcpy(name,WEB_SERVER_MORRYS);
				strcat(name,PATH_FILE_APOS_BUSCA_EDITA_PACIENTE_CGI);
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,name);
				found=1;
			}
			
			if(!strcmp("WEB_PATH_FILE_MORRYS_APOS_BUSCA_REMOVE_PACIENTE_CGI",firstPart))
			{
				strcpy(name,WEB_SERVER_MORRYS);
				strcat(name,PATH_FILE_APOS_REMOVE_PACIENTE_CGI);
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,name);
				found=1;
			}
			
			if(!strcmp("WEB_PATH_FILE_MORRYS_REMOVE_PACIENTE_CGI",firstPart))
			{
				strcpy(name,WEB_SERVER_MORRYS);
				strcat(name,PATH_FILE_REMOVE_PACIENTE_CGI);
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,name);
				found=1;
			}
			
			if(!strcmp("WEB_PATH_MORRYS_INICIO",firstPart))
			{
				strcpy(name,WEB_SERVER_MORRYS);
				strcat(name,PATH_INICIO);
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,name);
				found=1;
			}
			
			if(!strcmp("WEB_PATH_FILE_MORRYS_INDEX_SISTEMA_2",firstPart))
			{
				strcpy(name,WEB_SERVER_MORRYS);
				strcat(name,PATH_FILE_INDEX_SISTEMA_2_HTML);
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,name);
				found=1;
			}
			
			if(!strcmp("WEB_PATH_FILE_DOENTES_NOVOS_INDEX_SISTEMA_2",firstPart))
			{
				strcpy(name,WEB_SERVER_DOENTES_NOVOS);
				strcat(name,PATH_FILE_INDEX_SISTEMA_2_HTML);
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,name);
				found=1;
			}
			
			if(!strcmp("LOCAL_PATH_FILE_MORRYS_PACIENTES_REMOVIDOS_XML",firstPart))
			{
				strcpy(name,STORAGE_PATH_MORRYS);
				strcat(name,PATH_FILE_PACIENTE_REMOVIDO_XML);
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,name);
				found=1;
			}
			
			if(!strcmp("LOCAL_PATH_FILE_MORRYS_HISTORICO_XML",firstPart))
			{
				strcpy(name,STORAGE_PATH_MORRYS);
				strcat(name,PATH_FILE_PACIENTE_HISTORICO_XML);
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,name);
				found=1;
			}
			
			if(!strcmp("WEB_PATH_FILE_MORRYS_PACIENTE_ADICIONADO_XSL",firstPart))
			{
				strcpy(name,WEB_SERVER_MORRYS);
				strcat(name,PATH_FILE_PACIENTE_ADICIONADO_XSL);
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,name);
				found=1;
			}
		
			if(!strcmp("LOCAL_PATH_FILE_MORRYS_BACKUP",firstPart))
			{
				strcpy(name,STORAGE_PATH_MORRYS);
				strcat(name,PATH_FILE_BACKUP);
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,name);
				found=1;
			}
			if(!strcmp("WEB_PATH_FILE_MORRYS_APOS_BUSCA_VER_PACIENTE_CGI",firstPart))
			{
				strcpy(name,WEB_SERVER_MORRYS);
				strcat(name,PATH_FILE_APOS_BUSCA_VER_PACIENTE_CGI);
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,name);
				found=1;
			}
			if(!strcmp("WEB_PATH_FILE_MORRYS_LISTA_PACIENTES_XSL",firstPart))
			{
				strcpy(name,WEB_SERVER_MORRYS);
				strcat(name,PATH_FILE_LISTA_PACIENTES_XSL);
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,name);
				found=1;
			}
			
			if(!found)
				fputs(buffer,tempArq);
			else
				found--;
		}
		else
			fputs(buffer,tempArq);
		fgets(buffer, 1024, arq);
	}
	fclose(arq);
	fclose(tempArq);
	remove(PATH_FILE_MORRYS_CONFIG_H);
	rename(PATH_FILE_MORRYS_CONFIG_TEMP_H,PATH_FILE_MORRYS_CONFIG_H);

	/* fim cria config.h para o morrys */

	/* inicio config.h para doentes novos */

	arq=fopen(PATH_FILE_DOENTES_NOVOS_CONFIG_H,"r");	
	if(!arq)
	{
		printf("erro abrir arquivo config.h\n");
		exit(0);
	}
	tempArq=fopen(PATH_FILE_DOENTES_NOVOS_CONFIG_TEMP_H,"w");
	if(!tempArq)
	{
		printf("erro abrir arquivo arquivo temporario.h\n");
		exit(0);
	}
	fgets(buffer, 1024, arq);
	while(!feof(arq))
	{
		strcpy(opBuffer,buffer);
		firstPart = strtok(opBuffer," ");
		if(!strcmp(firstPart,"#define"))
		{
			firstPart = strtok(NULL," ");
		
			if(!strcmp("WEB_SERVER",firstPart))
			{
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,WEB_SERVER_DOENTES_NOVOS);
				found=1;
			}

			/* compara com o esperado escrito no config.h e depois concatena com as macros definidas nesse programa(
				obs: note que os nomes sao diferentes.
			*/
			
			if(!strcmp("LOCAL_PATH_FILE_DOENTES_NOVOS_PACIENTE_ADICIONADO_XML",firstPart))
			{
				strcpy(name,STORAGE_PATH_DOENTES_NOVOS);
				strcat(name,PATH_FILE_PACIENTE_ADICIONADO_XML);
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,name);
				found=1;
			}
			
			if(!strcmp("LOCAL_PATH_FILE_DOENTES_NOVOS_PACIENTE_ADICIONADO_TEMP_XML",firstPart))
			{
				strcpy(name,STORAGE_PATH_DOENTES_NOVOS);
				strcat(name,PATH_FILE_PACIENTE_ADICIONADO_TEMP_XML);
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,name);
				found=1;
			}
			
			if(!strcmp("WEB_PATH_DOENTES_NOVOS_PACIENTE_ADICIONADO_XML",firstPart))
			{
				strcpy(name,WEB_STORAGE_DOENTES_NOVOS);
				strcat(name,PATH_FILE_PACIENTE_ADICIONADO_XML);
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,name);
				found=1;
			}
			
			if(!strcmp("LOCAL_PATH_FILE_DOENTES_NOVOS_BUSCA_XSL",firstPart))
			{
				strcpy(name,LOCAL_PATH_DOENTES_NOVOS);
				strcat(name,PATH_FILE_BUSCA_XSL);
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,name);
				found=1;
			}
			
			if(!strcmp("WEB_PATH_FILE_DOENTES_NOVOS_BUSCA_XSL",firstPart))
			{
				strcpy(name,WEB_SERVER_DOENTES_NOVOS);
				strcat(name,PATH_FILE_BUSCA_XSL);
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,name);
				found=1;
			}
			
			if(!strcmp("WEB_PATH_FILE_DOENTES_NOVOS_APOS_BUSCA_EDITA_PACIENTE_CGI",firstPart))
			{
				strcpy(name,WEB_SERVER_DOENTES_NOVOS);
				strcat(name,PATH_FILE_APOS_BUSCA_EDITA_PACIENTE_CGI);
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,name);
				found=1;
			}
			
			if(!strcmp("WEB_PATH_FILE_DOENTES_NOVOS_APOS_BUSCA_REMOVE_PACIENTE_CGI",firstPart))
			{
				strcpy(name,WEB_SERVER_DOENTES_NOVOS);
				strcat(name,PATH_FILE_APOS_REMOVE_PACIENTE_CGI);
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,name);
				found=1;
			}
			
			if(!strcmp("WEB_PATH_FILE_DOENTES_NOVOS_REMOVE_PACIENTE_CGI",firstPart))
			{
				strcpy(name,WEB_SERVER_DOENTES_NOVOS);
				strcat(name,PATH_FILE_REMOVE_PACIENTE_CGI);
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,name);
				found=1;
			}
			
			if(!strcmp("WEB_PATH_DOENTES_NOVOS_INICIO",firstPart))
			{
				strcpy(name,WEB_SERVER_DOENTES_NOVOS);
				strcat(name,PATH_INICIO);
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,name);
				found=1;
			}
			
			if(!strcmp("WEB_PATH_FILE_MORRYS_INDEX_SISTEMA_2",firstPart))
			{
				strcpy(name,WEB_SERVER_MORRYS);
				strcat(name,PATH_FILE_INDEX_SISTEMA_2_HTML);
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,name);
				found=1;
			}
			
			if(!strcmp("WEB_PATH_FILE_DOENTES_NOVOS_INDEX_SISTEMA_2",firstPart))
			{
				strcpy(name,WEB_SERVER_DOENTES_NOVOS);
				strcat(name,PATH_FILE_INDEX_SISTEMA_2_HTML);
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,name);
				found=1;
			}
			
			if(!strcmp("LOCAL_PATH_FILE_DOENTES_NOVOS_PACIENTES_REMOVIDOS_XML",firstPart))
			{
				strcpy(name,STORAGE_PATH_DOENTES_NOVOS);
				strcat(name,PATH_FILE_PACIENTE_REMOVIDO_XML);
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,name);
				found=1;
			}
			
			if(!strcmp("LOCAL_PATH_FILE_DOENTES_NOVOS_HISTORICO_XML",firstPart))
			{
				strcpy(name,STORAGE_PATH_DOENTES_NOVOS);
				strcat(name,PATH_FILE_PACIENTE_HISTORICO_XML);
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,name);
				found=1;
			}
			
			if(!strcmp("WEB_PATH_FILE_DOENTES_NOVOS_PACIENTE_ADICIONADO_XSL",firstPart))
			{
				strcpy(name,WEB_SERVER_DOENTES_NOVOS);
				strcat(name,PATH_FILE_PACIENTE_ADICIONADO_XSL);
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,name);
				found=1;
			}
		
			if(!strcmp("LOCAL_PATH_FILE_DOENTES_NOVOS_BACKUP",firstPart))
			{
				strcpy(name,STORAGE_PATH_DOENTES_NOVOS);
				strcat(name,PATH_FILE_BACKUP);
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,name);
				found=1;
			}

			if(!strcmp("WEB_PATH_FILE_DOENTES_NOVOS_APOS_BUSCA_VER_PACIENTE_CGI",firstPart))
			{
				strcpy(name,WEB_SERVER_DOENTES_NOVOS);
				strcat(name,PATH_FILE_APOS_BUSCA_VER_PACIENTE_CGI);
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,name);
				found=1;
			}
			if(!strcmp("WEB_PATH_FILE_DOENTES_NOVOS_LISTA_PACIENTES_XSL",firstPart))
			{
				strcpy(name,WEB_SERVER_DOENTES_NOVOS);
				strcat(name,PATH_FILE_LISTA_PACIENTES_XSL);
				fprintf(tempArq,"#define %s \"%s\"\n",firstPart,name);
				found=1;
			}
			
			
			if(!found)
				fputs(buffer,tempArq);
			else
				found--;
		}
		else
			fputs(buffer,tempArq);
		fgets(buffer, 1024, arq);
	}
	fclose(arq);
	fclose(tempArq);
	remove(PATH_FILE_DOENTES_NOVOS_CONFIG_H);
	rename(PATH_FILE_DOENTES_NOVOS_CONFIG_TEMP_H,PATH_FILE_DOENTES_NOVOS_CONFIG_H);
	printf("fim\n");

	/* fim config.h para doentes novos */

	return(0);
}
