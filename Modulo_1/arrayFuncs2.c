/*
!Realizzare un programma che consiste di due funzioni.

La funzione main legge una sequenza di interi introdotta dall'utente (
prima di leggere tale sequenza chiede all'utente di quanti numeri consiste la sequenza).
La funzione main invoca quindi la funzione tripleSommaZero che calcola e restituisce il numero di
triple di interi consecutivi nella sequenza la cui somma è pari a 0;
la funzione main stampa quindi tale intero.

La funzione tripleSommaZero riceve come parametro un array di interi e la sua lunghezza e restituisce
il numero di triple di interi consecutivi nella sequenza la cui somma è pari a 0.
*/

#include <stdio.h>

int tripleSommaZero(int *array, int ln);

int main()
{ // dati di input
    int triple = 0;
    int dimensione;
    printf("dimmi quanti saranno i numeri che introdurrai");
    scanf("%d", &dimensione);
    int array[dimensione];

    // compilazione array

    for (int i = 0; i < dimensione; i++)
    {
        printf("dammi il numero %d \n", i + 1);
        scanf("%d", &array[i]);
    }
    printf("%d triple ", tripleSommaZero(array, dimensione));
}

int tripleSommaZero(int *array, int ln)
{
    int triple = 0;
    for (int i = 1; i < ln - 1; i++)
    {
        if ((array[i] + array[i - 1] + array[i + 1]) == 0)
            triple++;
    }
    return triple;
}