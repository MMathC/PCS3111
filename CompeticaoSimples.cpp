#include "CompeticaoSimples.h"

CompeticaoSimples::CompeticaoSimples(string nome, Equipe** equipes, int quantidade, Modalidade* m):Competicao(nome,equipes, quantidade), m(m){
}

CompeticaoSimples::~CompeticaoSimples(){
}

void CompeticaoSimples::imprimir(){
  cout << nome << endl;
  m->getTabela()->imprimir();
}

Modalidade* CompeticaoSimples::getModalidade(){
    return m;
}

Tabela* CompeticaoSimples::getTabela(){
    return m->getTabela();
}
