#include <stdio.h>
#include <stdlib.h>
#include "EstruturaVetores.h"

int menu();

int menu() {
  int op;
  printf("----- MENU -----\n");
  printf("0 - Sair\n");
  printf("1 - Criar Estrutura\n");
  printf("2 - Inserir Valor em Estrutura\n");
  printf("3 - Listar Numeros\n");
  printf("4 - Listar Numeros da Estrutura de Forma Ordenada\n");
  printf("5 - Listar Todos os Numeros da Estrutura\n");
  printf("6 - Listar Todos os Numeros da Estrutura de Forma Ordenada\n");
  printf("7 - Excluir Numero Especifico da Estrutura\n");
  printf("8 - Excluir Ultimo Numero da Estrutura\n");
  printf("9 - Aumentar Tamanho de uma Estrutura\n");
  scanf("%d", & op);
  return op;
}

int main() {
  int op;
  int sair = 0;
  int ret;
  int i;
  int tamanho = 0;
  int posicao = 0;
  int valor = 0;
  int somatorio = 0;
  int novoTamanho = 0;
  while (!sair) {
    op = menu();
    switch (op) {
    case 0:{
        sair = 1;
        finalizar();
        break;
      }

    case 1:{
        system("clear");
        printf("Criar Estrutura - De 1 a 10, qual vetor voce deseja criar?");
        scanf("%d", & posicao);
        posicao -= 1;

        printf("Digite a qtd de elementos que voce deseja inserir:");
        scanf("%d", & tamanho);

        ret = criarEstruturaAuxiliar(tamanho, posicao);

        if (ret == SUCESSO) {
          printf("Inserido com Sucesso\n");
        } else if (ret == SEM_ESPACO) {
          printf("Tamanho Invalido\n");
        } else if (ret == JA_TEM_ESTRUTURA_AUXILIAR) {
          printf("Ja tem estrutura Auxiliar\n");
        } else if (ret == SEM_ESPACO_DE_MEMORIA){
          printf("Sem espaco de memoria\n");
        } else if(ret == POSICAO_INVALIDA){
          printf("Posicao invalida\n");
        }


        break;
      }

    case 2:{
        //inserir
        system("clear");
        printf("Inserir Dados - De 1 a 10, qual vetor voce deseja escolher?");
        scanf("%d", & posicao);
        posicao -= 1;

        printf("Digite o valor que voce deseja inserir:");
        scanf("%d", & valor);

        ret = inserirNumeroEmEstrutura(valor, posicao);

        if (ret == SUCESSO) {
          printf("Inserido com sucesso\n");
        } else if (ret == SEM_ESPACO) {
          printf("Sem Espaco\n");
        } else if (ret == SEM_ESTRUTURA_AUXILIAR) {
          printf("Sem estrutura Auxiliar\n");
        } else if (ret == POSICAO_INVALIDA) {
          printf("Posicao do numero do vetor invalida\n");
        }

        break;
      }

    case 3:{
        //listar dados
        system("clear");

        printf("Listar Dados - De 1 a 10, qual vetor voce deseja listar os dados?");
        scanf("%d", & posicao);
        posicao -= 1;

        int vetorAux[lista[posicao].contador];
        ret = getDadosEstruturaAuxiliar(posicao, vetorAux);

        if (ret == SUCESSO) {
          printf("Sucesso\n");

          for(i=0; i<lista[posicao].contador; i++) {
            printf("%d\n", vetorAux[i]);
          }
        } else if (ret == SEM_ESTRUTURA_AUXILIAR) {
          printf("Sem estrutura Auxiliar\n");
        } else if (ret == POSICAO_INVALIDA) {
          printf("Posicao do numero do vetor invalida\n");
        }

        break;
      }

    case 4:{
        //listar dados ordenados
        system("clear");

        printf("Listar Dados Ordenados - De 1 a 10, qual vetor voce deseja listar os dados?");
        scanf("%d", & posicao);
        posicao -= 1;

        int vetorAux[lista[posicao].contador];

        ret = getDadosOrdenadosEstruturaAuxiliar(posicao, vetorAux);

        if (ret == SUCESSO) {
          printf("Sucesso\n");

          for (i = 0; i < lista[posicao].contador; i++) {
            printf("%d\n", vetorAux[i]);
          }
        } else if (ret == SEM_ESTRUTURA_AUXILIAR) {
          printf("Sem estrutura Auxiliar\n");
        } else if (ret == POSICAO_INVALIDA) {
          printf("Posicao do numero do vetor invalida\n");
        }

        break;
      }

    case 5:{
        //listar todos os dados
        somatorio = 0;
        system("clear");
        for (i = 0; i <TAM; i++) {
          somatorio += lista[i].contador;
        }
        int vetorAux[somatorio];
        ret = getDadosDeTodasEstruturasAuxiliares(vetorAux);

        if (ret == SUCESSO) {
          printf("Sucesso\n");

          for (i = 0; i < somatorio; i++) {
            printf("%d\n", vetorAux[i]);
          }
        } else if (ret == TODAS_ESTRUTURAS_AUXILIARES_VAZIAS) {
          printf("Todas as estruturas auxiliares estao vazias.\n");
        }

        break;
      }

    case 6:{
        //listar todos os dados ordenados
        system("clear");
        somatorio = 0;
        for (i = 0; i < TAM; i++) {
          somatorio += lista[i].contador;
        }
        int vetorAux[somatorio];
        ret = getDadosOrdenadosDeTodasEstruturasAuxiliares(vetorAux);

        if (ret == SUCESSO) {
          printf("Sucesso\n");

          for (i = 0; i < somatorio; i++) {
            printf("%d\n", vetorAux[i]);
          }
        } else if (ret == TODAS_ESTRUTURAS_AUXILIARES_VAZIAS) {
          printf("Todas as estruturas auxiliares estao vazias.\n");
        }

        break;
      }

    case 7:{
        //excluir numero especifico
        system("clear");

        printf("Excluir Num Específico - Qual vetor voce deseja escolher?");
        scanf("%d", & posicao);
        posicao -= 1;

        printf("Qual valor voce deseja apagar?");
        scanf("%d", & valor);

        ret = excluirNumeroEspecificoDeEstrutura(valor, posicao);

        if (ret == SUCESSO) {
          printf("Removido com sucesso\n");
        } else if (ret == SEM_ESTRUTURA_AUXILIAR) {
          printf("Sem Estrutura Auxiliar\n");
        } else if (ret == ESTRUTURA_AUXILIAR_VAZIA) {
          printf("Estrutura Auxiliar Vazia\n");
        } else if (ret == POSICAO_INVALIDA) {
          printf("Posicao do numero do vetor invalida\n");
        } else if (ret == NUMERO_INEXISTENTE) {
          printf("Numero Inexistente\n");
        }

        break;
      }

    case 8:{
        //excluir ultimo numero
        system("clear");

        printf("Excluir Ultimo Numero - Qual vetor voce deseja escolher?");
        scanf("%d", & posicao);
        posicao -= 1;

        ret = excluirNumeroDoFinaldaEstrutura(posicao);

        if (ret == SUCESSO) {
          printf("Removido com sucesso\n");
        } else if (ret == SEM_ESTRUTURA_AUXILIAR) {
          printf("Sem Estrutura Auxiliar\n");
        } else if (ret == ESTRUTURA_AUXILIAR_VAZIA) {
          printf("Estrutura Auxiliar Vazia\n");
        } else if (ret == POSICAO_INVALIDA) {
          printf("Posicao do numero do vetor invalida\n");
        }

        break;
      }

    case 9:{
        //modificar tamanho
        system("clear");

        printf("Aumentar Tamanho - Qual vetor voce deseja escolher?");
        scanf("%d", & posicao);
        posicao -= 1;

        printf("Insira o novo tamanho?");
        scanf("%d", & novoTamanho);

        ret = modificarTamanhoEstruturaAuxiliar(posicao, novoTamanho);

        if (ret == SUCESSO) {
          printf("foi modificado corretamente o tamanho da estrutura auxiliar");
        } else if (ret == SEM_ESTRUTURA_AUXILIAR) {
          printf("Não tem estrutura auxiliar");
        } else if (ret == POSICAO_INVALIDA) {
          printf("Posição inválida para estrutura auxiliar");
        } else if (ret == NOVO_TAMANHO_INVALIDO) {
          printf("novo tamanho não pode ser negativo");
        } else if (ret == SEM_ESPACO_DE_MEMORIA) {
          printf("erro na alocação do novo valor");
        }

        break;
      }

    default: {
        printf("opcao invalida\n");
      }
    }
  }

  return 0;

}
