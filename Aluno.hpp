#ifndef ALUNO_HPP
#define ALUNO_HPP
#include "Pessoa.hpp"
#include <iostream>
#include <string>
using namespace std;
class Aluno: public Pessoa {
    public:
    void setMatricula(int matricula);
    int getMatricula();
    Aluno(string nome, string endereco, int matricula);
    Aluno();
    
    private:
    int matricula;
    
        
};
#endif

 
