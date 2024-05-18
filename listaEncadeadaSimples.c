#include <stdio.h>
#include <stdlib.h>

typedef struct noDaLista
{
    int valor;
    struct noDaLista *proximo;
} No;

typedef struct listaEncadeada
{
    No *inicio;
    int tamanho;
} Lista;

void inserirInicio(Lista *listaPorRef, int valor)
{                                            // Passa a lista por referencia pras alterações se manterem ao final da função
    No *novo = (No *)malloc(sizeof(No));     // cria o espaço que precisar
    (*novo).valor = valor;                   // O novo nó recebe o valor efetivamente
    (*novo).proximo = (*listaPorRef).inicio; // Esse novo nó passa a apontar pra NULL, de início
    (*listaPorRef).inicio = novo;            // E o novo nó passa a ser o início da lista
    (*listaPorRef).tamanho++;                // Atualiza o tamanho da lista
}

void imprimirLista(Lista *listaPorRef)
{
    No *inicioAux = (*listaPorRef).inicio; // Cria um ponteiro auxiliar pra receber os valores de inicio da lista
    while (inicioAux != NULL)
    {                                      // Cria loop pra impressão, já que a lista não tem um tamanho fixo (não é vetor)
        printf("%d ", (*inicioAux).valor); // Printa os valores atrelados ao nosso auxiliar que indica posição
        inicioAux = (*inicioAux).proximo;  // Atualiza o valor do auxiliar pro inicio ser o proximo valor agora
    }
    printf("\n\n");
}

void InserirFinal(Lista *listaPorRef, int valor)
{
    No *aux, *novo = (No *)malloc(sizeof(No));
    (*novo).valor = valor;  // Valor inserido é associado ao novo nó, que é o ponteiro "novo"
    (*novo).proximo = NULL; // Esse novo nó já recebe o seu próximo como NULL, visto que ele será o último da lista

    if ((*listaPorRef).inicio == NULL)
    {                                 // Esse primeiro if verifica se a lista tá vazia, ou seja, com início NULL, aí a inserção pode ser feito de qualquer jeito
        (*listaPorRef).inicio = novo; // Insere o novo valor
    }
    else
    {
        aux = (*listaPorRef).inicio;   // Senão o ponteiro aux recebe o inicio da lista
        while ((*aux).proximo != NULL) // E verifica se seu proximo é NULL
            aux = (*aux).proximo;      // E vai percorrendo a lista até bater a condição
        (*aux).proximo = novo;         // Batendo a condição, sai do while e insere o novo valor com suas caracteristicas como sendo o novo proximo do valor que tinha como proximo o NULL, tomando o lugar desse NULL
    }
    listaPorRef->tamanho++; // Atualiza o tamanho da lista
}

void remover(Lista *listaPorRef, int valor)
{
    No *inicio = (*listaPorRef).inicio;
    No *noARemover = NULL;

    if ((*listaPorRef).inicio != NULL && listaPorRef->inicio->valor == valor)
    {
        noARemover = (*listaPorRef).inicio;
        (*listaPorRef).inicio = (*noARemover).proximo;
    }
    else
    {

        while (inicio != NULL && inicio->proximo != NULL && inicio->proximo->valor != valor)
            inicio = inicio->proximo;

        if (inicio != NULL && inicio->proximo != NULL)
        {
            noARemover = inicio->proximo;
            inicio->proximo = noARemover->proximo;
        }
    }
    if (noARemover)
    {
        free(noARemover);
        listaPorRef->tamanho--;
    }
}

int main()
{
    Lista listaEncad;
    int opcao, valor;

    listaEncad.inicio = NULL;
    listaEncad.tamanho = 0;

    do
    {
        printf("\n1 - Inserir no Inicio\n2 - Imprimir\n3 - Inserir no Fim\n4 - Remover\n5 - Sair\n\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("\nInsira um valor: ");
            scanf("%d", &valor);
            inserirInicio(&listaEncad, valor);
            break;
        case 2:
            imprimirLista(&listaEncad);
            break;
        case 3:
            printf("\nInsira um valor: ");
            scanf("%d", &valor);
            InserirFim(&listaEncad, valor);
            break;
        case 4:
            printf("\nInsira um valor a ser removido: ");
            scanf("%d", &valor);
            remover(&listaEncad, valor);
            break;
        case 5:
            printf("\nFinalizando...\n\n");
            break;
        default:
            printf("\nOpção Inválida!\n\n");
        }
    } while (opcao != 5);

    return 0;
}
