#ifndef GLOBAL_DECLARATIONS
#define GLOBAL_DECLARATIONS

#define VALOR_SAIDA 1
#define VALOR_PAREDE 1000
#define VALOR_DIAGONAL 1.5
#define PANICO 0.05

extern int num_lin_grid;
extern int num_col_grid;
extern int numero_simulacoes;
extern int original_seed;
extern int numero_pedestres;

enum Status {SAINDO, SAIU, PARADO, MOVENDO};

typedef int ** Grid;

typedef struct celula{
    int loc_lin, loc_col;
    double valor;
}celula;


/**
 * Uma porta dupla ou duas portas lado a lado? Qual a diferença?
 * O pedestre é capaz de entrar na porta via diagonal? (pensar em ambos os casos)
 * Como ficam portas nos cantos da sala?
*/


struct saida {
    int largura; // largura da saída (em células contíguas)
    celula *loc; // celulas que fazem parte da saída. Valor setado para 1.0
    double **estatico; // peso estático
    double **dinamico; // peso dinâmico
    double **field; // piso final referente à saída
};
typedef struct saida * Saida;

typedef struct conjunto_portas{
    double **static_combined_field; // piso resultante da combinação dos pisos estáticos de cada saída
    double **dynamic_combined_field; // piso resultante da combinação dos pisos dinâmicos de cada saída
    Saida *vet_saidas;// vetor de todas as saidas
    int num_saidas;// número de saidas
} Conjunto_saidas;

struct pedestre {
    int id;
    enum Status estado;
    int origin_lin, origin_col; // localização inicial do pedestre (não se altera)
    int loc_lin, loc_col; // localização atual do pedestre
    int mov_lin, mov_col; // célula que o pedestre pretende se mover
};
typedef struct pedestre * Pedestre;

typedef struct conjunto_pedestres {
    Pedestre *vet;
    int num_ped;
} Conjunto_pedestres;

typedef struct command_line {
    char nome_arquivo_entrada[51];
    char nome_arquivo_saida[51];
    char nome_arquivo_auxiliar[51];
    int output_type;
    int output_to_file;
    int input_method;
    int debug;
    double alfa;
    int na_saida;
    int sempre_menor;
    int evitar_mov_cantos;
} Command_line;

extern Grid grid_esqueleto;
extern Grid grid_pedestres;
extern Grid grid_mapa_calor;
extern Conjunto_saidas saidas;
extern Conjunto_pedestres pedestres;
extern Command_line commands;

int **alocar_matriz_int(int num_lin, int num_col);
int zerar_matriz_inteiros(int **mat, int num_lin, int num_col);
void desalocar_matriz_int(int **mat, int lin);
double **alocar_matriz_double(int num_lin, int num_col);
void desalocar_matriz_double(double **mat, int lin);
int copiar_matriz_double(double **dest, double **src);
int eh_diagonal_valida(int loc_lin, int loc_col, int j, int k, double **mat);

#endif