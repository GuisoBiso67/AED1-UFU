#ifndef DICTIONARY_H
#define DICTIONARY_H

typedef struct entry{
    char word[20];
    char classification[20];
    char meaning[200];
} Entry;

typedef struct node {
    Entry data;
    struct node *next;
} Node;

typedef struct {
    Node *start;
    Node *end;
    int quantity;
} Descriptor;

Descriptor* create_list();
int load_words(Descriptor* d, const char* fileName);
int insert_word(Descriptor* d, Entry e);
void show_dictionary(Descriptor* d);
void search_word(Descriptor* d, const char* word);

void trim(char *str);

#endif //DICTIONARY_H
