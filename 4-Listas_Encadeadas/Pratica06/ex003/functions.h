#ifndef FUNCTIONS_H
#define FUNCTIONS_H

// Structs:
struct student{
    char name[30];
    float pGrade; // nota pratica;
    float tGrade; // nota teoria;
};

struct node {
    struct student data;
    struct node *next;
};
typedef struct node Student;

typedef struct node* ListStudents;

// Funções:

// cria lista vazia;
ListStudents* createEmptyList();
// imprime lista;
void printList(ListStudents *l);
// insere estudante;
int insertStudent(ListStudents *l, struct student studN);
// procura aluno;
int searchStudent(ListStudents *l, char *name);
// lista alunos com média >=70;
ListStudents* listOfStudents70(ListStudents *l);
// remove aluno;
ListStudents* removeStudent(ListStudents *l, char* name);

#endif //FUNCTIONS_H
