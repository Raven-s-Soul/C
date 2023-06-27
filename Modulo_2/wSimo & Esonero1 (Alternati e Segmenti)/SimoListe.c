#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*****************************/
/********* STRUTTURE *********/
/*****************************/

typedef struct punto
{
    float x, y;
} P;

typedef struct segmento
{
    P a, b;
} S;

typedef struct nodo
{
    S seg;
    struct nodo *next;

} N;

//*(1pt) Definire delle strutture per rappresentare un punto, un segmento, ed un nodo della lista.

float Plen(P a, P b)
{
    P lun;
    if (a.x > b.x)
    {
        lun.x = a.x - b.x;
    }
    else
    {
        lun.x = b.x - a.x;
    }
    if (a.y > b.y)
    {
        lun.y = a.y - b.y;
    }
    else
    {
        lun.y = b.y - a.y;
    }

    return (sqrt((lun.x * lun.x) + (lun.y * lun.y)));
}

/**********************************************
 **************** INSERIMENTO *****************
 **********************************************/

N *inserimento(N *head)
{
    N *newNodo = malloc(sizeof(N));
    // leggi i campi

    printf("\nA x: ");
    scanf("%f%*c", &(newNodo->seg.a.x));
    printf("\nA y: ");
    scanf("%f%*c", &(newNodo->seg.a.y));
    printf("\nB x: ");
    scanf("%f%*c", &(newNodo->seg.b.x));
    printf("\nB y: ");
    scanf("%f%*c", &(newNodo->seg.b.y));

    newNodo->next = head;
    return newNodo;
}

//*(4pt) Definire una funzione che inserisce un segmento in coda alla lista.

N *inserimentoCoda(N *head)
{

    N *newNodo = malloc(sizeof(N));
    newNodo->next = NULL;
    if (head == NULL)
    {
        head = newNodo;
    }
    else
    {
        N *reHead = head;
        while (reHead->next != NULL)
        {
            reHead = reHead->next;
        }
        reHead->next = newNodo;
    }

    printf("\nA x: ");
    scanf("%f%*c", &(newNodo->seg.a.x));
    printf("\nA y: ");
    scanf("%f%*c", &(newNodo->seg.a.y));
    printf("\nB x: ");
    scanf("%f%*c", &(newNodo->seg.b.x));
    printf("\nB y: ");
    scanf("%f%*c", &(newNodo->seg.b.y));

    return head;
}

/**********************************************
 ******* CANCELLAZIONE ************************
 **********************************************/

//* To cmplete

N *cancellare(N *head)
{
    // Lista vuota
    if (head == NULL)
    {
        printf("\nLista vuota, niente da cancellare\n\n");
    }
    else
    { // In testa
        if (Plen(head->seg.a, head->seg.b) == 12)
        {
            N *deal = head;
            head = head->next;
            free(deal);
            printf("\nCancellazione 1' elemento della lista\n\n");
        }
        else
        { // Non in testa
            N *reHead = head;
            int status = 0;
            while (reHead != NULL && status != 1)
            {
                float len = Plen(reHead->seg.a, reHead->seg.b);
                if (len == 12)
                {
                    printf("\n Trovato segmento con lunghezza 12\n");
                    status = 1;
                    N *buffer = reHead;
                    reHead = reHead->next;
                    free(buffer);
                }
                else
                {
                    reHead = reHead->next;
                }
            }
            if (status == 0)
            {
                printf("\nNon trovato un segmento con lunghezza 12\n");
            }
        }
    }
    return head;
}

//? (5,5pt) Definire una funzione che cancella il primo segmento della lista la cui lunghezza è pari a
//? 12 o, se tale segmento non esiste, stampa il messaggio “non esiste nessun segmento lungo 12”.

/**************************************/
/*********** VISUALIZZAZIONE **********/
/**************************************/

void printLista(N *head)
{
    N *cpyHead = head;

    if (cpyHead == NULL)
    {
        printf("\nLista vuota\n");
    }
    else
    {
        printf("\nEcco la Lista:\n");
        for (int i = 1; cpyHead != NULL; i++)
        {
            // print
            printf("\nSegmento %d A x: %f\n", i, cpyHead->seg.a.x);
            printf("\nSegmento %d A y: %f\n", i, cpyHead->seg.a.y);
            printf("\nSegmento %d B x: %f\n", i, cpyHead->seg.b.x);
            printf("\nSegmento %d B y: %f\n", i, cpyHead->seg.b.y);
            float len = Plen(cpyHead->seg.a, cpyHead->seg.b);
            printf("\nSegmento %d lenght: %f\n", i, len);
            printf("--------------------------\n");
            cpyHead = cpyHead->next;
        }
    }
}

//*(1,5pt) Definire una funzione che visualizza una lista di segmenti, stampando per ciascun
//*segmento le coordinate dell’estremo sinistro, le coordinate dell’estremo destro e la lunghezza
//*del segmento.

/**********************************************
 ************ FUNZIONE PRINCIPALE ************
 **********************************************/

int main()
{
    N *head = NULL;
    /* inizializza la lista */

    int risposta = -1; // per interazione con utente

    while (risposta != 0)
    {
        /* richiedi un'operazione all'utente */
        printf("Che operazione vuoi svolgere?\n");
        printf("1 -> Inserimento\n");
        printf("2 -> Inserimento in coda\n");
        printf("3 -> Cancellazione\n");
        printf("4 -> Visualizzazione\n");
        printf("0 -> Termina il programma\n");
        scanf("%d%*c", &risposta);

        /* gestisci le operazioni dell'utente */
        if (risposta == 1)
        {
            //* inserimeto
            head = inserimento(head);
        }

        else if (risposta == 2)
        {
            //* coda
            head = inserimentoCoda(head);
        }

        else if (risposta == 3)
        {
            //* cancellazione
            head = cancellare(head);
        }

        else if (risposta == 4)
        {
            //* visualizzazione
            printLista(head);
        }

        else if (risposta == 0)
            printf("Finito!\n\n");
        else
            printf("Selezione non valida!\n\n");
    }
}