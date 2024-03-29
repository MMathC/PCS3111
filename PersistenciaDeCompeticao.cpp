#include "PersistenciaDeCompeticao.h"
#include <list>


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
      p << endl;
      modalidade++;
    }    
  }
  
  p << endl;
  p << "\n";
  p.close();
  
}



Competicao* PersistenciaDeCompeticao::carregar(string arquivo){

  
  ifstream p;
  p.open(arquivo);

  
  
  if (p.fail()) throw new invalid_argument("arquivo não encontrado.");
  Competicao* competicao;
  int qntEquipes;
  Equipe** equipes;
  string nomeCompeticao;
  bool isMulti;

 
  
  p >> qntEquipes;
  equipes = new Equipe*[qntEquipes];


   
   for (int i = 0; i < qntEquipes; i++){ // erro de caminho     
    string tempNome;
    p >> tempNome;
    equipes[i] = new Equipe(tempNome);
    
  }

  

  
  p >> nomeCompeticao;

  p >> isMulti;

  

  if(isMulti) {

    competicao = new CompeticaoMultimodalidades(nomeCompeticao,
						equipes,
						qntEquipes);
    CompeticaoMultimodalidades* competicaoMulti =
      dynamic_cast<CompeticaoMultimodalidades*>(competicao);
    
    int qntModalidades;
    p >> qntModalidades;

    for (int nMod = 0; nMod < qntModalidades; nMod++) {
      //Modalidade* tempMod;
      
      string nomeModalidade;
      bool isResultado;
      int qntEquipesParticipantes;   

      p >> nomeModalidade;
      p >> isResultado;
      p >> qntEquipesParticipantes;

      

      //
    
      list<string>* nomeEquipesPartipantes = new list<string>();

    
      Equipe** equipesParticipantes = new Equipe*[qntEquipesParticipantes];

     

      
    
      for (int i = 0; i < qntEquipesParticipantes; i++){
	string nomeEquipe;
	p >> nomeEquipe;
	nomeEquipesPartipantes->push_back(nomeEquipe);
      }
    

    
      for (int i = 0; i < qntEquipesParticipantes; i++) {
	equipesParticipantes[i] = findEquipe(nomeEquipesPartipantes->front(), equipes, qntEquipes);
	nomeEquipesPartipantes->pop_front();
      }

    

    Modalidade* tempMod = new  Modalidade(nomeModalidade,
				equipesParticipantes,
				qntEquipes);

    
    if(isResultado) {
      tempMod->setResultado(equipesParticipantes);
    } 


    competicaoMulti->adicionar(tempMod);
   

    
      
    }

    //Competicao* cReturn = CompeticaoMulti;
    return competicaoMulti;
    
  } else {

    string nomeModalidade;
    bool isResultado;
    int qntEquipesParticipantes;   

    p >> nomeModalidade;
    p >> isResultado;
    p >> qntEquipesParticipantes;

    
    
    list<string>* nomeEquipesPartipantes = new list<string>();

    
    Equipe** equipesParticipantes = new Equipe*[qntEquipesParticipantes];

    
    for (int i = 0; i < qntEquipesParticipantes; i++){
      string nomeEquipe;
      p >> nomeEquipe;
      nomeEquipesPartipantes->push_back(nomeEquipe);
    }
    

    
    for (int i = 0; i < qntEquipesParticipantes; i++) {
      equipesParticipantes[i] = findEquipe(nomeEquipesPartipantes->front(), equipes, qntEquipes);
      nomeEquipesPartipantes->pop_front();
    }

    

    Modalidade* modalidade = new Modalidade(nomeModalidade, equipesParticipantes, qntEquipes);

    if(isResultado) {
      modalidade->setResultado(equipesParticipantes);
    } 
    
    competicao = new CompeticaoSimples(nomeCompeticao, equipes, qntEquipes, modalidade);
    
    
  }
  
  p.close();
  return competicao;
}

Equipe* PersistenciaDeCompeticao::findEquipe(string nomeEquipe, Equipe** equipes, int quantidade){
  for (int i = 0; i < quantidade; i++){
    if (equipes[i]->getNome() == nomeEquipe) return equipes[i];
  }

  return NULL;
}
