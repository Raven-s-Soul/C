/*  Specifica
    input: una seguenza di ....
    precondizione: ...
    output: un valore ...
    postcondizione: esce ... se ... è esattamente ...,  altrimenti ...

    TIPO: Verifica universale

    diagramma a blocchi su carta
*/
#include <stdio.h>

// Func che verifica se ogni tripla di interi consecutivi in un array contiene esattamente due pari
int tripleDuePari(int array[], int lenght);

int main()
{
    int lunghezza;
    printf("Lunghezza array? ");
    scanf("%d", &lunghezza);
    int seq[lunghezza];
    for (int i = 0; i < lunghezza; i++)
    {
        scanf("%d", &seq[i]);
    }

    if (tripleDuePari(seq, lunghezza))
        printf("Ogni tripla di consecutivi contiene esattmente due pari");
    else
        printf("Non ogni tripla di consecutivi contiene esattamente due pari");
}

int tripleDuePari(int array[], int lenght)
{
    int triple = 1; // variabile di universaità
    int i = 0;      // contatore
    /*guarda var consecutive fino al termine e non ne hai trovata una negativa*/
    while (i <= lenght - 3 && triple)
    {
        /*tripla corrente soddisfa la proprietà? */
        if (((array[i] % 2 == 0 && array[i + 1] % 2 == 0 && array[i + 2] % 2 != 0) || (array[i] % 2 == 0 && array[i + 2] % 2 == 0 && array[i + 1] % 2 != 0) || (array[i + 1] % 2 == 0 && array[i + 2] % 2 == 0 && array[i] % 2 != 0)))
            i++;
        else
            triple = 0;
    }
    return triple;
}