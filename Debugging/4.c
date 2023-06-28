#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fritto
{
    char nome[20];
    float prezzo;
    char tipo;
} FRITTO;

struct nodo
{
    FRITTO f;
    struct nodo *next;
};
typedef struct nodo *NODO;

/******************
*******INSERIMENTO*******
*****************/
FRITTO leggiFritto()
{
    FRITTO f;
    printf("Inserisci il nome del fritto:\n");
    fgets(f.nome, 20, stdin);
    f.nome[strlen(f.nome) - 1] = '\0';
    printf("Inserisci il prezzo: \n");
    scanf("%f%*c", &f.prezzo);
    do
    {
        printf("Inserisci 'f' se %c fresco o 's' se %c surgelato:\n", 138, 138);
        scanf("%c", &f.tipo);
        if (f.tipo != 'f' && f.tipo != 's')
            printf("Inserimento non valido\n");
    } while (f.tipo != 'f' && f.tipo != 's');
    return f;
}
void inserimentoCoda(NODO *head)
{
    NODO nuovoNodo = malloc(sizeof(NODO));

    nuovoNodo->f = leggiFritto();
    nuovoNodo->next = NULL;

    if (*head == NULL)
        *head = nuovoNodo;
    else
    {
        while (*head != NULL)
            *head = (*head)->next;
        (*head)->next = nuovoNodo;
    }
    printf("Inserimento avvenuto\n");
}

/******************
*******VISUALIZZA********
*****************/
void stampaFritto(FRITTO f)
{
    printf("Nome: %s, Prezzo: %.2f, Tipo: %c\n", f.nome, f.prezzo, f.tipo);
}

void stampaLista(NODO head)
{
    if (head == NULL)
        printf("Niente da stampare\n");
    else
    {
        printf("\nEcco la lista:\n");
        while (head != NULL)
        {
            stampaFritto(head->f);
            head = head->next;
        }
    }
}

/******************
*******ORDINA LISTA********
*****************/

int precede(FRITTO *f1, FRITTO *f2)
{
    return ((f1->tipo == 'f' && f2->tipo == 's') || ((f1->tipo == f2->tipo) && (f1->prezzo <= f2->prezzo)));
}

void scambia(FRITTO *f1, FRITTO *f2)
{
    FRITTO f;
    f = *f1;
    *f1 = *f2;
    *f2 = f;
}

void ordinaLista(NODO *head)
{

    if (*head == NULL || (*head)->next == NULL)
        printf("Lista piccola!\n");
    else
    {
        int cambiato = 1;
        while (cambiato != 0)
        {
            cambiato = 0;
            for (NODO nodo = *head; nodo != NULL; nodo = nodo->next)
            {
                if (precede(&(nodo->next->f), &(nodo->f)))
                {
                    scambia(&(nodo->f), &(nodo->next->f));
                    cambiato = 1;
                }
            }
        }
    }
}

/******************
********FILE*********
*****************/
NODO acquisizione()
{
    NODO head = NULL;
    NODO nodo;
    FILE *fp = fopen("fritti.txt", "r");
    if (fp == NULL)
        printf("Recupero non riuscito\n\n");
    else
    {
        head = malloc(sizeof(NODO));
        nodo = head; // per scorrere la lista
        /* variabili per leggere nome, prezzo e tipo */
        char nome[30];
        float p;
        char tipo;

        while (fscanf(fp, "%s%f%*c%c%*c", nome, &p, &tipo) != EOF)
        {
            nodo = nodo->next;
            strcpy(nodo->f.nome, nome);
            nodo->f.prezzo = p;
            nodo->f.tipo = tipo;
        }
        printf("Recupero riuscito\n\n");
        nodo->next = NULL;
    }
    fclose(fp);

    return head;
}

void salvataggio(NODO head)
{
    FILE *fp = fopen("fritti.txt", "w");
    if (fp == NULL)
        printf("Salvataggio non riuscito\n\n");
    else
    {
        while ((head) != NULL)
        {
            fprintf(fp, "%s %f %c\n", (head)->f.nome, (head)->f.prezzo, (head)->f.tipo);
            (head) = (head)->next;
        }

        printf("Salvataggio riuscito\n\n");
        fclose(fp);
    }
}

/****************
 **** FUNZIONE PRINCIPALE ****
 ****************/

int main()
{
    /* inizializza la lista */
    NODO head = acquisizione();

    int risposta = -1; // per interazione con utente

    while (risposta != 0)
    {
        /* richiedi un'operazione all'utente */
        printf("Che operazione vuoi svolgere?\n");
        printf("1 -> Visualizzazione\n");
        printf("2 -> Inserimento\n");
        printf("3 -> Ordinamento\n");
        printf("0 -> Termina il programma\n");
        scanf("%d%*c", &risposta);

        /* gestisci le operazioni dell'utente */
        if (risposta == 1)
            stampaLista(head);
        else if (risposta == 2)
            inserimentoCoda(&head);
        else if (risposta == 3)
            ordinaLista(&head);
        else if (risposta == 0)
            printf("Finito!\n\n");
        else
            printf("Selezione non valida!\n\n");
    }

    salvataggio(head->next);
}