#include <stdio.h>

// funzione valore assoluto
float ValoriAssoluti(float x)
{
    if (x < 0)
    {
        x = -x;
    }
    return x;
}

int main()
{

    // dati di input
    int dimensione;
    printf("dimmi quanti saranno i numeri che introdurrai");
    scanf("%d", &dimensione);
    float array[dimensione];

    // compilazione array

    for (int i = 0; i < dimensione; i++)
    {
        printf("dammi il numero %d \n", i + 1);
        scanf("%f", &array[i]);
        array[i] = ValoriAssoluti(array[i]);
    }

    // stampa il nuovo array
    printf("il tuoi valori ora sono \n");
    for (int i = 0; i < dimensione; i++)
    {
        printf("%f \n", array[i]);
    }
}