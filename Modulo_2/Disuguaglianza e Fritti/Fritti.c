#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxLenght 50
#define fnameb "Fritti.dat"
#define fnamet "Fritti.txt"

/*****************************/
/********* STRUTTURE *********/
/*Definire due strutture, una per rappresentare un elemento della
lista ed una per rappresentare un fritto che fa parte del menù.
In particolare, l’applicazione deve gestire ciascun fritto come una
struttura con tre campi. Il primo campo è una stringa che indica il
nome del fritto (ad esempio “fiori di zucca”), il secondo campo è un valore
reale che indica il prezzo del fritto, ed il terzo campo è un carattere ‘s’
o ‘f’ che indica se il fritto è surgelato o fresco.*/
//* DONE
typedef struct fritto
{
    char nome[MaxLenght];
    float prezzo;
    char stato;
} F;

typedef struct nodo
{
    struct nodo *next;
    F fritto;
} N;

/**************************************/
/*********** VISUALIZZAZIONE **********/
/*Definire una funzione che visualizza il menù,
stampando per ciascuna fritto il nome, il prezzo
e se il fritto è surgelato oppure no.*/
//* DONE
void stampaLista(N *head)
{
    N *newHead = head;
    if (newHead == NULL)
        printf("\nLista vuota\n");
    else
    {
        while (newHead != NULL)
        {
            printf("\nNome: %s", newHead->fritto.nome);
            printf("\nStato: %c", newHead->fritto.stato);
            printf("\nPrezzo: %f\n", newHead->fritto.prezzo);
            newHead = newHead->next;
        }
    }
}

/**********************************************
 **************** ORDINA *********************
 *Definire una funzione che ordina la lista così che i fritti
 freschi compaiano prima di quelli surgelati e così che i fritti
 freschi (e quelli surgelati) siano fra loro ordinati per prezzo.*/
//* DONE
N *ordinaLista(N *head)
{
    int ordine = 0;
    do
    {
        if (ordine != 0)
        {
            printf("\nValore inserito non valido\n");
        }
        printf("\n1 per lo stato fritto/surgelato - 2 per prezzo\n");
        scanf("%d%*c", &ordine);
    } while (ordine != 1 && ordine != 2);

    //?stato
    if (ordine == 1)
    {
        if (head == NULL)
        {
            printf("\nlista vuota\n");
        }
        else
        {
            //! BoubleSort
            int trovato = 0;
            for (N *newHead = head; newHead != NULL && !trovato; newHead = newHead->next)
            {
                trovato = 0;
                for (N *newNewHead = head; newNewHead->next != NULL; newNewHead = newNewHead->next)
                {
                    if (newNewHead->fritto.stato == 's' && newNewHead->next->fritto.stato == 'f')
                    {
                        trovato = 1;
                        // printf("\ntrovato\n"); //*Debug
                        //* Swap
                        F aux = newNewHead->fritto;
                        newNewHead->fritto = newNewHead->next->fritto;
                        newNewHead->next->fritto = aux;
                    }
                }
            }
        }
    }
    //?Prezzo
    else if (ordine == 2)
    {
        if (head == NULL)
        {
            printf("\nlista vuota\n");
        }
        else
        {
            //! BoubleSort
            int trovato = 0;
            for (N *newHead = head; newHead != NULL && !trovato; newHead = newHead->next)
            {
                trovato = 0;
                for (N *newNewHead = head; newNewHead->next != NULL; newNewHead = newNewHead->next)
                {
                    if (newNewHead->fritto.prezzo > newNewHead->next->fritto.prezzo)
                    {
                        trovato = 1;
                        // printf("\ntrovato\n"); //*Debug
                        //* Swap
                        F aux = newNewHead->fritto;
                        newNewHead->fritto = newNewHead->next->fritto;
                        newNewHead->next->fritto = aux;
                    }
                }
            }
        }
    }
    return head;
}

/**********************************************
 ********** INSERIMENTO ************************
 *Definire una funzione che inserisce un fritto in coda al menù.*/
//* DONE
N *addLista(N *head) // In coda
{
    N *newNodo = malloc(sizeof(N));
    newNodo->next = NULL;

    printf("\nDimmi il nome del fritto\n");
    fgets(newNodo->fritto.nome, MaxLenght, stdin);
    newNodo->fritto.nome[strlen(newNodo->fritto.nome) - 1] = '\0';
    printf("\nDimmi lo stato del fritto: f - fritto o s - surgelato\n");
    scanf("%c%*c", &(newNodo->fritto.stato));
    printf("\nDimmi il prezzo\n");
    scanf("%f%*c", &(newNodo->fritto.prezzo));

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

    return head;
}

/**********************************************
 ********** FILE ******************************
 *Definire una funzione che ordina la lista così che i fritti freschi
 compaiano prima di quelli surgelati e così che i fritti freschi
 (e quelli surgelati) siano fra loro ordinati per prezzo.*/

N *readFileBinario(N *head)
{
    FILE *fp = fopen(fnameb, "rb");
    if (!fp)
        printf("\nImpossibile leggere file\n");
    else
    {
        int status = 0;
        N *buffer;
        while (!status)
        {
            buffer = malloc(sizeof(N));
            if (fread(&(buffer->fritto), sizeof(F), 1, fp) > 0)
            {
                buffer->next = head;
                head = buffer;
            }
            else
                status = 1;
        }
    }
    fclose(fp);
    return head;
}

void printFileBinario(N *head)
{
    FILE *fp = fopen(fnameb, "wb");
    if (!fp)
        printf("\nImpossibile aprire il file\n");
    else
    {
        N *newHead = head;
        while (newHead != NULL)
        {
            if (fwrite(&(newHead->fritto), sizeof(F), 1, fp))
                printf("\nSalvataggi riuscito\n");
            newHead = newHead->next;
        }
    }
    fclose(fp);
}

/**********************************************
 ************ FUNZIONE PRINCIPALE ************
 **********************************************/

int main()
{
    /* inizializza la lista */
    N *head = NULL;
    head = readFileBinario(head);
    //! FILE
    int risposta = -1; // per interazione con utente

    while (risposta != 0)
    {
        /* richiedi un'operazione all'utente */
        printf("\nChe operazione vuoi svolgere?\n");
        printf("1 -> Visualizzazione\n");
        printf("2 -> Ordina\n");
        printf("3 -> Inserimento\n");
        printf("0 -> Termina il programma\n");
        scanf("%d%*c", &risposta);

        /* gestisci le operazioni dell'utente */
        if (risposta == 1)
        {
            stampaLista(head);
        }

        else if (risposta == 2)
        {
            head = ordinaLista(head);
        }

        else if (risposta == 3)
        {
            head = addLista(head);
        }

        else if (risposta == 0)
        {
            printf("Finito!\n\n");
            //! FILE
            printFileBinario(head);
        }

        else
            printf("Selezione non valida!\n\n");
    }
}