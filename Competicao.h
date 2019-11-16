#ifndef COMPETICAO_H
#define COMPETICAO_H

#include <iostream>
#include <stdexcept>
#include "Tabela.h"
#include "Modalidade.h"


using namespace std;

class Competicao{
 public:
    Competicao(string nome, Equipe** equipes, int quantidade);
    ~Competicao();

    string getNome();
    Equipe** getEquipes();
    int getQuantidadeDeEquipes();

    virtual Tabela* getTabela() = 0;
    virtual void imprimir() = 0;

 protected:
        string nome;
        Equipe** equipes;
        int quantidadeEquipes;
};

#endif

