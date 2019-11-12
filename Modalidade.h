#ifndef MODALIDADE_H
#define MODALIDADE_H

#include <iostream>
#include <stdexcept>
#include "Equipe.h"

using namespace std;

class Modalidade{
public:
    Modalidade(string nome, Equipe** participantes, int quantidade);
    virtual ~Modalidade();

    virtual string getNome();
    virtual Equipe** getEquipes();
    virtual int getQuantidadeDeEquipes();

    virtual bool temResultado();
    virtual TabelaComOrdem* getTabela(); // probelma aqui
    virtual void setResultado(Equipe** ordem);

    virtual void imprimir();

private:
    Equipe** participantes;
    int quantidadeEquipes;
    string nome;
    bool resultado;
    Modalidade** modalidades[];
};

#endif // MODALIDAE_H

