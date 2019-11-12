#ifndef TABELACOMPONTOS_H
#define TABELACOMPONTOS_H

#include "Tabela.h"

#include <vector>
#include <stdexcept>

using namespace std;

class TabelaComPontos: public Tabela {
 public:
  TabelaComPontos(Equipe** participantes, int quantidade);
  virtual ~TabelaComPontos();

  int getPosicao(Equipe* participante);
  void imprimir();

  void pontuar(Equipe* participante, int pontos);
  int getPontos(Equipe* participante);
  Equipe** getEquipesEmOrdem();
 private:
  vector<int> pontos;
  bool inEquipes(Equipe* p);
  bool isResultadoAtualizado = false;
};

#endif // TABELACOMPONTOS_H
