#ifndef CONFIG_H
#define CONFIG_H

#define WEB_SERVER "https://www.gruyere.lps.ufrj.br/~pleural/"

#define PATH_BACKUP "../backup/"

#define PATH_CGI_APOS_BUSCA_VER_PACIENTE "../cgi-bin/verPaciente.cgi?paciente="
#define PATH_CGI_APOS_BUSCA_EDITA_PACIENTE "../cgi-bin/editaPaciente.cgi?paciente="
#define PATH_CGI_APOS_BUSCA_REMOVE_PACIENTE "../cgi-bin/motivoRemove.cgi?paciente="
#define PATH_CGI_REMOVE_PACIENTE "../cgi-bin/removePatient.cgi"

#define PATH_HTML_INICIO "../inicio.html"
#define PATH_HTML_MORRYS_INDEX_SISTEMA_2 "../morrys/indexSistema2.html"
#define PATH_HTML_DOENTES_NOVOS_INDEX_SISTEMA_2 "../doentesNovos/indexSistema2.html"

#define PATH_XML_PACIENTE_ADICIONADO "../xml/pacienteAdicionado.xml"
#define PATH_XML_PACIENTES_REMOVIDOS "../xml/removed.xml"
#define PATH_XML_HISTORICO "../xml/historic.xml"
#define PATH_XML_PACIENTE_ADICIONADO_TEMP "../xml/pacienteAdicionadoTemp.xml"

#define PATH_XSL_BUSCA "../xml/busca.xsl"
#define PATH_XSL_LISTA_PACIENTES "../xml/listaPacientes.xsl"
#define PATH_XSL_LISTA_PACIENTES_REMOVIDOS "../xml/listaPacientesRemovidos.xsl"
#define PATH_XSL_PACIENTE_ADICIONADO "../xml/pacienteAdicionado.xsl"
#define PATH_XSL_VER_PACIENTE "../xml/verPaciente.xsl"

#endif
