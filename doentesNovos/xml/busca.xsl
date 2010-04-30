<?xml version="1.0" encoding="iso-8859-1"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/">
<xsl:variable name="contador">
0
<xsl:for-each select="doc/paciente">
<xsl:if test="numeroPaciente = '1'">
<xsl:number count="paciente" />
</xsl:if>
</xsl:for-each>
</xsl:variable>
<html>
<head>
<title>.:. Pacientes Encontrados .:. Projeto Neural TB .:.</title>
</head>
<body>
<xsl:choose>
<xsl:when test="$contador != 0">
<xsl:for-each select="doc/paciente[numeroPaciente='1']">
<table border="2" cellspacing="0" width="50%"><tr>
  <td>editar</td>
  <td>remover</td>
	<td>Numero Paciente</td>
	<td>Endereço</td>
</tr>
<tr>
<xsl:variable name="posicaoPacienteBusca" select="(position()-1)" />
<xsl:variable name="edita" select="''"/>
<xsl:variable name="remove" select="''"/>
<td> <a>editar</a></td>
<td> <a>remover</a></td>
<td> <xsl:value-of select="numeroPaciente"/> </td>
<xsl:choose>
<xsl:when test="logradouro != ''">
	<td> <xsl:value-of select="logradouro"/> </td>
</xsl:when>
<xsl:otherwise>
	<td> não possui endereço</td>
</xsl:otherwise>
</xsl:choose>
</tr>
</table>
</xsl:for-each>
</xsl:when>
<xsl:otherwise>
Não possui paciente 1
</xsl:otherwise>
</xsl:choose>
</body>
</html>
</xsl:template>
</xsl:stylesheet>
