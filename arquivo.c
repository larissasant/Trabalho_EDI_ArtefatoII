#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivo.h"

Lista *cria() //cria e retorna NULL
{
    return NULL;
}
indicePalavra *criaIndice() //cria
{
    return NULL;
}

//insere em uma lista todos os indices de apariçoes juntos
void insereOcorrencias(indicePalavra **Indices, int linha, int ocorrencias){
    indicePalavra *nova = (indicePalavra*)malloc(sizeof(indicePalavra));

    nova->linhaPalavra = linha;
    nova->quantidade = ocorrencias;

    nova->prox = *Indices;
    *Indices = nova;
}


//insere as palavras sem filtrar nada, recebendo uma lista e inserindo palavras e guardando as linha
void insere(Lista **l, char palavra[], int linha)
{
    Lista *nova=(Lista*)malloc(sizeof(Lista));
    int i;
    for (i = 0 ; palavra [i] != '\0'; i++) //percorre a string e vai salvando os caracteres
    {
        nova->palavra[i] = palavra[i];
    }
    nova->palavra[i] = '\0'; // fecha a palavra

    nova->linhaPalavra = linha; // recebe o valor da linha e salva
    nova->prox = *l; // proximo recebe um proximo no NULL
    *l = nova; //a lista recebe a lista com a palavra inserida
}

void insereSomentePalavrasUnicas(Lista **l, char palavra[]) // filtra as palavras, inserindo apenas uma vez cada palavra
{
    Lista *aux1 = *l; // recebe e aponta para lista passada
    Lista *nova=(Lista*)malloc(sizeof(Lista)); // cria uma nova lista e armazena valor para ela
    Lista *auxiliar = NULL; // ponteiro auxiliar que ajuda a percorrer o ciclo while
    int cont = 0; // variavel contador que auxilia o if
    int i = 0; // contador usado no for

    while (aux1 != NULL) // entrará nessa condição quando a lista não for mais vazia
    {
        if (strcmp(palavra, aux1->palavra) == 0) //compara as palavras
            cont = 1; //caso as palarvas sejam iguais cont recebe 1 e assim indca que elas se repetem para condição if
        auxiliar = aux1; // ajuda a não entra no if da inserção, tendo controle sobre a primera inserção
        aux1 = aux1->prox; // percorre a lista
    }

    if(auxiliar == NULL) //primeira inserção
    {
        for (i = 0 ; palavra [i] != '\0'; i++) // inserção da palavra
        {
            nova->palavra[i] = palavra[i]; // inserção de caractere a caractere
        }
        nova->palavra[i] = '\0'; // fecha a palavra
        nova->prox = *l; // mesma função da principal
        *l = nova;

    }
    else// caso não seja a primeira inserção
    {
        if (cont != 1) // como o contador não recebeu 1 sinal que a palavra ainda não existe e sera inserida
        {
            int i;// variavel auxiliar para percorrer o for
            for (i = 0 ; palavra[i] != '\0'; i++) // percorrendo o for para inserir caracterer a caracter
            {
                nova->palavra[i] = palavra[i]; // formando a palavra
            }
            nova->palavra[i] = '\0'; // fecha a palavra
            nova->prox = *l;
            *l = nova;
        }
    }
}
void insereIndices(Lista **Tds, indicePalavra **l, char palavra[], int quantidadeLinhas)
{
    //indicePalavra *indice = (indicePalavra*)malloc(sizeof(indicePalavra)); // criaria uma lista dos indices
    int i = 0; // auxiliar
    int ocorrencias = 0;
    for (; i <= quantidadeLinhas ; i++) //percorrer a lista a quantidade de vezes igual ao numero de linha
    {
        Lista *aux1 = *Tds; // todas as palavras
                while (aux1 != NULL) // percorre as palavras e compara ver se elas existe
        {
            if ((strcmp(palavra, aux1->palavra) == 0)) /*se a linha for igual a linha que esta sendo percorrida
            e palavra recebida for igual a uma daquelas existente em toda lista*/
            {
                if (aux1->linhaPalavra == i) //aqui so e acrecentado valor caso a linha da palavra seja igual a linha percorrida no momento
                {
                    ocorrencias++; // acrecenta 1 ao resultado toda vez que a palavra aparece na linha em questão
                }
            }
            aux1 = aux1->prox; //percorre o while
        }

        insereOcorrencias(l, i, ocorrencias); //insere as ocorrencias
        ocorrencias = 0; //zera as ocorrencias para ir para linha seguinte
    }
}

void tratamento1 (char *str) // faz a conversão das palavras pra minusculo para não ocorrer erro
{
    int x;
    char aux;
    for (x = 0 ;  str[x] != '\0' ; x++)
    {
        if (str[x] >= 'A' && str[x] <= 'Z')
        {
            aux  = str[x] - 'A';
            str[x] = 'a' + aux;
        }
        else
        {
        }
    }
}
void imprime(Lista *l, indicePalavra *indices, int quantidadeLinhas) //imprime a lista
{
    Lista *aux1;// auxiliar usada para impressao
    indicePalavra *indice;// auxiliar usada para impressao
    int i = 0;
    printf("\n\n\n\t\tDICIONARIO:\n\n");
    //são feitos dois for, o primeiro para exibição da palavra
    for (aux1 = l, indice = indices ; aux1 != NULL; aux1 = aux1->prox )
    {
        //o segundo para exibição das ocorrencias
        printf("\n%s ", aux1->palavra);
        for (i = 0 ; i <= quantidadeLinhas; indice = indice->prox, i++)
        {
            if (indice->quantidade > 0 )
            printf("<%d/%d> ", indice->linhaPalavra, indice->quantidade);
        }
        printf ("\n");
    }
    printf ("\n\n\n");
}

void libera( Lista *li){
    Lista *aux = li;
    while (li != NULL){
        aux = li;
        li = li->prox;
        free(aux);
    }
}
void liberaIndice( indicePalavra *li){
    indicePalavra *aux = li;
    while (li != NULL){
        aux = li;
        li = li->prox;
        free(aux);
    }
}

