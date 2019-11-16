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

    //Modalidade** getModalidades();
    //int getQuantidadeDeModalidades();

    virtual Tabela* getTabela() = 0;
    //void adicionar(Modalidade* m); tabelaMultimodalidade
    virtual void imprimir() = 0;
    protected:
        string nome;
        Equipe** equipes;
        int quantidadeEquipes;

        //Tabela* tabela;
        //Modalidade** modalidades;
        //int quantidadeDeModalidades;
};

#endif

