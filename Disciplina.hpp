#ifndef DISCIPLINA_HPP
#define DISCIPLINA_HPP
#include <vector>
#include "Aluno.hpp"
#include "Professor.hpp" 
#include <iostream>
#include <string>
using namespace std;

class Disciplina {
public:
    Disciplina(string nome, int CH, Professor professor);

    Disciplina();

    string getNome();
    void setNome(string nome);
    
    int getCH();
    void setCH(int CH);

    Professor getProfessor();
    void setProfessor(Professor professor);
    
    bool CadastrarAluno(Aluno aluno);
    bool Imprimir_Lista_De_Alunos();
    

    // Retorna o aluno da posição [i]
    Aluno getAluno(unsigned long int i);
    
    vector<Aluno>& getListaDeAlunos();

private:
    string nome;
    int CH;
    Professor professor;
    vector<Aluno> lista_De_Alunos;
};

#endif
