#include <stdio.h>

void funzioneNumeri(char *stringa);
void delete(char *stringa, int index, int numbersToDelete);

int main(void)
{
    char stringa[50];
    printf("Damme na stringa: ");
    fgets(stringa, 50, stdin);
    //! rimuovere /n
    // logica
    funzioneNumeri(stringa);
    // stampa
    printf("%s", stringa);
    // printf("%d", sizeof(stringa) / sizeof(char));
}

void delete(char *stringa, int index, int numbersToDelete)
{
    for (int i = index; stringa[i] != '\0'; i++)
    {
        stringa[i] = stringa[i + numbersToDelete - 1];
    }
}

void funzioneNumeri(char *stringa)
{
    int counterToDelete;

    for (int i = 0; stringa[i] != '\0'; i++)
    {
        if (stringa[i] >= '0' && stringa[i] <= '9')
        {
            counterToDelete = 0;
            for (int j = i; (stringa[j] != '\0') && ((stringa[j] >= '0' && stringa[j] <= '9')); j++)
            {
                counterToDelete++;
            }
            // printf("-%d- ", counterToDelete);
            delete (stringa, i, counterToDelete);
            stringa[i] = '*';
        }
    }
}
/*
printf(“Test primaLeAPoiLeZ(\“000a\”): Atteso = \“a000\”, Calcolato = \”%s\” \n”, stringa1);

void testPrimaLeAPoiLeZ(char *stringa)
{
    printf(“Test primaLeAPoiLeZ(\“000a\”)
           : Atteso = \“a000\”, Calcolato = \”% s\” \n”, stringa1);
}
*/