#include <stdio.h>
#include <stdlib.h>
#define TAM 10

struct listaDados {
	int *vetPont;
	int *vetOrdenado;
	int qtd;
	int escolha;
} lista[TAM];
	
int menu(); 

int insereDados(struct listaDados *lista);
void listarDados(struct listaDados *lista);
void listarDadosOrdenados(struct listaDados *lista);
void excluirNumero(struct listaDados *lista);

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
				excluirNumero(lista);
				break;
			}
			
			case 6 : {
				exit(0);
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
	printf("1- Inserir Dados\n2- Listar Dados\n3- Listar de Forma Ordenada\n4- Sair\n");
	scanf("%d", &opcao);	
	
	return opcao;
}

int insereDados(struct listaDados *lista){
		
	int i, j, aux;	
	
	printf("De 1 a 10, qual vetor voce deseja escolher?");
	scanf("%d", &aux);
		
	aux -= 1;
	lista[aux].escolha = aux;	
	
	if(lista[aux].vetPont > 0){
		
		printf("Estrutura já preenchida");
		return 0;		
		
	} else {					
	
		printf("Digite a qtd de elementos que voce deseja inserir:");
		scanf("%d", &lista[aux].qtd);
		
		lista[aux].vetPont = (int *) malloc(lista[aux].qtd * sizeof(int));
			
		printf("Agora, insira %d numeros no vetor %d\n", lista[aux].qtd, (lista[aux].escolha+1));
			
		for(i=0; i<lista[aux].qtd; i++){
			scanf("%d", &lista[aux].vetPont[i]);
		} 
	}
}

void listarDados(struct listaDados *lista){
	
	int i, j;
	
	for(i=0; i<TAM; i++){
		
		printf("Posicao: %d\n", i+1);
		
		if(lista[i].qtd > 0){
			printf("Itens: %d\n", lista[i].qtd);
			
			printf("Valores: ");
			for(j=0; j<lista[i].qtd; j++){
				printf("%d", lista[i].vetPont[j]);			
				
				if(j < (lista[i].qtd-1)){
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

	int i, j, aux;
	
	for(i=0; i<TAM; i++){
		lista[i].vetOrdenado = (int *) malloc(lista[i].qtd * sizeof(int));			
		for(j=0; j<lista[i].qtd; j++){
			lista[i].vetOrdenado[j] = lista[i].vetPont[j];	
		}
	} 	
	
	for(i=0; i<TAM; i++){		
		for(j=i+1; j<lista[i].qtd; j++){	
			if( lista[i].vetOrdenado[i] > lista[i].vetOrdenado[j]){
				aux = lista[i].vetOrdenado[i];	
				lista[i].vetOrdenado[i] = lista[i].vetOrdenado[j];
				lista[i].vetOrdenado[j] = aux;				
			}	
		}
	}		
		
	for(i=0; i<TAM; i++){
			printf("Posicao: %d\n", i+1);
	
			if(lista[i].qtd > 0){
				printf("Itens: %d\n", lista[i].qtd);
				
				printf("Valores: ");
				for(j=0; j<lista[i].qtd; j++){
					printf("%d", lista[i].vetOrdenado[j]);			
					
					if(j < (lista[i].qtd-1)){
						printf(" - ");
					}
				} 		
				
			} else {
				printf("Itens: 0\nValores: 0");
			}			
		
		puts("\n\n");
	} 
}	

void excluirNumero(struct listaDados *lista){
	
	int i, j, num, vetEscolhido;
	int valorNull = 1111;
	
	printf("Qual vetor voce deseja escolher?");
	scanf("%d", &vetEscolhido);	
	vetEscolhido -= 1;	
	
	printf("Qual valor deseja apagar?");
	scanf("%d", &num);		
	
	for(j=0; j<lista[vetEscolhido].qtd; j++){
		
		if(lista[vetEscolhido].vetPont[j] == num){
			lista[vetEscolhido].vetPont[j] = valorNull;
		} else {
			printf("Numero inexistente\n");
			break;
		}
	}
}
	








