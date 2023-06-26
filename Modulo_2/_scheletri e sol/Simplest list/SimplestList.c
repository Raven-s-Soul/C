#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    int dato;
    struct nodo *next;
};

void leggi(struct nodo *punta)
{
    struct nodo *bkHead = punta;

    while (bkHead != NULL)
    {
        printf("%d ", bkHead->dato);
        bkHead = bkHead->next;
    }
}

void scrivi(struct nodo **testa, int n)
{
    for (int i = 0; i < n; i++)
    {
        struct nodo *nuovoNodo = malloc(sizeof(struct nodo));
        printf("Inserire un numero: ");
        scanf("%d", &(nuovoNodo->dato));
        nuovoNodo->next = *testa;
        *testa = nuovoNodo;
    }
}

int main()
{
    struct nodo *testa = NULL;
    int n;
    printf("Quanti numeri vuoi inserire? ");
    scanf("%d", &n);
    scrivi(&testa, n);
    leggi(testa);
}
