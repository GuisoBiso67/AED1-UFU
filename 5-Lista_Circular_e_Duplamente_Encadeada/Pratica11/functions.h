#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct person { // elementos da lista;
    char name[20];
    struct person *next;
    struct person *prev;
} Person;

// ver se está certo depois;
typedef struct {
    Person *start; // *start = end->prox pq é circular
    Person *end; // Ponteiro para o final da lista
    int quant; // Quantidade de elementos na lista
    Person *box; // pessoa com a caixa
} Descriptor;

void createList(Descriptor *li);

void printList(Descriptor *li);

int insertAtBeginning(Descriptor *li, char* name);
int removeNode(Descriptor *li, char* name);

char* firstPersonWithBox(Descriptor *li, int a);

char* goForward(Descriptor *li, int k); // achar "pessoa 1"
char* goBackward(Descriptor *li, int k); // achar "pessoa 1"
char* chooseLeader(Descriptor *li, int k);

// extra
void carregar_nome_arquivo(Descriptor* li, const char* nomeArquivo);

#endif //FUNCTIONS_H
