#include "Equipe.h"

Equipe::Equipe(string nome){
    this->nome = nome;
}

Equipe::~Equipe(){
    //delete &nome;
}

string Equipe::getNome(){
    return this->nome;
}

void Equipe::imprimir(){
    cout << "Equipe " << this->nome << endl;
}
