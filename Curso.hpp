#ifndef CURSO_HPP
#define CURSO_HPP

#include "Aluno.hpp"
#include "Professor.hpp"
#include "Disciplina.hpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Curso {
public:
    Curso(string nome);
    Curso();

    string getNome();
    void setNome(string nome);

    bool cadastrarAluno(Aluno aluno);
    bool cadastrarProfessor(Professor professor);
    bool cadastrarDisciplina(Disciplina disciplina);
    void imprimirListaAlunos();
    void imprimirListaProfessores();
    void imprimirListaDisciplinas();

    void excluirAluno(string nome);
    void excluirProfessor(string nome);
    void excluirDisciplina(string nome);
    bool existeProfessor(string nome) ;
    bool existeAluno(string nome) ;
    bool existeDisciplina(string nome);
    Professor obterProfessor(string nome);
    Aluno obterAluno(string nome);
    bool cadastrarAlunoNaDisciplina(string nomeDisciplina, Aluno aluno);


private:
    string nome;
    vector<Aluno> listaAlunos;
    vector<Professor> listaProfessores;
    vector<Disciplina> listaDisciplinas;
};
// getAluno()[i]
#endif
