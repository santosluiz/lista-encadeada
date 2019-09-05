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
#define TAMM 10

struct listaDados {
	int *vetPont;
	int qtd;
	int contador;
	int escolha;	
} lista[TAM];

int  criarEstruturaAuxiliar ( int tamanho, int posicao);

/*
int  inserirNumeroEmEstrutura ( int valor, int posicao);
int  excluirNumeroDoFinaldaEstrutura ( int posicao);
int  excluirNumeroEspecificoDeEstrutura ( int valor, int posicao);
int  getDadosEstruturaAuxiliar ( int posição, int vetorAux []);
int  getDadosOrdenadosEstruturaAuxiliar ( int posição, int vetorAux []);
int  getDadosDeTodasEstruturasAuxiliares ( int vetorAux []);
int  getDadosOrdenadosDeTodasEstruturasAuxiliares ( int vetorAux []);
int  modificarTamanhoEstruturaAuxiliar ( int posição, int novoTamanho);
int  getQuantidadeElementosEstruturaAuxiliar ( int posicao);
Não * montarListaEncadeadaComCabecote ();
void  getDadosListaEncadeadaComCabecote (No * inicio, int vetorAux []);
void  destruirListaEncadeadaComCabecote (No * inicio);*/
void  inicializar ();
void  finalizar ();


/*int inserirNumeroEmEstrutura(struct listaDados *lista);
void listarDados(struct listaDados *lista);
void listarDadosOrdenados(struct listaDados *lista);
void ordena(int i, struct listaDados *lista);
void listarTodosOsDados(struct listaDados *lista);
void modificarTamanho(struct listaDados *lista);
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho, struct listaDados *lista);
void excluirEspecifico(struct listaDados *lista);
int excluirNumeroDoFinaldaEstrutura(int posicao, struct listaDados *lista);
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor, struct listaDados *lista);
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]);
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]);
int getQuantidadeElementosEstruturaAuxiliar(int posicao);
void inicializar();
void finalizar(struct listaDados *lista);
void dobrar(int *x);*/
