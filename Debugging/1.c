#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/********/
/*STRUTTURE**/
/********/

typedef struct punto
{
    float x;
    float y;
} P;

typedef struct cerchio
{
    P centro;
    float raggio;
} C;

typedef struct nodo
{
    C c;
    struct nodo *next;
} *N;

/********/
/*LETTURE****/
/********/
C leggiCerchio()
{
    C c;
    printf("Inserisci la coordinata x del centro: ");
    scanf("%d", &c.centro.x);
    printf("Inserisci la coordinata y del centro: ");
    scanf("%d", &c.centro.y);
    do
    {
        printf("Inserisci il raggio: ");
        scanf("%d", &c.raggio);
        if (c.raggio <= 0)
            printf("Il raggio deve essere positivo!");
    } while (c.raggio <= 0);
    return c;
}

/********/
/**STAMPE****/
/********/

// per stampare cerchio/
void stampaCerchio(C c)
{
    printf("Il cerchio ha raggio %.2f e centro (%.2f,%.2f)\n", c.raggio, c.centro.x, c.centro.y);
}

// per stampare la lista /
void stampaLista(N lista)
{
    // vai avanti fino a che ci sono cerchi /
    if (lista == NULL)
        printf("La lista %c vuota\n", 138);
    else
    {
        printf("Ecco la lista di cerchi\n");
        while (lista != NULL)
        {
            stampaCerchio(lista->c);
            lista = lista->next;
        }
        printf("\n");
    }
}

/********/
/*INSERIMENTO**/
/********/

void inserimentoTesta(struct nodo **head)
{
    N nuovoNodo;
    nuovoNodo = malloc(sizeof(N));

    // inserisci campo dati /
    nuovoNodo->c = leggiCerchio();

    nuovoNodo->next = *head;

    *head = nuovoNodo;
    printf("Inserimento avvenuto!\n");
}

/********/
/*CANCELLAZIONE**/
/********/

// cancellazione di un cerchio in base a quello che vuole l'utente/
N cancellazione(N head)
{
    int risposta = 0; // per interazione utente
    N nodoCorrente;
    N nodoPrec;

    // se la lista è vuota non cancelli niente /
    if (head != NULL)
    {
        printf("Ecco il primo cerchio della lista:\n");
        stampaCerchio(head->c);
        printf("E' questo il cerchio che vuoi cancellare? (1=SI, 0=NO)\n");
        scanf("%d", &risposta);
        if (risposta == 1)
        {
            nodoCorrente = head;
            head = head->next;
            free(nodoCorrente);
        }
        // cancelli un cerchio che non è il primo /
        else
        {
            nodoCorrente = head->next; // parti dal secondo
            nodoPrec = head;
            while (nodoCorrente != NULL && risposta != 1)
            {
                printf("Ecco un nuovo cerchio della lista:\n");
                stampaCerchio(nodoCorrente->c);
                printf("E' questo il cerchio che vuoi cancellare? (1=SI, 0=NO)\n");
                scanf("%d", &risposta);
                if (risposta == 1)
                {
                    nodoPrec->next = nodoCorrente->next;
                    free(nodoCorrente);
                }
                else
                {
                    nodoCorrente = nodoCorrente->next;
                    nodoPrec = nodoPrec->next;
                }
            }
        }
    }
    if (risposta == 1)
        printf("Nodo cancellato!\n\n");
    else
        printf("Non ho cancellato niente!\n\n");
    return head;
}

/********/
/*VERIFICA***/
/********/

// distanza tra i due punti /
float distanza(P p1, P p2)
{
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// restituisce 1 se il primo cerchio è contenuto nel secondo /
int contenuto(C c1, C c2)
{
    /*il primo è contenuto nel secondo se e solo se: la distanza fra i centri
     * più il raggio del cerchio c1 è minore o uguale al raggio del centro c2*/
    return distanza(c1.centro, c2.centro) + c1.raggio <= c2.raggio;
}

void verifica(N head)
{
    if (head == NULL || head->next == NULL)
        printf("Non ci sono abbastanza cerchi per la verifica\n");
    else
    {
        if (contenuto(head->c, head->next->c))
            printf("Il primo %c contenuto nel secondo\n", 138);
        else
            printf("Il primo NON %c contenuto nel secondo\n", 138);
    }
}

/********/
/*GESTIONE FILE**/
/********/

// funzione per l'acquisizione di una lista su file//
N acquisizione()
{
    FILE *fp = fopen("cerchi.dat", "rb");
    N head = NULL;
    N corrente;
    N precedente;

    C cerchio;
    int letto; // lettura ok o no

    // se non hai aperto il file non devi fare niente /
    if (fp != NULL)
    {
        // leggi il primo nodo della lista /
        letto = fread(&cerchio, sizeof(C), 1, fp);
        if (letto)
        {
            // memorizza nell'heap il primo nodo della lista/ head = malloc(sizeof(N)); head->c = cerchio;

            /* devi tenere traccia dell'ultimo nodo letto, per collegarlo al successivo nella lista */
            precedente = head;
            // leggi gli altri nodi /
            do
            {
                letto = fread(&cerchio, sizeof(C), 1, fp);
                if (letto)
                {
                    corrente = malloc(sizeof(N));
                    corrente->c = cerchio;

                    precedente->next = corrente;

                    precedente = corrente;
                }
                else
                    precedente->next = NULL;
            } while (letto);
            printf("Lista recuperata da file!\n");
        }
        else
            printf("Lista vuota, niente da recuperare!\n");
        fclose(fp);
    }
    else
        printf("Apertura file non riuscita!\n");
    return head;
}

// funzione per il salvataggio di una lista su file /
void salvataggio(N lista)
{
    FILE *fp = fopen("cerchi.dat", "wb");
    if (fp == NULL)
    {
        while (lista != NULL)
        {
            fwrite(&(lista->c), sizeof(C), 1, fp);
            lista = lista->next;
        }
        fclose(fp);
        printf("Salvataggio eseguito!\n");
    }
    else
        printf("Salvataggio non eseguito\n");
}

/********/
/***MAIN***/
/********/
int main()
{
    // creo lista /
    N lista = acquisizione();

    int risposta = -1; // per interazione utente

    while (risposta != 0)
    {
        printf("Che operazione vuoi svolegere?\n");
        printf("1 -> Inserisci un cerchio nella lista\n");
        printf("2 -> Cancella un cerchio dalla lista\n");
        printf("3 -> Visualizza la lista\n");
        printf("4 -> Verifica se il primo cerchio della lista %c contenuto nel secondo\n", 138);
        printf("0 -> Termina il programma\n");
        scanf("%d", &risposta);

        if (risposta == 1)
            inserimentoTesta(&lista);
        else if (risposta == 2)
            cancellazione(lista);
        else if (risposta == 3)
            stampaLista(lista);
        else if (risposta == 4)
            verifica(lista);
        else if (risposta == 0)
            printf("\nAdios!!!\n");
        else
            printf("Selezione non valida\n");
    }
    salvataggio(lista);
}