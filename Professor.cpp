#include "Professor.hpp"
#include <iostream>
#include <string>
using namespace std;

Professor::Professor(string nome, string endereco, string titulacao,string curso)
    : Pessoa(nome, endereco), titulacao(titulacao),curso(curso) {}
Professor::Professor(){}
void Professor:: setTitulacao(string titulacao){
    this -> titulacao = titulacao;
}
string Professor:: getTitulacao(){
    return titulacao;
}
void Professor:: setCurso(string curso){
    this -> curso = curso;
}
string Professor:: getCurso(){
    return curso;
}