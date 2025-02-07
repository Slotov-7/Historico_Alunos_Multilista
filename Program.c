#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//
// Created by Guilherme Araújo on 07/02/2025.
typedef struct Diciplina {
    char nome[30];
    float nota;
    float percPresenca;
    char situacao[3]; //AP, RM, RF e TR
    int periodo;
    struct Diciplina *proximo;
}Diciplina;

typedef struct Aluno {
    char nome[50];
    int matricula;
    Diciplina *diciplinas;
    struct Aluno *anterior;
    struct Aluno *proximo;
}Aluno;

typedef struct ListaAlunos {
    Aluno *primeiro;
    Aluno *ultimo;
}ListaAlunos;

void criar_lista(ListaAlunos *lista) {
    lista->primeiro = NULL;
    lista->ultimo = NULL;
}

void cadastrar_aluno(ListaAlunos *lista, char nome[], int matricula){
    Aluno *novo_aluno = (Aluno *)malloc(sizeof(Aluno));
    if (novo_aluno) {
        strcpy(novo_aluno->nome, nome);
        novo_aluno->matricula = matricula;
        novo_aluno->diciplinas = NULL;
        novo_aluno->anterior = NULL;
        novo_aluno->proximo = NULL;

        if (lista -> primeiro == NULL) {
            lista->primeiro = novo_aluno;
            lista->ultimo = novo_aluno;
        }else {
            lista->ultimo->proximo = novo_aluno;
            novo_aluno->anterior=lista->ultimo;
            lista->ultimo = novo_aluno;
        }
        printf("Aluno '%s' cadastrado com sucesso.\n", nome);
    }else {
        printf("Erro ao alocar memoria");
    }
}
void cadastrar_diciplina_aluno(Aluno *aluno, char nome[], float nota, float percPresenca, char situacao[], int periodo){
    Diciplina *aux, *nova_diciplina = (Diciplina *)malloc(sizeof(Diciplina));
    if (nova_diciplina) {
        strcpy(nova_diciplina->nome, nome);
        nova_diciplina->nota = nota;
        nova_diciplina->percPresenca = percPresenca;
        strcpy(nova_diciplina->situacao, situacao);
        nova_diciplina->periodo = periodo;
        nova_diciplina->periodo = NULL;

        if (aluno->diciplinas == NULL) {
            aluno->diciplinas = nova_diciplina;
        }else {
            aux = aluno->diciplinas;
            while (aux->proximo) {
                aux = aux->proximo;
            }
            aux->proximo = nova_diciplina;
        }
        printf("Disciplina '%s' cadastrada para o aluno '%s'!\n", nome, aluno->nome);git
    }else {
        printf("Erro ao alocar memoria");
    }
}

