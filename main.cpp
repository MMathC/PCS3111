#include <iostream>
#include <stdexcept>
#include <vector>
#include "PersistenciaDeCompeticao.h"
#include <typeinfo>


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
}*/


int main(){

    string car, castCar;
    string salvar, castSalvar;
    string nomeArquivo, castnomeArquivo;
    int quant, castQuant;
    string nomeEq, castNomeEq, nomeComp, castNomeComp, SouM, castSimpOuMult;
    int m, castm, PosEq, castPosEq;
    string y;

    cout<<"Deseja carregar uma competicao (s/n)? ";
    cin>>car;
    castCar = car;


    string nomeArq, castnomeArq;//escolha1 e castEscolha1
    if (castCar == "s"){
        cout<<"\nDigite o nome do arquivo: ";
        cin>>nomeArq;
        castnomeArq = nomeArq;

        PersistenciaDeCompeticao* arquivo = new PersistenciaDeCompeticao();

        Competicao* comp = arquivo->carregar(nomeArq);

        CompeticaoSimples* compSimples = dynamic_cast<CompeticaoSimples*>(comp);

        bool isSimples = (compSimples != NULL);

        if (isSimples) {
            compSimples->imprimir();
        }else {
            CompeticaoMultimodalidades* compMulti = dynamic_cast<CompeticaoMultimodalidades*>(comp);
            compMulti->imprimir();//ele n�o acha o tempTabela (tabela com pontos criada no
        }

    }else if (castCar == "n"){

        cout<<"\nInforme a quantidade de equipes: ";
        cin>>quant;
        castQuant = quant;

        Equipe** equipes = new Equipe*[castQuant];
        for(int x = 0;x<castQuant;x++){
            cout<<"Informe o nome da equipe "<< x+1 <<": ";
            cin>>nomeEq;
            castNomeEq = nomeEq;

            equipes[x] = new Equipe(castNomeEq);
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

            cout<<"Tem resultado (s/n): ";
            cin>>result;
            castResult = result;

            cout<<""<<endl;

            int umAn, castUmAn;
            if (castResult == "s"){
                Equipe** ordem = new Equipe*[castQuant];
                for(int x = 0; x<castQuant; x++){
                    cout<<"Informe a equipe "<< x+1 <<"a colocada: ";
                    cin>>umAn;
                    castUmAn = umAn;

                    ordem[x] = equipes[castUmAn-1];
                    cout<<ordem[x]->getNome()<<endl;
                }

                Modalidade* NovaModalidade = new Modalidade(castNomeMod, ordem, castQuant);

                CompeticaoSimples* CompSimples = new CompeticaoSimples(castNomeComp, ordem, castQuant, NovaModalidade);// arrumar o vetor de equipes para o novo ordenado no for de cima


                cout<<"Deseja salvar a competicao (s/n)? ";
                cin>>salvar;
                castSalvar = salvar;

                if(castSalvar == "s"){
                    cout<<"Digite o nome do arquivo: ";
                    cin>>nomeArquivo;
                    castnomeArquivo = nomeArquivo;

                    PersistenciaDeCompeticao* save = new PersistenciaDeCompeticao();
                    save->salvar(castnomeArquivo,CompSimples);

                    cout<<""<<endl;
                    CompSimples->imprimir();

                }else if(castSalvar == "n"){

                cout<<""<<endl;
                CompSimples->imprimir();
                }
            }else if(castResult == "n"){

                Modalidade* NovaModalidade = new Modalidade(castNomeMod, equipes, castQuant);

                CompeticaoSimples* CompSimples = new CompeticaoSimples(castNomeComp, equipes, castQuant, NovaModalidade);

                cout<<"Deseja salvar a competicao (s/n)? ";
                cin>>salvar;
                castSalvar = salvar;

                if(castSalvar == "s"){
                    cout<<"Digite o nome do arquivo: ";
                    cin>>nomeArquivo;
                    castnomeArquivo = nomeArquivo;

                    PersistenciaDeCompeticao* save = new PersistenciaDeCompeticao();
                    save->salvar(castnomeArquivo,CompSimples);

                    cout<<""<<endl;
                    CompSimples->imprimir();

                }else if(castSalvar == "n"){
                    cout<<""<<endl;
                    CompSimples->imprimir();
                }

            }
        }else if (castSimpOuMult == "m"){


            cout<<"\nInforme a quantidade de modalidades: ";
            cin>>m;
            castm = m;

            CompeticaoMultimodalidades* compMult = new CompeticaoMultimodalidades(castNomeComp,equipes,castQuant);

            for(int y = 0; y < castm; y++){

                Equipe** ordem = new Equipe*[castQuant];

                if(y == 0){
                    cout<<"Informe o nome da modalidade "<< y+1 <<": ";
                    cin>>nomeMod;
                    castNomeMod = nomeMod;

                    cout<<"Tem resultado (s/n): ";
                    cin>>result;
                    castResult = result;

                    if(castResult == "s"){


                        for(int i = 0; i < castQuant;i++){
                            cout<<"Informe a equipe "<< i+1 <<"a colocada: ";
                            cin>>PosEq;
                            castPosEq = PosEq ;

                            ordem[i] = equipes[castPosEq-1];
                        }
                        Modalidade* novaMod = new Modalidade(castNomeMod, ordem,castQuant);
                        compMult->adicionar(novaMod);

                    }
                    if(y+1 > castm)break;
                }else{
                    cout<<"\nInforme o nome da modalidade "<< y+1 <<": ";
                    cin>>nomeMod;
                    castNomeMod = nomeMod;

                    cout<<"Tem resultado (s/n): ";
                    cin>>result;
                    castResult = result;

                    if(castResult == "s"){
                        for(int i = 0; i < castQuant;i++){
                            cout<<"Informe a equipe "<< i+1 <<"a colocada: ";
                            cin>>PosEq;
                            castPosEq = PosEq ;

                            ordem[i] = equipes[castPosEq-1];
                        }
                        Modalidade* novaMod = new Modalidade(castNomeMod, ordem,castQuant);
                        compMult->adicionar(novaMod);

                    }
                }if(y+1 > castm)break;
            }



            cout<<"\nDeseja salvar a competicao (s/n)? ";
            cin>>salvar;
            castSalvar = salvar;

            if(castSalvar == "s"){
                cout<<"Digite o nome do arquivo: ";
                cin>>nomeArquivo;
                castnomeArquivo = nomeArquivo;

                PersistenciaDeCompeticao* save = new PersistenciaDeCompeticao();

                save->salvar(castnomeArquivo,compMult);

                cout<<""<<endl;
                compMult->imprimir();
            }else if (castSalvar == "n"){
                cout<<""<<endl;
                compMult->imprimir();
            }
        }
    }
return 0;
}

