// Definição da estrutura no para encadeadeamento de inteiros
struct no {
    int item;
    struct no* prox;
};
// Definição do tipo No
typedef struct no No;

/*
1- É recursiva pois a estrutura cria uma ponteiro que aponta para outra estrutura igual (do mesmo tipo), formando uma
cadeia de elementos;
2- Algumas vantagens das listas encadeadas são: tamanho dinêmico, inserção e remoção eficientes, melhor uso da memória
e facilidade para implementar estruturas mais complexas (ex: grafos);
*/