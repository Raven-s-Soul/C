#include <stdio.h>
#include <string.h>

void primaLeAPoiLeZ(char *stringa)
{
    int i, j, temp1, temp2;
    for (i = 0; i < strlen(stringa); i++)
    {
        if (stringa[i] == 'a')
        {
            temp2 = stringa[0];
            for (j = 1; j <= i; j++)
            {
                temp1 = temp2;
                temp2 = stringa[j];
                stringa[j] = temp1;
            }
            stringa[0] = 'a';
        }
        else if (stringa[i] == 'z')
        {
            temp2 = stringa[strlen(stringa) - 2];
            for (j = strlen(stringa) - 3; j >= i; j--)
            {
                temp1 = temp2;
                temp2 = stringa[j];
                stringa[j] = temp1;
            }
            stringa[strlen(stringa) - 2] = 'z';
        }
    }
    /*for (i = 0; i < strlen(stringa); i++)
    {
        if (stringa[i] == 'a')
        {
            temp2 = stringa[0];
            for (j = 1; j <= i; j++)
            {
                temp1 = temp2;
                temp2 = stringa[j];
                stringa[j] = temp1;
            }
            stringa[0] = 'a';
        }
        else if (stringa[i] == 'z')
        {
            temp2 = stringa[strlen(stringa) - 2];
            for (j = strlen(stringa) - 3; j >= i; j--)
            {
                temp1 = temp2;
                temp2 = stringa[j];
                stringa[j] = temp1;
            }
            stringa[strlen(stringa) - 2] = 'z';
        }
    }*/
}

int main()
{
    char stringa[50];
    fgets(stringa, 50, stdin);

    primaLeAPoiLeZ(stringa);
    printf("%s", stringa);
    return 0;
}