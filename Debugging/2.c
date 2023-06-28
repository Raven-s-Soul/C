#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**************
*****STRUTTURE*******
***************/
typedef struct data
{
    int giorno;
    int mese;
    int anno;
} DATA;
typedef struct persona
{
    char nome[20];
    char cognome[20];
    DATA nascita;
} P;

struct nodo
{
    P p;
    struct nodo *next;
};
typedef struct nodo *NODO;

/**************
***INSERIMENTO*******
***************/
DATA leggiData()
{
    DATA d;
    printf("Inserisci il giorno di nascita:\n");
    scanf("%d%*c", &d.giorno);
    printf("Inserisci il mese di nascita:\n");
    scanf("%d%*c", &d.mese);
    printf("Inserisci l' anno di nascita:\n");
    scanf("%d%*c", &d.anno);
    return d;
}
P leggiPersona()
{
    P p;
    printf("Inserisci il nome della persona:\n");
    fgets((p.nome), 20, stdin);
    (p.nome)[strlen(p.nome) - 1] = '\0';
    printf("Inserisci il cognome della persona:\n");
    fgets((p.cognome), 20, stdin);
    (p.cognome)[strlen(p.cognome) - 1] = '\0';
    p.nascita = leggiData();
    return p;
}

NODO inserimentoCoda(NODO *head)
{
    NODO nuovoNodo = malloc(sizeof(NODO));

    nuovoNodo->p = leggiPersona();

    nuovoNodo->next = NULL;
    if (*head == NULL)
        *head = nuovoNodo;
    else
        while ((*head)->next != NULL)
            *head = (*head)->next;
    (*head)->next = nuovoNodo;
    printf("Inserimento avvenuto :)\n");
    printf("\n%s\n", (*head)->next->p.nome);
    return *head;
}
/**************
****VISUALIZZA*******
***************/
void stampaPersona(P p)
{
    printf("Nome: %s, Cognome: %s, Data di Nascita: %d/%d/%d\n", p.nome, p.cognome, p.nascita.giorno, p.nascita.mese, p.nascita.anno);
}

void stampaLista(NODO head)
{
    if (head == NULL)
        printf("Niente da stampare :(\n");
    else
    {
        printf("Ecco la lista!!!\n");
        while (head != NULL)
        {
            stampaPersona(head->p);
            head = head->next;
        }
        printf("\n");
    }
}
/**************
***CANCELLAZIONE*******
***************/
void eliminaTesta(NODO *head)
{
    NODO nodo;

    if (*head != NULL)
    {
        nodo = (*head)->next;
        free(*head);
        *head = nodo;
    }
    printf("Cancellazione effettuata :)\n");
}

/**************
******MAIN*******
***************/
int main()
{
    int risposta = -1;
    NODO head = NULL;

    while (risposta != 0)
    {
        printf("Che operazione vuoi azionare:\n");
        printf("Introduci 1->Inserisci una persona in coda alla lista\n");
        printf("Introduci 2->Cancelli la persona in testa alla lista\n");
        printf("Introduci 3->Visualizzi la lista\n");
        printf("Introduci 0->Termina programma\n");
        scanf("%d%*c", &risposta);

        if (risposta == 1)
            head = inserimentoCoda(&head);
        else if (risposta == 2)
            eliminaTesta(&head);
        else if (risposta == 3)
            stampaLista(head);
        else if (risposta != 0)
            printf("Inserisci qualcosa che abbia senso grazie :)\n");
    }
}