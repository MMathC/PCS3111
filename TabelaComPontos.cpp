#include "TabelaComPontos.h"
#include <vector>
#include <list>

TabelaComPontos::TabelaComPontos(Equipe** participantes, int quantidade): Tabela(participantes, quantidade) {
  pontos = new vector<int>();
 
  for (int i = 0; i < quantidade; i++){
    pontos->push_back(0);
  }
  
}

TabelaComPontos::~TabelaComPontos(){
}

Equipe** TabelaComPontos::getEquipesEmOrdem(){
  
  int pos = 1;
  int indice = 0;

  while (pos <= quantidadeParticipantes){
    for (int i = 0; i < quantidadeParticipantes; i++){
      if (getPosicao(participantes[i]) == pos) {
	resultado[indice] = participantes[i];
	//cout << resultado[indice]->getNome() << endl;;
	indice++;
	}
    }
    pos++;
  }
  
return resultado;
}


bool TabelaComPontos::inEquipes(Equipe* p){
  for (int i = 0; i < quantidadeParticipantes; i++){
    if (participantes[i] == p) return true;
  }
  return false;
}

int TabelaComPontos::getPosicao(Equipe* participante){
  int pos = quantidadeParticipantes;
  
  for (int i = quantidadeParticipantes - 1; i >= 0; i--){
    if (getPontos(participante) > getPontos(participantes[i])) pos -= 1;
  }
    return pos;
}

int TabelaComPontos::getIndice(Equipe* participante){
  for (int i = 0; i < quantidadeParticipantes; i++){
    if (participantes[i] == participante) return i;
  } return -1;
}


void TabelaComPontos::pontuar(Equipe* participante, int pontos){
  if (!inEquipes(participante)) throw new invalid_argument("Equipe não pertence a tabela.");
  
  this->pontos->at(getIndice(participante)) += pontos;
  isResultadoAtualizado = false;
}

int TabelaComPontos::getPontos(Equipe* participante){
  if (!inEquipes(participante)) throw new invalid_argument("Equipe não pertence a tabela.");
  return pontos->at(getIndice(participante));
}

void TabelaComPontos::imprimir(){
  for (int i = 0; i < quantidadeParticipantes; i++){
    cout << getPosicao(getEquipesEmOrdem()[i]) << "o " << getEquipesEmOrdem()[i]->getNome() << " (" << getPontos(getEquipesEmOrdem()[i]) << " pontos) " <<  endl;
    }  
  
  

}
