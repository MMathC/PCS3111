#include <iostream>
#include "Tabela.h"

using namespace std;


Tabela::Tabela(Equipe** participantes, int quantidade){
    if(quantidade < 2){
        throw new invalid_argument("Quantidade de equipes abaixo de 2.");
    }
    this->participantes = participantes;
    this->quantidadeParticipantes = quantidade;
    resultado = new Equipe*[quantidadeParticipantes];
}

Tabela::~Tabela(){
}

int Tabela::getIndice(Equipe* participante){
        for (int i = 0; i < this->quantidadeParticipantes; i++){
            if(this->participantes[i] == participante) {
                return i;
            }
        }return -1;
}

int Tabela::getQuantidadeDeEquipes(){
  return this->quantidadeParticipantes;
}

