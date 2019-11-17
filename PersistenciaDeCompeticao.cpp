#include "PersistenciaDeCompeticao.h"


PersistenciaDeCompeticao::PersistenciaDeCompeticao(){
}

PersistenciaDeCompeticao::~PersistenciaDeCompeticao(){
}

void PersistenciaDeCompeticao::salvar(string arquivo, Competicao* c){
  ofstream p;
  p.open(arquivo);

  p << c->getQuantidadeDeEquipes();
  
  for (int i = 0; i < c->getQuantidadeDeEquipes(); i++){
    p << " " << c->getEquipes()[i]->getNome();
  }

  p << endl;
  p << c->getNome();
  p << endl;

  CompeticaoSimples* verificaTipo = dynamic_cast<CompeticaoSimples*>(c);
  bool isSimples = (verificaTipo != NULL);
  delete verificaTipo;

  if (isSimples) {

    
    
    p << "0";
    p << endl;

   
    
    //p << endl;
    /*
    p << c->getModalidade()->temResultado() << " "
      << c->getModalidade()->getQuantidadeDeEquipes();;
    
    
    if (c->getModalidade()->temResultado()) {
      for (int i = 0; i < c->getModalidade()->getQuantidadeDeEquipes(); i++)
	p << " " << c->getModalidade()->getTabela()->getEquipesEmOrdem()[i]->getNome();
    } else {
      for (int i = 0; i < c->getModalidade()->getQuantidadeDeEquipes(); i++)
	p << " " << c->getModalidade()->getEquipes()[i]->getNome();
    }
    */
    
  } else {

  }
  
  p << endl;

  p.close();
}
