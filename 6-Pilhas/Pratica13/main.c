#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <ctype.h>
#include "dictionary.h"
#include "battery.h"

int main() {
    Descriptor *d = create_list();
    DescriptorBattery *db = create_battery_list();

    int op;
    do {
        printf("\n1 - Carregar Palavras do Dicionario\n");
        printf("2 - Mostrar Dicionario\n");
        printf("3 - Buscar palavra\n");
        printf("4 - Carregar Frases\n");
        printf("5 - Mostrar Palavras+Significado das frases\n");
        printf("0 - Sair\n");
        printf("Selecione uma opcao: ");
        scanf("%d", &op);
        getchar();
        switch (op) {
            case 1:
                const int vLD = load_words(d, "words_list.txt");
                if (vLD == 1) {
                    printf("Dicionario carregado com sucesso!\n");
                }else {
                    printf("Dicionario nao foi carregado. Verifique o arquivo!\n");
                }
                break;
            case 2:
                show_dictionary(d);
                break;
            case 3:
                char word[20];
                printf("\nBusque uma palavra: ");
                scanf("%[^\n]", word);
                search_word(d, word);
                printf("\n");
                break;
            case 4:
                const int vLP = load_phrases(db, "phrases.txt");
                if (vLP == 1) {
                    printf("Frases carregadas com sucesso!\n");
                }else {
                    printf("Frases nao foram carregadas. Verifique o arquivo!\n");
                }
                break;
            case 5:
                // apos chamar esse, eh necessário carregar as frases de novo (opção 4), pq eu libero o descritor das pilhas após
                // imprimir as frases para evitar outro erro que duplica o número de frases, mas não imprime nada;
                show_all_batteries(db, d);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    }while (op != 0);

    //free_descriptor(db);
    free(db);
}