#include "CompeticaoMultimodalidades.h"

CompeticaoMultimodalidades::CompeticaoMultimodalidades(string nome, Equipe** equipes, int quantidade):Competicao(nome,equipes, quantidade){
  tabela = new TabelaComPontos(equipes, quantidade);
  listaModalidades = new list<Modalidade*>();
  
}

vector<int>* CompeticaoMultimodalidades::pontuacao = new vector<int>();
  
CompeticaoMultimodalidades::~CompeticaoMultimodalidades(){
}

void CompeticaoMultimodalidades::adicionar(Modalidade* m){
  listaModalidades->push_back(m);
}

list<Modalidade*>* CompeticaoMultimodalidades::getModalidades(){
  return listaModalidades;
}

Tabela* CompeticaoMultimodalidades::getTabela(){
  return tabela;
}

void CompeticaoMultimodalidades::setPontuacao(vector<int>* pontos){
  if(pontos->size() < 3) {
    throw new invalid_argument("");
  }

  vector<int>::iterator j = pontos->end();
  while(j != pontos->begin()){
    CompeticaoMultimodalidades::pontuacao->pop_back();
    j--;
  }
  
  vector<int>::iterator i = pontos->begin();
  while(i != pontos->end()) {
    CompeticaoMultimodalidades::pontuacao->push_back(*i);
    i++;
  }
  
}


int CompeticaoMultimodalidades::getPontoPorPosicao(int posicao){
  return CompeticaoMultimodalidades::pontuacao->at(posicao - 1);
  
  }

void CompeticaoMultimodalidades::imprimir(){

}
