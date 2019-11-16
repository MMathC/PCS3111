#ifndef TABELACOMORDEM_H
#define TABELACOMORDEM_H

#include "Tabela.h"

#include <iostream>
#include <stdexcept>

using namespace std;

class TabelaComOrdem: public Tabela{
    public:
        TabelaComOrdem(Equipe** participantes, int quantidade);
        virtual ~TabelaComOrdem();

        int getPosicao(Equipe* participante);
        void setResultado(Equipe** resultado);
        void imprimir();
        Equipe** getEquipesEmOrdem();
    private:
        Equipe* participantes;
        int quantidadeParticipantes;


};

#endif // TABELACOMORDEM_H
