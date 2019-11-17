#ifndef COMPETICAOMULTIMODALIDADES_H
#define COMPETICAOMULTIMODALIDADES_H

#include <vector>
#include <list>
#include "Competicao.h"
#include "TabelaComPontos.h"

class CompeticaoMultimodalidades:public Competicao{
    public:
        CompeticaoMultimodalidades(string nome, Equipe** equipes, int quantidade);
        virtual ~CompeticaoMultimodalidades();

        void adicionar(Modalidade* m);
        list<Modalidade*>* getModalidades();

	Tabela* getTabela();

        static void setPontuacao(vector<int>* pontos);
        static int getPontoPorPosicao(int posicao);

        void imprimir();

    private:
	list<Modalidade*>* listaModalidades;
	static vector<int>* pontuacao;

};

#endif // COMPETICAOMULTIMODALIDADES_H
