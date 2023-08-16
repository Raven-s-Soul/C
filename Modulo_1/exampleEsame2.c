/*  funzione che verifica se in un array di interi ha un elemento è il quadrato nel precedente o successivo */
#include <stdio.h>

// Func che verifica se ogni tripla di interi consecutivi in un array contiene esattamente due pari
int quadrati(int array[], int lenght);

// parte 2 func che verifica
int ugualiCompresi(int *array, int lenght);

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

    if (quadrati(seq, lunghezza))
        printf("C'è un quadrato");
    else
        printf("Non c'è un quadrato");
}

int quadrati(int array[], int lenght)
{
    int ris = 0;
    int i = 0; // contatore
    /*guarda var consecutive fino al termine e non ne hai trovata una negativa*/
    while (i <= lenght - 1 && !ris)
    {
        if (array[i] * array[i] == array[i + 1] || array[i + 1] * array[i + 1] == array[i])
        {
            ris = 1;
        }
        else
            i++;
    }
    return ris;
}

int ugualiCompresi(int *array, int lenght)
{
    int ris = 0;
    int i = 0; // contatore

    while (i <= lenght - 2 && !ris)
    {
        if (((10 <= array[i] + array[i + 1] && array[i] + array[i + 1] <= 20) ||
             (10 <= array[i] + array[i + 2] && array[i] + array[i + 2] <= 20) ||
             (10 <= array[i + 2] + array[i + 1] && array[i + 2] + array[i + 1] <= 20)) &&
            ((array[i] == array[i + 1] && array[i] == array[i + 1]) ||
             (array[i] == array[i + 2] && array[i] == array[i + 2]) ||
             (array[i + 2] == array[i + 1] && array[i + 2] == array[i + 1])))
        {
            ris = 1;
        }
        else
            i++;
    }
    return ris;
}
