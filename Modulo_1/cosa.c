#include <stdio.h>

int fun(int *array, int lunghezza)
{
    int res;
    // printf("%d ", array[0]);
    if (lunghezza == 0)
        res = 0;

    else

        res = (array[0] % 2 == 0) + fun(array + 2, lunghezza - 2);

    return res;
}

int main()
{
    int array[] = {0, 1, 1, 3, 4, 5, 6, 7, 8, 9};
    //  printf("%d\n", sizeof(array) / sizeof(int));
    //  int var = fun(array, sizeof(array) / sizeof(int));
    //  printf("\n%d", var);

    // const float pi = 3.14;
    int *var = array;
    *var = 3;
    printf("%d", array[1]);

    // for (int i = 0; i <= 10 - 1; i++)
    // {
    //     printf("%d ", i + 1);
    // }
    // if (!0)
    //     printf("vero");
}