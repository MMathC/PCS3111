#include "TabelaComPontos.h"

TabelaComPontos::TabelaComPontos(Equipe** participantes, int quantidade): Tabela(participantes, quantidade) {
  vector<int> suporte(quantidade, 0);
  this->pontos = suporte;
}

TabelaComPontos::~TabelaComPontos(){
}

Equipe** TabelaComPontos::getEquipesEmOrdem(){
  //alg: achar posição, conferir quantas posições iguais no sub vetor annterior, inserir na posição pos + n
    if (!isResultadoAtualizado){
        for (int i = 0; i < quantidadeParticipantes; i++){
            int pos = getPosicao(participantes[i]);
            int n = 0;
            for (int j = 0; j < i; j++){
                if (getPosicao(participantes[j]) == pos){
                    n += 1;
                }
            }
            resultado[pos + n] = participantes[i];
        }
    isResultadoAtualizado = true;
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

void TabelaComPontos::pontuar(Equipe* participante, int pontos){
  if (!inEquipes(participante)) throw new invalid_argument("Equipe não pertence a tabela.");
  this->pontos[getIndice(participante)] += pontos;
  isResultadoAtualizado = false;
}

int TabelaComPontos::getPontos(Equipe* participante){
  if (!inEquipes(participante)) throw new invalid_argument("Equipe não pertence a tabela.");
  return this->pontos[getIndice(participante)];
}

void TabelaComPontos::imprimir(){
  for (int i = 0; i < quantidadeParticipantes; i++){
    //cout << getPosicao(participantes[i] << "o " << participantes[i]->getNome() << " (" << getPontos(participantes[i]) << " pontos) " << endl; Errado

  }
}
