#include "CompeticaoSimples.h"

CompeticaoSimples::CompeticaoSimples(string nome, Equipe** equipes, int quantidade, Modalidade* m):Competicao(nome,equipes, quantidade){
    this->m = m;
}

CompeticaoSimples::~CompeticaoSimples(){
}

void CompeticaoSimples::imprimir(){
    m->imprimir();
    for(int i = 0; i< quantidadeEquipes; i++){
        cout<<equipes[i]<<endl;
    }
}

Modalidade* CompeticaoSimples::getModalidade(){
    return m;
}

Tabela* CompeticaoSimples::getTabela(){
    return m->getTabela();
}
