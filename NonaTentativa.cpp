#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define t 200
//-----------------------------------------------------------------------------------------------------------------
typedef struct tabela{
 char token[t];
 struct tabela *prox;
}table;
//-----------------------------------------------------------------------------------------------------------------
char alfabeto[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
'r', 's', 't', 'u', 'v', 'x', 'y', 'z','0','1','2','3','4','5','6','7','8','9','=','<','<','(',')','{','}',
'+','-','%',',',';','"','[',']','/',':','\0'};
//-----------------------------------------------------------------------------------------------------------------
char caracterInvalido;
int aval=1;
//-----------------------------------------------------------------------------------------------------------------
void inserirTable(table **topo, char s[]);
void lerTable(table **topo);
void imprimirTable(table *topo);
int compAlfabeto(char aux[]);
int compTable(table *topo, char aux[]);
void validarLinguagem(table **topo);
void limpaFrase(table **topo, char frase[]);
void cuidaAspas(table **topo, char frase[]);
void cuidaSpace(table **topo, char frase[]);
void removeEstranho(table **topo, char frase[]);
void tokenizador(table **topo, char frase[]);
void verificaVariavel(table **topo, char frase[]);
void verificaToken(table **topo, char frase[]);
//-----------------------------------------------------------------------------------------------------------------
int main(){
  table *topo=NULL;
  lerTable(&topo);
  validarLinguagem(&topo);
}
//-----------------------------------------------------------------------------------------------------------------
void lerTable(table **topo){
    FILE *file;
    char aux[t];

    file = fopen("table.txt","r");
    while(fscanf(file," %[^\n]s",&aux)!=EOF){
        inserirTable(&(*topo),aux);
    }
}
//-----------------------------------------------------------------------------------------------------------------
void inserirTable(table **topo, char palavra[]){
	table *novo;
	novo = (table*)malloc(sizeof(table));
    strcpy(novo->token,palavra);
    if(*topo == NULL){
        novo->prox=NULL;
        *topo = novo;
    }
    else {
        novo->prox = *topo;
        *topo = novo;
    }
}
//-----------------------------------------------------------------------------------------------------------------
void imprimirTable(table *topo){
    system("cls");
    if(topo == NULL){
        printf("Tabela vazia\n");
    }
    else {
        while(topo != NULL){
            printf("%s\n", topo->token);
            topo = topo->prox;
        }
	}
    //system("pause");
}
//-----------------------------------------------------------------------------------------------------------------
int compTable(table *topo, char aux[]){
	if(topo == NULL){
        printf("Tabela vazia\n");
    }
    else {
        while(topo != NULL){
            if(strcmp(aux,topo->token)==0){
                return 0;
            }
            topo = topo->prox;
        }
    }
    return 1;
}
//-----------------------------------------------------------------------------------------------------------------
int compAlfabeto(char aux[]){
    int i,j,control=0;
    for(i=0; i<strlen(aux) /*aux[i]!='\0'*/;i++){ //Faz percorrer a string enquanto nao chegar ao fim dela
        for(j=0; alfabeto[j]!='\0';j++){ // faz percorrer o alfabeto enquanto nao chegar ao fim dele
            if(aux[i]==alfabeto[j]){ // faz comparar cada palavra da string com as palavras do alfabeto
                control = 1; //variavel de controle, caso alguma palavra nao esteja no alfabeto
            }
        }
        if(control!=1){
            caracterInvalido = aux[i]; //Se nao der certo retorne 0 de falso e ponha a letra na variavel global char
            return 0;
        }
        control  = 0; //devolve zero para a variavel control
    }
    return 1; // aqui, caso control!=1 nao tenha sido verdade, retorna verdade pra função validar linguagem na parte if(compAlfabeto(tok)

}
//-----------------------------------------------------------------------------------------------------------------
void validarLinguagem(table **topo){
    FILE *file,*valid;
    char f_Lida[t], f_Nova[t], p_Lida;
    int i, j=0, controle;

    file = fopen("teste.txt","r");
    valid = fopen("validacao.txt","w");
    while(fscanf(file," %[^\n]s",&f_Lida)!=EOF){ // pega a primeira palavra até um espaço ou uma quebra de linha
    limpaFrase(&(*topo),f_Lida);
    }
    if(aval){
        fprintf(valid,"Linguagem valida");
    }
    fclose(valid);
}
//-----------------------------------------------------------------------------------------------------------------
void limpaFrase(table **topo, char frase[]){
	int i, j=0, controle, ante=0;
	char n_Frase[t];
	for(i=0; i<strlen(frase); i++){
		if( frase[i]=='('||
			frase[i]==')'||
			frase[i]=='{'||
			frase[i]=='}'||
			frase[i]=='/'||
			frase[i]=='*'||
			frase[i]=='-'||
			frase[i]=='+'||
			frase[i]=='='||
			frase[i]=='<'||
			frase[i]=='>'
		){
			frase[i] = ' ';
		}
		if(n_Frase[ante]==' '){
			if(frase[i] != ' '){
				n_Frase[j] = frase[i];
				ante=j;
				j++;
			}
		}else if(n_Frase[ante] != ' '){
			if(frase[i]==' '||frase[i]!=' '){
				n_Frase[j] = frase[i];
				ante=j;
				j++;
			}
		}
	}
	n_Frase[j] = '\0';
/*	if(n_Frase[0] ==' '&&n_Frase[1]=='\0'){
		
	}else{
		printf("Frase nova: %s\n", n_Frase);
	} */
	cuidaAspas(&(*topo),n_Frase);
}
//-----------------------------------------------------------------------------------------------------------------
void cuidaAspas(table **topo, char frase[]){
	FILE *valid;
	valid = fopen("validacao.txt","aw");
	
	int i, controle=0, j=0;
	char n_Frase[t];
	
	for(i=0; i<strlen(frase); i++){
		if(frase[i] == '"' && controle == 0){
			controle = 1;
		}
		else if(frase[i] == '"' && controle == 1){
			controle = 0;
		}
		else if(frase[i] != '"' && controle == 0){
		n_Frase[j] = frase[i];
		j++;	
		}
	}
	if(controle == 1){
		n_Frase[j] = '\0';
		fprintf(valid,"Nao houve fechamento de aspas na frase: %s\n", frase);
		aval = 0;
	}else{
		n_Frase[j] = '\0';
		//printf("Frase nova: %s\n", n_Frase);
	}
	cuidaSpace(&(*topo),n_Frase);
}
//-----------------------------------------------------------------------------------------------------------------
void cuidaSpace(table **topo, char frase[]){
	int i, ant=0, j=0;
	char n_Frase[t];
	for(i=0; i<strlen(frase); i++){
		if(n_Frase[ant]==' ' && frase[i] != ' '){
			n_Frase[j]=frase[i];
			ant=j;
			j++;
		}
		else if(n_Frase[ant]!=' '){
			if(frase[i]==' '||frase[i]!=' '){
				n_Frase[j]=frase[i];
				ant=j;
				j++;
			}
		}
	}
	n_Frase[j] = '\0';
	//printf("Frase nova: %s\n", n_Frase);
	removeEstranho(&(*topo),n_Frase);
}
//-----------------------------------------------------------------------------------------------------------------
void removeEstranho(table **topo, char frase[]){
	int i, controle=0, j=0;
	char n_Frase[t];
	for(i=0; i<strlen(frase); i++){
		if(frase[i]!=' '){
			controle = 1;
			i = strlen(frase);
		}
	}
	if(controle == 1){
		for(i=0; i<strlen(frase); i++){
			n_Frase[i] = frase[i];
			j++;
		}
		n_Frase[j] = '\0';
		//printf("Frase nova: %s\n", n_Frase);
		tokenizador(&(*topo),n_Frase);
	}
}
//-----------------------------------------------------------------------------------------------------------------
void tokenizador(table **topo, char frase[]){
	int i;
	char *token, n_Frase[t];
	strcpy(n_Frase,frase);
	token = strtok(frase, " ,");
	while(token != NULL){
		if(!strcmp(token,"num")){
			//printf("Nova frase: %s\n", n_Frase);
			verificaVariavel(&(*topo),n_Frase);
			break;
		}
		//printf("palavra tokenizada: %s\n", token);
		verificaToken(&(*topo),token);
		token = strtok(NULL, " ,");
	}
}
//-----------------------------------------------------------------------------------------------------------------
void verificaVariavel(table **topo, char frase[]){
	char *token;
	FILE *valid;
	valid = fopen("validacao.txt","aw");
	token = strtok(frase, " ,");
	while(token != NULL){
		if(strcmp(token,"num")){
			if(compAlfabeto(token)){
				//printf("Tokenizado: %s\n", token);
				inserirTable(&(*topo), token);
			}
			else{
				//printf("Tokenizado invalido: %s\n", token);
				fprintf(valid,"O caracter '%c' na palavra '%s' eh invalido\n", caracterInvalido, token);
				aval = 0;
			}
		}
		token = strtok(NULL, " ,");
	}
}
//-----------------------------------------------------------------------------------------------------------------
void verificaToken(table **topo, char palavra[]){
	FILE *valid;
	valid = fopen("validacao.txt","aw");
	if(compTable(*topo, palavra)){
		fprintf(valid,"A seguinte palavra '%s' não foi reconhecida\n", palavra);
		aval=0;
	}
}
//-----------------------------------------------------------------------------------------------------------------
