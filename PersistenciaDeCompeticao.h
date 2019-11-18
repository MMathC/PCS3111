#ifndef PERSISTENCIADECOMPETICAO_H
#define PERSISTENCIADECOMPETICAO_H

#include "CompeticaoSimples.h"
#include "CompeticaoMultimodalidades.h"
#include <fstream>
#include <string>

using namespace std;


class PersistenciaDeCompeticao{
 public:
  PersistenciaDeCompeticao();
  ~PersistenciaDeCompeticao();

  Competicao* carregar(string arquivo);
  void salvar(string arquivo, Competicao* c);
 private:
  Equipe* findEquipe(string nomeEquipe, Equipe** equipes, int quantidade);

};

#endif
