#include <stdio.h>
#include <stdlib.h>

// typedef struct Intervallo
// {
//     //! a<=b
//     int a, b;
// } I;

typedef struct nodo
{
    int a, b; // intervallo
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
        scanf("%d", &newNodo->a);
        printf("\nInserire b: ");
        scanf("%d", &newNodo->b);

        if (newNodo->a > newNodo->b || newNodo->b < 0 || newNodo->a < 0)
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
            printf("\na: %d", head->a);
            printf(" b: %d \n", head->b);
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
            if (((j->a <= i->a) && ((i->a <= j->b) || (i->a >= j->b))) ||
                ((j->b >= i->a) && ((i->b >= j->b) || (i->a <= j->a))))
            {
                intersezioni++;
                // printf("\nTest");
                // printf("\na: %d", j->a);
                // printf(" b: %d \n", j->b);
            }
        }
        printf("\n %d Intersezione presente in %d - %d\n", intersezioni, j->a, j->b);
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
                if (i->a >= i->next->a)
                {
                    // printf("\ntest");
                    trovato = 1;
                    if (i->a > i->next->a)
                    {
                        N backup = *i;
                        i->a = i->next->a;
                        i->b = i->next->b;
                        i->next->a = backup.a;
                        i->next->b = backup.b;
                    }
                    else if (i->b > i->next->b)
                    {
                        N backup = *i;
                        i->a = i->next->a;
                        i->b = i->next->b;
                        i->next->a = backup.a;
                        i->next->b = backup.b;
                    }
                }
            }
        }
    }
    return head;
}

int main()
{
    N *head = NULL;
    int scelta = -1;

    do
    {
        printf("\n0 uscire - 1 aggiungere - 2 cancellare - 3 stampare - 4 ordinamento - 5 intersezione\n");
        scanf("%d", &scelta);
        if (scelta == 0)
        {
            printf("\nChiusura in corso");
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