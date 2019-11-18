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
       
  
  CompeticaoSimples* compVerificacao = dynamic_cast<CompeticaoSimples*>(c);
       
  bool isSimples = (compVerificacao != NULL);
  
    
    
  if (isSimples) {
    CompeticaoSimples* compSimples = dynamic_cast<CompeticaoSimples*>(c);

    p << "0";
    p << endl;

    p << compSimples->getModalidade()->getNome();
    p << endl;

    p << compSimples->getModalidade()->temResultado();
    p << " ";
    p << compSimples->getQuantidadeDeEquipes();

    Equipe** ordemS;
    
    if(compSimples->getModalidade()->temResultado()){
      ordemS = compSimples->getModalidade()->getTabela()->getEquipesEmOrdem();
    } else {
      ordemS = compSimples->getModalidade()->getEquipes();
    }
    

    for (int i = 0; i < c->getQuantidadeDeEquipes(); i++){
      p << " ";
      p << ordemS[i]->getNome();
    }
    
  } else {

    CompeticaoMultimodalidades* compMulti = dynamic_cast<CompeticaoMultimodalidades*>(c);

    p << "1";
    p << endl;
    p << compMulti->getModalidades()->size();
    p << endl;

    list<Modalidade*>::iterator modalidade = compMulti->getModalidades()->begin();

    while(modalidade != compMulti->getModalidades()->end()){
      p << (*modalidade)->getNome();
      p << endl;
      
      
      p << (*modalidade)->temResultado();
      p << " ";
      p << (*modalidade)->getQuantidadeDeEquipes();

      Equipe** ordemS;
    
      if((*modalidade)->temResultado()){
        ordemS = (*modalidade)->getTabela()->getEquipesEmOrdem();
      } else {
        ordemS = (*modalidade)->getEquipes();
      }
      
      for (int i = 0; i < c->getQuantidadeDeEquipes(); i++){
	p << " ";
	p << ordemS[i]->getNome();
      }
      cout << (*modalidade)->getNome() << endl;
      p << endl;
      modalidade++;
    }    
  }
  
  p << endl;
  p.close();
  
}
