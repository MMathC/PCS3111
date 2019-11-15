#include "Modalidade.h"

using namespace std;

Modalidade::Modalidade(string nome, Equipe** participantes, int quantidade){
    if (quantidade < 2){
        throw new invalid_argument("Quantidade de equipes abaixo de 2.");
    }
    this->nome = nome;
    this->quantidadeEquipes = quantidade;
    this->participantes = participantes;
    this->resultado = false;
    this->novaTab = novaTab;
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
   //implemetar nova logica de setar o resultado
    this->resultado = true;
}

TabelaComOrdem* Modalidade::getTabela(){
    return novaTab;
}


bool Modalidade::temResultado(){
  return this->resultado;
}

void Modalidade::imprimir(){
    cout<<"Modalidade: "<<nome<<endl;
    //TabelaComOrdem->imprimir();
}





