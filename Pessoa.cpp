#include "Pessoa.hpp"
#include <iostream>
#include <string>

using namespace std;

Pessoa::Pessoa(string nome,string endereco):nome(nome),endereco(endereco){}

Pessoa::Pessoa(){}

void Pessoa:: setNome(string nome){
    this -> nome = nome;
}
string Pessoa:: getNome(){
    return nome;
}
void Pessoa:: setEndereco(string endereco){
    this -> endereco = endereco;
}
string Pessoa:: getEndereco(){
    return endereco;
}