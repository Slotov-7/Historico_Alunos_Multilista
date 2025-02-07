#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//
// Created by Guilherme Araújo on 07/02/2025.

// Estrutura que representa uma disciplina
typedef struct Disciplina {
    char nome[30]; // Nome da disciplina
    float nota; // Nota da disciplina
    float percPresenca; // Percentual de presença na disciplina
    char situacao[3]; // Situação da disciplina (AP, RM, RF, TR)
    int periodo; // Período em que a disciplina foi cursada
    struct Diciplina *proximo; // Ponteiro para a próxima disciplina na lista
} Disciplina;

// Estrutura que representa um aluno
typedef struct Aluno {
    char nome[50]; // Nome do aluno
    int matricula; // Matrícula do aluno
    Disciplina *diciplinas; // Ponteiro para a lista de disciplinas do aluno
    struct Aluno *anterior; // Ponteiro para o aluno anterior na lista
    struct Aluno *proximo; // Ponteiro para o próximo aluno na lista
} Aluno;

// Estrutura que representa a lista de alunos
typedef struct ListaAlunos {
    Aluno *primeiro; // Ponteiro para o primeiro aluno da lista
    Aluno *ultimo; // Ponteiro para o último aluno da lista
} ListaAlunos;

// Função para criar uma lista de alunos vazia
void criar_lista(ListaAlunos *lista) {
    lista->primeiro = NULL;
    lista->ultimo = NULL;
}

// Função para cadastrar um novo aluno na lista
void cadastrar_aluno(ListaAlunos *lista, char nome[], int matricula) {
    Aluno *novo_aluno = (Aluno *)malloc(sizeof(Aluno)); // Aloca memória para um novo aluno
    if (novo_aluno) {
        strcpy(novo_aluno->nome, nome); // Copia o nome do aluno
        novo_aluno->matricula = matricula; // Define a matrícula do aluno
        novo_aluno->diciplinas = NULL; // Inicializa a lista de disciplinas do aluno como vazia
        novo_aluno->anterior = NULL; // Define o ponteiro anterior como NULL
        novo_aluno->proximo = NULL; // Define o ponteiro próximo como NULL

        if (lista->primeiro == NULL) { // Se a lista estiver vazia
            lista->primeiro = novo_aluno; // O novo aluno é o primeiro da lista
            lista->ultimo = novo_aluno; // O novo aluno é também o último da lista
        } else {
            lista->ultimo->proximo = novo_aluno; // Adiciona o novo aluno ao final da lista
            novo_aluno->anterior = lista->ultimo; // Define o ponteiro anterior do novo aluno
            lista->ultimo = novo_aluno; // Atualiza o ponteiro para o último aluno da lista
        }
        printf("Aluno '%s' cadastrado com sucesso.\n", nome); // Mensagem de sucesso
    } else {
        printf("Erro ao alocar memoria"); // Mensagem de erro
    }
}

// Função para cadastrar uma nova disciplina para um aluno
void cadastrar_disciplina_aluno(Aluno *aluno, char nome[], float nota, float percPresenca, char situacao[], int periodo) {
    Disciplina *aux, *nova_disciplina = (Disciplina *)malloc(sizeof(Disciplina)); // Aloca memória para uma nova disciplina
    if (nova_disciplina) {
        strcpy(nova_disciplina->nome, nome); // Copia o nome da disciplina
        nova_disciplina->nota = nota; // Define a nota da disciplina
        nova_disciplina->percPresenca = percPresenca; // Define o percentual de presença
        strcpy(nova_disciplina->situacao, situacao); // Copia a situação da disciplina
        nova_disciplina->periodo = periodo; // Define o período da disciplina
        nova_disciplina->proximo = NULL; // Define o ponteiro próximo como NULL

        if (aluno->diciplinas == NULL) { // Se a lista de disciplinas do aluno estiver vazia
            aluno->diciplinas = nova_disciplina; // A nova disciplina é a primeira da lista
        } else {
            aux = aluno->diciplinas; // Ponteiro auxiliar para percorrer a lista de disciplinas
            while (aux->proximo) { // Percorre até o final da lista
                aux = aux->proximo;
            }
            aux->proximo = nova_disciplina; // Adiciona a nova disciplina ao final da lista
        }
        printf("Disciplina '%s' cadastrada para o aluno '%s'!\n", nome, aluno->nome); // Mensagem de sucesso
    } else {
        printf("Erro ao alocar memoria"); // Mensagem de erro
    }
}

