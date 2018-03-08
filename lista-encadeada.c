#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int menu(); 

int main(){

	int opcaoSelecionada;

	do{		
		opcaoSelecionada = menu();		
	
		switch(opcaoSelecionada){
			case 1 : {
				insereDados();
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
