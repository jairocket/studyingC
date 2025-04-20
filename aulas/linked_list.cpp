#include <stdio.h>
#include <stdlib.h>

struct Node {
    int age;
    struct Node *next;
};

typedef struct Node node;

int checkIfNextItemIsNull(node *LIST) {
    if (LIST->next == NULL){
        return 1;
    } else {
        return 0;
    }
}

int checkIfNextAgeMatches(node *LIST, int age) {
    if(LIST->next == NULL) {
        return 0;
    }
    if(LIST->next->age == age) {
        return 1;
    }
    return 0;
}

int checkIfAgeIsAlreadyAdded(node *LIST, int age) {
    node* element = LIST;
    int nextNodeMatches = checkIfNextAgeMatches(element, age);
    while (nextNodeMatches == 0) {
        if(element->next == NULL) {
            return 0;
        }
        if(element->next->age == age) {
            nextNodeMatches = 1;           
            break;
        }
        if(element->next->age != age) {
            element = element->next;
            nextNodeMatches = checkIfNextAgeMatches(element, age);
        } 
    }
    return nextNodeMatches;

}

node* getNodeByAge(node *LIST, int age) {
    node* element = LIST;
    int nodeMatches = checkIfNextAgeMatches(element, age);
    while (nodeMatches == 0) {
        if(element->next != NULL) {
            element = element->next;
            nodeMatches = checkIfNextAgeMatches(element, age);
        } else {
            printf("Idade %d nao encontrada, sera adicionada no final da lista. \n", age);
        }
    }
    return element;

}

node* getLastItem(node *LIST) {   
    node* element = LIST;
    int isLastItem = checkIfNextItemIsNull(element);
    while (isLastItem == 0) {
        element = element->next;
        isLastItem = checkIfNextItemIsNull(element);      
    }

    return element;
} 

void insertInTheLastPosition(node *LIST) {
    node *newElement = (node *)malloc(sizeof(node));
    printf("Digite uma idade: ");
    scanf("%d", &newElement->age);

    if(checkIfAgeIsAlreadyAdded(LIST, newElement->age) == 0) {
        node *lastItem = getLastItem(LIST);
        lastItem->next = newElement;
    } else {
        printf("\nIdade %d ja foi adicionada. \n", newElement->age);
    }
}

void insertInFirstPosition(node *LIST) {
    node *newElement = (node *)malloc(sizeof(node));
    printf("Digite uma idade: ");
    scanf("%d", &newElement->age);

    if(checkIfAgeIsAlreadyAdded(LIST, newElement->age) == 0) {
        node *temp = LIST->next;
        LIST->next = newElement;
        newElement->next = temp;
    } else {
        printf("\nIdade %d ja foi adicionada. \n", newElement->age);
    }
}

void insertAfterReferencedItem(node *LIST) {
    node *newElement = (node *)malloc(sizeof(node));
    int referencedItem;

    printf("Informe apos qual idade deseja adicionar: ");
    scanf("%d", &referencedItem);

    printf("Digite uma idade: ");
    scanf("%d", &newElement->age);

    if(checkIfAgeIsAlreadyAdded(LIST, newElement->age) == 0){
        node *previousNode = getNodeByAge(LIST, referencedItem);
        node* temp = previousNode->next;
        previousNode->next = newElement;
        newElement->next = temp;   
    } else {
        printf("\nIdade %d ja foi adicionada. \n", newElement->age);
    }
}

void deleteNodeByAge(node *LIST) {
    int age;
    printf("Informe a idade que deseja remover da lista: ");
    scanf("%d", &age);

    node *previousNode = getNodeByAge(LIST, age);

    if(checkIfNextItemIsNull(previousNode->next) == 1) {
        previousNode->next = NULL;
    }

    node* temp = previousNode->next;
    previousNode->next = previousNode->next->next;
    free(temp);

}

void printElements(node *LIST) {
    if(checkIfNextItemIsNull(LIST)) {
        printf("\nEnd of the list \n");
        printf("-------------------\n");
        return;
    }

    printf("- %d \n", LIST->next->age);
    printElements(LIST->next);
}

void startLinkedList(node *LIST)
{
    LIST->next = NULL;
}

void printMenu()
{
    printf("Escolha uma das opcoes abaixo: \n\n");
    printf("0 - Sair \n");
    printf("1 - Inserir no inicio \n");
    printf("2 - Inserir no meio \n");
    printf("3 - Inserir no fim \n");
    printf("4 - Imprimir a lista \n");
    printf("5 - Remover item \n");
    printf("Digite: ");
}



int main() {
    node *list = (node *)malloc(sizeof(node));
    startLinkedList(list);
    int selectedItem;

    printMenu();
    scanf("%d", &selectedItem);

    while (selectedItem != 0) {
        switch (selectedItem) {
        case 1:
            insertInFirstPosition(list);           
            printMenu();
            scanf("%d", &selectedItem);
            break;
        case 2:
            insertAfterReferencedItem(list);
            printMenu();
            scanf("%d", &selectedItem);
            break;
        case 3:
            insertInTheLastPosition(list);
            printMenu();
            scanf("%d", &selectedItem);
            break;
        case 4:
            printf("\n --- Idades --- \n");
            printElements(list);
            printMenu();
            scanf("%d", &selectedItem);
            break;
        case 5:
            deleteNodeByAge(list);
            printMenu();
            scanf("%d", &selectedItem);
            break;              
        default:
            printf("Opcao Invalida :| \n\n");
            printMenu();
            scanf("%d", &selectedItem);
            break;
        }
    }
    printf("Ate a proxima :) \n");
    printf("\n");
    return 0;
}