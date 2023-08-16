/*
(6 pt) Una funzione viaParoleDaDue riceve come parametro una stringa e la modifica
rimuovendo ogni sequenza di esattamente due caratteri alfabetici consecutivi.
Ad esempio, se la stringa ricevuta come parametro è "ab12cde56ee78a67bb",
la stringa deve essere modificata in "12cde5678a67".
(3 pt) Una funzione testViaParoleDaDue verifica la correttezza della funzione viaParoleDaDue.
La funzione di test deve realizzare un test a scatola nera. Ciascuno degli insiemi di dati
di ingresso usato per il test deve essere commentato nel codice con un’indicazione
dell’insieme di equivalenza corrispondente. Ad esempio:
/stringa vuota
char stringa1[] = “”;
viaParoleDaDue(stringa1);
printf(“Test viaParoleDaDue(\“\”): Atteso = \“\”, Calcolato = \”%s\” \n”, stringa1);
(2 pt) Una funzione main chiede all'utente di inserire una stringa da tastiera ed utilizzando la
funzione fgets memorizza la stringa introdotta dall'utente all'interno di un array di 50 caratteri.
Dopo aver rimosso il carattere '\n' dalla stringa, la funzione main invoca la funzione
viaParoleDaDue fornendole come parametro la stringa letta; la funzione main stampa quindi
la stringa modificata. La funzione main termina invocando la funzione di test.*/
#include <stdio.h>
#include <string.h>

void viaParoleDaDue(char *string);
void testViaParoleDaDue();

int main()
{
    char stringa[50];
    printf("Damme na stringa: ");
    fgets(stringa, 50, stdin);
    stringa[strlen(stringa) - 1] = '\0';
    viaParoleDaDue(stringa);
    printf("%s\n", stringa);
    testViaParoleDaDue();
}

void viaParoleDaDue(char *string)
{
    for (int i = 0; string[i] != '\0'; i++)
    {
        if ((((string[i] >= 'a' && string[i] <= 'z') || (string[i] >= 'A' && string[i] <= 'Z')) && ((string[i + 1] >= 'a' && string[i + 1] <= 'z') || (string[i + 1] >= 'A' && string[i + 1] <= 'Z'))) && !((string[i + 2] >= 'a' && string[i + 2] <= 'z') || (string[i + 2] >= 'A' && string[i + 2] <= 'Z')) && !((string[i - 1] >= 'a' && string[i - 1] <= 'z') || (string[i - 1] >= 'A' && string[i - 1] <= 'Z')))
        {
            for (int j = i; string[j] != '\0'; j++)
            {
                // printf("shift %c and %c \n", string[j], string[j + 2]);
                string[j] = string[j + 2];
            }
        }
    }
}

void testViaParoleDaDue()
{
    char stringa1[] = "ab12cde56ee78a67bb";
    viaParoleDaDue(stringa1);
    printf("Test viaParoleDaDue(ab12cde56ee78a67bb): Atteso = 12cde5678a67, Calcolato = %s \n", stringa1);
}