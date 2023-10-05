#include "Curso.hpp"
#include <iostream>
#include <string>
using namespace std;


Curso::Curso(string nome) : nome(nome) {}
Curso::Curso(){}

string Curso::getNome() {
    return nome;
}

void Curso::setNome(string nome) {
    this->nome = nome;
}

bool Curso::cadastrarAluno(Aluno aluno) {
    listaAlunos.push_back(aluno);
    // Verifique se o aluno foi adicionado com sucesso
    for (Aluno a : listaAlunos) {
        if (a.getMatricula() == aluno.getMatricula()) 
        {
            return true; // Aluno adicionado com sucesso
        }
    }
    // Se não foi possível adicionar o aluno, lance uma exceção ou retorne falso
    throw std::runtime_error("Erro ao cadastrar aluno");
}

bool Curso::cadastrarProfessor(Professor professor) {
    listaProfessores.push_back(professor);
    // Verifique se o professor foi adicionado com sucesso
    for (Professor p : listaProfessores) {
        if (p.getNome() == professor.getNome()) {
            return true; // Professor adicionado com sucesso
        }
    }
    // Se não foi possível adicionar o professor, lance uma exceção ou retorne falso
    throw std::runtime_error("Erro ao cadastrar professor");
}

bool Curso::cadastrarDisciplina(Disciplina disciplina) {
    listaDisciplinas.push_back(disciplina);
    // Verifique se a disciplina foi adicionada com sucesso
    for (Disciplina d : listaDisciplinas) {
        if (d.getNome() == disciplina.getNome()) {
            return true; // Disciplina adicionada com sucesso
        }
    }
    // Se não foi possível adicionar a disciplina, lance uma exceção ou retorne falso
    throw std::runtime_error("Erro ao cadastrar disciplina");
}




void Curso::imprimirListaAlunos() {
    cout<<"\t\t---------------------------------------------------------"<<endl;
    cout << "\t\tLista de Alunos do Curso " << endl;
    cout<<"\t\t---------------------------------------------------------"<<endl;
    cout<<""<<endl;
    cout<<"\t\t"<<nome<<endl;
    cout<<""<<endl;
    cout<<"\t\t---------------------------------------------------------"<<endl;
    for (Aluno aluno : listaAlunos) {
        cout<<"\t -------------------------------------"<<endl;
        cout << "\t  Nome: \t" << aluno.getNome() <<endl;
        cout<<"\t -------------------------------------"<<endl;
        cout<<"\t Matrícula: \t" << aluno.getMatricula() << endl;
    }
}

void Curso::imprimirListaProfessores() {
    cout<<"\t\t---------------------------------------------------------"<<endl;
    cout << "\t\tLista de Professores do Curso " << endl;
    cout<<"\t\t---------------------------------------------------------"<<endl;
    cout<<""<<endl;
    cout<<"\t\t"<<nome<<endl;
    cout<<""<<endl;
    cout<<"\t\t---------------------------------------------------------"<<endl;
    for (Professor professor : listaProfessores) {
        cout<<"\t -------------------------------------"<<endl;
        cout <<"\t  Nome: \t" << professor.getNome() <<endl;
        cout<<"\t -------------------------------------"<<endl;
        cout<<"\t Titulação: \t " << professor.getTitulacao() <<endl;
        cout<<"\t Curso: " << professor.getCurso() << endl;
        cout<<"\t -------------------------------------"<<endl;

    }
}

void Curso::imprimirListaDisciplinas() {
    cout<<"\t\t\t---------------------------------------------------------"<<endl;
    cout << "\t\t\tLista de Disciplinas do Curso "<<endl;
    cout<<"\t\t\t---------------------------------------------------------"<<endl;
    cout<<""<<endl;
    cout << "\t\t\t" << nome << endl;
    cout<<""<<endl;
    cout<<"---------------------------------------------------------"<<endl;

    for (Disciplina disciplina : listaDisciplinas) {
        cout<<"\t\t -------------------------------------"<<endl;
        cout <<"\t\t  Nome: \t" << disciplina.getNome()<<endl;
        cout<<"\t\t -------------------------------------"<<endl;
        cout << "\t\t CH : \t" << disciplina.getCH() <<"Horas"<<endl;
        cout << "\t\t Professor: \t" << disciplina.getProfessor().getNome() << endl;
        cout<<"\t-------------------------------------------------------"<<endl;
        cout<<"\t Lista De Alunos cadastrados na disciplina "<<disciplina.getNome()<<endl;
        cout<<"\t-------------------------------------------------------"<<endl;

        if(disciplina.Imprimir_Lista_De_Alunos()){

        }
        else{
            cout<<"\tErro ao imprimir "<<endl;
        }
    }
}




