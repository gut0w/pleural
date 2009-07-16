/*
* UFRJ - LPS
* Autor: Gabriel Nascimento Machado
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "config.h"


int main (int argc, char *argv[])
{
	FILE *xml, *backup;
	//char date[DATE_LENGTH+1];
	//char backupPath[strlen(XML_NAME)+32+1+1+strlen(XML_BACKUP_PATH)+1+DATE_LENGTH+1];
	//char posto[32+1], path[strlen(XML_DIR_PATH)+1+MAX_LENGTH_HEALTH_CENTER+1+strlen(XML_GENERIC_NAME)+1];
	//int ch;
	time_t rawtime;
	char buffer[100+1];
	char date[100+1];
	int ch;
	char fileName[200+1];
	char *system_path = NULL;
	char *system_dir = NULL;
//	char temp[1024 +1];
//	time_t seg;
	struct tm *timeinfo;
//	struct tm *tempo;

	time(&rawtime);
	timeinfo = localtime ( &rawtime );
	
//	time(&seg);
//	tempo=localtime(&seg);PATH_FILE_MORRYS_PACIENTE_ADICIONADO_XML
//	strftime (date,80,"%d_%m_%Y_%H-%X",timeinfo);
	strftime (date,80,"%Y\'%m\'%d\'%Hh%Mmin",timeinfo);
	strcpy(buffer,date);
	strcat(buffer,"pacienteAdicionado.xml");
//	snprintf (date,DATE_LENGTH+1,"%04i-%02i-%02i_%02i-%02i-%02i",1900+tempo->tm_year,tempo->tm_mon+1,tempo->tm_mday,tempo->tm_hour,tempo->tm_min,tempo->tm_sec);
	//lerPosto(USERS_DATA_PATH,posto);

	strcat(fileName,PATH_BACKUP);
	strcat(fileName,buffer);
	xml = fopen(PATH_XML_PACIENTE_ADICIONADO,"r");
	if (xml == NULL)
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
		exit(0);
	}
	fclose(xml);
	backup=fopen(fileName,"w");
	if (!backup)
	{
		fclose(backup);
		printf("Content-Type: text/html\r\n\r\n");
		printf("<html><head><title>Erro</title></head><body>Erro abrindo arquivo de usu&aacute;rios</body></html>");
		exit(0);
	}
	
	//strcpy(backupPath,"");
//	snprintf (path,strlen(XML_DIR_PATH)+1+MAX_LENGTH_HEALTH_CENTER+1+strlen(XML_GENERIC_NAME),"%spacientesGuadalupe.xml",XML_DIR_PATH);
//	snprintf (backupPath,strlen(XML_NAME)+strlen(XML_BACKUP_PATH)+DATE_LENGTH+strlen(posto)+1+1+1+1,"%s%s-pacientesGuadalupe.xml",XML_BACKUP_PATH,date);
//	if (!(xml=fopen(path, "r")))
//	{
//		printf("Content-Type: text/html\r\n\r\n");
//		printf("%s",path);
//		printf("<html><head><title>Erro</title></head><body>Erro abrindo arquivo de usu&aacute;rios</body></html>");
//		exit(0);
//	}
//	if (!(backup=fopen(backupPath, "w")))
//	{
//		printf("Content-Type: text/html\r\n\r\n");
//		fclose(xml);
//		printf("<html><head><title>Erro</title></head><body>Erro abrindo arquivo de Backup</body></html>");
//		exit(0);
//	}

	// obter nome do diretorio do sistema (doentesNovos ou morrys) atraves do caminho absoluto
	system_path = get_current_dir_name();
	system_dir = strtok(system_path,"/");
	while ( (strcmp(system_dir,"doentesNovos")!=0) && (strcmp(system_dir,"morrys")!=0) )
	{
		system_dir = strtok(NULL,"/");
	}
	printf("Content-Type: application/force-download\r\n");
	printf("Content-Disposition: attachment; filename=paciente_%s_%s_backup.xml\r\n\r\n",system_dir,date);	
/*	fgets(temp, 1024, xml);
//	printf("%s\n",temp);
	while (!feof(xml))
	{
		fputs(temp, backup);
		fgets(temp, 1024, xml);	
//		printf("%s\n",temp);
	}
*/
	while((ch=getc(xml)) != EOF)
	{
		printf("%c",ch);
		fputc(ch,backup);
	}
	fclose(xml);
	fclose(backup);

	exit(0);
}
