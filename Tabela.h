#ifndef TABELA_H
#define TABELA_H

#include <stdexcept>
#include <iostream>
#include "Equipe.h"

using namespace std;

class Tabela {
public:
    Tabela(Equipe** participantes, int quantidade);
    virtual ~Tabela();

    virtual int getPosicao(Equipe* participante) = 0;
    virtual Equipe** getEquipesEmOrdem() = 0;
    virtual int getQuantidadeDeEquipes();
    virtual void imprimir() = 0;

protected:
    int quantidadeParticipantes;
    Equipe** participantes;
    int getIndice(Equipe* participante);
    Equipe** resultado;
};

#endif // TABELA_H



