#include "Disciplina.hpp"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Disciplina::Disciplina(string nome, int CH, Professor professor)
    : nome(nome), CH(CH), professor(professor) {}

Disciplina::Disciplina(){}

string Disciplina::getNome() {
    return nome;
}

void Disciplina::setNome(string nome) {
    this->nome = nome;
}

int Disciplina::getCH() {
    return CH;
}

void Disciplina::setCH(int CH) {
    this->CH = CH;
}

Professor Disciplina::getProfessor() {
    return professor;
}


void Disciplina::setProfessor(Professor professor) {
    this->professor = professor;
}


bool Disciplina::CadastrarAluno(Aluno aluno) 
{
    for (unsigned long int i = 0; i < lista_De_Alunos.size(); i++) 
    {
        if (lista_De_Alunos[i].getNome() == aluno.getNome() && lista_De_Alunos[i].getMatricula() == aluno.getMatricula()) 
        {
            return false; // Aluno já cadastrado na disciplina
        }
    }
    lista_De_Alunos.push_back(aluno);
    return true; // Aluno cadastrado com sucesso
}


// Imprime a lista de alunos da disciplina
bool Disciplina::Imprimir_Lista_De_Alunos() 
{
    // Verifica se a lista de alunos está vazia
    if (lista_De_Alunos.empty()) {
        cout << "\t\tNão há alunos cadastrados nesta disciplina." << endl;
        return false;
    }

    // Imprime a lista de alunos

    for (unsigned long int i = 0; i < lista_De_Alunos.size(); i++) 
    {
        cout << "\t--------------------------------" << endl;
        cout << "\t Nome: \t" << getAluno(i).getNome() << endl;
        cout << "\t Matrícula: \t" << getAluno(i).getMatricula() << endl;
        cout << "\t--------------------------------" << endl;
    }

    return true;
}
Aluno Disciplina::getAluno(unsigned long int i) {
    if (i >= lista_De_Alunos.size()) {
        throw std::runtime_error("Índice inválido");
    }
    return lista_De_Alunos[i];
}

vector<Aluno>& Disciplina::getListaDeAlunos() {
    return lista_De_Alunos;
}