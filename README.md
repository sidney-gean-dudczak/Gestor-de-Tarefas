# Gestor de Tarefas

## 1. Sobre o projeto

O **Gestor de Tarefas** é um sistema desenvolvido em C++ com o objetivo de cadastrar, organizar, editar, pesquisar e excluir tarefas por meio de um menu interativo.

O projeto foi desenvolvido como parte das atividades do curso de Engenharia de Software, colocando em prática conceitos de programação e estruturas de dados estudados durante o período.

## 2. Funcionalidades implementadas

- Cadastro de tarefas com ID sequencial automático.
- Exibição das tarefas cadastradas.
- Remoção da primeira tarefa.
- Remoção da última tarefa.
- Edição de tarefas pelo ID.
- Exclusão de tarefas pelo ID, com confirmação.
- Ordenação por prioridade utilizando Selection Sort.
- Busca de tarefas pelo ID.
- Busca de tarefas pelo status.
- Desfazer a última operação (Ctrl+Z), contemplando cadastro, edição e exclusão.

## 3. Estruturas de dados e conceitos utilizados

- **Structs:** organização dos dados das tarefas, datas e operações.
- **Lista simplesmente encadeada:** armazenamento dinâmico das tarefas.
- **Pilha encadeada:** utilizada no histórico de operações e implementada por meio de funções de manipulação de pilha.
- **Ponteiros:** acesso e manipulação dos nós das estruturas.
- **Alocação dinâmica:** utilização de `new` e `delete`.
- **Funções:** divisão do programa em operações específicas.
- **Selection Sort:** ordenação das tarefas por prioridade.
- **Busca sequencial:** localização de tarefas por ID e status.

## 4. Tecnologias utilizadas

- Linguagem C++.
- Biblioteca `<iostream>`.
- Biblioteca `<string>`.
- Compilador G++.

## 5. Compilação e execução

Para compilar o projeto, é necessário ter o compilador G++ instalado.

Utilize o seguinte comando no terminal:

```bash
g++ -std=c++17 gestor.cpp -o gestor
```

Para executar no Linux:

```bash
./gestor
```

No Windows:

```bash
gestor.exe
```

## 6. Utilização de inteligência artificial

Durante o desenvolvimento do projeto, foi utilizada inteligência artificial como ferramenta de apoio.

A IA auxiliou principalmente no levantamento e na organização das funcionalidades do sistema, no esclarecimento de dúvidas sobre conceitos de programação e estruturas de dados e na compreensão de possíveis erros durante a implementação.

Também foi utilizada como apoio para discutir soluções e entender melhor o funcionamento de determinados trechos do código.

A utilização da ferramenta teve como objetivo complementar o processo de aprendizagem, servindo como suporte durante o desenvolvimento. As decisões sobre o projeto e o acompanhamento da implementação fizeram parte do trabalho realizado pelo estudante.

## 7. Integrantes e divisão das responsabilidades

O projeto foi desenvolvido em equipe, com as responsabilidades divididas entre os integrantes.

### Sidney e Juan

Responsáveis pelas estruturas `Data`, `Tarefa` e `node`, pelo desenvolvimento da função `main` e pelas funcionalidades relacionadas ao gerenciamento das tarefas.

**Funções:**
- `main()`
- `limparLista()`
- `inserirFinal()`
- `inserirNaPosicao()`
- `localizarPorId()`
- `removerSemConfirmacao()`
- `exibirLista()`
- `removerInicio()`
- `removerFinal()`
- `editarTarefa()`
- `removerPorId()`
- `ordenarPrioridade()`
- `buscarPorId()`
- `buscarPorStatus()`
- `consultarTopo()`

### Rafael e Natael

Responsáveis pelas estruturas `Operacao` e `nodeOperacao`, utilizadas no controle do histórico de operações e na funcionalidade de desfazer ações.

**Funções:**
- `pushOperacao()`
- `popOperacao()`
- `limparHistorico()`
- `registrarExclusao()`
- `desfazer()`
- `exibirPilha()`
- `push()`
- `pop()`


