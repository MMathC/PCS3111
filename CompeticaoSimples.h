#ifndef COMPETICAOSIMPLES_H
#define COMPETICAOSIMPLES_H

#include "Competicao.h"

class CompeticaoSimples:public Competicao{
    public:
        CompeticaoSimples(string nome, Equipe** equipes, int quantidade, Modalidade* m);
        virtual ~CompeticaoSimples();

        void imprimir();
        Modalidade* getModalidade();

    private:

};

#endif // COMPETICAOSIMPLES_H
