#include "Competicao.h"
#include <iostream>
#include<stdexcept>

using namespace std;

Competicao::Competicao(string nome, Equipe** equipes,int quantidade){
    if(quantidade<2){
        throw new invalid_argument ("");
    }
    this->nome = nome;
    this->equipes = equipes;
    this->quantidadeEquipes = quantidade;
}

Competicao::~Competicao(){
}


string Competicao::getNome(){
  return this->nome;
}

Equipe** Competicao::getEquipes(){
  return this->equipes;
}

int Competicao::getQuantidadeDeEquipes(){
  return this->quantidadeEquipes;
}



