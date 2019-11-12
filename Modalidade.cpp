#include "Modalidade.h"

using namespace std;

Modalidade::Modalidade(string nome, Equipe** participantes, int quantidade){
    if (quantidadeEquipes < 2){
        throw new invalid_argument("Quantidade de equipes abaixo de 2.");
    }
    this->nome = nome;
    this->quantidadeEquipes = quantidade;
    this->participantes = participantes;
    this->resultado = false;
}

Modalidade::~Modalidade(){

}

int Modalidade::getQuantidadeDeEquipes(){
    return this->quantidadeEquipes;
}

Equipe** Modalidade::getEquipes(){
    return this->participantes;
}

string Modalidade::getNome(){
    return this->nome;
}

void Modalidade::setResultado(Equipe** participantes){
   //implemetar nova logica de setar o resultado
    this->resultado = true;
}
/*
TabelaComOrdem* Modalidade::getTabela(){
  return this->tabela;
}
*/

bool Modalidade::temResultado(){
  return this->resultado;
}

void Modalidade::imprimir(){
    cout>>"Modalidade: "<<nome<<endl;
    TabelaComOrdem->imprimir();
}





