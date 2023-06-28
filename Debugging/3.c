#include <stdio.h>
#include <stdlib.h>

/******************
*******STRUTTURE*********
*****************/
typedef struct punto
{
    float x;
    float y;
} P;

typedef struct segmento
{
    P p;
    float lunghezza;
} S;

struct nodo
{
    S s;
    struct nodo *next;
};
typedef struct nodo *NODO;

/******************
*******INSERIMENTO*******
*****************/
P leggiPunto()
{
    P p;
    printf("Inserisci la coordinata x del punto:\n");
    scanf("%f%*c", &p.x);
    printf("Inserisci la coordinata y del punto:\n");
    scanf("%f%*c", &p.y);
    return p;
}

S leggiSegmento()
{
    S s;
    printf("Inserisci la lunghezza del punto:\n");
    scanf("%f%*c", &s.lunghezza);
    s.p = leggiPunto();
    return s;
}

NODO inserimento(NODO *head)
{
    NODO nuovoNodo = malloc(sizeof(NODO));

    nuovoNodo->s = leggiSegmento();
    nuovoNodo->next = NULL;

    if (*head == NULL)
        *head = nuovoNodo;
    else
    {
        NODO *nodoCorrente = head;
        while ((*nodoCorrente)->next != NULL)
            *nodoCorrente = (*nodoCorrente)->next;
        (*nodoCorrente)->next = nuovoNodo;

        //* while ((*head)->next != NULL)
        //     *head = (*head)->next;
        //* (*head)->next = nuovoNodo;
    }
    printf("Inserimento avvenuto :)\n");
    return *head;
}
/******************
*******CANCELLAZIONE*******
*****************/
void cancella(NODO *head)
{
    NODO nodo;

    if ((*head)->s.lunghezza == 12)
    {
        nodo = *head;
        *head = (*head)->next;
        free(nodo);
        printf("Cancellazione effettuata\n");
    }
    else
    {
        int trovato = 0; // vale 1 se c'è il segmento con lunghezza = 12
        while ((*head)->next != NULL && !trovato)
        {
            if ((*head)->next->s.lunghezza == 12)
                trovato = 1;
            else
                *head = (*head)->next;
        }
        if (trovato == 1)
        {
            nodo = (*head)->next;
            (*head)->next = (*head)->next->next;
            free(nodo);
            printf("Cancellazione effettuata");
        }
        else
            printf("Non esistono segmenti di lunghezza 12\n");
    }
}

/******************
*******VISUALIZZA********
*****************/
void stampaSegmento(S s)
{
    printf("\nLunghezza: %.2f, Coordinate: (%.2f,%.2f)\n", s.lunghezza, s.p.x, s.p.y);
}

void stampaLista(NODO head)
{
    NODO currentNode = head;

    if (currentNode == NULL)
    {
        printf("Niente da stampare :(\n");
    }
    else
    {
        printf("Ecco la lista\n");
        while (currentNode != NULL)
        {
            stampaSegmento(currentNode->s);
            currentNode = currentNode->next;
        }
    }
}

/******************
********MAIN*********
*****************/
int main()
{
    int risposta = -1;
    NODO head = NULL;

    while (risposta != 0)
    {
        printf("Che operazione vuoi fare?\n");
        printf("Introduci 1->Cancella primo segmento con lunghezza pari 12\n");
        printf("Introduci 2->Inserimento in coda alla lista\n");
        printf("Introduci 3->Visualizza lista\n");
        printf("Introudci 0->Termina programma\n");
        scanf("%d%*c", &risposta);

        if (risposta == 1)
            cancella(&head);
        else if (risposta == 2)
            head = inserimento(&head);
        else if (risposta == 3)
            stampaLista(head);
        else if (risposta != 0)
            printf("Numero non valido\n");
    }
}