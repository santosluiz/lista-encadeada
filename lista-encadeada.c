#include <stdio.h>
#include <stdlib.h>
#define TAM 10
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct listaDados {
	int *vetPont;
	int qtd;
	int escolha;
} lista[TAM];
	
int menu(); 

int insereDados(struct listaDados *lista);
void listarDados(struct listaDados *lista);
void listarDadosOrdenados(struct listaDados *lista);

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
				exit(0);
				break;
			}
			
			default : {
				printf("opcao invalida\n");
				break;
			}
		} 
	} while(opcaoSelecionada != 4);
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
	
	for(j=0; j<TAM; j++){
		
		printf("Posicao: %d\n", j+1);
		
		if(lista[j].qtd > 0){
			printf("Itens: %d\n", lista[j].qtd);
			
			printf("Valores: ");
			for(i=0; i<lista[j].qtd; i++){
				printf("%d", lista[j].vetPont[i]);			
				
				if(i < (lista[j].qtd-1)){
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
	
}
