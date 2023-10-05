#include "Aluno.hpp"
#include <iostream>
#include <string>
using namespace std;

Aluno::Aluno(string nome, string endereco, int matricula)
    : Pessoa(nome, endereco), matricula(matricula) {}
Aluno::Aluno(){}
void Aluno:: setMatricula(int matricula){
    this -> matricula = matricula;
}
int Aluno:: getMatricula(){
    return matricula;
}