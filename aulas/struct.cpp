#include <stdio.h>
#include <string.h>

struct Aluno {
    char nome[50];
    int idade;
    int matricula;
    char curso[30];
}; 

int main() {
    int i;
    struct Aluno alunos[3]; // Array de structs para armazenar 3 alunos

    // Cadastrando dados de alunos
    strcpy(alunos[0].nome, "Sergio Silva");
    alunos[0].idade = 16;
    alunos[0].matricula = 1001;
    strcpy(alunos[0].curso, "Matematica");

    strcpy(alunos[1].nome, "Julia Pereira");
    alunos[1].idade = 17;
    alunos[1].matricula = 1002;
    strcpy(alunos[1].curso, "Fisica");

    strcpy(alunos[2].nome, "Joao Souza");
    alunos[2].idade = 18;
    alunos[2].matricula = 1003;
    strcpy(alunos[2].curso, "Quimica");

    // Exibindo dados dos alunos cadastrados
    printf("=== Dados dos Alunos Cadastrados ===\n");
    for (i = 0; i < 3; i++) {
        printf("Aluno %d:\n", i + 1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Idade: %d\n", alunos[i].idade);
        printf("Matricula: %d\n", alunos[i].matricula);
        printf("Curso: %s\n\n", alunos[i].curso);
    }

    return 0;
} 