#include "Competicao.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
    Equipe* poli = new Equipe("Poli");
    Equipe* fea = new Equipe("Fea");
    Equipe* esalq = new Equipe("Esalq");

    Equipe* participantes[3];
    participantes[0] = fea;
    participantes[1] = poli;
    participantes[2] = esalq;

    Modalidade* futcampo = new Modalidade("Futebol de Campo", participantes, 3);
    Modalidade* volei = new Modalidade("Volei", participantes, 3);
    Modalidade* basquete = new Modalidade("Basquete", participantes, 3);

    Equipe* ordem1[3];
    ordem1[1] = fea;
    ordem1[0] = poli;
    ordem1[2] = esalq;

    futcampo -> setResultado(ordem1);
    futcampo -> imprimir();

    //CompeticaoSimples* compSimples = new CompeticaoSimples("Tusca", participantes, 3, futcampo);
    //compSimples -> getTabela();
    //compSimples -> imprimir();
    return 0;
}
/*
int main(){

   Equipe* equipes[2];
    Equipe* minhaeq = new Equipe("Poli");
    Equipe* mina = new Equipe("Fea");
    equipes[0] = minhaeq;
    equipes[1] = mina;
    //Modalidade** m = new Modalidade*[1];
    equipes[0]->imprimir();
    equipes[1]->imprimir();
    //CompeticaoSimples("inter",equipes,2,m)->imprimir();

    string car, castCar;
    cout<<"Deseja carregar uma competicao (s/n)? ";
    cin>>car;
    castCar = car;

    string nomeArq, castnomeArq;//escolha1 e castEscolha1
    if (castCar == "s"){
        cout<<"Digite o nome do arquivo: ";
        cin>>nomeArq;
        castnomeArq = nomeArq;

        //Competicao->imprimir();
    }else if (castCar == "n"){
        int quant, castQuant;
        string nomeEq, castNomeEq, nomeComp, castNomeComp, escolha2, castEscolha2;
        cout<<"Informe a quantidade de equipes: ";
        cin>>quant;
        castQuant = quant;

        for(int x=0;x<castQuant;x++){
            cout<<"Informe o nome da equipe"<< x <<":";
            cin>>nomeEq;
            castNomeEq = nomeEq;
        }
        cout<<"Informe o nome da competicao: ";
        cin>>nomeComp;
        castNomeComp = nomeComp;

        cout<<"Competicao simples (s) ou multimodalidades (m)? ";
        cin>>escolha2;
        castEscolha2 = escolha2;

        string nomeMod, castNomeMod, result,castResult;
        if (castEscolha2 == "s"){
            cout<<"Informe o nome da modalidade: ";
            cin>>nomeMod;
            castNomeMod = nomeMod;

            cout<<"Tem resultado (s/n): ";
            cin>>result;
            castResult = result;

            int umAn, castUmAn;
            if (castResult == "s"){
                for(int x = 0; x<castQuant; x++){
                    cout<<"Informe a equipe "<< x <<"a colocada: ";
                    cin>>umAn;
                    castUmAn = umAn;
                }
            }
         //quantMod , castQuantMod
        }else if (castEscolha2 == "m"){
            int m, castm;
            string y;
            cout<<"Informe a quantidade de modalidades: ";
            cin>>m;
            castm = m;

            cout<<"Informe o nome da modalidade "<< y <<":";
            cin>>nomeMod;
            castNomeMod = nomeMod;

            cout<<"Tem resultado (s/n): ";
            cin>>result;
            castResult = result;

        }

    }

}
*/
