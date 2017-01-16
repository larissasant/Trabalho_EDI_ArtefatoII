// struct indicePalavra que e usada para controle das apari�oes da palavra

typedef struct indicePalavra
{
    int linhaPalavra;
    int quantidade;
    struct indicePalavra* prox;
} indicePalavra;


//struct principal com os dados que a lista tera
typedef struct ListaPalalavras
{
    char palavra[10000];
    int linhaPalavra;
    struct ListaPalalavras* prox;
} Lista;

void libera(Lista *li);
Lista *cria(); //fun��o que cria a lista
void insere(Lista **l, char palavra[], int linha); // fun��o que insere normalmente as palavras sem filtro
void imprime(Lista *l, indicePalavra *indices, int quantidadeLinhas);// fun��o que imprime as listas
void tratamento1 (char *str);// fun��o que faz o tratamento de caracteres se s�o minusculos ou n�o
void insereSomentePalavrasUnicas(Lista **l, char palavra[]);// fun��o que insere  as palavras com filtro

void liberaIndice(indicePalavra *li); // libera as listas criadas
indicePalavra *criaIndice(); // cria lista do tipo Indice Palavras
void insereOcorrencias(indicePalavra **Indices, int linha, int ocorrencias); // insere as ocorrencias em uma lista
void insereIndices(Lista **Tds, indicePalavra **indices, char palavra[], int quantidadeLinhas);// fun��o que insere os indices


