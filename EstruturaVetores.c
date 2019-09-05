#include <stdio.h>
#include <stdlib.h>
#define TAM 10
#include "EstruturaVetores.h"

/*
Objetivo: criar estrutura auxiliar na posicao 'posicao'.
com tamanho 'tamanho'
Rertono (int)
    SUCESSO - criado com sucesso
   - JA_TEM_ESTRUTURA_AUXILIAR - j� tem estrutura na posicao
   - POSICAO_INVALIDA - posicao inv�lida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espa�o de mem�ria
   - TAMANHO_INVALIDO - o tamanho tem inteiro maior ou igual a 1
*/
int criarEstruturaAuxiliar(int tamanho, int posicao){
	//retorno = SEM_ESPACO_DE_MEMORIA; ???
    int retorno = 0;

    if(ehPosicaoValida(posicao)){    	//posicao valida
        posicao -= 1;

      if(lista[posicao].vetPont != NULL){	//Ja existe estrutura

        if(tamanho > 0){				//tamanho valido
						lista[posicao].vetPont = (int *) malloc(tamanho * sizeof(int));
						lista[posicao].qtd = tamanho;
        		lista[posicao].contador = 0;
        		retorno = SUCESSO;
				} else {
					retorno = TAMANHO_INVALIDO;
				}
			} else {
    		retorno = JA_TEM_ESTRUTURA_AUXILIAR;
			}
		} else {
			retorno = POSICAO_INVALIDA;
		}

  return retorno;

}


/*
Objetivo: inserir n�mero 'valor' na estrutura auxiliar da posicao 'posicao'
	Rertono (int)
	    SUCESSO - inserido com sucesso
	    SEM_ESPACO - n�o tem espa�o
	    SEM_ESTRUTURA_AUXILIAR - N�o tem estrutura auxiliar
	    POSICAO_INVALIDA - posicao inv�lida para estrutura auxiliar
	CONSTANTES
*/
int inserirNumeroEmEstrutura (int valor, int posicao) {

    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;

    if(ehPosicaoValida(posicao))
        if(lista[posicao].vetPont != NULL) {
          if(lista[posicao].contador != lista[posicao].qtd) {
            	lista[posicao].vetPont[lista[posicao].contador] = valor;
            	lista[aux].contador += 1;
            	retorno = SUCESSO;

          } else {
              retorno = SEM_ESPACO;
          }
        } else {
          retorno = SEM_ESTRUTURA_AUXILIAR;
        }
    else{
		retorno = POSICAO_INVALIDA;
	}

    return retorno;
}



