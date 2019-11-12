#ifndef COMPETICAO_H
#define COMPETICAO_H

#include <iostream>
#include <stdexcept>
#include "Tabela.h"
#include "Modalidade.h"


using namespace std;

class Competicao {
 public:
  Competicao(string nome, Equipe** equipes, int quantidade, int maximoModalidades);
  ~Competicao();

  string getNome();
  Equipe** getEquipes();
  int getQuantidadeDeEquipes();
  Modalidade** getModalidades();
  int getQuantidadeDeModalidades();
  Tabela* getTabela();
  bool adicionar(Modalidade* m);
  void imprimir();

 private:
  string nome;
  Equipe** equipes;
  int quantidadeEquipes;
  int maximoModalidades;
  Tabela* tabela;
  Modalidade** modalidades;
  int quantidadeDeModalidades;
};

#endif

