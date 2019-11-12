#include <iostream>
#include "Competicao.h"
#include "Equipe.h"
#include "Modalidade.h"
#include "Tabela.h"

using namespace std;

int main(){

    string nomeComp,castComp;
    cout << "Informe o nome da competicao: ";
    cin >> nomeComp;
    castComp = nomeComp;

    int quantEq,castQuantEq;
    cout << "\nInforme a quantidade de equipes: ";
    cin >> quantEq;
    castQuantEq = quantEq;

    string castEq, nomeEq;
    Equipe* equipes[castQuantEq];
    for(int i = 1; i <= castQuantEq; i++ ){
        cout << "Informe o nome da equipe " << i << ": ";
        cin >> nomeEq;
        castEq = nomeEq;
        Equipe* minha_equipe = new Equipe(castEq);
        equipes[i-1] = minha_equipe;
    }

    int quantMod, numEq, castMod, castnumEq;
    cout << "\nInforme a quantidade de modalidades: ";
    cin >> quantMod;
    castMod = quantMod;

    Modalidade** modalidades = new Modalidade*[castMod];

    Competicao* comp = new Competicao(castComp,equipes,castQuantEq,castMod);

    string nomeMod,castNomeMod;
    for(int m = 1 ; m <= castMod; m++){
        if (m == 1){
            cout << "Informe o nome da modalidade "<< m <<": ";
            cin >> nomeMod;
            castNomeMod = nomeMod;
        }else{
            cout << "\nInforme o nome da modalidade "<< m <<": ";
            cin >> nomeMod;
            castNomeMod = nomeMod;
        }

	modalidades[m-1] = new Modalidade(castNomeMod,equipes,castQuantEq);

	Equipe** ordem = new Equipe*[castQuantEq];
        for(int n = 1; n <= castQuantEq; n++){
            cout << "Informe a equipe " << n << "a colocada: ";
            cin >> numEq;
            castnumEq = numEq - 1;
            ordem[n-1] = equipes[castnumEq];
        }
    cout<<""<<endl;
	modalidades[m-1]->setResultado(ordem);
	comp->adicionar(modalidades[m-1]);

    }
    comp->imprimir();
}


