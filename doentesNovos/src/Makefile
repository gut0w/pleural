# Makefile

CC = gcc
LD = gcc

LIBXML = `xml2-config --cflags --libs`

#CGI IS THE DIR WHERE CGI ARE SUPPOSED TO BE
CGI = ../cgi-bin/

EXECS = addPatient.o backup.o busca.o login.o showAll.o

all:
	$ gcc -Wall -o addPatient.cgi addPatient.c
	$ gcc -Wall -o backup.cgi backup.c
	$ gcc -Wall -o busca.cgi busca.c
	$ gcc -Wall -o login.cgi login.c
	$ gcc -Wall -o showAll.cgi showAll.c
	#$ gcc -Wall -o motivoRemove.cgi motivoRemove.c
	#$ gcc -Wall -o removePatient.cgi removePatient.c $(LIBXML)
	
	$ mv addPatient.cgi $(CGI)addPatient.cgi
	$ mv backup.cgi $(CGI)backup.cgi
	$ mv busca.cgi $(CGI)busca.cgi
	$ mv login.cgi $(CGI)login.cgi
	$ mv showAll.cgi $(CGI)showAll.cgi
	#$ mv motivoRemove.cgi $(CGI)motivoRemove.cgi
	#$ mv removePatient.cgi $(CGI)removePatient.cgi
	
clean:
	$ rm -f $(EXECS)
	$ rm -f $(CGI)addPatient.cgi
	$ rm -f $(CGI)backup.cgi
	$ rm -f $(CGI)busca.cgi
	$ rm -f $(CGI)login.cgi
	$ rm -f $(CGI)showAll.cgi
	#$ rm -f $(CGI)motivoRemove.cgi
	$ rm -f $(CGI)removePatient.cgi
