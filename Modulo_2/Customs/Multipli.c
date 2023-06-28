#include <stdio.h>

int ricursione(int *array, int len)
{
    int risultato = 0;
    if (len < 3)
        risultato = 0;
    else
    {
        if ((array[0] == array[1] * array[2]) || (array[1] == array[0] * array[2]) || (array[2] == array[1] * array[0]) || ricursione(array + 1, len - 1))
            risultato = 1;
    }
    return risultato;
}

int main()
{
    int len = 0;
    printf("\nScegli la dimensione dell'array: ");
    scanf("%d", &len);
    int array[len];

    for (int i = 0; i < len; i++)
    {
        printf("\nInserisci l'elemento \"%d\" : ", i + 1);
        scanf("%d", &array[i]);
    }

    if (ricursione(array, len))
        printf("\nIstanza positiva\n"); //* Non fare all esame
    else
        printf("\nIstanza negativa\n"); //* Non fare all esame
    // for (int i = 0; i < len; i++)
    // {
    //     printf("%d ", array[i]);
    // }
}