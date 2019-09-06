#define SUCESSO -1
#define SEM_ESPACO -2
#define SEM_ESTRUTURA_AUXILIAR -3
#define JA_TEM_ESTRUTURA_AUXILIAR -4
#define POSICAO_INVALIDA -5
#define SEM_ESPACO_DE_MEMORIA -6
#define TAMANHO_INVALIDO -7
#define ESTRUTURA_AUXILIAR_VAZIA -8
#define NUMERO_INEXISTENTE -9
#define NOVO_TAMANHO_INVALIDO -10
#define TODAS_ESTRUTURAS_AUXILIARES_VAZIAS -11
#define TAM 10

struct listaDados {
	int *vetPont;
	int qtd;
	int contador;
	int escolha;
} lista[TAM];

int criarEstruturaAuxiliar(int tamanho, int posicao);
int inserirNumeroEmEstrutura (int valor, int posicao);
int getDadosEstruturaAuxiliar( int posicao, int vetorAux[]);
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int excluirNumeroEspecificoDeEstrutura(int valor, int posicao);
int excluirNumeroDoFinaldaEstrutura(int posicao);
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho);
int ehPosicaoValida(int posicao);
int obterTamanhoVetor();
int valorExisteNaEstrutura(int valor);
void ordena(int tamanho, int vetorAux[]);
void finalizar();
void inicializar();