/*
Objetivo: retornar os n�meros da estrutura auxiliar da posicao 'posicao (1..10)'.
os n�meros devem ser armazenados no vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posicao 'posicao'
    SEM_ESTRUTURA_AUXILIAR - N�o tem estrutura auxiliar
    POSICAO_INVALIDA - posicao inv�lida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar( int posicao, int vetorAux[]) {

    int i, retorno = 0;

    if(ehPosicaoValida(posicao)){
      if(lista[posicao].vetPont != NULL) {

				for(i=0; i<lista[posicao].contador; i++){
					vetorAux[i] = lista[posicao].vetPont[i]);
				}

				retorno = SUCESSO;

      } else {
          retorno = SEM_ESTRUTURA_AUXILIAR;
      }
    } else {
		retorno = POSICAO_INVALIDA;
	}

    return retorno;
}


/*
Objetivo: retornar os n�meros ordenados da estrutura auxiliar da posicao 'posicao (1..10)'.
os n�meros devem ser armazenados no vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posicao 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - N�o tem estrutura auxiliar
    POSICAO_INVALIDA - posicao inv�lida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]) {

	int i, tamanhoVetor = 0, retorno = 0;

	retorno = getDadosEstruturaAuxiliar(posicao, vetorAux);
	tamanhoVetor = obterTamanhoVetor();

	if(retorno == SUCESSO){
		ordena(tamanhoVetor, vetorAux);
	}

	return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - nao tem nenhum valor
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){

	int retorno = 0;
	int k = 0;
	int count = 0;

	for(i=0; i<TAM; i++){

		if(lista[i].contador != NULL){
			for(j=0; j<lista[i].contador; j++){
				vetorAux[k] = lista[i].vetPont[j];
				k++;
			}
		} else {
			count++;
		}
	}

	if(count == TAM){
		retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
	} else {
		retorno = SUCESSO;
	}

  return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - nao tem nenhum valor
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){

	int i, tamanhoVetor = 0, retorno = 0;

	retorno = getDadosDeTodasEstruturasAuxiliares(vetorAux);
	tamanhoVetor = obterTamanhoVetor();

	if(retorno == SUCESSO){
		ordena(tamanhoVetor, vetorAux);
	}

	return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    NUMERO_INEXISTENTE - Número não existe
*/
int excluirNumeroEspecificoDeEstrutura(int valor, int posicao){
  int retorno = SUCESSO;

	if(ehPosicaoValida(posicao)){
		posicao -= 1;

		if(lista[posicao].vetPont != NULL){

			if(lista[posicao].contador == 0){
				if(!valorExisteNaEstrutura(valor)){

					for(i=0; i<lista[posicao].contador; i++){
						if(valor == lista[posicao].vetPont[i]){
							for(j=i; j<lista[posicao].contador-1; j++){
								lista[posicao].vetPont[i] = lista[posicao].vetPont[j+1];
							}
						}
					}

					lista[posicao].contador -= 1;
					lista[posicao].qtd -= 1;
					retorno = SUCESSO;

				} else {
					retorno = NUMERO_INEXISTENTE;
				}
			} else {
				retorno = ESTRUTURA_AUXILIAR_VAZIA;
			}
		} else {
			retorno = SEM_ESTRUTURA_AUXILIAR;
		}
	} else {
		retorno = POSICAO_INVALIDA;
	}

  return retorno;
}


/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia

    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
*/

int excluirNumeroDoFinaldaEstrutura(int posicao){
  int retorno = SUCESSO;
  int pos, j, l, i, cont = 0;

  pos = ehPosicaoValida(posicao);
	posicao -= 1;

	if(pos == SUCESSO){
		if(lista[posicao].vetPont != NULL){
			if(lista[posicao].contador == 0){

				for(j=0; j<lista[posicao].contador; j++){
						cont++;
				}

				for(i=0; i<TAM; i++){
					for(j=0; j<lista[posicao].contador; j++){
						if(cont == j){
							for(l=i; l<lista[posicao].contador-1; l++){
								lista[posicao].vetPont[i] = lista[posicao].vetPont[l+1];
							}
						}
					}
				}

				lista[posicao].contador -= 1;
				lista[posicao].qtd -= 1;
				retorno = SUCESSO;
			} else {
				retorno = ESTRUTURA_AUXILIAR_VAZIA;
			}
		} else {
			retorno = SEM_ESTRUTURA_AUXILIAR;
		}
  } else {
    retorno = POSICAO_INVALIDA;
  }

  return retorno;
}


// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao){
    int retorno = 0;
    if(posicao < 1 || posicao > 10){
        retorno = POSICAO_INVALIDA;
    }else retorno = SUCESSO;

    return retorno;

}

void ordena(int tamanho, int vetorAux[]){

	int i, j, aux;

	//for(i=0; i<lista[posicao]; i++){
	for(i=0; i<tamanho; i++){
		for(j=i+1; j<tamanho; j++){
			if(vetorAux[i] > vetorAux[j]){
    			aux = vetorAux[i];
    			vetorAux[i] = vetorAux[j];
    			vetorAux[j] = aux;
			}
		}
	}
}

int obterTamanhoVetor(){
	int i, tamanhoVetor = 0;

	for(i=0; i<TAM; i++){
		tamanhoVetor += lista[i].contador;
	}

	return tamanhoVetor;
}

