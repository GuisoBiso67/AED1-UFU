#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include <ctype.h>
#include "functions.h"

int main() {
    Descriptor *li = malloc(sizeof(Descriptor));
    createList(li);

    int op, a;
    char name[20];
    srand(time(NULL));

    do {
        printf("\n");
        printf("1- Adicionar pessoa ao circulo;\n");
        printf("2- Remover pessoa do circulo;\n");
        printf("3- Mostrar Lista\n");
        printf("4- Eleger Lider (o programa fecha apos exibir resultado!)\n");
        printf("Opcao: ");
        scanf("%d", &op);

        switch (op){
            case 1:
                carregar_nome_arquivo(li, "names.txt");
                /*
                printf("Nome a ser adicionado: ");
                scanf("%s[^\n]", name);
                insertAtBeginning(li, name);
                break;
                */
                break;
            case 2:
                printf("Nome a ser removido: ");
                getchar();
                scanf("%[^\n]", name);
                removeNode(li, name);
                break;
            case 3:
                printList(li);
                break;
            case 4:
                printf("Escolha um numero entre 1 a 100 para sortear a caixa: ");
                scanf("%d", &a);
                char* box = firstPersonWithBox(li, a);
                if (box == NULL) {
                    printf("Lista esta vazia!\n");
                    break;
                }
                const int k = rand()%50;
                printf("Lider eh a/o %s\n", chooseLeader(li, k));
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }while (op != 4);

    /*
    insertAtBeginning(li, "Guilherme");
    insertAtBeginning(li, "Maria");
    insertAtBeginning(li, "Joao");
    insertAtBeginning(li, "Matheus");
    insertAtBeginning(li, "Marcus");
    insertAtBeginning(li, "Caue");
    printList(li);

    removeNode(li, "Guilherme");
    printList(li);
    removeNode(li, "Caue");
    printList(li);
    removeNode(li, "Joao");
    printList(li);
    */


    free(li);
}
