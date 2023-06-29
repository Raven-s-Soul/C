#include <stdio.h>
#include <stdlib.h>

#define fname "invervalli.dat"

typedef struct Intervallo
{
    //! a<=b
    int a, b;
} I;

typedef struct nodo
{
    I intervallo; // intervallo
    struct nodo *next;

} N;

//*Inserimento di un nuovo intervallo in testa alla lista.
N *addList(N *head)
{
    N *newNodo = malloc(sizeof(N));
    int status = 1;
    do
    {
        printf("\nInserire a: ");
        scanf("%d", &newNodo->intervallo.a);
        printf("\nInserire b: ");
        scanf("%d", &newNodo->intervallo.b);

        if (newNodo->intervallo.a > newNodo->intervallo.b || newNodo->intervallo.b < 0 || newNodo->intervallo.a < 0)
        {
            printf("\nErrore riprovare inserire a < b positivi");
        }
        else
            status = 0;

    } while (status != 0);

    newNodo->next = head;
    return newNodo;
}

void printList(N *head)
{
    if (head == NULL)
    {
        printf("\nNulla da stampare\n");
    }
    else
    {

        for (int i = 0; head != NULL; i++)
        {
            printf("\nSegmento  \"%d\"", i + 1);
            printf("\na: %d", head->intervallo.a);
            printf(" b: %d \n", head->intervallo.b);
            head = head->next;
        }
    }
}

void intersezione(N *head)
{

    for (N *j = head; j != NULL; j = j->next)
    {
        int intersezioni = 0;
        for (N *i = head; i->next != NULL; i = i->next)
        {
            //! Intersezione cant find the right combination
            if (((j->intervallo.a <= i->intervallo.a) && ((i->intervallo.a <= j->intervallo.b) || (i->intervallo.a >= j->intervallo.b))) &&
                    ((j->intervallo.b >= i->intervallo.a) && ((i->intervallo.a <= j->intervallo.a) || (i->intervallo.a >= j->intervallo.a))) ||
                ((j->intervallo.a >= i->intervallo.a) && ((i->intervallo.a >= j->intervallo.b) || (i->intervallo.a <= j->intervallo.b))) &&
                    ((j->intervallo.b <= i->intervallo.a) && ((i->intervallo.a >= j->intervallo.a) || (i->intervallo.a <= j->intervallo.a))))
            {
                intersezioni++;
                // printf("\nTest");
                // printf("\na: %d", j->a);
                // printf(" b: %d \n", j->b);
            }
        }
        printf("\n %d Intersezione presente in %d - %d\n", intersezioni, j->intervallo.a, j->intervallo.b);
    }
}

N *cancellaLista(N *head)
{

    if (head == NULL)
    {
        // Vuoto
        printf("\nCancellazione impossibile\n");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else
    {
        N *rehead = head;
        while (rehead->next->next != NULL)
        {
            // printf("\nEx");
            rehead = rehead->next;
            // printList(rehead);
        }
        free(rehead->next->next);
        rehead->next = NULL;
    }
    return head;
}

N *ordinamento(N *head)
{
    if (head == NULL || head->next == NULL)
    {
        printf("\nOrdinamento impossibile\n");
    }
    else
    {
        N *rehead = head;
        int trovato = 1;
        for (N *j = rehead; j != NULL && trovato; j = j->next)
        {
            trovato = 0;
            for (N *i = rehead; i->next != NULL; i = i->next)
            {
                // printf("\nOrdinamento");
                if (i->intervallo.a >= i->next->intervallo.a)
                {
                    // printf("\ntest");
                    trovato = 1;
                    if (i->intervallo.a > i->next->intervallo.a)
                    {
                        N backup = *i;
                        i->intervallo.a = i->next->intervallo.a;
                        i->intervallo.b = i->next->intervallo.b;
                        i->next->intervallo.a = backup.intervallo.a;
                        i->next->intervallo.b = backup.intervallo.b;
                    }
                    else if (i->intervallo.b > i->next->intervallo.b)
                    {
                        N backup = *i;
                        i->intervallo.a = i->next->intervallo.a;
                        i->intervallo.b = i->next->intervallo.b;
                        i->next->intervallo.a = backup.intervallo.a;
                        i->next->intervallo.b = backup.intervallo.b;
                    }
                }
            }
        }
    }
    return head;
}

N *letturaFile(N *head)
{
    FILE *fp = fopen(fname, "rb");
    if (!fp)
    {
        printf("\nImpossibile leggere file\n");
    }
    else
    {
        N *buffer = malloc(sizeof(N));
        while (fread(&buffer->intervallo, sizeof(I), 1, fp) > 0)
        {
            N *newNodo = malloc(sizeof(N));
            newNodo->intervallo = buffer->intervallo;
            newNodo->next = head;
            head = newNodo;
        }
        free(buffer);
    }
    fclose(fp);
    return head;
}

void scritturaFile(N *head)
{
    FILE *fp = fopen(fname, "wb");
    if (!fp)
    {
        printf("\nImpossibile scrivere file\n");
    }
    else
    {
        while (head != NULL)
        {
            fwrite(&head->intervallo, sizeof(I), 1, fp);
            head = head->next;
        }
    }
    fclose(fp);
}

int main()
{
    N *head = NULL;
    int scelta = -1;

    do
    {
        printf("\n1 leggere dal file - 2 no file\n");
        scanf("%d", &scelta);
        if (scelta == 1)
        {
            head = letturaFile(head);
        }
        else if (scelta == 2)
        {
        }
        else
        {
            printf("\nScelta non valida\n");
        }
    } while (scelta != 1 && scelta != 2);

    do
    {
        printf("\n0 uscire - 1 aggiungere - 2 cancellare - 3 stampare - 4 ordinamento - 5 intersezione\n");
        scanf("%d", &scelta);
        if (scelta == 0)
        {
            printf("\nChiusura in corso");
            scritturaFile(head);
        }
        else if (scelta == 1)
        {
            head = addList(head);
        }
        else if (scelta == 2)
        {
            head = cancellaLista(head);
        }
        else if (scelta == 3)
        {
            printList(head);
        }
        else if (scelta == 4)
        {
            head = ordinamento(head);
        }
        else if (scelta == 5)
        {
            intersezione(head);
        }
        else
        {
            printf("\nScelta non valida\n");
        }

    } while (scelta != 0);
}