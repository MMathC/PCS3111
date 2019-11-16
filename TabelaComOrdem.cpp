#include "TabelaComOrdem.h"

using namespace std;

TabelaComOrdem::TabelaComOrdem(Equipe** participantes, int quantidade): Tabela (participantes, quantidade){
    if(quantidade < 2){
        throw new invalid_argument ("Quantidade de equipes abaixo de 2.");
    }

}

TabelaComOrdem::~TabelaComOrdem(){
}

void TabelaComOrdem::setResultado(Equipe** resultado){
    //implementar o m�todo de fato
    this->resultado = resultado;
}

Equipe** TabelaComOrdem::getEquipesEmOrdem(){
  return this->resultado;
}

int TabelaComOrdem::getPosicao(Equipe* participante){
  return this->getIndice(participante) + 1;
}

void TabelaComOrdem::imprimir(){
  for (int i = 0; i < quantidadeParticipantes; i++){
    cout << i + 1 << "o " << this->resultado[i]->getNome() << endl;
  }
}

