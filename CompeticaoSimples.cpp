#include "CompeticaoSimples.h"

CompeticaoSimples::CompeticaoSimples(string nome, Equipe** equipes, int quantidade, Modalidade* m):Competicao(nome,equipes, quantidade), m(m){
}

CompeticaoSimples::~CompeticaoSimples(){
}

void CompeticaoSimples::imprimir(){
  cout << nome << endl;

  if(m->temResultado()){
    m->getTabela()->imprimir();

  } else {
    for (int i = 0; i < quantidadeEquipes; i++) {
      cout << "    " << equipes[i]->getNome() << endl;
    }
  }
}

Modalidade* CompeticaoSimples::getModalidade(){
    return m;
}

Tabela* CompeticaoSimples::getTabela(){
  return m->getTabela();
}
