#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data
{
    int anno;
    int mese;
    int giorno;

} D;

typedef struct persona
{
    char nome[20];
    char cognome[20];
    D date;
} P;

typedef struct nodo
{
    P persona;
    struct nodo *next;
} N;

N *NewAhead(N *head)
{
    N *newNodo = malloc(sizeof(N));
    printf("\nDammi Nome: ");
    fgets(newNodo->persona.nome, 20, stdin);
    newNodo->persona.nome[strlen(newNodo->persona.nome) - 1] = '\0';
    printf("\nDammi Cognome: ");
    fgets(newNodo->persona.cognome, 20, stdin);
    newNodo->persona.cognome[strlen(newNodo->persona.cognome) - 1] = '\0';
    printf("\nDammi Anno: ");
    scanf("%d%*c", &(newNodo->persona.date.anno));
    printf("\nDammi Mese: ");
    scanf("%d%*c", &(newNodo->persona.date.mese));
    printf("\nDammi Giorno: ");
    scanf("%d%*c", &(newNodo->persona.date.giorno));

    newNodo->next = head;
    return newNodo;
}

void printLista(struct nodo *head)
{
    N *newHead = head;
    int counter = 0;
    if (newHead == NULL)
        printf("\nLista Attualmente vuota\n");
    while (newHead != NULL)
    {
        counter++;
        printf("\nPersona \"%d\"", counter);
        printf("\nNome: %s", newHead->persona.nome);
        printf("\nCognome: %s", newHead->persona.cognome);
        printf("\nAnno: %d", newHead->persona.date.anno);
        printf("\nMese: %d", newHead->persona.date.mese);
        printf("\nGiorno: %d\n", newHead->persona.date.giorno);
        newHead = newHead->next;
    }
}

N *ReadFile(N *head);
void WriteFile(N *head);

int main()
{

    N *head = NULL;
    head = ReadFile(head);
    // printlista
    printLista(head);
    // rimepi lista
    int scelta = 0;
    printf("\nPiu persone?\n1-Yes 0-No\t");
    scanf("%d%*c", &scelta);
    while (scelta != 0)
    {
        head = NewAhead(head);
        printf("Vuoi aggiungere un altro?\n1-Yes 0-No\t");
        scanf("%d%*c", &scelta);
    }
    // stampa lista
    printLista(head);
    WriteFile(head);
}

N *ReadFile(N *head)
{
    char *filename = "interi.dat";
    FILE *fp = fopen(filename, "rb");
    if (!fp)
    {
        printf("Recupero sequenza non riuscito!");
    }
    else
    {
        int status = 1;
        N *buffer;
        while (status)
        {
            buffer = malloc(sizeof(N));
            if (fread(&(buffer->persona), sizeof(P), 1, fp) > 0)
            {
                status = 1;
                printf("Lettura Effettuata\n");
                buffer->next = head;
                head = buffer;
            }
            else
                status = 0;
        }
    }
    fclose(fp);
    return head;
}
void WriteFile(N *head)
{
    char *filename = "interi.dat";
    FILE *fp = fopen(filename, "wb+");

    N *newHead = head;

    if (!fp)
    {
        printf("\nFile opening failed");
    }
    else
    {
        int counter = 0;
        while (newHead != NULL)
        {
            counter++;
            size_t status = fwrite(&(newHead->persona), sizeof(P), 1, fp);
            if (status)
            {
                printf("\nScrittura Riuscita elemento %d", counter);
            }
            newHead = newHead->next;
        }
    }
    fclose(fp);
    // remove(filename);
}