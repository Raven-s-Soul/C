#include <stdio.h>

void primaLeAPoiLeZ(char *stringa);

void testPrimaLeAPoiLeZ(char *stringa);

void delete(char *stringa, int f);
void rightshift(char *stringa);
void leftshift(char *stringa, int f, int zs);

int main(void)
{
    char stringa[50];
    printf("Damme na stringa: ");
    fgets(stringa, 50, stdin);
    //! rimuovere /n
    primaLeAPoiLeZ(stringa);
    printf("%s", stringa);
    // printf("%d", sizeof(stringa) / sizeof(char));
}

/*
riceve come parametro una stringa e la modifica
riordinando i caratteri della stringa così che tutte le ‘a’ (minuscole) compaiono all’inizio della
stringa e tutte le ‘z’ (minuscole) compaiono alla fine della stringa. Caratteri diversi da ‘a’ e ‘z’
possono apparire in un ordine qualsiasi (comunque dopo le ‘a’ e prima delle ‘z’).
*/
void primaLeAPoiLeZ(char *stringa)
{
    int zcounter = 0;
    for (int i = 0; stringa[i] != '\0'; i++)
    {
        if (stringa[i] == 'a')
        {
            delete (stringa, i);
            // rightshift
            rightshift(stringa);
            stringa[0] = 'a';
        }
        else if (stringa[i] == 'z')
        {
            zcounter++;
            // delete (stringa, i);
            //  rightshift
            leftshift(stringa, i, zcounter);
        }
    }
}

void delete(char *stringa, int f)
{
    for (int i = f; stringa[i] != '\0'; i++)
    {
        stringa[i] = stringa[i + 1];
    }
}
void rightshift(char *stringa)
{
    for (int j = 50; j > 0; j--)
    {
        // printf("%c", stringa[i]);
        stringa[j] = stringa[j - 1];
    }
}
void leftshift(char *stringa, int f, int zs)
{
    int j;
    // printf("%d", j);
    for (j = f; (stringa[j] != '\0'); j++)
    {
        // printf("%c", stringa[i]);
        stringa[j] = stringa[j + 1];
    }
    // printf("%d", j);
    stringa[j - 1] = 'z';
    stringa[j] = '\0';
}
/*
printf(“Test primaLeAPoiLeZ(\“000a\”): Atteso = \“a000\”, Calcolato = \”%s\” \n”, stringa1);

void testPrimaLeAPoiLeZ(char *stringa)
{
    printf(“Test primaLeAPoiLeZ(\“000a\”)
           : Atteso = \“a000\”, Calcolato = \”% s\” \n”, stringa1);
}
*/