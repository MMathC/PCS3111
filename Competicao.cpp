#include "Competicao.h"
#include <iostream>

using namespace std;

Competicao::Competicao(string nome, Equipe** equipes,int quantidade){
    this->nome = nome;
    this->equipes = equipes;
    this->quantidadeEquipes = quantidade;

    //this->modalidades = new Modalidade*[maximoModalidades];
    //this->quantidadeDeModalidades = 0;
}

Competicao::~Competicao(){
  /*for (int i = 0; i < this->quantidadeDeModalidades; i++){
    delete this->modalidades[i];
  }
  delete[] modalidades;*/
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


/*
Tabela* Competicao::getTabela() {

  Tabela* tempTabela = new TabelaComPontos(equipes, quantidadeEquipes);//tabela é abstrata e não pode criar objetos(new), tem que ser ou TabelaComOrdem ou TabelaComPontos

  for (int i = 0; i < quantidadeDeModalidades; i++){
    if (modalidades[i]->temResultado()){
        for (int j = 0; j < modalidades[i]->getQuantidadeDeEquipes(); j++){
            Equipe* tempEquipe = modalidades[i]->getEquipes()[j];
        }if(modalidades[i]->getPosicao(tempEquipe) == 1) {
            tempTabela->pontuar(tempEquipe, 13);
        }else if(modalidades[i]->getPosicao(tempEquipe) == 2){
            tempTabela->pontuar(tempEquipe, 10);
        }else if(modalidades[i]->getPosicao(tempEquipe) == 3){
            tempTabela->pontuar(tempEquipe, 8);
         }else if(modalidades[i]->getPosicao(tempEquipe) == 4){
            tempTabela->pontuar(tempEquipe, 7);
        }else if(modalidades[i]->getPosicao(tempEquipe) >= 5 && modalidades[i]->getPosicao(tempEquipe) < 10){
         tempTabela->pontuar(tempEquipe, 10 - modalidades[i]->getPosicao(tempEquipe));
        }

    }
  } return tempTabela;
}





int Competicao::getQuantidadeDeModalidades(){
  return this->quantidadeDeModalidades;
}



Modalidade** Competicao::getModalidades(){
  return this->modalidades;
}



void Competicao::adicionar(Modalidade* m){
  if (this->quantidadeDeModalidades < this->maximoModalidades){

    this->modalidades[this->quantidadeDeModalidades] = m;

    this->quantidadeDeModalidades++;
    return true;

  } else return false;

}


implemantar para cada classe competição
void Competicao::imprimir() {
  cout << this->nome << endl;
  this->getTabela()->imprimir();
}
*/