void Curso::excluirAluno(string nome) {
    while (true) {
        string op;
        cout << "Tem certeza disso (S/N)? "<<endl;
        cout<<" Ao digitar sim o aluno "<<nome<<" sera permanentemente excluido "<<endl;
        //cin.ignore(); não é nescessario pois é tratado se nao for s/n
        getline(cin, op);
        if (op == "Sim" || op == "sim" || op == "S" || op == "s") {
            bool encontrado = false;
            for (auto it = listaAlunos.begin(); it != listaAlunos.end(); ++it) {
                if (it->getNome() == nome) {
                    it = listaAlunos.erase(it);
                    encontrado = true;
                    cout << "Aluno apagado com sucesso" << endl;
                    return; // Sai da função depois de excluir o Aluno
                }
            }
            if (!encontrado) {
                cout << "O aluno: " << nome << " não foi encontrado" << endl;
            }
            break; // Saia do loop enquanto após a exclusão bem-sucedida ou não
        } else if (op == "Não" || op == "nao" || op == "N" || op == "n") {
            cout << "Voltando ao menu" << endl;
            return; // Sai da função se o usuário decide não excluir o Aluno
        } else {
            cout << "Opção inválida. Por favor, digite 'Sim' ou 'Não'." << endl;
        }
    }
}


void Curso::excluirProfessor(string nome) {
    while(true)
    {
        string op;
        cout << "Tem certeza disso ?  (S/N)?" << endl;
        cout <<" Ao digitar sim o professor "<<nome<< " sera permanentemente excluido"<<endl;
        //cin.ignore(); não é nescessario pois é tratado se nao for s/n
        getline(cin, op);
        if (op == "Sim" || op == "sim" || op == "S" || op == "s") {
            bool encontrado = false;
            for (auto it = listaProfessores.begin(); it != listaProfessores.end(); ++it) {
                if (it->getNome() == nome) {
                    it = listaProfessores.erase(it);
                    encontrado = true;
                    cout << "Professor apagado com sucesso" << endl;
                    return; //  Sai da função depois de excluir o professor
                }
            }
            if (!encontrado) {
                cout << "O professor: " << nome << " não foi encontrado" << endl;
            }
        }
        else if (op == "Não" || op == "nao" || op == "N" || op == "n") {
            cout << "Voltando ao menu" << endl;
            return; // Sai da função se o usuário decide não excluir o Professor;
        }
    
        else 
        {
            cout << "Opção inválida. Por favor, digite 'Sim' ou 'Não'." << endl;
        }
    }
    
}


void Curso::excluirDisciplina(string nome) {
    while (true) {
        string op;
        cout << "Tem certeza disso (S/N)?" << endl;
        //cin.ignore(); não é nescessario pois é tratado se nao for s/n
        getline(cin, op);
        if (op == "Sim" || op == "sim" || op == "S" || op == "s") {
            bool encontrado = false;
            for (auto it = listaDisciplinas.begin(); it != listaDisciplinas.end(); ++it) {
                if (it->getNome() == nome) {
                    it = listaDisciplinas.erase(it);
                    encontrado = true;
                    cout << "Disciplina apagada com sucesso" << endl;
                    return;  // Sai da função depois de excluir a disciplina
                }
            }
            if (!encontrado) {
                cout << "A disciplina: " << nome << " não foi encontrada" << endl;
                return;  // Sai da função se a disciplina não foi encontrada
            }
        } else if (op == "Nao" || op == "nao" || op == "N" || op == "n") {
            cout << "Voltando ao menu" << endl;
            return;  // Sai da função se o usuário decide não excluir a disciplina
        } else {
            cout << "Opção inválida. Tente novamente (S/N): ";
        }
    }
}

bool Curso::existeProfessor(string nome)  {
    for (Professor professor : listaProfessores) {
        if (professor.getNome() == nome) {
            return true;
        }
    }
    return false;
}
bool Curso::existeAluno(string nome)  {
    for (Aluno aluno : listaAlunos) {
        if (aluno.getNome() == nome) {
            return true;
        }
    }
    return false;
}
bool Curso::existeDisciplina(string nome){
    for(Disciplina disciplina : listaDisciplinas){
        if(disciplina.getNome()== nome){
            return true;
        }
    }
    return false;
}
Professor Curso::obterProfessor(string nome) {
    for (Professor professor : listaProfessores) {
        if (professor.getNome() == nome) {
            return professor;
        }
    }
    // Professor não encontrado, lançar uma exceção
    throw std::runtime_error("Professor não encontrado");
}
Aluno Curso::obterAluno(string nome){
    for (Aluno aluno : listaAlunos){
        if(aluno.getNome()==nome){
            return aluno;
        }
    }
    // Aluno não encontrado, lançar uma exceção
    throw std::runtime_error("Aluno não encontrado");
}
bool Curso::cadastrarAlunoNaDisciplina(string nomeDisciplina, Aluno aluno) {
    for (Disciplina& disciplina : listaDisciplinas) {
        if (disciplina.getNome() == nomeDisciplina) {
            // Verifique se o aluno já está cadastrado na disciplina
            vector<Aluno>& listaAlunos = disciplina.getListaDeAlunos();
            for (Aluno& a : listaAlunos) {
                if (a.getNome() == aluno.getNome() && a.getMatricula() == aluno.getMatricula()) {
                    return false; // Aluno já cadastrado na disciplina
                }
            }
            
            // Adicione o aluno à disciplina
            disciplina.CadastrarAluno(aluno);
            return true; // Aluno cadastrado com sucesso na disciplina
        }
    }
    return false; // Disciplina não encontrada
}