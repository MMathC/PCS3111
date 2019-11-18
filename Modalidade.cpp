#include "Modalidade.h"

using namespace std;

Modalidade::Modalidade(string nome, Equipe** participantes, int quantidade){
    if (quantidade < 2){
      throw new invalid_argument("Quantidade de equipes abaixo de 2.");
    }
    this->nome = nome;
    this->quantidadeEquipes = quantidade;
    this->participantes = participantes;
    this->tabela = new TabelaComOrdem(participantes, quantidade);
}

Modalidade::~Modalidade(){
}

int Modalidade::getQuantidadeDeEquipes(){
    return quantidadeEquipes;
}

Equipe** Modalidade::getEquipes(){
    return participantes;
}

string Modalidade::getNome(){
    return nome;
}

void Modalidade::setResultado(Equipe** participantes){
    tabela->setResultado(participantes);
    this->resultado = true;
}


TabelaComOrdem* Modalidade::getTabela(){
  return tabela;
}


bool Modalidade::temResultado(){
  return resultado;
}

void Modalidade::imprimir(){
  cout<< nome << endl;

  if(temResultado()){
    tabela->imprimir();

  } else {
    for (int i = 0; i < quantidadeEquipes; i++) {
      cout << "    " << participantes[i]->getNome() << endl;
    }
  }
}





