# Histórico de Alunos com Multilista

Este repositório contém a implementação de um programa para gerenciamento de histórico de alunos utilizando uma estrutura de multilista. O programa foi desenvolvido como parte do trabalho da faculdade para explorar conceitos de listas encadeadas e manipulação de dados.

## Descrição do Projeto

O programa implementa um sistema de gerenciamento de históricos acadêmicos de alunos utilizando uma estrutura de **multilista**. Cada aluno é representado em uma **lista duplamente encadeada**, e cada aluno possui uma **lista simplesmente encadeada** que armazena as disciplinas cursadas.

### Estrutura de Dados
- **Lista Duplamente Encadeada**: Armazena os alunos cadastrados. Cada nó da lista contém:
  - Nome do aluno
  - Matrícula do aluno
  - Ponteiro para o próximo aluno
  - Ponteiro para o aluno anterior
  - Ponteiro para uma lista de disciplinas cursadas pelo aluno

- **Lista Simplesmente Encadeada**: Armazena as disciplinas cursadas por um aluno específico. Cada nó da lista contém:
  - Nome da disciplina
  - Nota
  - Percentual de presença
  - Situação (AP - Aprovado, RM - Reprovado por Média, RF - Reprovado por Falta, TR - Trancado)
  - Período em que foi cursada

### Funcionalidades Implementadas
O programa oferece as seguintes funcionalidades:

1. **Cadastrar Aluno**
   - Adiciona um novo aluno à lista duplamente encadeada.
   - Requer informações como nome e matrícula.

2. **Cadastrar Disciplina de Aluno**
   - Adiciona uma nova disciplina à lista de disciplinas de um aluno específico.
   - Requer informações como nome da disciplina, nota, percentual de presença, situação e período.

3. **Remover Aluno**
   - Remove um aluno da lista duplamente encadeada, incluindo todas as suas disciplinas.

4. **Exibir Listagem de Alunos Cadastrados**
   - Exibe o nome e a matrícula de todos os alunos cadastrados.

5. **Exibir Histórico de Aluno Específico**
   - Busca um aluno pelo nome ou matrícula e exibe todas as disciplinas cursadas por ele, incluindo detalhes como nota, percentual de presença, situação e período.

### Como Executar o Programa

#### Pré-requisitos
- Compilador C/C++ instalado (como `gcc` ou `g++`).

#### Passos para Execução
1. Clone este repositório:
   ```bash
   git clone https://github.com/seu-usuario/Historico-Alunos-Multilista.git
   ```

2. Navegue até o diretório do projeto:
   ```bash
   cd Historico-Alunos-Multilista
   ```

3. Compile o código-fonte:
   ```bash
   g++ main.cpp -o historico_alunos
   ```

4. Execute o programa:
   ```bash
   ./historico_alunos
   ```

### Estrutura do Projeto
```
Historico-Alunos-Multilista/
├── README.md          # Documentação do projeto
├── main.cpp           # Código-fonte principal do programa
├── aluno.h            # Definição da estrutura de aluno e funções relacionadas
├── disciplina.h       # Definição da estrutura de disciplina e funções relacionadas
└── utils.h            # Funções auxiliares (ex.: menus, validações)
```

### Contribuições
Contribuições são bem-vindas! Se você deseja melhorar o projeto, corrigir bugs ou adicionar novas funcionalidades, siga os passos abaixo:

1. Faça um fork deste repositório.
2. Crie uma branch para sua contribuição:
   ```bash
   git checkout -b feature/nova-funcionalidade
   ```
3. Envie um pull request detalhando suas alterações.