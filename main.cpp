#include "Tabela.h"
#include <iostream>
#include <stdexcept>

using namespace std;

int main(){
    string car, castCar;
    cout<<"Deseja carregar uma competicao (s/n)? ";
    cin>>car;
    castCar = car;

    string nomeArq, castnomeArq;//escolha1 e castEscolha1
    if castCar == "s"{
        cout<<"Digite o nome do arquivo: ";
        cin>>nomeArq;
        castnomeArq = nomeArq;

        Competicao->imprimir();
    }
    int quant, castQuant;
    string nomeEq, castNomeEq, nomeComp, castNomeComp, escolha2, castEscolha2;
    else if castCar == "n"{
        count<<"Informe a quantidade de equipes: ";
        cin>>quant;
        castQuant = quant;

        for(int x=0,i<castQuant,x++){
            cout>>"Informe o nome da equipe"<< x <<":";
            cin>>nomeEq;
            castNomeEq = nomeEq;
        }
        count<<"Informe o nome da competicao: ";
        cin>>nomeComp;
        castNomeComp = nomeComp;

        cout>>"Competicao simples (s) ou multimodalidades (m)? ";
        cin>>escolha2;
        castEscolha2 = escolha2;

        string nomeMod, castNomeMod, result,castResult;
        if castEscolha2 == "s"{
            cout<<"Informe o nome da modalidade: ";
            cin>>nomeMod;
            castNomeMod = nomeMod;

            cout<<"Tem resultado (s/n): ";
            cin>>result;
            castResult = result;

            int umAn, castUmAn;
            if castResult == "s"{
                for(int x = 0, x<castQuant, x++){
                    cout<<"Informe a equipe "<< x <<"a colocada: ";
                    cin>>umAn;
                    castUmAn = umAn;
                }
            }

        int m, castm; //quantMod , castQuantMod
        }else if castEscolha2 == "m"{
            cout<<"Informe a quantidade de modalidades: ";
            cin>>m>>endl;
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