int valorExisteNaEstrutura(int valor){
	int i, j, valorValido = 0;

	for(i=0; i<TAM; i++){
		if(lista[i].contador > 0){
			for(j=0; j<lista[i].contador; j++){
				if(lista[i].vetPont[j] == valor){
					valorValido = 1;
				}
			}
		}
	}

	return valorValido;
}

int ehPosicaoValida(int posicao){
    int retorno = 0;

    if(posicao < 1 || posicao > 10){
        retorno = POSICAO_INVALIDA;
    } else {
        retorno = SUCESSO;
    }

    return retorno;
}

void finalizar(struct listaDados *lista){
    int i;

    for(i=0; i<TAM; i++){
        free(lista[i].vetPont);
    }

}



/*
int inserirNumeroEmEstrutura(struct listaDados *lista){

    int retorno = 0;
    int existeEstruturaAuxiliar = 0;
    int temEspaco = 0;
    int posicao_invalida = 0;

    int i, j, aux, pos;

	printf("De 1 a 10, qual vetor voce deseja escolher?");
	scanf("%d", &aux);

    pos = ehPosicaoValida(aux);

    if(pos == SUCESSO){
        aux -= 1;
        lista[aux].escolha = aux;

        while(lista[aux].contador == 0){
            printf("Digite a qtd de elementos que voce deseja inserir:");
            scanf("%d", &lista[aux].qtd);

            lista[aux].vetPont = (int *) malloc(lista[aux].qtd * sizeof(int));

            printf("Agora, insira um numero no vetor %d\n", (lista[aux].escolha+1));
            scanf("%d", &lista[aux].vetPont[0]);

            lista[aux].contador += 1;
            return SUCESSO;
        }

        if(lista[aux].contador == lista[aux].qtd){
            //"Estrutura cheia"
            retorno = SEM_ESPACO;
        } else {
            printf("Agora, insira um numero no vetor %d\n", (lista[aux].escolha+1));
            scanf("%d", &lista[aux].vetPont[lista[aux].contador]);
            lista[aux].contador += 1;
            retorno = SUCESSO;
        }

    } else {
        retorno = POSICAO_INVALIDA;
    }

    return retorno;
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

void listarTodosOsDados(struct listaDados *lista){
	int i, j, k= 0;
	int somatorio = 0;
	int aux;
	int *vet;

	for(i=0; i<TAM; i++){
		somatorio += lista[i].contador;
	}

	//int vet[somatorio];
	vet = (int *) malloc(somatorio * sizeof(int));

	for(i=0; i<TAM; i++){
		for(j=0; j<lista[i].contador; j++){
			vet[k] = lista[i].vetPont[j];
			k++;
		}
	}

	for(i=0; i<somatorio; i++){
		for(j=i+1; j<somatorio; j++){
			if(vet[i] > vet[j]){
				aux = vet[i];
				vet[i] = vet[j];
				vet[j] = aux;
			}
		}
	}

	printf("Todos os valores ordenados: ");
	for(i=0; i<somatorio; i++){
		printf("%d ", vet[i]);

		if(i < (somatorio - 1)){
			printf(" - ");
		}
	}

	puts("\n");
}

void modificarTamanho(struct listaDados *lista){

	int i, j, posicao, novoTamanho, pos, retorno;

	printf("Qual vetor voce deseja escolher?");
	scanf("%d", &posicao);

	pos = ehPosicaoValida(posicao);

	if(pos == SUCESSO){
	    printf("Quantas posicoes deseja aumentar?");
        scanf("%d", &novoTamanho);

        retorno = modificarTamanhoEstruturaAuxiliar(posicao, novoTamanho, lista);

        if(retorno == SUCESSO){
            printf("Ajustado com sucesso\n");
        } else if(retorno == TAMANHO_INVALIDO){
            printf("Novo tamanho invalido\n");
        }

	} else {
        printf("Vetor invalido\n");
	}
}

int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho, struct listaDados *lista){
    int retorno = 0;
    int pos;

    if(novoTamanho >= 0){
        posicao -= 1;
        lista[posicao].qtd += novoTamanho;
        puts("\n");
        lista[posicao].vetPont = (int *) realloc(lista[posicao].vetPont, lista[posicao].qtd * sizeof(int));

        retorno = SUCESSO;
    } else {
        retorno = TAMANHO_INVALIDO;
    }

    return retorno;

}

void excluirEspecifico(struct listaDados *lista){
	int i, j, posicao, valor, pos, retorno;

    printf("Qual vetor voce deseja escolher?");
	scanf("%d", &posicao);

	pos = ehPosicaoValida(posicao);

	if(pos == SUCESSO){
    posicao -= 1;

        if(lista[posicao].contador > 0){
            printf("Qual valor deseja apagar?");
            scanf("%d", &valor);

            retorno = excluirNumeroEspecificoDeEstrutura(posicao, valor, lista);

            if(retorno == SUCESSO){
                printf("Excluido com sucesso\n");
            } else if(retorno == NUMERO_INEXISTENTE){
                printf("Valor inexistente\n");
            }
        } else {
            printf("Estrutura inexistente\n");
        }

	} else {
        printf("Vetor invalido\n");
	}
}

int excluirNumeroEspecificoDeEstrutura(int posicao, int valor, struct listaDados *lista){
    int retorno = SUCESSO;
    int i, j, l, valorValido = 0;

  	for(i=0; i<TAM; i++){
		if(lista[i].contador > 0){
			for(j=0; j<lista[i].contador; j++){
				if(lista[i].vetPont[j] == valor){
                    valorValido = 1;
				}
            }
        }
    }

    if(valorValido != 1){
        retorno = NUMERO_INEXISTENTE;
        return retorno;
    }

    for(i=0; i<TAM; i++){
        for(j=0; j<lista[posicao].contador; j++){
            if(valor == lista[posicao].vetPont[j]){
                for(l=i; l<lista[posicao].contador-1; l++){
                    lista[posicao].vetPont[i] = lista[posicao].vetPont[l+1];
                }
            }
        }
    }

    lista[posicao].contador -= 1;
    lista[posicao].qtd -= 1;

  return retorno;
}

void excluirUltimoNumero(struct listaDados *lista){
	int posicao, retorno;

    printf("Qual vetor voce deseja escolher?");
	scanf("%d", &posicao);

    retorno = excluirNumeroDoFinaldaEstrutura(posicao, lista);

    if(retorno == SUCESSO){
        printf("Ultimo numero excluido com sucesso\n");
    } else if(retorno == ESTRUTURA_AUXILIAR_VAZIA){
        printf("Estrutura vazia\n");
    } else if(retorno == POSICAO_INVALIDA){
        printf("Posicao do vetor invalida\n");
    }
}

int excluirNumeroDoFinaldaEstrutura(int posicao, struct listaDados *lista){
  int retorno = SUCESSO;
  int pos, j, l, i, cont = 0;

  	pos = ehPosicaoValida(posicao);
	posicao -= 1;

	if(pos == SUCESSO){
        if(lista[posicao].contador > 0){
            for(j=0; j<lista[posicao].contador; j++){
                cont++;
            }

            for(i=0; i<TAM; i++){
                for(j=0; j<lista[posicao].contador; j++){
                    if(cont == j){
                        for(l=i; l<lista[posicao].contador-1; l++){
                            lista[posicao].vetPont[i] = lista[posicao].vetPont[l+1];
                        }
                    }
                }
            }

            lista[posicao].contador -= 1;
            lista[posicao].qtd -= 1;
            retorno = SUCESSO;
        } else {
            retorno = ESTRUTURA_AUXILIAR_VAZIA;
        }
    } else {
        retorno = POSICAO_INVALIDA;
    }

  return retorno;
}



*/







/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]){

    int retorno = 0;


    return retorno;

}


/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]){

    int retorno = 0;


    return retorno;

}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]){

    int retorno = 0;
    return retorno;

}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]){

    int retorno = 0;
    return retorno;

}



/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao){
    int retorno = 0;

    return retorno;

}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa

*/

void inicializar(){
}




