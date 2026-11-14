#include <iostream>
#include <string>
using namespace std;

struct Data
{
    int dia, mes, ano;
};

struct Tarefa
{
    int id;
    string titulo;
    string descricao;
    int prioridade;
    string status;
    Data prazo;
};

struct node
{
    Tarefa dado;
    node *prox;
};


struct Operacao
{
    int tipo;
    int idTarefa;
    Tarefa tarefaAnterior;
    Tarefa tarefaNova;
    int posicao;
};

struct nodeOperacao
{
    Operacao dado;
    nodeOperacao *prox;
};


void inserirFinal(node *&head, Tarefa tarefa)
{
    node *novo = new node();
    novo->dado = tarefa;
    novo->prox = nullptr;

    if (head == nullptr)
    {
        head = novo;
        return;
    }

    node *p = head;
    while (p->prox != nullptr)
        p = p->prox;

    p->prox = novo;
}
void exibirLista(node *head)
{
    if (head == nullptr)
    {
        cout << "Lista vazia!" << endl;
        return;
    }

    node *atual = head;
    while (atual != nullptr)
    {
        cout << "ID: " << atual->dado.id << endl;
        cout << "Titulo: " << atual->dado.titulo << endl;
        cout << "Descricao: " << atual->dado.descricao << endl;
        cout << "Prioridade: " << atual->dado.prioridade << endl;
        cout << "Status: " << atual->dado.status << endl;
        cout << "Prazo: " << atual->dado.prazo.dia << "/"
             << atual->dado.prazo.mes << "/" << atual->dado.prazo.ano << endl;
        cout << endl;
        atual = atual->prox;
    }
}

void buscarPorId(node *head, int id)
{
    node *aux = localizarPorId(head, id);
    if (aux == nullptr)
    {
        cout << "Tarefa nao encontrada!" << endl;
        return;
    }

    cout << "Tarefa encontrada!" << endl;
    cout << "ID: " << aux->dado.id << endl;
    cout << "Titulo: " << aux->dado.titulo << endl;
    cout << "Descricao: " << aux->dado.descricao << endl;
    cout << "Prioridade: " << aux->dado.prioridade << endl;
    cout << "Status: " << aux->dado.status << endl;
    cout << "Data: " << aux->dado.prazo.dia << "/"
         << aux->dado.prazo.mes << "/" << aux->dado.prazo.ano << endl;
}

void limparLista(node *&head)
{
    while (head != nullptr)
    {
        node *atual = head;
        head = head->prox;
        delete atual;
    }
}

void inserirNaPosicao(node *&head, Tarefa tarefa, int posicao)
{
    node *novo = new node();
    novo->dado = tarefa;

    if (head == nullptr || posicao <= 0)
    {
        novo->prox = head;
        head = novo;
        return;
    }

    node *p = head;
    int indice = 0;

    while (p->prox != nullptr && indice < posicao - 1)
    {
        p = p->prox;
        indice++;
    }

    novo->prox = p->prox;
    p->prox = novo;
}
node *localizarPorId(node *head, int id)
{
    node *aux = head;
    while (aux != nullptr && aux->dado.id != id)
        aux = aux->prox;
    return aux;
}

void ordenarPrioridade(node *head)
{
    if (head == nullptr || head->prox == nullptr)
        return;

    node *atual = head;
    while (atual->prox != nullptr)
    {
        node *maior = atual;
        node *aux = atual->prox;

        while (aux != nullptr)
        {
            if (aux->dado.prioridade > maior->dado.prioridade)
                maior = aux;
            aux = aux->prox;
        }

        Tarefa temp = atual->dado;
        atual->dado = maior->dado;
        maior->dado = temp;
        atual = atual->prox;
    }
}


void buscarPorStatus(node *head, const string &statusBusca)
{
    bool encontrado = false;
    node *aux = head;

    while (aux != nullptr)
    {
        if (aux->dado.status == statusBusca)
        {
            cout << "ID: " << aux->dado.id << endl;
            cout << "Titulo: " << aux->dado.titulo << endl;
            cout << "Descricao: " << aux->dado.descricao << endl;
            cout << "Prioridade: " << aux->dado.prioridade << endl;
            cout << "Status: " << aux->dado.status << endl;
            cout << "Data: " << aux->dado.prazo.dia << "/"
                 << aux->dado.prazo.mes << "/" << aux->dado.prazo.ano << endl
                 << endl;
            encontrado = true;
        }
        aux = aux->prox;
    }

    if (!encontrado)
        cout << "Nenhuma tarefa encontrada com esse status!" << endl;
}



void pushOperacao(nodeOperacao *&topo, Operacao operacao)
{
    nodeOperacao *novo = new nodeOperacao();
    novo->dado = operacao;
    novo->prox = topo;
    topo = novo;
}

void popOperacao(nodeOperacao *&topo)
{
    if (topo == nullptr)
        return;

    nodeOperacao *p = topo;
    topo = topo->prox;
    delete p;
}

void limparHistorico(nodeOperacao *&topo)
{
    while (topo != nullptr)
        popOperacao(topo);
}



bool removerSemConfirmacao(node *&head, int id, Tarefa &removida, int &posicao)
{
    node *atual = head;
    node *anterior = nullptr;
    posicao = 0;

    while (atual != nullptr && atual->dado.id != id)
    {
        anterior = atual;
        atual = atual->prox;
        posicao++;
    }

    if (atual == nullptr)
        return false;

    removida = atual->dado;

    if (anterior == nullptr)
        head = atual->prox;
    else
        anterior->prox = atual->prox;

    delete atual;
    return true;
}

void push(node *&topo, Tarefa tarefa)
{
    node *novo = new node();
    novo->dado = tarefa;
    novo->prox = topo;
    topo = novo;
}

void pop(node *&topo)
{
    if (topo == nullptr)
        return;
    node *p = topo;
    topo = topo->prox;
    delete p;
}

void consultarTopo(node *topo)
{
    if (topo == nullptr)
    {
        cout << "Pilha vazia!" << endl;
        return;
    }
    cout << "ID: " << topo->dado.id << endl;
    cout << "Titulo: " << topo->dado.titulo << endl;
    cout << "Prioridade: " << topo->dado.prioridade << endl;
}

void exibirPilha(node *topo)
{
    if (topo == nullptr)
    {
        cout << "Pilha vazia!" << endl;
        return;
    }
    for (node *p = topo; p != nullptr; p = p->prox)
    {
        cout << "ID: " << p->dado.id << endl;
        cout << "Titulo: " << p->dado.titulo << endl;
        cout << "Prioridade: " << p->dado.prioridade << endl
             << endl;
    }
}



int main()
{

    return 0;
}
