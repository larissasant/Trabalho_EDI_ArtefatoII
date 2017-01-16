// struct indicePalavra que e usada para controle das apariçoes da palavra

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
Lista *cria(); //função que cria a lista
void insere(Lista **l, char palavra[], int linha); // função que insere normalmente as palavras sem filtro
void imprime(Lista *l, indicePalavra *indices, int quantidadeLinhas);// função que imprime as listas
void tratamento1 (char *str);// função que faz o tratamento de caracteres se são minusculos ou não
void insereSomentePalavrasUnicas(Lista **l, char palavra[]);// função que insere  as palavras com filtro

void liberaIndice(indicePalavra *li); // libera as listas criadas
indicePalavra *criaIndice(); // cria lista do tipo Indice Palavras
void insereOcorrencias(indicePalavra **Indices, int linha, int ocorrencias); // insere as ocorrencias em uma lista
void insereIndices(Lista **Tds, indicePalavra **indices, char palavra[], int quantidadeLinhas);// função que insere os indices


