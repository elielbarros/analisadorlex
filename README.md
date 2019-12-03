# analisadorlex
Trabalho faculdade

1º:
Criado uma estrutura que serve como tabela de palavras válidas.
As palavras estão ligadas dinamicamente

2º:
Alfabeto, que será utilizado quando o codigo verificar a palavra "num", para poder criar as variaveis que assim forem declaradas no txt

3º:
Duas variaveis de controle global
Uma para recolher o caracter invalido da variavel que está sendo criada devido a declaração inicial "num"
Outra para dizer se a linguagem eh totalmente valida

4º:
Declaração de todas as funções que foram necessarias

5º:
main
Cria a cabeça da estrutura dinamica (tabela de palavras validas)
Lê o table.txt que contem todas as palavras validas e armazena na tabela de palavras validas(estrutura dinamica)
Valida a linguagem passando como informação para a função o topo da estrutura

6º:
função lerTable
Responsavel por ler as palavras validas do table.txt e inserir na estrutura dinamica

7º:
inserirTable
Responsavel por receber as palavras declaradas no teste.txt e inserir na tabela de palavras validas(table a estrutura dinamica)
São as palavras que vem logo depois da palavra "num"

8º:
imprimirTable
Responsavel por imprimir a tabela de palavras validas, foi feito pra me ajudar a saber se a tabela estava certa ou nao

9º:
compTable
Responsavel por comparar as palavras encontradas no teste.txt com as palavras validas e retornar 1 ou 0, se for 1 eh pq a palavra comparada está na tabela de palavras validas, se 0 então não está na tabela de palavras validas... eh retornado para verificaToken

10º:
compAlfabeto
Responsavel por comparar letra a letra da palavra declarada como variavel no teste.txt... sao as palavras que vem logo depois do "num"
Caso nao tenha uma letra no alfabeto, retorna 0, caso contrario retorna 1 para a função verificaVariavel

11º:
validarLinguagem
Responsavel por abrir o arquivo teste.txt e ler o que tem nele e passar o que foi lido de cada linha lida para a função limpaFrase
Responsavel tbm de dizer se o teste.txt eh totalmente valido ou nao
Professor, aqui é necessário alterar o nome do arquivo fonte... de 1 para 2 ou de 2 para 1.

12º:
limpaFrase
Responsavel por tirar tokens das palavras validas que aparecem nas frases lidas
No lugar delas é posto um espaço em forma de controle
E logo depois retira esses espaços postos
Responsavel por passar o resultado para a função cuidaAspas

13º:
cuidaAspas
Resposavel por desconsiderar tudo que está entre aspas e passar um erro, caso nao tenha fechamento de aspas
Ao fim, chama a função cuidaSpace

14º:
cuidaSpace
Redundante, mas eh uma função pra remover espaços
Durante a programação, fui observando que alguns espaços a mais eram postos na frase... essa função resolve isso
Ao fim, chama a função removeEstranho

15º:
removeEstranho
Responsável por remover algumas palavras formadas de espaço sem nenhuma palavra ou nada diferente de espaço
Ao fim, chama a função verificaPalavra

16º:
tokenizador
Responsável por reconhecer na frase se a primeira palavra eh "num" e chamar a função verificaVariavel, enviando a frase inteira para essa função
Além disso, é responsável de enviar as outras frases para a função verificaToken

17º:
verificaVariavel
Resposável pela frase que contém a palavra "num"
Através da função strtok, removo as importancias e trato os tokens formados
Cada token eh uma nova variavel(palavra) a ser comparada com o alfabeto, pra saber se existe alguma letra que nao pertence ao nosso alfabeto. Caso a palavra corresponda ao alfabeto, essa palavra eh inserida na tabela de palavras validas.
Caso alguma letra nao esteja no nosso alfabeto, retorna um erro para "validacao.txt"

18º:
verificaToken
Verifica as palavras enviadas pela função "tokenizador". As palavras recebidas são comparadas com a tabela de palavras validas, caso alguma palavra não esteja na nossa tabela de palavras validas, retorna um erro para "validacao.txt"
