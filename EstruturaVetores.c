#include <stdio.h>
#include <stdlib.h>
#define TAM 10
#include "EstruturaVetores.h"

/*
Objetivo: criar estrutura auxiliar na posicao 'posicao'.
com tamanho 'tamanho'
Rertono (int)
    SUCESSO - criado com sucesso
   - JA_TEM_ESTRUTURA_AUXILIAR - ja tem estrutura na posicao
   - POSICAO_INVALIDA - posicao invalida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espa�o de mem�ria
   - TAMANHO_INVALIDO - o tamanho tem inteiro maior ou igual a 1
*/
int criarEstruturaAuxiliar(int tamanho, int posicao) {

  int retorno = 0;

  if (ehPosicaoValida(posicao) == SUCESSO) {

    if (lista[posicao].vetPont == NULL) {

      if (tamanho > 0) {
        lista[posicao].vetPont = (int * ) malloc(tamanho * sizeof(int));
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
	    SEM_ESPACO - nao tem espa�o
	    SEM_ESTRUTURA_AUXILIAR - Nao tem estrutura auxiliar
	    POSICAO_INVALIDA - posicao invalida para estrutura auxiliar
	CONSTANTES
*/
int inserirNumeroEmEstrutura(int valor, int posicao) {

  int retorno = 0;
  int existeEstruturaAuxiliar = 0;
  int temEspaco = 0;
  int posicao_invalida = 0;

  if (ehPosicaoValida(posicao) == SUCESSO)
    if (lista[posicao].vetPont != NULL) {
      if (lista[posicao].contador != lista[posicao].qtd) {
        lista[posicao].vetPont[lista[posicao].contador] = valor;
        lista[posicao].contador += 1;
        retorno = SUCESSO;

      } else {
        retorno = SEM_ESPACO;
      }
    } else {
      retorno = SEM_ESTRUTURA_AUXILIAR;
    }
  else {
    retorno = POSICAO_INVALIDA;
  }

  return retorno;
}

/*
Objetivo: retornar os numeros da estrutura auxiliar da posicao 'posicao (1..10)'.
os numeros devem ser armazenados no vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posicao 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Nao tem estrutura auxiliar
    POSICAO_INVALIDA - posicao invalida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]) {

  int i, retorno = 0;

  if (ehPosicaoValida(posicao) == SUCESSO) {
    if (lista[posicao].vetPont != NULL) {

      for (i = 0; i < lista[posicao].contador; i++) {
        vetorAux[i] = lista[posicao].vetPont[i];
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
Objetivo: retornar os numeros ordenados da estrutura auxiliar da posicao 'posicao (1..10)'.
os numeros devem ser armazenados no vetorAux
Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posicao 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Nao tem estrutura auxiliar
    POSICAO_INVALIDA - posicao invalida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]) {

  int i, tamanhoVetor = 0, retorno = 0;

  retorno = getDadosEstruturaAuxiliar(posicao, vetorAux);
  tamanhoVetor = obterTamanhoVetor();

  if (retorno == SUCESSO) {
    ordena(tamanhoVetor, vetorAux);
  }

  return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux
Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - nao tem nenhum valor
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]) {

  int retorno = 0;
  int i, j, k = 0;
  int count = 0;

  for(i=0; i<TAM; i++){

    if (lista[i].contador != NULL) {
      for (j = 0; j < lista[i].contador; j++) {
        vetorAux[k] = lista[i].vetPont[j];
        k++;
      }
    } else {
      count++;
    }
  }

  if (count == TAM) {
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
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]) {

  int i, tamanhoVetor = 0, retorno = 0;

  retorno = getDadosDeTodasEstruturasAuxiliares(vetorAux);
  tamanhoVetor = obterTamanhoVetor();

  if (retorno == SUCESSO) {
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
int excluirNumeroEspecificoDeEstrutura(int valor, int posicao) {
  int i, j, retorno = 0;

  if (ehPosicaoValida(posicao) == SUCESSO) {

    if (lista[posicao].vetPont != NULL) {

      if (lista[posicao].contador == 0) {
        retorno = ESTRUTURA_AUXILIAR_VAZIA;
      } else {

        if (valorExisteNaEstrutura(valor) == 1) {

          for (i = 0; i < lista[posicao].contador; i++) {
            if (valor == lista[posicao].vetPont[i]) {
              for (j = i; j < lista[posicao].contador - 1; j++) {
                lista[posicao].vetPont[i] = lista[posicao].vetPont[j + 1];
              }
            }
          }

          lista[posicao].contador -= 1;
          lista[posicao].qtd -= 1;
          retorno = SUCESSO;

        } else {
          retorno = NUMERO_INEXISTENTE;
        }
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

int excluirNumeroDoFinaldaEstrutura(int posicao) {
  int retorno = SUCESSO;
  int pos, j, l, i, cont = 0;

  pos = ehPosicaoValida(posicao);

  if (pos == SUCESSO) {
    if (lista[posicao].vetPont != NULL) {
      if (lista[posicao].contador == 0) {

      retorno = SEM_ESTRUTURA_AUXILIAR;

      } else {
        for (j = 0; j < lista[posicao].contador; j++) {
          cont++;
        }

        for (i = 0; i < TAM; i++) {
          for (j = 0; j < lista[posicao].contador; j++) {
            if (cont == j) {
              for (l = i; l < lista[posicao].contador - 1; l++) {
                lista[posicao].vetPont[i] = lista[posicao].vetPont[l + 1];
              }
            }
          }
        }

        lista[posicao].contador -= 1;
        lista[posicao].qtd -= 1;
        retorno = SUCESSO;

      }
    } else {

    }
  } else {
    retorno = POSICAO_INVALIDA;
  }

  return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1
Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho) {

  int retorno = 0;

  if (ehPosicaoValida(posicao) == SUCESSO) {

    if (lista[posicao].vetPont != NULL) {

      if (novoTamanho > 0 && novoTamanho < 100) {
        lista[posicao].vetPont = (int * ) realloc(lista[posicao].vetPont, novoTamanho * sizeof(int));
        lista[posicao].qtd += novoTamanho;

        retorno = SUCESSO;

      } else {
        retorno = NOVO_TAMANHO_INVALIDO;
      }
    } else {
      retorno = SEM_ESTRUTURA_AUXILIAR;
    }
  } else {
    retorno = POSICAO_INVALIDA;
  }

  return retorno;

}

void ordena(int tamanho, int vetorAux[]) {

  int i, j, aux;

  //for(i=0; i<lista[posicao]; i++){
  for (i = 0; i < tamanho; i++) {
    for (j = i + 1; j < tamanho; j++) {
      if (vetorAux[i] > vetorAux[j]) {
        aux = vetorAux[i];
        vetorAux[i] = vetorAux[j];
        vetorAux[j] = aux;
      }
    }
  }
}

int obterTamanhoVetor() {
  int i, tamanhoVetor = 0;

  for (i = 0; i < TAM; i++) {
    tamanhoVetor += lista[i].contador;
  }

  return tamanhoVetor;
}

int valorExisteNaEstrutura(int valor) {
  int i, j, valorValido = 0;

  for (i = 0; i < TAM; i++) {
    if (lista[i].contador > 0) {
      for (j = 0; j < lista[i].contador; j++) {
        if (lista[i].vetPont[j] == valor) {
          valorValido = 1;
        }
      }
    }
  }

  return valorValido;
}

int ehPosicaoValida(int posicao) {
  int retorno = 0;

  if (posicao >= 0 && posicao < 10) {
    retorno = SUCESSO;
  } else {
    retorno = POSICAO_INVALIDA;
  }

  return retorno;
}

void finalizar() {
  int i;

  for (i = 0; i < TAM; i++) {
    free(lista[i].vetPont);
  }
}

void inicializar(){
  FILE *arqEntrada;
  char *result;
  char linha[linhaQtd], vetQuantidade[vetQuantidadeQTD], vetValores[vetValoresQTD];
  int a = 0, b = 0, *indexVetQtd, *auxiliar, opcao;

  indexVetQtd = &a;
  auxiliar = &b;

  do{
    printf("Voce deseja carregar os dados com arquivo de texto ou binario? \n 0 - Texto\n 1 - Binario\n");
    scanf("%d", &opcao);
  } while(opcao > 1);

  if(opcao == 0){
    carregarTexto(arqEntrada, result, linha, vetQuantidade, vetValores, indexVetQtd, auxiliar);
  } else {
    carregarBinario();
  }
}

void carregarTexto(FILE *arqEntrada, char *result, char linha[], char vetQuantidade[], char vetValores[], int *indexVetQtd, int *auxiliar){
  int i, indexVetorValido, achouQtd, retorno, posicao;

  arqEntrada = fopen("entrada.txt", "rt");

  if(arqEntrada == NULL){
    printf("Problemas na abertura do arquivo\n");
    return 0;
  }

  while (!feof(arqEntrada)){
    result = fgets(linha, 100, arqEntrada);

    if(result){
      //O primeiro item é o index do array. Ele é de 0 a 9.
      //Caso seja um numero diferente disso: erro!
      if(linha[0] >= 48 && linha[0] <= 57){
        printf("Vetor: %c \n", linha[0]);
        posicao = atoi(linha[0]);
        indexVetorValido = SUCESSO;
      } else {
        indexVetorValido = ERRO_INDEX_VETOR;
      }

      if(indexVetorValido == SUCESSO){
        achouQtd = 0;
        *indexVetQtd = 0;

        for(i = 2; i < strlen(linha) != '\0'; i++){
          if(achouQtd != SUCESSO){
            //PEGA A QUANTIDADE -> 43 é um mais ( + )
            achouQtd = insereQuantidade(linha, vetQuantidade, indexVetQtd, auxiliar, i, posicao);
            retorno = achouQtd;
          }

          if(achouQtd == SUCESSO){
            retorno = insereValores(linha, vetValores, indexVetQtd, auxiliar, i, posicao);
          }
        }
        printf("Retorno - %d", retorno);
        puts("\n");
      } else {
        printf("Erro - Index do vetor invalido!\n");
      }
    }
  }
}

int insereQuantidade(char vetor[], char vetQuantidade[], int *indexVetQtd, int *auxiliar, int i, int posicao){
  int retorno = 0, tamanho = 0;

  if(vetor[i] != 43){
    vetQuantidade[*indexVetQtd] = vetor[i];
    vetQuantidade[*indexVetQtd + 1] = '\0';
    *indexVetQtd += 1;
  }
  else if(vetor[i] == 43){
    retorno = verificaValor(vetQuantidade, 1);

    if(retorno == SUCESSO){
      tamanho = atoi(vetQuantidade);
      printf("Qtd: %d\n", tamanho);

      criarEstruturaAuxiliar(tamanho, posicao);

      *indexVetQtd = 0;
      memset(vetQuantidade, 0, vetQuantidadeQTD);
    }
  }

  return retorno;
}

int insereValores(char vetor[], char vetValores[], int *indexVetQtd, int *auxiliar, int i, int posicao){
  int j, valor, retorno;

  if(vetor[i + 1] != 44){
    vetValores[*indexVetQtd] = vetor[i + 1];
    vetValores[*indexVetQtd + 1] = '\0';
    *indexVetQtd += 1;
  }
  else if(vetor[i + 1] == 44){
    retorno = verificaValor(vetValores, 2);

    if(retorno == SUCESSO){
      valor = atoi(vetValores);
      inserirNumeroEmEstrutura(valor, posicao);

      *indexVetQtd = 0;
      memset(vetValores, 0, vetValoresQTD);
      printf("Valor: %d\n", valor);
    }
  }

  return retorno;
}

int verificaValor(char vetor[], int tipo){
  //Tipo 1 - Quantidade
  //Tipo 2 - Valor
  int i, ehNumero = 0, retorno;

  for(i = 0; i < strlen(vetor); i++){
    if(vetor[i] >= 48 && vetor[i] <= 57)  {
      ehNumero++;
    }
  }

  if(ehNumero == strlen(vetor)){
    retorno = SUCESSO;
  } else {
    if(tipo == 1)  {
      retorno = ERRO_QUANTIDADE_VETOR;
    } else {
      retorno = ERRO_VALORES_VETOR;
    }
  }

  return retorno;
}