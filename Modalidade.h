#ifndef MODALIDADE_H
#define MODALIDADE_H

#include <iostream>
#include <stdexcept>
#include "Equipe.h"
#include "TabelaComOrdem.h"

using namespace std;

class Modalidade{
public:
    Modalidade(string nome, Equipe** participantes, int quantidade);
    virtual ~Modalidade();

    virtual string getNome();
    virtual Equipe** getEquipes();
    virtual int getQuantidadeDeEquipes();

    virtual bool temResultado();
    virtual TabelaComOrdem* getTabela();
    virtual void setResultado(Equipe** ordem);

    virtual void imprimir();

private:
    string nome;
    Equipe** participantes;
    int quantidadeEquipes;
    bool resultado;
    Modalidade** modalidades[];
    TabelaComOrdem* novaTab = new TabelaComOrdem(participantes,quantidadeEquipes);
};

#endif // MODALIDAE_H

