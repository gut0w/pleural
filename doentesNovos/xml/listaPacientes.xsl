<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
<xsl:template match="/doc">
<html>
	<head>
		<title>.:. Pacientes cadastrados com sucesso .:. Projeto Neural TB .:.</title>
	</head>
	<body>
		<center>
		<table border="0">
		<tr>
			<td><center><font size="5" > Pacientes Cadastrados </font></center></td>
		</tr>
		<tr><td></td></tr>
		<tr><td></td></tr>
		</table>

		<table align="center" id="dadosPaciente" border="0" cellpadding="0" cellspacing="0" width="90%">
        <xsl:for-each select="paciente">
			<tr bgcolor="#8888BB">
				<td align="left" >Número Paciente: </td>
				<td ><xsl:value-of select ="numeroPaciente" /></td>
			</tr>
			<tr bgcolor="#CCCCFF">
				<td align="left" >Endereço: </td>
				<td><xsl:value-of select ="logradouro" />,
					<xsl:value-of select ="numero" />
					<xsl:if test="complemento != ''">
					&#160;/(<xsl:value-of select ="complemento" />)</xsl:if> -
					<xsl:value-of select ="estadoEndereco" />- 
					<xsl:value-of select ="municipioEndereco" />- 
					<xsl:value-of select ="bairroEndereco" /> 
					<xsl:if test="cep != ''">
					&#160; - (<xsl:value-of select ="cep" />)</xsl:if>
				</td>
			</tr>
			<tr bgcolor="#8888BB">
				<td align="left">Telefone(s): </td>
				<td><xsl:if test="telefone1 != ''">
						(<xsl:value-of select = "telefone1" />)
					</xsl:if>
					<xsl:if test="telefone2 != ''">
						(&#160;e <xsl:value-of select= "telefone2" />)
					</xsl:if>
				</td>
			</tr>
			<tr bgcolor="#CCCCFF">
				<td align="left">Georreferenciamento: </td>
				<td>
					<xsl:if test="latitude != ''">
					<table border="0">
						<tr>
							<td>Latitude: <xsl:value-of select="latitude" /></td>
						</tr>
					</table>
					</xsl:if>
					<xsl:if test="longitude != ''">
					<table border="0">
							<tr>
								<td>Longitude: <xsl:value-of select="latitude" /></td>
							</tr>
					</table>
					</xsl:if>
				</td>
			</tr>
			<tr bgcolor="#8888BB">
				<td align="left">Data de nascimento: </td>
				<td><xsl:value-of select="txt_diaNascimento"/>&#160;/&#160;<xsl:value-of select="txt_mesNascimento"/>&#160;/&#160;<xsl:value-of select="txt_anoNascimento"/></td>
			</tr>
			<tr bgcolor="#CCCCFF">
				<td align="left">Sexo: </td>
				<td><xsl:value-of select="sexo" /></td>
			</tr>
			<tr bgcolor="#8888BB">
				<td align="left">Estado Civil: </td>
				<td><xsl:value-of select="estadoCivil" /></td>
			</tr>
			<tr bgcolor="#CCCCFF">
				<td align="left">Estuda: </td>
				<td><xsl:value-of select="estudaMomento" /></td>
			</tr>
			<tr bgcolor="#8888BB">
				<td align="left">Grau de Instrução: </td>
				<td><xsl:value-of select="grauInstrucao" /></td>
			</tr>
			<tr bgcolor="#CCCCFF">
				<td align="left">Ocupação: </td>
				<td><xsl:value-of select="ocupacao" /></td>
			</tr>
			<tr bgcolor="#8888BB">
				<td align="left">Profissional Saúde: </td>
				<td><xsl:value-of select="profissionalSaude" /></td>
			</tr>
			<tr bgcolor="#CCCCFF">
				<td align="left">Atividade: </td>
				<td><xsl:value-of select="atividadeTrabalho" /></td>
			</tr>
			<tr bgcolor="#8888BB">
				<td align="left">Renda familiar: </td>
				<td><xsl:value-of select="rendaFamiliarAtual" /></td>
			</tr>
			<tr bgcolor="#CCCCFF">
				<td align="left">Renda familiar a cerca de dis anos: </td>
				<td><xsl:value-of select="rendaFamiliarPassado" /></td>
			</tr>
			<tr bgcolor="#8888BB">
				<td align="left">Grau de intrução do chefe de família: </td>
				<td><xsl:value-of select="grauInstrucaoChefe" /></td>
			</tr>
			<tr bgcolor="#CCCCFF">
				<td align="left">Quantidade de itens que tem em casa: </td>
				<td>
					<table border="0">
						<tr>
							<td>Aspirador de pó: <xsl:value-of select="aspiradorPo" />&#160;</td>
						</tr>
						<tr>
							<td>Automóvel: <xsl:value-of select="automovel" />&#160;</td>
						</tr>
						<tr>
							<td>Banheiro: <xsl:value-of select="banheiro" />&#160;</td>
						</tr>
						<tr>
							<td>Empregada: <xsl:value-of select="empregada" />&#160;</td>
						</tr>
						<tr>
							<td>Freezer: <xsl:value-of select="freezer" />&#160;</td>
						</tr>
						<tr>
							<td>Geladeira Duplex: <xsl:value-of select="geladeiraDuplex" />&#160;</td>
						</tr>
						<tr>
							<td>Geladeira Simples: <xsl:value-of select="geladeiraSimples" />&#160;</td>
						</tr>
						<tr>
							<td>Máquina de lavar roupa: <xsl:value-of select="maquinaLavar" />&#160;</td>
						</tr>
						<tr>
							<td>Rádio: <xsl:value-of select="radio" />&#160;</td>
						</tr>
						<tr>
							<td>Tv: <xsl:value-of select="tv" />&#160;</td>
						</tr>
						<tr>
							<td>DVD/video cassete: <xsl:value-of select="dvd" />&#160;</td>
						</tr>
					</table>
				</td>
			</tr>
			<tr bgcolor="#8888BB">
				<td align="left">Naturalidade: </td>
				<td><xsl:value-of select="cidadeNaturalidade" />
					<xsl:value-of select="estadoNaturalidade" />
				</td>
			</tr>
			<tr bgcolor="#8888BB">
				<td align="left">Há quanto tempo mora no endereço atual: </td>
				<td><xsl:value-of select="tempoEnderecoAtual" /> meses</td>
			</tr>
			<tr bgcolor="#CCCCFF">
				<td align="left">Morou em outro endereço: </td>
				<td><xsl:value-of select="morouOutro" /></td>
			</tr>
			<tr bgcolor="#8888BB">
				<td align="left">Quantas pessoas moram no domicílio: </td>
				<td><xsl:value-of select="numeroPessoas" /></td>
			</tr>
			<tr bgcolor="#CCCCFF">
				<td align="left">Quantos cômodos: </td>
				<td><xsl:value-of select="numeroComodos" /></td>
			</tr>
			<tr bgcolor="#8888BB">
				<td align="left">Quantos cômodos utilizados como dormitório: </td>
				<td><xsl:value-of select="numeroDormitorios" /></td>
			</tr>
			<tr bgcolor="#CCCCFF">
				<td align="left">Ex-morador de rua: </td>
				<td><xsl:value-of select="moradorRua" /></td>
			</tr>
			<tr bgcolor="#8888BB">
				<td align="left">Ex-morador/morador de asilo: </td>
				<td><xsl:value-of select="moradorAsilo" /></td>
			</tr>
			<tr bgcolor="#CCCCFF">
				<td align="left">Ex-detento: </td>
				<td><xsl:value-of select="exDetento" /></td>
			</tr>
			<tr bgcolor="#8888BB">
				<td align="left">Em relação ao hábito de fumar: </td>
				<td><table border="0">
					<tr>
						<td><xsl:value-of select="habitoFumar" /></td>
					</tr>
					<xsl:if test="inalaFumaca != ''">
					<tr>
						<td>(&#160;Inala fumaça: <xsl:value-of select="inalaFumaca" />)</td>
					</tr>
					</xsl:if>
					<xsl:if test="tempoParouDias != ''">
					<tr>
						<td>(&#160;Parou há <xsl:value-of select="tempoParouDias" />&#160;dias)</td>
					</tr>
					</xsl:if>
					<xsl:if test="tempoParouMeses != ''">
					<tr>
						<td>(&#160;Parou há <xsl:value-of select="tempoParouMeses" />&#160;meses)</td>
					</tr>
					</xsl:if>
					<xsl:if test="tempoParouAnos != ''">
					<tr>
						<td>(&#160;Parou há <xsl:value-of select="tempoParouAnos" />&#160;anos)</td>
					</tr>
					</xsl:if>
					<xsl:if test="cigarrosDia != ''">
					<tr>	
						<td>(&#160;Número de cigarros por dia: <xsl:value-of select="cigarrosDia" />)</td>
					</tr>
					</xsl:if>
					<xsl:if test="anosFuma != ''">
					<tr>
						<td>(&#160;Há quanto tempo fuma: <xsl:value-of select="anosFuma" />&#160;anos)</td>
					</tr>
					</xsl:if>
					<xsl:if test="cargaTabagica != ''">
					<tr>
						<td>(&#160;Carga tabágica: <xsl:value-of select="cargaTabagica" />&#160;cigarros por ano)</td>
					</tr>
					</xsl:if>
					</table>		
				</td>
			</tr>
			<tr bgcolor="#CCCCFF">
				<td align="left">Usuário/ex-usuário de drogas: </td>
				<td><xsl:value-of select="usuarioDrogas" /></td>
			</tr>
			<tr bgcolor="#8888BB">
				<td align="left">Bebida preferida: </td>
				<td><xsl:value-of select="bebidaPreferida" /></td>
			</tr>
			<tr bgcolor="#CCCCFF">
				<td align="left">Toma bebida alcoólica:  </td>
				<td><table border="0">
					<tr>
						<td><xsl:value-of select="bebidaPreferida" /></td>
					</tr>
					<xsl:if test="tomaBebida != ''">
					<tr>
						<td>(&#160;Pacilidade para fazer amizades: <xsl:value-of select="tomaBebida" />)</td>
					</tr>
					</xsl:if>
					<xsl:if test="deveriaDiminuir != ''">
					<tr>
						<td>(&#160;Já sentiu que deveria beber menos: <xsl:value-of select="deveriaDiminuir" />)</td>
					</tr>
					</xsl:if>
					<xsl:if test="recebeuCritica != ''">
					<tr>
						<td>(&#160;Já recebeu críticas: <xsl:value-of select="recebeuCritica" />)</td>
					</tr>
					</xsl:if>
					<xsl:if test="bebeManha != ''">
					<tr>
						<td>(&#160;Bebe de manhã para diminuir o nervosismo/ressaca: <xsl:value-of select="bebeManha" />)</td>
					</tr>
					</xsl:if>
					<xsl:if test="senteCulpa != ''">
					<tr>
						<td>(&#160;Sente-se culpado: <xsl:value-of select="senteCulpa" />)</td>
					</tr>
					</xsl:if>
					</table>
				</td>
			</tr>
			<tr bgcolor="#8888BB">
				<td align="left">Morou com alguém com tuberculose: </td>
				<td><table border="0">
					<xsl:if test="quantoTempoContato != ''">
					<tr>
						<td>(&#160;Há quanto tempo foi o contato: <xsl:value-of select="quantoTempoContato " />&#160;meses)</td>
					</tr>
					</xsl:if>
					<xsl:if test="horasSemanaisContato != ''">
					<tr>
						<td>(&#160;Por quanto tempo foi o contato: <xsl:value-of select="horasSemanaisContato " />&#160;horas)</td>
					</tr>
					</xsl:if>
					</table>
				</td>
			</tr>
			<tr bgcolor="#CCCCFF">
				<td align="left">Teve alguém da família com tuberculose: </td>
				<td><table broder="0">
					<xsl:if test="quantoTempoContato != ''">
					<tr>
						<td>(&#160;Há quanto tempo foi o contato: <xsl:value-of select="quantoTempoContato " />&#160;meses)</td>
					</tr>
					</xsl:if>
					<xsl:if test="horasSemanaisContato != ''">
					<tr>
						<td>(&#160;Por quanto tempo foi o contato: <xsl:value-of select="horasSemanaisContato " />&#160;horas)</td>
					</tr>
					</xsl:if>
					</table>
				</td>
			</tr>
			<tr bgcolor="#8888BB">
				<td align="left">Teve alguém de ciclo amizade/trabalho com tuberculose: </td>
				<td><table border="0">
					<xsl:if test="quantoTempoContato != ''">
					<tr>
						<td>(&#160;Há quanto tempo foi o contato: <xsl:value-of select="quantoTempoContato " />&#160;meses)</td>
					</tr>
					</xsl:if>
					<xsl:if test="horasSemanaisContato != ''">
					<tr>
						<td>(&#160;Por quanto tempo foi o contato: <xsl:value-of select="horasSemanaisContato " />&#160;horas)</td>
					</tr>
					</xsl:if>
					</table>
				</td>
			</tr>
			<tr bgcolor="#CCCCFF">
				<td align="left">Teve tuberculose: </td>
				<td><table border="0">
					<tr>
						<td><xsl:value-of select="teveTuberculose" /></td>
					</tr>
					<xsl:if test="quantosAnos != ''">
					<tr>
						<td>(&#160;Há <xsl:value-of select="quantosAnos" /> anos)</td>
					</tr>
					</xsl:if>
					<xsl:if test="tratamento != ''">
					<tr>
						<td>(&#160;Tratamento: 
						<xsl:if test="tratamento != ''">
							<xsl:value-of select="tratamento " />
						</xsl:if>
						<xsl:if test="outroTratamento != ''">
							<xsl:value-of select="outroTratamento " />
						</xsl:if>)
						</td>
					</tr>
					</xsl:if>
					<xsl:if test="desfecho != ''">
					<tr>
						<td>(&#160;Desfecho: <xsl:value-of select="desfecho " />)</td>
					</tr>
					</xsl:if>
					</table>
				</td>
			</tr>
			<tr bgcolor="#8888BB">
				<td align="left">Riscos para TB MDR: </td>
				<td><xsl:value-of select="riscoTbMdr" /></td>
			</tr>
			<tr bgcolor="#CCCCFF">
				<td align="left">Cicatriz BCG: </td>
				<td><xsl:value-of select="cicatrizBcg" /></td>
			</tr>
			<tr bgcolor="#8888BB">
				<td align="left">Internado nos últimos 2 anos: </td>
				<td><xsl:value-of select="internadoUltimosAnos" /></td>
			</tr>
			<tr bgcolor="#CCCCFF">
				<td align="left">Co-morbidades: </td>
				<td><table border="0">
					<tr>
						<td><xsl:value-of select="comorbidades" /></td>
					</tr>
					<tr>
						<td>(Quais: 
							<xsl:if test="transplantes != ''">
								<xsl:value-of select="transplantes"/>
							</xsl:if>
							<xsl:if test="imunossupressor != ''">
								, <xsl:value-of select="imunossupressor"/>
							</xsl:if>
							<xsl:if test="diabetes != ''">
								, <xsl:value-of select="diabetes"/>
							</xsl:if>
							<xsl:if test="imunossupressor != ''">
								, <xsl:value-of select="imunossupressor"/>
							</xsl:if>
							<xsl:if test="sarcoidose != ''">
								, <xsl:value-of select="sarcoidose"/>
							</xsl:if>
							<xsl:if test="silicose != ''">
								, <xsl:value-of select="silicose"/>
							</xsl:if>
							<xsl:if test="ulcera != ''">
								, <xsl:value-of select="ulcera"/>
							</xsl:if>
							<xsl:if test="rcu != ''">
								, <xsl:value-of select="rcu"/>
							</xsl:if>
							<xsl:if test="doencaHepaticaCronica != ''">
								, <xsl:value-of select="doencaHepaticaCronica"/>
							</xsl:if>
							<xsl:if test="insuficienciaRenalCronica != ''">
								, <xsl:value-of select="insuficienciaRenalCronica"/>
							</xsl:if>
							<xsl:if test="cancer != ''">
								, <xsl:value-of select="cancer"/>
							</xsl:if>							
							<xsl:if test="infeccaoHiv != ''">
								, <xsl:value-of select="infeccaoHiv"/>
							</xsl:if>
							<xsl:if test="dpoc != ''">
								, <xsl:value-of select="dpoc"/>
							</xsl:if>
							<xsl:if test="asmaBronquica != ''">
								, <xsl:value-of select="asmaBronquica"/>
							</xsl:if>
							<xsl:if test="outras != ''">
								, <xsl:value-of select="outras"/>
							</xsl:if>
							<xsl:if test="quaisComorbidadesOutras != ''">
								, <xsl:value-of select="quaisComorbidadesOutras"/>
							</xsl:if>
							<xsl:if test="nenhumaAlteracao != ''">
								, <xsl:value-of select="nenhumaAlteracao"/>
							</xsl:if>)
						</td>
					</tr>
					</table>
				</td>
			</tr>
			<tr bgcolor="#8888BB">
				<td align="left">Sinais e Sintomas: </td>
				<td><table border="0">
					<tr>
						<td><xsl:value-of select="sinaisSintomas" /></td>
					</tr>
					<xsl:if test="sinais ='Sim'">
					<tr>
						<td>(Quais:	
							<xsl:if test="tosse != ''">
								<xsl:value-of select="tosse " />
							</xsl:if>
							<xsl:if test="expectoracao != ''">
								<xsl:value-of select="expectoracao " />
							</xsl:if>
							<xsl:if test="hemoptise != ''">
								<xsl:value-of select="hemoptise " />
							</xsl:if>
							<xsl:if test="escarro != ''">
								<xsl:value-of select="escarro " />
							</xsl:if>
							<xsl:if test="dor != ''">
								<xsl:value-of select="dor " />
							</xsl:if>
							<xsl:if test="febre != ''">
								<xsl:value-of select="febre " />
							</xsl:if>
							<xsl:if test="sudorese != ''">
								<xsl:value-of select="sudorese " />
							</xsl:if>
							<xsl:if test="hiporexia != ''">
								<xsl:value-of select="hiporexia " />
							</xsl:if>
							<xsl:if test="emagrecimento != ''">
								<xsl:value-of select="semagrecimento " />
							</xsl:if>
							<xsl:if test="cansaco != ''">
								<xsl:value-of select="cansaco " />
							</xsl:if>
							<xsl:if test="rouquidao != ''">
								<xsl:value-of select="rouquidao " />
							</xsl:if>
							<xsl:if test="linfadenomegalia != ''">
								<xsl:value-of select="linfadenomegalia " />
							</xsl:if>
							<xsl:if test="faltaAr != ''">
								<xsl:value-of select="faltaAr " />
							</xsl:if>
							<xsl:if test="faltaPeso != ''">
								<xsl:value-of select="faltaPeso " />
							</xsl:if>
							<xsl:if test="chiado != ''">
								<xsl:value-of select="chiado " />
							</xsl:if>
							<xsl:if test="outros != ''">
								<xsl:value-of select="outros " />
							</xsl:if>
							<xsl:if test="outrosSintomas != ''">
								<xsl:value-of select="outrosSintomas " />
							</xsl:if>
							<xsl:if test="assintomatico != ''">
								<xsl:value-of select="assintomatico " />
							</xsl:if>)
						</td>
						</tr>
						</xsl:if>
					</table>
				</td>
			</tr>
			<tr bgcolor="#CCCCFF">
				<td align="left">Exame físico: </td>
				<td><table border="0">
					<tr>
						<td><xsl:value-of select="exameFisico" /></td>
					</tr>
					<xsl:if test="alteracoesExameFisico != ''">
					<tr>
						<td>(Alterações: <xsl:value-of select="alteracoesExameFisico " />)</td>
					</tr>
					</xsl:if>
					</table>
				</td>
			</tr>
			<tr bgcolor="#8888BB">
				<td align="left">Resultado HIV: </td>
				<td><xsl:value-of select="resultadoAntiHiv" /></td>
			</tr>
			<tr bgcolor="#CCCCFF">
				<td align="left">Probabilidade de tuberculose Pleural: </td>
				<td><xsl:value-of select="probabilidadeSemAvaliacao" /></td>
			</tr>
			<tr bgcolor="#8888BB">
				<td align="left">Observações: </td>
				<td><xsl:value-of select="observacoes" /></td>
			</tr>
			<tr bgcolor="#CCCCFF">
				<td align="left">Telerradiografia de tórax: </td>
				<td><table border="0">
					<tr>
						<td><xsl:value-of select="telerradiografia" /></td>
					</tr>
					<xsl:if test="txt_diaExame != ''">
						<xsl:if test="txt_mesExame != ''">
							<xsl:if test="txt_anoExame != ''">
							<tr>
								<td>(Data: <xsl:value-of select="txt_diaExame " />/
									   <xsl:value-of select="txt_mesExame " />/
									   <xsl:value-of select="txt_anoExame " />)
								</td>
							</tr>
							<!--<tr>
								<td>(Área Acometida: <xsl:value-of select="paciente[last()]/areaAcometida " />)</td>
							</tr>-->
							</xsl:if>
						</xsl:if>
					</xsl:if>
					<xsl:if test="selecionouAreaAcometida != 'falso'">
					<tr>
						<td> área acometida:
						<xsl:if test="superior != ''">
							<xsl:value-of select="superior" />(
						<xsl:if test="superiorEsquerdo != '' ">
							<xsl:value-of select="superiorEsquerdo" />,
						</xsl:if>
						<xsl:if test="superiorDireito != '' ">
							<xsl:value-of select="superiorDireito" />
						</xsl:if>
						</xsl:if>
						)
						<xsl:if test="medio != ''">
							;<xsl:value-of select="medio" />(
						<xsl:if test="medioEsquerdo != '' ">
							<xsl:value-of select="medioEsquerdo" />,
						</xsl:if>
						<xsl:if test="medioDireito != '' ">
							<xsl:value-of select="medioDireito" />
						</xsl:if>
						</xsl:if>
						)
						<xsl:if test="inferior != ''">
							;<xsl:value-of select="inferior" />(
						<xsl:if test="inferiorEsquerdo != '' ">
							<xsl:value-of select="inferiorEsquerdo" />,
						</xsl:if>
						<xsl:if test="inferiorDireito != '' ">
							<xsl:value-of select="inferiorDireito" />						
						</xsl:if>
						)
						</xsl:if>
						</td>
					</tr>					
					</xsl:if>
					</table>
				</td>
			</tr>
			<tr bgcolor="#8888BB">
				<td align="left">Volume do derrame pleural: </td>
				<td><xsl:value-of select="volumeDerramePleural" /></td>
			</tr>
			<tr bgcolor="#CCCCFF">
				<td align="left">Derrame pleural livre: </td>
				<td><xsl:value-of select="derramePleuralLivre" /></td>
			</tr>
			<tr bgcolor="#8888BB">
				<td align="left">Associação com alterações pulmonares: </td>
				<td><table border="0">
					<tr>
						<td><xsl:value-of select="associacaoAlteracoesPulmonares" /></td>
					</tr>
					<xsl:if test="qualAssociacao != ''">
					<tr>
						<td>(Qual: <xsl:value-of select="qualAssociacao " />)</td>
					</tr>
					</xsl:if>
					</table>
				</td>
			</tr>
			<tr bgcolor="#CCCCFF">
				<td align="left">Outras alterações pulmonares: </td>
				<td><table border="0">
					<tr>
						<td><xsl:value-of select="outrasAlteracoes" /></td>
					</tr>
					<xsl:if test="qualAlteracao != ''">
					<tr>
						<td>(Qual: <xsl:value-of select="qualAlteracao " />)</td>
					</tr>
					</xsl:if>
					</table>
				</td>
			</tr>
			<tr bgcolor="#8888BB">
				<td align="left">Fez prova tuberculínica (PT) reatora: </td>
				<td><table border="0">
					<tr>
						<td><xsl:value-of select="provaTuberculinicaReatora" /></td>
					</tr>
					<xsl:if test="txt_diaProva != ''">
						<xsl:if test="txt_mesProva != ''">
							<xsl:if test="txt_anoProva != ''">
							<tr>
								<td>(Data : <xsl:value-of select="txt_diaProva " />/
									   <xsl:value-of select="txt_mesProva " />/
									   <xsl:value-of select="txt_anoProva " />)
								</td>
							</tr>
							</xsl:if>
						</xsl:if>
					</xsl:if>
					<tr>
					<xsl:if test="txt_diaLeitura != ''">
						<xsl:if test="txt_mesLeitura != ''">
							<xsl:if test="txt_anoLeitura != ''">
							<tr>
								<td>(Data da aplicacão: <xsl:value-of select="txt_diaLeitura " />/
									   <xsl:value-of select="txt_mesLeitura " />/
									   <xsl:value-of select="txt_anoLeitura " />)
								</td>
							</tr>
							</xsl:if>
						</xsl:if>
					</xsl:if>					</tr>
					<tr>
						<td>(Milímetros de enduração: <xsl:value-of select="milimetrosEnduracao " />)</td>
					</tr>
					<tr>
					<xsl:if test="txt_diaProva != ''">
						<xsl:if test="txt_mesProva != ''">
							<xsl:if test="txt_anoProva != ''">
							<tr>
								<td>(Data da Leitura: <xsl:value-of select="txt_diaProva " />/
									   <xsl:value-of select="txt_mesProva " />/
									   <xsl:value-of select="txt_anoProva " />)
								</td>
							</tr>
							</xsl:if>
						</xsl:if>
					</xsl:if>
					</tr>
					<tr>
						<td>(Leitor: <xsl:value-of select="leitor " />)</td>
					</tr>
					</table>
				</td>
			</tr>
			<tr bgcolor="#CCCCFF">
				<td align="left">Resultado citometria líquido pleural (células mononucleares): </td>
				<td><xsl:value-of select="resultadoCiometria" /></td>
			</tr>
			<tr bgcolor="#8888BB">
				<td align="left">Resultado proteínas no líquido pleural: </td>
				<td><xsl:value-of select="resultadoProteinas" /></td>
			</tr>
			<tr bgcolor="#CCCCFF">
				<td align="left">Resultado da razão proteína LP/proteína soro: </td>
				<td><xsl:value-of select="resultadoRazaoProteina" /></td>
			</tr>
			<tr bgcolor="#8888BB">
				<td align="left">Resultado da razão LDH LP/proteína soro: </td>
				<td><xsl:value-of select="resultadoRazaoLdh" /></td>
			</tr>
			<tr bgcolor="#CCCCFF">
				<td align="left">BAAR LP: </td>
				<td><xsl:value-of select="baarLp" /></td>
			</tr>
			<tr bgcolor="#8888BB">
				<td align="left">BAAR escarro (1ª amostra): </td>
				<td><table border="0">
					<tr>
						<td><xsl:value-of select="baarEscarro1" /></td>
					</tr>
					<xsl:if test="intensidade1 != ''">
					<tr>
						<td>(Qual a intensidade: <xsl:value-of select="intensidade1 " />)</td>
					</tr>
					</xsl:if>
					</table>
				</td>
			</tr>
			<tr bgcolor="#CCCCFF">
				<td align="left">BAAR escarro (2ª amostra): </td>
				<td><table border="0">
					<tr>
						<td><xsl:value-of select="baarEscarro2" /></td>
					</tr>
					<xsl:if test="intensidade2 != ''">
					<tr>
						<td>(Qual a intensidade: <xsl:value-of select="intensidade2 " />)</td>
					</tr>
					</xsl:if>
					</table>
				</td>
			</tr>
			<tr bgcolor="#8888BB">
				<td align="left">BAAR escarro induzido: </td>
				<td><table border="0">
					<tr>
						<td><xsl:value-of select="baarEscarroInduzido" /></td>
					</tr>
					<xsl:if test="intensidadeInduzido != 'NA'">
					<tr>
						<td>(Qual a intensidade: <xsl:value-of select="intensidadeInduzido " />)</td>
					</tr>
					</xsl:if>
					</table>
				</td>
			</tr>
			<tr bgcolor="#CCCCFF">
				<td align="left">ADA líquido pleural: </td>
				<td><table border="0">
					<tr>
						<td><xsl:value-of select="adaLiquidoPleural" /></td>
					</tr>
					<xsl:if test="quantidade != ''">
					<tr>
						<td>(Quantidade: <xsl:value-of select="quantidade " />UI/mL)</td>
					</tr>
					</xsl:if>
					</table>
				</td>
			</tr>
			<tr bgcolor="#8888BB">
				<td align="left">Probabilidade de tuberculose com a avaliação complementar: </td>
				<td><xsl:value-of select="probabilidadeComAvaliacao" /></td>
			</tr>
			<tr bgcolor="#CCCCFF">
				<td align="left">Cultura para microbactérias no LP: </td>
				<td><table border="0">
					<tr>
						<td><xsl:value-of select="cultura" /></td>
					</tr>
					<xsl:if test="metodo != ''">
					<tr>
						<td>(Método: <xsl:value-of select="metodo " />)</td>
					</tr>
					<tr>
						<td>(Resultado: <xsl:value-of select="resultado " />)</td>
					</tr>
						<xsl:if test="tipificacao != ''">
						<tr>
							<td>(Tipificaçao: <xsl:value-of select="tipificacao " />)</td>
						</tr>
						</xsl:if>
					</xsl:if>
					</table>
				</td>
			</tr>
			<tr bgcolor="#8888BB">
				<td align="left">Resultado do exame histopatológico: </td>
				<td><xsl:value-of select="resultadoExameHistopatologico" /></td>
			</tr>
			<tr bgcolor="#CCCCFF">
				<td align="left">Cultura para microbactérias escarro: </td>
				<td><table border="0">
					<tr>
						<td><xsl:value-of select="metodoCultura" /></td>
					</tr>
					<xsl:if test="metodoCultura != ''">
					<tr>
						<td>(Método: <xsl:value-of select="metodoCultura " />)</td>
					</tr>
					<tr>
						<td>(Resultado: <xsl:value-of select="resultadoCultura " />)</td>
					</tr>
						<xsl:if test="tipificacaoCultura != ''">
						<tr>
							<td>(Tipificaçao: <xsl:value-of select="tipificacaoCultura " />)</td>
						</tr>
						</xsl:if>
					</xsl:if>
					</table>
				</td>
			</tr>
			<tr bgcolor="#8888BB">
				<td align="left">Sorologia LP : </td>
				<td><table border="0">
					<tr>
						<td><xsl:value-of select="sorologiaLp" /></td>
					</tr>
					<xsl:if test="antigenos != ''">
					<tr>
						<td>(Antígenos: <xsl:if test="antigenos[1] != ''">
											<xsl:value-of select="antigenos[1] " />
										</xsl:if>
										<xsl:if test="antigenos[2] != ''">
											,<xsl:value-of select="antigenos[2] " />
										</xsl:if>
										<xsl:if test="antigenos[3] != ''">
											,<xsl:value-of select="antigenos[3] " />
										</xsl:if>
										<xsl:if test="antigenos[4] != ''">
											,<xsl:value-of select="antigenos[4] " />
										</xsl:if>
										<xsl:if test="antigenos[5] != ''">
											,<xsl:value-of select="antigenos[5] " />
										</xsl:if>
							)
						</td>
					</tr>
					<tr>
						<td>(Resultado: <xsl:value-of select="resultadoSorologia " />)</td>
					</tr>
					</xsl:if>
					</table>
				</td>
			</tr>
			<tr bgcolor="#CCCCFF">
				<td align="left">PCR: </td>
				<td><table border="0">
					<tr>
						<td><xsl:value-of select="pcr" /></td>
					</tr>
					<xsl:if test="tecnicaUtilizada != ''">
					<tr>
						<td>(Técnica utilizada: <xsl:value-of select="tecnicaUtilizada " />)</td>
					</tr>
					<tr>
						<td>(Resultado: <xsl:value-of select="resultadoPcr " />)</td>
					</tr>
					</xsl:if>
					</table>
				</td>
			</tr>
			<tr bgcolor="#8888BB">
				<td align="left">Outro exame: </td>
				<td><table border="0">
					<tr>
						<td><xsl:value-of select="outroExame" /></td>
					</tr>
					<xsl:if test="exame != ''">
					<tr>
						<td>(Exame: <xsl:value-of select="exame " />)</td>
					</tr>
					<tr>
						<td>(Resultado: <xsl:value-of select="resultadoExame " />)</td>
					</tr>
					</xsl:if>
					</table>
				</td>
			</tr>
			<tr bgcolor="#CCCCFF">
				<td align="left">Probabilidade de tuberculose após exames: </td>
				<td><xsl:value-of select="probabilidadeAposExames" /></td>
			</tr>

<!--			<tr bgcolor="#8888BB">
				<td align="right">Desfecho do caso se TB: </td>
				<td><xsl:value-of select="paciente [last()]/desfechoCaso" /></td>
			</tr>
			<tr bgcolor="#CCCCFF">
				<td align="right">Desfecho se contato: </td>
				<td><xsl:value-of select="paciente [last()]/desfechoContato" /></td>
			</tr>
			<tr bgcolor="#8888BB">
				<td align="right">Desfecho se SR: </td>
				<td><xsl:value-of select="paciente [last()]/desfechoSr" /></td>
			</tr>
			<tr bgcolor="#CCCCFF">
				<td align="right">Desfecho se suspeito: </td>
				<td><xsl:value-of select="paciente [last()]/desfechoSuspeito" /></td>
			</tr>
-->
			<tr bgcolor="#8888BB">
				<td align="left">Data da última consulta/VD: </td>
				<!--<xsl:if test="paciente[last()]/txt_diaUltima != ''">
					<xsl:if test="paciente[last()]/txt_mesUltima != ''">
						<xsl:if test="paciente[last()]/txt_anoUltima != ''">-->
							<td>
								   (<xsl:value-of select="txt_diaUltima " />/
								   <xsl:value-of select="txt_mesUltima " />/
								   <xsl:value-of select="txt_anoUltima " />)
							</td>
				<!--		</xsl:if>	
					</xsl:if>
				</xsl:if>-->
			</tr>
			<tr bgcolor="#CCCCFF">
				<td align="left">Observações: </td>
				<td><xsl:value-of select="observacoesUltima" /></td>
			</tr>
			<tr>
				<td><BR/><BR/><BR/></td>
			</tr>
		</xsl:for-each>
		</table>
		</center>
	</body>
</html>
</xsl:template>
</xsl:stylesheet>
