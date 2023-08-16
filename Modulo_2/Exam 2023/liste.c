#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxLenStringa 50

/***************
/*****	STRUTTURE *******
****************/

typedef struct punto
{
    float x, y;
} P;

typedef struct rettangolo
{
    char colore[maxLenStringa];
    P bs;
    float base, altezza;
} R;

typedef struct nodo
{
    R rettangolo;
    struct nodo *next;
} N;

/****************
 ***** VISUALIZZAZIONE ******
 ****************/

void printLista(N *head)
{
    if (head == NULL)
    {
        printf("\nLista vuota\n");
    }
    else
    {
        for (int i = 0; head != NULL; i++)
        {
            printf("\nRettangolo \"%d\":", i + 1);
            printf("\nColore: %s", head->rettangolo.colore);
            printf("\nPunti: A(%f:%f) B(%f:%f) C(%f:%f) D(%f:%f)\n",
                   head->rettangolo.bs.x, head->rettangolo.bs.y,
                   head->rettangolo.bs.x + head->rettangolo.base, head->rettangolo.bs.y,
                   head->rettangolo.bs.x + head->rettangolo.base, head->rettangolo.bs.y + head->rettangolo.altezza,
                   head->rettangolo.bs.x, head->rettangolo.bs.y + head->rettangolo.altezza);
            head = head->next;
        }
    }
}

/***************
 ***** INSERIMENTO *******
 ****************/

N *inserimentoSecondoPosto(N *head)
{
    if (head == NULL)
    {
        // Inserimento in testa
        printf("\nInserimento come unico elemento della lista\n");
        N *newNodo = malloc(sizeof(N));
        printf("\nInserire colore dell rettangolo: ");
        fgets(newNodo->rettangolo.colore, maxLenStringa, stdin);
        newNodo->rettangolo.colore[strlen(newNodo->rettangolo.colore) - 1] = '\0';
        printf("\nInserire il punto in basso a sinistra: \nx : ");
        scanf("%f%*c", &newNodo->rettangolo.bs.x);
        printf("\ny : ");
        scanf("%f%*c", &newNodo->rettangolo.bs.y);
        printf("\nInserire la base: ");
        scanf("%f%*c", &newNodo->rettangolo.base);
        printf("\nInserire l'altezza: ");
        scanf("%f%*c", &newNodo->rettangolo.altezza);
        newNodo->next = NULL;
        head = newNodo;
        printf("\nLista non piu' vuota\n");
    }
    else
    {

        N *goingTo = head->next;

        N *newNodo = malloc(sizeof(N));
        printf("\nInserire colore dell rettangolo: ");
        fgets(newNodo->rettangolo.colore, maxLenStringa, stdin);
        newNodo->rettangolo.colore[strlen(newNodo->rettangolo.colore) - 1] = '\0';
        printf("\nInserire il punto in basso a sinistra: \nx : ");
        scanf("%f%*c", &newNodo->rettangolo.bs.x);
        printf("\ny : ");
        scanf("%f%*c", &newNodo->rettangolo.bs.y);
        printf("\nInserire la base: ");
        scanf("%f%*c", &newNodo->rettangolo.base);
        printf("\nInserire l'altezza: ");
        scanf("%f%*c", &newNodo->rettangolo.altezza);
        newNodo->next = goingTo;

        head->next = newNodo;
    }
    return head;
}

/****************
 ***** CANCELLAZIONE ******
 ****************/

N *cancellazione(N *head)
{

    if (head == NULL)
    {
        printf("\nLista vuota impossibile cancellare\n");
    }
    else
    {
        N *reHead = head;
        int trovato = 1;
        if (head->rettangolo.base == 10 || head->rettangolo.altezza == 10)
        {
            printf("\nCancellazione in testa\n");
            N *aux = head->next;
            free(head);
            head = aux;
        }
        else
        {

            N *preCancella = head;
            reHead = reHead->next;
            while (reHead != NULL && trovato)
            {
                if (reHead->rettangolo.base == 10 || reHead->rettangolo.altezza == 10)
                {
                    trovato = 0;
                    printf("\nCancellazione rettangolo con lato uguale a 10\n");
                    N *aux = reHead->next;
                    free(reHead);
                    preCancella->next = aux;
                }

                else
                {
                    preCancella = preCancella->next;
                    reHead = reHead->next;
                }
            }
            if (trovato == 1)
            {
                printf("\nLato uguale a 10 non trovato\n");
            }
        }
    }
    return head;
}

/****************
 **** FUNZIONE PRINCIPALE ****
 ****************/

int main()
{
    /* inizializza la lista */
    N *head = NULL;

    int risposta = -1; // per interazione con utente

    while (risposta != 0)
    {
        /* richiedi un'operazione all'utente */
        printf("Che operazione vuoi svolgere?\n");
        printf("1 -> Visualizzazione\n");
        printf("2 -> Inserimento\n");
        printf("3 -> Cancellazione\n");
        printf("0 -> Termina il programma\n");
        scanf("%d%*c", &risposta);

        /* gestisci le operazioni dell'utente */
        if (risposta == 1)
        {
            // Visualizzazione
            printLista(head);
        }
        else if (risposta == 2)
        {
            // Inserimento
            head = inserimentoSecondoPosto(head);
        }
        else if (risposta == 3)
        {
            // Cancellazione
            head = cancellazione(head);
        }
        else if (risposta == 0)
            printf("Finito!\n\n");
        else
            printf("Selezione non valida!\n\n");
    }
}