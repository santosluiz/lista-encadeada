#include <stdio.h>
#include <stdlib.h>
#define TAM 10

struct listaDados {
	int *vetPont;
	int *vetOrdenado;
	int qtd;
	int contador;
	int escolha;
} lista[TAM];
	
int menu(); 

int insereDados(struct listaDados *lista);
void listarDados(struct listaDados *lista);
void listarDadosOrdenados(struct listaDados *lista);
void ordena(int i, struct listaDados *lista);
void excluirNumero(struct listaDados *lista);
void aumentarTamanho(struct listaDados *lista);
void sair(struct listaDados *lista);

int main(){

	int opcaoSelecionada;

	do{		
		opcaoSelecionada = menu();		
	
		switch(opcaoSelecionada){
			case 1 : {					
				insereDados(lista);				
				break;
			}  
			
			case 2 : {
				system("cls");
				listarDados(lista);				
				break;
			}
			
			case 3 : {
				system("cls");
				listarDadosOrdenados(lista);				
				break;
			}
			
			case 4 : {
				system("cls");
				excluirNumero(lista);
				break;
			}
			
			case 5 : {
				system("cls");
				aumentarTamanho(lista);
				break;
			}
			case 6 : {
				sair(lista);
				break;
			}
			
			default : {
				printf("opcao invalida\n");
				break;
			}
		} 
	} while(opcaoSelecionada != 6);
} 


int menu(){
	int opcao;
	
	printf(" --------------- MENU ---------------- \n");
	printf("1 - Inserir Numeros\n2 - Listar Numeros\n3 - Listar Numeros de Forma Ordenada\n4 - Listar Todos os Numeros de Forma Ordenada\n5 - Excluir Numero\n6 - Aumentar Tamanho de uma Estrutura\n7 - Sair\n");
	scanf("%d", &opcao);	
			
	return opcao;
}

int insereDados(struct listaDados *lista){
		
	int i, j, aux;	
	
	printf("De 1 a 10, qual vetor voce deseja escolher?");
	scanf("%d", &aux);
		
	aux -= 1;
	lista[aux].escolha = aux;	
	
	while(lista[aux].contador == 0){			    
    	printf("Digite a qtd de elementos que voce deseja inserir:");
    	scanf("%d", &lista[aux].qtd);
    	
		lista[aux].vetPont = (int *) malloc(lista[aux].qtd * sizeof(int));
    	
    	printf("Agora, insira um numero no vetor %d\n", (lista[aux].escolha+1));
        scanf("%d", &lista[aux].vetPont[0]);
        
        lista[aux].contador++;                
        return 0;
    } 
    
	if(lista[aux].contador == lista[aux].qtd){		
		printf("Estrutura cheia.");
		return 0;				
	} else {		
		printf("Agora, insira um numero no vetor %d\n", (lista[aux].escolha+1));
	    scanf("%d", &lista[aux].vetPont[lista[aux].contador]);
        lista[aux].contador++;		
	}
} 

void listarDados(struct listaDados *lista){
	
	int i, j;
	
	for(i=0; i<TAM; i++){
		
		printf("Posicao: %d\n", i+1);
		
		if(lista[i].contador > 0){
			printf("Itens: %d\n", lista[i].qtd);
			
			printf("Valores: ");
			for(j=0; j<lista[i].contador; j++){
				printf("%d", lista[i].vetPont[j]);			
				
				if(j < (lista[i].contador-1)){
					printf(" - ");
				}
			} 		
		} else {
			printf("Itens: 0\nValores: 0");
		}	
		
		puts("\n");
	}
}

void listarDadosOrdenados(struct listaDados *lista){

	int i;

	for(i=0; i<TAM; i++){
		ordena(i, lista);
	}

}	

void ordena(int i, struct listaDados *lista){
	
	int aux, j, c;
	int *vet;
	
	vet = (int *) malloc(lista[i].qtd * sizeof(int));
	
	for(j=0; j<lista[i].contador; j++){
		vet[j] = lista[i].vetPont[j];	
	}
	
	for(j=0; j<lista[i].contador; j++){	
		for(c=j+1; c<lista[i].contador; c++){		
			if(vet[j] > vet[c]){
    			aux = vet[j];
    			vet[j] = vet[c];
    			vet[c] = aux;
			}	
		}
	}
			
	printf("Posicao: %d\n", i+1);
		
	if(lista[i].contador > 0){
		printf("Itens: %d\n", lista[i].qtd);
			
		printf("Valores: ");
		for(j=0; j<lista[i].contador; j++){
			printf("%d", vet[j]);			
				
			if(j < (lista[i].contador-1)){
				printf(" - ");
			}
		} 		
	} else {
		printf("Itens: 0\nValores: 0");
	}	
		
	puts("\n");		
		
}
			


void excluirNumero(struct listaDados *lista){
	
	int i, j, num, vetEscolhido;
	int valorNull = 1111;
	
	printf("Qual vetor voce deseja escolher?");
	scanf("%d", &vetEscolhido);	
	vetEscolhido -= 1;	
	
	printf("Qual valor deseja apagar?");
	scanf("%d", &num);		
	
	for(j=0; j<lista[vetEscolhido].contador; j++){
		
		if(lista[vetEscolhido].vetPont[j] == num){
			lista[vetEscolhido].vetPont[j] = valorNull;
		} else {
			printf("Numero inexistente\n");
			break;
		}
	}
}
	

void aumentarTamanho(struct listaDados *lista){
	
	int i, j, vetEscolhido, aumento;
	int tamanho;
	
	printf("Qual vetor voce deseja escolher?");
	scanf("%d", &vetEscolhido);	
	vetEscolhido -= 1;	
	
	printf("Quantas posicoes deseja aumentar?");
	scanf("%d", &aumento);	
	
	aumento += lista[vetEscolhido].contador;
	
	//tamanho = sizeof(lista[vetEscolhido].vetPont)/sizeof(int);
	
	lista[vetEscolhido].vetPont = (int *) realloc(lista[vetEscolhido].vetPont,aumento);	
}

void sair(struct listaDados *lista){
	
	int i, j;
	
	for(i=0; i<TAM; i++){
		for(j=0; j<lista[i].qtd; j++){
			free(lista[i].vetPont);				
		}
	}
	
	system("cls");
	exit(0);	
}