// Função para remover um aluno da lista
void remove_aluno(ListaAlunos *lista, int matricula) {
    Aluno *aluno = lista->primeiro; // Ponteiro para percorrer a lista de alunos
    while (aluno != NULL && aluno->matricula != matricula) { // Procura o aluno pela matrícula
        aluno = aluno->proximo;
    }
    if (aluno == NULL) { // Se o aluno não for encontrado
        printf("Aluno nao encontrado.\n");
        return;
    }
    Disciplina *disciplina = aluno->diciplinas; // Ponteiro para percorrer a lista de disciplinas do aluno
    Disciplina *aux;
    while (disciplina != NULL) { // Libera a memória de todas as disciplinas do aluno
        aux = disciplina;// Salva o ponteiro para a disciplina atual
        disciplina = disciplina->proximo;// Avança para a próxima disciplina
        free(aux);// Libera a memória da disciplina atual
    }
    if (aluno->anterior != NULL) { // Ajusta o ponteiro do aluno anterior, se existir
        aluno->anterior->proximo = aluno->proximo;
    } else { // Se o aluno for o primeiro da lista
        lista->primeiro = aluno->proximo;// Atualiza o ponteiro para o primeiro aluno
    }
    if (aluno->proximo != NULL) { // Ajusta o ponteiro do próximo aluno, se existir
        aluno->proximo->anterior = aluno->anterior;// Atualiza o ponteiro do próximo aluno
    } else { // Se o aluno for o último da lista
        lista->ultimo = aluno->anterior;// Atualiza o ponteiro para o último aluno
    }
    free(aluno); // Libera a memória do aluno
    printf("Aluno removido com sucesso.\n");
}

// Função para exibir os alunos cadastrados
void exibir_alunos(ListaAlunos *lista){
    Aluno *aluno = lista->primeiro; // Ponteiro para percorrer a lista de alunos
    if (aluno == NULL) {
        printf("Nenhum aluno cadastrado.\n"); // Mensagem de erro
    }
    printf("\n=== ALUNOS ===\n");
    while (aluno) {
        printf("Nome: %s\n", aluno->nome); // Exibe o nome do aluno
        printf("Matricula: %d\n", aluno->matricula); // Exibe a matrícula do aluno
        aluno = aluno->proximo; // Avança para o próximo aluno
    }
}
void exibir_historico(ListaAlunos *lista, int matricula) {
    Aluno *aluno = lista->primeiro; // Ponteiro para percorrer a lista de alunos
    if (aluno == NULL) {
        printf("Nenhum aluno cadastrado.\n"); // Mensagem de erro
    }
    else {
        while (aluno->proximo && aluno->matricula != matricula) {
            aluno = aluno->proximo;
        }
        if (aluno->matricula == matricula){
            printf("Disciplinas do aluno %s:\n", aluno->nome); // Exibe o nome do aluno
            Disciplina *disciplina = aluno->diciplinas; // Ponteiro para percorrer a lista de disciplinas do aluno
            while (disciplina) {
                printf("  Nome: %s\n", disciplina->nome); // Exibe o nome da disciplina
                printf("  Nota: %.2f\n", disciplina->nota); // Exibe a nota da disciplina
                printf("  Percentual de presenca: %.2f%%\n", disciplina->percPresenca); // Exibe o percentual de presença
                printf("  Situacao: %s\n", disciplina->situacao); // Exibe a situação da disciplina
                printf("  Periodo: %d\n", disciplina->periodo); // Exibe o período da disciplina
                disciplina = disciplina->proximo; // Avança para a próxima disciplina
            }
        }
    }
}

int main() {
    ListaAlunos lista;// Declara uma lista de alunos
    criar_lista(&lista);// Cria a lista de alunos

    int opcao, matricula, periodo;// Variáveis para armazenar a opção do menu, a matrícula do aluno e o período da disciplina
    char nome[100], disciplinaNome[50], situacao[3];// Variáveis para armazenar o nome do aluno, o nome da disciplina e a situação da disciplina
    float nota, presenca;// Variáveis para armazenar a nota e o percentual de presença na disciplina

    do {// Loop do menu
        printf("\n=== MENU ===\n");
        printf("1. Cadastrar Aluno\n");
        printf("2. Cadastrar Disciplina\n");
        printf("3. Exibir Alunos\n");
        printf("4. Exibir Historico\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:// Cadastrar um novo aluno
                printf("Digite o nome do aluno: ");
                scanf(" %[^\n]", nome);
                printf("Digite a matricula do aluno: ");
                scanf("%d", &matricula);
                cadastrar_aluno(&lista, nome, matricula);
                break;
            case 2:// Cadastrar uma nova disciplina para um aluno
                printf("Digite a matricula do aluno: ");
                scanf("%d", &matricula);
                Aluno *aluno = lista.primeiro;
                while (aluno != NULL && aluno->matricula != matricula) {
                    aluno = aluno->proximo;
                }
                if (aluno == NULL) {
                    printf("Aluno nao encontrado.\n");
                    break;
                }
                printf("Digite o nome da disciplina: ");
                scanf(" %[^\n]", disciplinaNome);
                printf("Digite a nota: ");
                scanf("%f", &nota);
                printf("Digite o percentual de presenca: ");
                scanf("%f", &presenca);
                printf("Digite a situacao (AP, RM, RF, TR): ");
                scanf(" %[^\n]", situacao);
                printf("Digite o periodo: ");
                scanf("%d", &periodo);
                cadastrar_disciplina_aluno(aluno, disciplinaNome, nota, presenca, situacao, periodo);
                break;
            case 3:// Exibir os alunos cadastrados
                exibir_alunos(&lista);
                break;
            case 4:// Exibir o histórico de um aluno
                printf("Digite a matricula do aluno: ");
                scanf("%d", &matricula);
                exibir_historico(&lista, matricula);
                break;

            case 0:// Sair do programa
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}