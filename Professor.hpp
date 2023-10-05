#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP
#include "Pessoa.hpp"
#include <iostream>
#include <string>
using namespace std;
class Professor: public Pessoa {
    public:
    void setTitulacao(string titulacao);
    void setCurso(string curso);
    string getTitulacao();
    string getCurso();
    Professor(string nome, string endereco, string titulacao,string curso);
    Professor();
    
    private:
    string titulacao;
    string curso;
    
        
};
#endif

 
