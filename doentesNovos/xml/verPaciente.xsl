<?xml version="1.0" encoding="utf-8"?>

<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform" version="1.0"
				xmlns:fo="http://www.w3.org/1999/XSL/Format"
				xmlns="http://www.w3.org/1999/xhtml">

<xsl:include href="pacienteDados.xsl" />
<xsl:template match="/doc">

	<xsl:for-each select="paciente[numeroPaciente='87']">
			<p align="right"> <a target="blank" href="imprimir.cgi?paciente=87">Versão para Impressão</a></p>
			<center>
			<table>
			<tr>
				<th colspan="2">.:.Projeto Neural TB .:.</th>
			</tr>
			<xsl:apply-templates select="." />
			</table>
			</center>
	</xsl:for-each>
	
</xsl:template>

</xsl:stylesheet>
