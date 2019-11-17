#include "CompeticaoMultimodalidades.h"

CompeticaoMultimodalidades::CompeticaoMultimodalidades(string nome, Equipe** equipes, int quantidade):Competicao(nome,equipes, quantidade){
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
  TabelaComPontos* tempTabela = new TabelaComPontos(equipes, quantidadeEquipes);

  list<Modalidade*>::iterator mod  = listaModalidades->begin();

  while(mod != listaModalidades->end()){
    for (int eq = 0; eq < quantidadeEquipes; eq++){
      tempTabela->pontuar(equipes[eq], getPontoPorPosicao((*mod)->getTabela()->getPosicao(equipes[eq])));				 
    }
    mod++;
  }
  return tempTabela;  
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
  if (posicao > CompeticaoMultimodalidades::pontuacao->size()) return 0;
  return CompeticaoMultimodalidades::pontuacao->at(posicao - 1);
  
  }

void CompeticaoMultimodalidades::imprimir(){
  
}
