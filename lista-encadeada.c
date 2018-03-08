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

void insereDados(struct listaDados *lista);

int main(){

	int opcaoSelecionada;

	do{		
		opcaoSelecionada = menu();		
	
		switch(opcaoSelecionada){
			case 1 : {
				insereDados(&lista);
				break;
			}  
			
			case 2 : {
				printf("opcao 2\n");
				break;
			}
			
			case 3 : {
				printf("opcao 3\n");
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
	printf("1- Inserir Dados 1 \n2- Opcao 2 \n3- Opcao 3 \n4- Sair\n");
	scanf("%d", &opcao);	
	
	return opcao;
}

void insereDados(struct listaDados *lista){
		
	int i, j, aux;
	int a = 0;
				
	printf("De 1 a 10, qual vetor voce deseja escolher?");
	scanf("%d", &aux);
		
	aux -= 1;
	lista[aux].escolha = aux;	
					
	printf("Digite a qtd de elementos que voce deseja inserir:");
	scanf("%d", &lista[aux].qtd);
	
	lista[aux].vetPont = (int *) malloc(lista[aux].qtd * sizeof(int));
		
	printf("Agora, insira %d numeros no vetor %d\n", lista[aux].qtd, lista[aux].escolha);
		
	for(i=0; i<lista[aux].qtd; i++){
		scanf("%d", &lista[aux].vetPont[i]);
	} 
}
