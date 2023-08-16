/*
!Realizzare un programma che consiste di due funzioni.

La funzione main legge una sequenza di interi introdotta dall'utente
(prima di leggere tale sequenza chiede all'utente di quanti numeri consiste la sequenza).

La funzione tutteUnQuadrato riceve come parametro un array di interi e la sua lunghezza e verifica,
tutte le triple di interi consecutivi della sequenza,
sono tali che uno degli elementi della tripla sia il quadrato di uno tra gli altri due elementi.

Ad esempio, se l’array è [4, 3, 2, 9], la funzione deve restituire 1,
in quanto nella tripla [4, 3, 2], 4 è il quadrato di 2 e nella tripla [3,4,9], 9 è il quadrato di 3. Se l’array è [1, 3, 1, 12], la funzione
deve restituire 0, poiché nella tripla [3, 1, 12]
nessun numero è il quadrato di uno degli altri due elementi della tripla.
*/

#include <stdio.h>
#include <math.h>
int tutteUnQuadrato(int *array, int ln, int triple)
{
    for (int i = 1; i < ln; i++)
    {
        if ((sqrt(array[i]) == array[i - 1]) || (sqrt(array[i]) == array[i + 1]))
            triple++;
    }
    return triple;
}

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
    printf("%d triple ", tutteUnQuadrato(array, dimensione, triple));
}