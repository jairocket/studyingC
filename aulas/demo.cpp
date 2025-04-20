#include <stdio.h>
#include <stdlib.h>

int main()
{
    int number = 10;
    int *pointerNumber = &number;

    printf("Valor de number: %d\n", number);
    printf("Endereço de number: %p\n", pointerNumber);
    printf("Valor apontado por pointerNumber: %d\n", *pointerNumber);

    *pointerNumber = 20;

    printf("Novo valor de number após modificação pelo ponteiro: %d\n", number);

    int *dynamicPointer;
    dynamicPointer = (int *)malloc(sizeof(int));

    if (dynamicPointer == NULL)
    {
        printf("Erro ao alocar memória! \n");
        return 1;
    }
    *dynamicPointer = 50;
    printf("Valor armazenado na memória dinamicamente: %d\n", *dynamicPointer);

    free(dynamicPointer);
    dynamicPointer = NULL;

    if (dynamicPointer == NULL)
    {
        printf("Memória alocada dinamicamente foi liberada e ponteiro invalidado! \n");
    }
    return 0;
}