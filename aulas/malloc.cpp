#include <stdio.h>
#include <stdlib.h>

int main() {
    int *pointer;
    pointer = (int*) malloc(5 * sizeof(int)); //aloca memória para cinco inteiros
    
    if(pointer != NULL) { //verifica se a alocação foi bem sucedida
        int i;
        
        for (i = 0; i < 5; i++) {
            pointer[i] = i + 1; // inicia valores manualmente
        }
        
        for (i = 0; i < 5; i ++) {
            printf("%d ", pointer[i]);
          
        }
        free(pointer); // libera a memória  
    
    } else {
        printf("Erro na alocação de memória");
    }

}