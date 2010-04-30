# Makefile

CC = gcc
CFLAGS = -Wall -o

LIBXML = `xml2-config --cflags --libs`
LIBCGIDIR = libs/
LIBCGIFLAGS = -L$(LIBCGIDIR) -lcgi

#CGI IS THE DIR WHERE CGI ARE SUPPOSED TO BE
CGI = ../cgi-bin/
DOENTES_NOVOS_CGI = ../doentesNovos/cgi-bin/

OBJS = backup.o busca.o login.o showAll.o newAddPatient.o

all:
	$ mkdir -p $(CGI)
	$ mkdir -p $(DOENTES_NOVOS_CGI)
	
	$ $(CC) $(CFLAGS) $(CGI)login.cgi login.c
	
	$ $(CC) $(CFLAGS) backup.cgi backup.c
	$ $(CC) $(CFLAGS) busca.cgi busca.c
	$ $(CC) $(CFLAGS) showAll.cgi showAll.c
	#$ $(CC) $(CFLAGS) motivoRemove.cgi motivoRemove.c
	#$ $(CC) $(CFLAGS) removePatient.cgi removePatient.c $(LIBXML)
	$ $(CC) $(CFLAGS) newAddPatient.cgi newAddPatient.c $(LIBXML) $(LIBCGIFLAGS)
	
	$ mv backup.cgi $(DOENTES_NOVOS_CGI)backup.cgi
	$ mv busca.cgi $(DOENTES_NOVOS_CGI)busca.cgi
	$ mv showAll.cgi $(DOENTES_NOVOS_CGI)showAll.cgi
	#$ mv motivoRemove.cgi $(DOENTES_NOVOS_CGI)motivoRemove.cgi
	#$ mv removePatient.cgi $(DOENTES_NOVOS_CGI)removePatient.cgi
	$ mv newAddPatient.cgi $(DOENTES_NOVOS_CGI)newAddPatient.cgi
	
clean:
	$ rm -f $(OBJS)
	$ rm -rf $(CGI)
	$ rm -rf $(DOENTES_NOVOS_CGI)
