#include <stdio.h>
/*
Data una sequenza di interi, verificare se ogni tripla di interi consecutivi nella sequenza
contiene almeno un intero pari ed uno dispari.

!tipo : verifica universale?
*/

int triplePariDispari(int *array, int s);

int main(void)
{
    int size;
    printf("Dimmi quanti numeri ");
    scanf("%d", &size);
    int array[size];

    for (int i = 0; i < size; i++)
    {
        printf("numero %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("%d", triplePariDispari(array, size));
}

int triplePariDispari(int *array, int s)
{
    int c = 1;
    for (int i = 0; i < s - 2; i++)
    {
        if (!((array[i] % 2 == 0 || array[i + 1] % 2 == 0 || array[i + 2] % 2 == 0) && (array[i] % 2 != 0 || array[i + 1] % 2 != 0 || array[i + 2] % 2 != 0)))
            c = 0;
    }
    return c;
}