/*
Trabalho Final EDI
Alunos: Larissa Santos e Bruno Reis
Disciplina: Estrutura de Dados I
IDE: Code Blocks 16.01
Compilador: GNU GCC
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "arquivo.h"


int main(){
    setlocale(LC_ALL, "Portuguese");
    FILE *arquivo = fopen("arquivo.txt", "r"); // ler o arquivo de texto
    char palavra[100];
    char textoOriginal[10000];
    int j=0; // contador usado no auxilio ao vetor que recebera o texto
    int linha = 0; //auxiliar para contar as linhas
    int a=0; // contador usado no auxilio ao vetor que recebera a palavra
    int quantidadeLinhas = 0;

    Lista *TodasPalavras; // Lista que receberar todas as palavras sem nem um filtro
    TodasPalavras = cria(); // criando a lista

    Lista *lPalavrasUnicas; // Lista que receberar todas as palavras filtradas
    lPalavrasUnicas = cria(); // criando a lista

    Lista *aux; //criando uma variavel ponteiro auxiliar para percorrer a lista com todas as palavras sem filtro
    Lista *aux2; //criando uma variavel ponteiro auxiliar para percorrer a lista com todas as palavras sem filtro
    indicePalavra *aux3;

    indicePalavra *indices; // lista que recebera os indices de cada palavra
    indices = criaIndice();

    indicePalavra *indicesOrganizado; // lista que recebera os indices de cada palavra
    indicesOrganizado = criaIndice();

    if (arquivo == NULL) // verifica se o arquivo foi aberto
    {
        printf ("Erro\n");
        exit(1);
    }
    else // se foi aberto o programa inicializa suas funçoes
    {
        char c; // caracter auxiliar usado para receber cada char do arquivo
        j = 0;
        printf("\n\n\t\tENTRADA:\n\n");
        while((c = fgetc(arquivo)) != EOF) // condição para ler todo arquivo ate chegar ao fim
        {
            if (c != ' ' && c != '\n') //condição de controle para inserção das palavras em cada vetor abaixo
            {
                palavra[j++] = c; // variavel vetor que recebe a palavra se diferente de espaço ou enter
                textoOriginal[a++] = c; // variavel vetor que recebe a palavra se diferente de espaço ou enter
            }
            else
            {
                textoOriginal[a++] = c; // o texto continua a ser armazenado
                palavra[j] = '\0'; // e dado fim a palavra para inserção
                tratamento1 (palavra); // e feito o tratamento de minusculo para maiusculo
                insere(&TodasPalavras, palavra, linha); // inserido a palavra na lista que contera todas as palavras sem filtro
                if (c == '\n') // se igual a \n o contador de linha sera somado +1 ao seu valor para ter o  controle das linhas
                {
                    linha++;
                    quantidadeLinhas++;
                }

                strcpy(palavra,"\0"); // por fim e alocado "\0" para começar novamente a inserção de valores
                j = 0; // variavel contador que auxiliar o vetor palavra e zerado para colocar os caracteres na posição 0 por diante
            }
        }
        textoOriginal[a] = '\0'; // apos percorrer todo arquivo e finalizado o texto com '\o'
        printf("%s\n", textoOriginal); // imprimindo o texto pra ver que realmente funcionou
   }

    for (aux = TodasPalavras ; aux != NULL; aux= aux->prox) //aqui se percorre a lista com todas as palavras
    {

        insereSomentePalavrasUnicas(&lPalavrasUnicas,aux->palavra); //a função faz o filtro e insere as palavras apenas uma vez mesmo que repita
    }
    for (aux2 = lPalavrasUnicas ; aux2 != NULL; aux2 = aux2->prox)
    {
//    chamar a função e salvar os indices e as palavras
        insereIndices(&TodasPalavras, &indices, aux2->palavra, quantidadeLinhas);
    }

    for (aux3 = indices ; aux3 != NULL; aux3 = aux3->prox)
    {
//    chamar a função e salvar os indices invertendo os mesmos para impressao certa
        insereOcorrencias(&indicesOrganizado, aux3->linhaPalavra, aux3->quantidade);
    }
    libera(TodasPalavras);
    liberaIndice(indices);

    imprime(lPalavrasUnicas, indicesOrganizado, quantidadeLinhas);  //imprime todas as palaavras acima separdas salva na lista PalavrasUnicas


    fclose(arquivo);
}
