#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct vagone
{

    int peso;

    int persone;

    struct vagone *nextvagone;

} room;

int random()
{

    return rand() % 101;
}

void creazioneVagone(room *lista)
{

    char c;

    lista->peso = random();
    lista->persone = random();

    printf("Vuoi creare un altro vagone? y/n ");
    scanf("%c", &c);
    getchar();

    if (c == 'y')
    {
        lista->nextvagone = malloc(sizeof(room));
        creazioneVagone(lista->nextvagone);
    }
    else
        lista->nextvagone = NULL;
}

void visualizza(room *head, int i)
{

    while (head != NULL)
    {
        printf("Vagone numero %d:\n", i);
        printf("Peso: %d kg\n", head->peso);
        printf("Numero persone: %d\n\n\n", head->persone);
        head = head->nextvagone;
        i++;
    }
}

int main()
{

    srand(time(NULL));
    room *head;
    char c;

    printf("Ciao utente, vuoi costruire il tuo treno? y/n ");
    scanf("%c", &c);
    getchar();

    if (c == 'y')
    {
        head = malloc(sizeof(room));
        creazioneVagone(head);
    }

    printf("Ecco i tuoi vagoni:\n\n\n");

    visualizza(head, 1);
}