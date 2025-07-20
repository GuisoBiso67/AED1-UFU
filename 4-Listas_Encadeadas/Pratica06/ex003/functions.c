#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

ListStudents* createEmptyList(){
    ListStudents* l = (ListStudents*)malloc(sizeof(ListStudents));
    if(l != NULL) {
        *l = NULL;
    }
    return l;
}

void printList(ListStudents *l) {
    Student *elem = *l;
    int i=0;

    printf("\n----- ALUNOS -----\n");
    while(elem != NULL) { // numero do aluno não eh necessário, mas fica mais bonitinho;
        printf("Student %d: %s| Nota Pratica: %.2f | Nota Teorica: %.2f\n", i+1, elem->data.name, elem->data.pGrade, elem->data.tGrade);
        i++;
        elem = elem->next;
    }
}

int insertStudent(ListStudents *l, struct student studN) {
    if (l == NULL) return 0;
    Student* newNode = (Student*)malloc(sizeof(Student));
    if (newNode == NULL) return 0;
    newNode->data = studN;
    newNode->next = (*l); // aponta para o "antigo fim";
    *l = newNode; // o novo nó eh o inicio da lista agora;
    return 1;
}

int searchStudent(ListStudents *l, char *name) {
    if (l == NULL) return 0;
    Student *elem = *l;
    while (elem != NULL && strcmp(elem->data.name, name) != 0) {
        elem = elem->next;
    }
    if (elem == NULL) {
        return 0;
    }else{
        printf("Aluno encontrado!\n");
        printf("Nome: %s | Nota Pratica: %.2f | Nota Teorica: %.2f\n", elem->data.name, elem->data.pGrade, elem->data.tGrade);
        return 1;
    }
}

ListStudents* listOfStudents70(ListStudents *l) {
    ListStudents* students70 = createEmptyList();
    Student *elem = *l;
    int i=0;
    printf("\n----- ALUNOS -----\n");
    while(elem != NULL) {
        if ((elem->data.pGrade+elem->data.tGrade) >= 70) {
            insertStudent(students70,elem->data);
        }
        i++;
        elem = elem->next;
    }
    return students70;
}

ListStudents* removeStudent(ListStudents *l, char *name) {
    if (l == NULL) return l;
    int found = 0;
    ListStudents before = NULL;
    ListStudents current = *l;
    while (current != NULL) {
        if (strcmp(current->data.name, name) == 0) {
            found = 1;
            break;
        }else {
            before = current;
            current = current->next;
        }
    }

    if (found == 1) {
        if (current == *l) {
            *l = (*l)->next;
        }else {
            before->next = current->next;
        }
        free(current);
    }
    else printf("Aluno nao encontrado!\n");
    return l;
}
