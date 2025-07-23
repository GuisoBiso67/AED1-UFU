#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

/*
    OBS: tem uma tentativa de verificar as entradas float (quando vai ler as notas práticas e teóricas), mas ela gera um
    loop infinito que não deixa ler o valor de novo. Isso faz o programa exibir o menu de novo e duplicar as
    informações do aluno que estava sendo inserido. Não sei resolver.
*/

int main() {
    ListStudents *studentsList = createEmptyList();
    ListStudents *students70 = createEmptyList();

    typedef struct student Student;
    Student studentN;

    int verAP;
    int verAT;

    unsigned int option;
    printf("\n------------- MENU ---------------\n");
    printf("1- Inserir Informacoes de Aluno\n");
    printf("2- Procurar Aluno\n");
    printf("3- Listar Alunos\n");
    printf("4- Listar Alunos Com Media >70\n");
    printf("5- Remover Informacoes de Aluno\n");
    printf("0- Sair\n");
    printf("Escolha uma opcao: \n\n");
    scanf("%d", &option);
    getchar();
    while (option != 0) {
        switch (option){
            case 1:
                printf("\nNome do aluno: ");
                scanf("%30[^\n]%*c", studentN.name);
                //getchar();
                printf("Nota Aula Pratica (<=50): ");
                /*verAP*/ scanf("%f", &studentN.pGrade);
                /*
                while (verAP != 1) { // verificador de entrada (tentativa de verificador, nao funciona!)
                    printf("Entrada inválida! Insira um numero decimal entre 0 e 50! : ");
                    verAP = scanf("%f", &studentN.pGrade);
                }
                */
                while (studentN.pGrade > 50) {
                    printf("Nota nao pode ser maior que 50. Insira novamente: ");
                    /*verAP*/ scanf("%f", &studentN.pGrade);
                    /*
                    while (verAP != 1) { // verificador de entrada (tentativa de verificador, nao funciona!)
                        printf("Entrada inválida! Insira um numero decimal entre 0 e 50! : ");
                        verAP = scanf("%f", &studentN.pGrade);
                    }
                    */
                }
                printf("Nota Aula Teorica: ");
                /*verAT*/ scanf("%f", &studentN.tGrade);
                /*
                while (verAT != 1) { // verificador de entrada (tentativa de verificador, nao funciona!)
                    printf("Entrada inválida! Insira um numero decimal entre 0 e 50! : ");
                    verAT = scanf("%f", &studentN.tGrade);
                }
                */
                while (studentN.tGrade > 50) {
                    printf("Nota nao pode ser maior que 50. Insira novamente: ");
                    /*verAT*/ scanf("%f", &studentN.tGrade);
                    /*
                    while (verAT != 1) { // verificador de entrada (tentativa de verificador, nao funciona!)
                        printf("Entrada inválida! Insira um numero decimal entre 0 e 50! : ");
                        verAT = scanf("%f", &studentN.tGrade);
                    }
                    */
                }
                const int v1 = insertStudent(studentsList, studentN); // v = verificador;
                if (v1==0) printf("Nao foi possivel adicionar aluno. Tente Novamente.\n");
                break;
            case 2:
                printf("Nome do aluno: ");
                scanf("%30[^\n]%*c", studentN.name);
                //getchar();
                const int v2 = searchStudent(studentsList, studentN.name);
                break;
            case 3:
                printList(studentsList);
                break;
            case 4:
                students70 = listOfStudents70(studentsList);
                if (students70 == studentsList) break;
                else {
                    printList(students70);
                    break;
                }
            case 5:
                printf("Nome do aluno para remover: ");
                scanf("%30[^\n]%*c", studentN.name);
                //getchar();
                removeStudent(studentsList, studentN.name);
                break;
            default: printf("Opcao Invalida\n"); break;
        }

        printf("\n------------- MENU ---------------\n");
        printf("1- Inserir Informacoes de Aluno\n");
        printf("2- Procurar Aluno\n");
        printf("3- Listar Alunos\n");
        printf("4- Listar Alunos Com Media >70\n");
        printf("5- Remover Informacoes de Aluno\n");
        printf("0- Sair\n");
        printf("Escolha uma opcao: \n\n");
        scanf("%d", &option);
        getchar();
    }
}