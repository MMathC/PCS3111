#include "CompeticaoSimples.h"

CompeticaoSimples::CompeticaoSimples(string nome, Equipe** equipes, int quantidade, Modalidade* m):Competicao(nome,equipes, quantidade){
    this-> m = m;
}


CompeticaoSimples::~CompeticaoSimples(){
}


void CompeticaoSimples::imprimir(){

}

Modalidade* CompeticaoSimples::getModalidade(){

}
