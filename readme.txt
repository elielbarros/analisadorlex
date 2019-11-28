1�:
Criado uma estrutura que serve como tabela de palavras v�lidas.
As palavras est�o ligadas dinamicamente

2�:
Alfabeto, que ser� utilizado quando o codigo verificar a palavra "num", para poder criar as variaveis que assim forem declaradas no txt

3�:
Duas variaveis de controle global
Uma para recolher o caracter invalido da variavel que est� sendo criada devido a declara��o inicial "num"
Outra para dizer se a linguagem eh totalmente valida

4�:
Declara��o de todas as fun��es que foram necessarias

5�:
main
Cria a cabe�a da estrutura dinamica (tabela de palavras validas)
L� o table.txt que contem todas as palavras validas e armazena na tabela de palavras validas(estrutura dinamica)
Valida a linguagem passando como informa��o para a fun��o o topo da estrutura

6�:
fun��o lerTable
Responsavel por ler as palavras validas do table.txt e inserir na estrutura dinamica

7�:
inserirTable
Responsavel por receber as palavras declaradas no teste.txt e inserir na tabela de palavras validas(table a estrutura dinamica)
S�o as palavras que vem logo depois da palavra "num"

8�:
imprimirTable
Responsavel por imprimir a tabela de palavras validas, foi feito pra me ajudar a saber se a tabela estava certa ou nao

9�:
compTable
Responsavel por comparar as palavras encontradas no teste.txt com as palavras validas e retornar 1 ou 0, se for 1 eh pq a palavra comparada est� na tabela de palavras validas, se 0 ent�o n�o est� na tabela de palavras validas... eh retornado para verificaToken

10�:
compAlfabeto
Responsavel por comparar letra a letra da palavra declarada como variavel no teste.txt... sao as palavras que vem logo depois do "num"
Caso nao tenha uma letra no alfabeto, retorna 0, caso contrario retorna 1 para a fun��o verificaVariavel

11�:
validarLinguagem
Responsavel por abrir o arquivo teste.txt e ler o que tem nele e passar o que foi lido de cada linha lida para a fun��o limpaFrase
Responsavel tbm de dizer se o teste.txt eh totalmente valido ou nao

12�:
limpaFrase
Responsavel por tirar tokens das palavras validas que aparecem nas frases lidas
No lugar delas � posto um espa�o em forma de controle
E logo depois retira esses espa�os postos
Responsavel por passar o resultado para a fun��o cuidaAspas

13�:
cuidaAspas
Resposavel por desconsiderar tudo que est� entre aspas e passar um erro, caso nao tenha fechamento de aspas
Ao fim, chama a fun��o cuidaSpace

14�:
cuidaSpace
Redundante, mas eh uma fun��o pra remover espa�os
Durante a programa��o, fui observando que alguns espa�os a mais eram postos na frase... essa fun��o resolve isso
Ao fim, chama a fun��o removeEstranho

15�:
removeEstranho
Respons�vel por remover algumas palavras formadas de espa�o sem nenhuma palavra ou nada diferente de espa�o
Ao fim, chama a fun��o verificaPalavra

16�:
tokenizador
Respons�vel por reconhecer na frase se a primeira palavra eh "num" e chamar a fun��o verificaVariavel, enviando a frase inteira para essa fun��o
Al�m disso, � respons�vel de enviar as outras frases para a fun��o verificaToken

17�:
verificaVariavel
Respos�vel pela frase que cont�m a palavra "num"
Atrav�s da fun��o strtok, removo as importancias e trato os tokens formados
Cada token eh uma nova variavel(palavra) a ser comparada com o alfabeto, pra saber se existe alguma letra que nao pertence ao nosso alfabeto. Caso a palavra corresponda ao alfabeto, essa palavra eh inserida na tabela de palavras validas.
Caso alguma letra nao esteja no nosso alfabeto, retorna um erro para "validacao.txt"

18�:
verificaToken
Verifica as palavras enviadas pela fun��o "tokenizador". As palavras recebidas s�o comparadas com a tabela de palavras validas, caso alguma palavra n�o esteja na nossa tabela de palavras validas, retorna um erro para "validacao.txt"