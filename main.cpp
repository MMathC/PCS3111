#include "Competicao.h"
#include "CompeticaoSimples.h"
#include "CompeticaoMultimodalidades.h"
#include <iostream>
#include <stdexcept>
#include <vector>
#include "PersistenciaDeCompeticao.h"

using namespace std;

/*
int main()
{
    Equipe* poli = new Equipe("Poli");
    Equipe* fea = new Equipe("Fea");
    Equipe* esalq = new Equipe("Esalq");

    Equipe* participantes[3];
    participantes[0] = fea;
    participantes[1] = poli;
    participantes[2] = esalq;
    poli->imprimir();
    fea->imprimir();
    esalq->imprimir();

    Modalidade* futcampo = new Modalidade("Futebol de Campo", participantes, 3);
    Modalidade* volei = new Modalidade("Volei", participantes, 3);
    Modalidade* basquete = new Modalidade("Basquete", participantes, 3);

    Equipe* ordem1[3];
    ordem1[1] = fea;
    ordem1[0] = poli;
    ordem1[2] = esalq;

    Equipe* ordem2[3];
    ordem2[0] = fea;
    ordem2[1] = poli;
    ordem2[2] = esalq;

    futcampo->setResultado(ordem1);
    volei->setResultado(ordem2);
    //basquete->setResultado(ordem1);

    futcampo->imprimir();
    volei->imprimir();
    //basquete->imprimir();


    CompeticaoSimples* compSimples = new CompeticaoSimples("Tusca", participantes, 3, futcampo);
    cout << compSimples->getTabela() << endl;

    compSimples->imprimir();


    CompeticaoMultimodalidades* multi = new CompeticaoMultimodalidades("TUSCA", participantes,3);

    multi->adicionar(futcampo);
    multi->adicionar(volei);
    multi->adicionar(basquete);

    vector<int>* tabelaPontos = new vector<int>({13, 10, 8, 7, 5, 4, 3, 2, 1});

    multi->setPontuacao(tabelaPontos);



    multi->imprimir();

    PersistenciaDeCompeticao* persistencia = new PersistenciaDeCompeticao();
    //persistencia->salvar("Multi.txt", multi);
    persistencia->salvar("Simples.txt", compSimples);





    return 0;
}
*/

int main(){

    string car, castCar;
    cout<<"Deseja carregar uma competicao (s/n)? ";
    cin>>car;
    castCar = car;


    string nomeArq, castnomeArq;//escolha1 e castEscolha1
    if (castCar == "s"){
        cout<<"\nDigite o nome do arquivo: ";
        cin>>nomeArq;
        castnomeArq = nomeArq;

        PersistenciaDeCompeticao* arquivo = new PersistenciaDeCompeticao();

        //arquivo->carregar(castnomeArq);


    }else if (castCar == "n"){

        int quant, castQuant;
        string nomeEq, castNomeEq, nomeComp, castNomeComp, SouM, castSimpOuMult;

        cout<<"Informe a quantidade de equipes: ";
        cin>>quant;
        castQuant = quant;

        Equipe* equipes[castQuant];
        for(int x = 0;x<castQuant;x++){
            cout<<"Informe o nome da equipe "<< x+1 <<": ";
            cin>>nomeEq;
            castNomeEq = nomeEq;

            Equipe* minha_equipe = new Equipe(castNomeEq);
            equipes[x] = minha_equipe;
            //cout<<equipes[x]<<endl;
        }
        cout<<"\nInforme o nome da competicao: ";
        cin>>nomeComp;
        castNomeComp = nomeComp;


        cout<<"Competicao simples (s) ou multimodalidades (m)? ";
        cin>>SouM;
        castSimpOuMult = SouM;


        string nomeMod, castNomeMod, result,castResult;
        if (castSimpOuMult == "s"){

            cout<<"\nInforme o nome da modalidade: ";
            cin>>nomeMod;
            castNomeMod = nomeMod;

            Modalidade* modali = new Modalidade(castNomeMod, equipes, castQuant);

            CompeticaoSimples* CompSimples = new CompeticaoSimples(castNomeComp, equipes, castQuant, modali);

            cout<<"Tem resultado (s/n): ";
            cin>>result;
            castResult = result;

            cout<<""<<endl;

            int umAn, castUmAn;
            if (castResult == "s"){
                for(int x = 0; x<castQuant; x++){
                    cout<<"Informe a equipe "<< x <<"a colocada: ";
                    cin>>umAn;
                    castUmAn = umAn;
                }
            }else if(castResult == "n"){

                string salvar, castSalvar;
                cout<<"Deseja salvar a competicao (s/n)? ";
                cin>>salvar;
                castSalvar = salvar;

                if(castSalvar == "s"){
                       string nomeArquivo, castnomeArquivo;

                    cout<<"Digite o nome do arquivo: "<<endl;
                    cin>>nomeArquivo;
                    castnomeArquivo = nomeArquivo;
                    CompSimples->imprimir();
                }else if(castSalvar == "n"){
                    CompSimples->imprimir();
                }

            }
         //quantMod , castQuantMod
        }else if (castSimpOuMult == "m"){
            int m, castm;
            string y;
            int PosEq, castPosEq;

            cout<<"Informe a quantidade de modalidades: ";
            cin>>m;
            castm = m;

            for(int y = 1, y<= castm, y++){
                cout<<"Informe o nome da modalidade "<< y <<":";
                cin>>nomeMod;
                castNomeMod = nomeMod;

                cout<<"Tem resultado (s/n): ";
                cin>>result;
                castResult = result;

                if(castResult == s){

                    Equipe** ordem = new Equipe(castNomeEq);
                    for(int i = 1; i <= castQuant,i++){
                        cout<<"Informe a equipe "<< i <<"a colocada: "<<endl;
                        cin>>PosEq;
                        castPosEq = PosEq -1;

                        ordem[i-1] = equipes[castPosEq];
                    }
                    TabelaComOrdem* tabOrd = new TabelaComOrdem(equipes, castQuant);
                    tabOrd->setResultado(ordem);
                }
                if(y > castm)break;
            }
        }
        cout<<"Deseja salvar a competicao (s/n)? ";
        cin>>

    }

}

