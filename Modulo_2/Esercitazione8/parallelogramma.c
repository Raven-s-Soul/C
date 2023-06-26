/*
*Realizzare un'applicazione per gestire un array di parallelogrammi con base parallela all’asse x.
*L’applicazione deve gestire ciascun parallelogramma come una struttura con tre campi, che
*rappresentano
*• il vertice in basso a sinistra (bs in figura),
*• il vertice in alto a destra (ad in figura) e
*• la lunghezza della base (b in figura).
*Inoltre ciascun vertice deve essere gestito come una struttura con due campi, che rappresentano le
*coordinate del vertice nel piano.
*Promemoria: Un parallelogramma ha i lati opposti paralleli e di uguale lunghezza. Tale lunghezza può
*essere ottenuta applicando il teorema di Pitagora al triangolo grigio in figura.

L’applicazione deve permettere all’utente di svolgere le seguenti funzionalità.
*• Inserimento di un nuovo parallelogramma dopo aver letto la lunghezza della base e le
*coordinate dei due vertici bs e ad.
*• Cancellazione di tutti i parallelogrammi con area maggiore di un valore dato in input.
*• Visualizzazione dell’array corrente di parallelogrammi, ciascuno comprensivo di:
o vertice in basso a sinistra, vertice in alto a destra e lunghezza della base
o area
o perimetro e
o indicazione se il parallelogramma è un rettangolo oppure no.
All’avvio dell’esecuzione l’applicazione deve inizializzare l’array di parallelogrammi con i valori letti da
un file; al termine dell’esecuzione l’applicazione deve salvare i dati dell’array nello stesso file.
*/

#include <stdio.h>
#include <stdlib.h>

#define Max 10
#define fname "parallelogrammi.txt"

typedef struct vertice
{
    float x, y;
} V;

typedef struct parallelogramma
{
    struct vertice bs;
    struct vertice ad;
    float b;
} P;

float calArea(P var)
{
    float res = var.b * (var.ad.y - var.bs.y);
    if (res < 0)
        res = res * -1;
    return res;
}

void stampaP(P array[], int counter)
{
    for (int i = 0; i < counter; i++)
    {
        printf("\n-------------------\nElemento %d", i + 1);
        printf("\nb = %f\n", array[i].b);
        printf("bs = %f : ", array[i].bs.x);
        printf("%f\n", array[i].bs.y);
        printf("ad = %f : ", array[i].ad.x);
        printf("%f\n", array[i].ad.y);
        printf("Area: %f\n", calArea(array[i]));
        // Perimetro
    }
}

void ArrayAdd(P *var, int counter)
{
    printf("\nb :");
    scanf("%f", &var[counter].b);
    printf("\nAD x :");
    scanf("%f", &var[counter].ad.x);
    printf("\nAD y:");
    scanf("%f", &var[counter].ad.y);
    printf("\nBS x:");
    scanf("%f", &var[counter].bs.x);
    printf("\nBS y:");
    scanf("%f", &var[counter].bs.y);
}

void setup(P array[], int *counter)
{
    //? TXT
    FILE *fp = fopen(fname, "r");
    if (fp == NULL)
    {
        printf("\nErrore accesso al file\n");
    }
    else
    {
        while (fscanf(fp, "%f %f %f %f %f", &array[*counter].b, &array[*counter].ad.x, &array[*counter].ad.y, &array[*counter].bs.x, &array[*counter].bs.y) > 0)
        {
            (*counter)++;
        }
    }
    fclose(fp);

    //! Binario
    // char *fnameu = "file.dat";
    // FILE *fp = fopen(fnameu, "rb");
    // if (fp == NULL)
    //     printf("No file \n");
    // else
    // {
    //     while ((fread(&array[*counter], sizeof(struct parallelogramma), 1, fp) > 0) && *counter <= Max)
    //     {
    //         *counter++;
    //         // todo lettura elementi
    //     }
    // }
    // fclose(fp);
}

void delete(P array[], int *counter)
{
    float maxArea;
    printf("Dammi l'area massima: ");
    scanf("%f", &maxArea);
    for (int i = 0; i < *counter; i++)
    {
        if ((maxArea <= calArea(array[i])) && maxArea >= 0)
        {
            // Traslare Array
            for (int j = i; j < *counter; j++)
            {
                array[j] = array[j + 1];
            }
            (*counter)--;
            printf("\nElemento eliminato\n");
        }
    }
}

void writefile(P array[], int counter)
{
    FILE *fp = fopen(fname, "w");
    if (!fp)
    {
        printf("\nFile non raggiungibile\n");
    }
    else
    {
        for (int i = 0; i < counter; i++)
        {
            fprintf(fp, "%f ", array[i].b);
            fprintf(fp, "%f ", array[i].ad.x);
            fprintf(fp, "%f ", array[i].ad.y);
            fprintf(fp, "%f ", array[i].bs.x);
            fprintf(fp, "%f \n", array[i].bs.y);
        }
    }
    fclose(fp);
}

int main()
{
    P array[Max];
    int counter = 0;
    setup(array, &counter);
    int scelta = -1;
    printf("\nCounter %d\n", counter);
    do
    {
        printf("\n1- Aggiungi\n2- Stampa\n3- Rimuovi\n0- Esci\n");
        scanf("%d", &scelta);
        if (scelta == 1)
        {
            //* TODO
            ArrayAdd(array, counter);
            counter++;
            printf("\nCounter %d\n", counter);
        }
        else if (scelta == 2)
        {
            //* TODO
            printf("\nCounter %d\n", counter);
            stampaP(array, counter);
        }
        else if (scelta == 3)
        {
            //* TODO
            printf("\nCounter %d\n", counter);
            delete (array, &counter);
        }
        else if (scelta == 0)
        {
            printf("\nTentativo scrittura su file\n");
            writefile(array, counter);
        }
        else
        {
            printf("\nValore scelta non valido\n");
        }

    } while (scelta != 0);
}