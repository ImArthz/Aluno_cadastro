#include <iostream>
#include <string>
#include <list>
#include <limits> //biblioteca para lidar com erros de leitura de inteiro
#include "Curso.hpp"
#include "Aluno.hpp"
#include "Professor.hpp"
#include "Disciplina.hpp"
#include <cstdlib> // For the system function

using namespace std;

int main() {
    Curso curso(""); // Inicialize o curso como vazio
    Disciplina disciplina;
    string nomeCurso1,auxiliar;
    bool aux,auxop = false;
    cout<<"\t\t\t\t ------------------------------------------------------------------"<<endl;
    cout<<"\t\t\t\t  Bem vindo ao Criador de cursos "<<endl;
    cout<<"\t\t\t\t ------------------------------------------------------------------"<<endl;

    while (true) 
    {
        while(true)
        {
            if(!auxop)
            {
            aux = false;

            cout<<"\t\t\t\t ------------------------------------------------------------------"<<endl;
            cout<<"\t\t\t\t Por favor Digite o Nome Do curso que deseja criar "<<endl;
            cout<<"\t\t\t\t ------------------------------------------------------------------"<<endl;
            getline(cin,nomeCurso1);
            cout<<"Você Digitou :  "<<nomeCurso1<<endl;
            }
            else
            {
                break;
            }
            while(!aux)
            {
                cout<<"Deseja criar o curso de "<<nomeCurso1<<" \n(S/N)? "<<endl;
                getline(cin,auxiliar);
                if (auxiliar == "Sim" || auxiliar == "sim" || auxiliar == "S" || auxiliar == "s") 
                {
                    curso.setNome(nomeCurso1);
                    aux=true;
                    auxop=true;
                }
                else if (auxiliar == "Não" || auxiliar == "nao" || auxiliar == "N" || auxiliar == "n") 
                {
                    cout<<"Curso de "<<nomeCurso1<<" Não criado voltando ao inicio ..."<<endl;
                    aux=true;
                }
                else
                {
                    cout<<"Opção invalida"<<endl;
                }
            }
        }
        cout<<"-----------------------------------------------------------------------------"<<endl;
        cout <<"\t\t\tMenu de Opções:" << endl;
        cout<<"-----------------------------------------------------------------------------"<<endl;

        cout << "\t\t1. Github  "<< endl;
        cout << "\n\t\t2. Cadastrar Aluno" << endl;
        cout << "\n\t\t3. Cadastrar Professor" << endl;
        cout << "\n\t\t4. Cadastrar Disciplina" << endl;
        cout << "\n\t\t5. Excluir Aluno" << endl;
        cout << "\n\t\t6. Excluir Professor" << endl;
        cout << "\n\t\t7. Excluir Disciplina" << endl;
        cout << "\n\t\t8. Listar Alunos" << endl;
        cout << "\n\t\t9. Listar Professores" << endl;
        cout << "\n\t\t10. Listar Disciplinas" << endl;
        cout << "\n\t\t11. Cadastrar Aluno Na Disciplina "<<endl;
        cout << "\n\t\t12. Sair" << endl;
        cout<<"-----------------------------------------------------------------------------"<<endl;
        
        int opcao;
        while (true) {
            cout << "Escolha uma opção: "<<endl;
            cin >> opcao;
        
            if (cin.fail()) {
                cin.clear();  // Limpa o estado de erro
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta entrada inválida
                cout << "Entrada inválida. Digite um número inteiro." << endl;
            } else {
                // Entrada válida, podemos sair do loop
                break;
            }
}

        switch (opcao) {
            case 1:{
            std::string link = "https://github.com/ImArthz";
            
                
                    // Construct the command to open the URL in the default web browser
                    std::string command = "xdg-open " + link;

                    // Use the system function to execute the command
                    int result = system(command.c_str());

                    // Check the result of the system call
                    if (result == 0) {
                        std::cout << "Web browser opened successfully." << std::endl;
                    } else 
                    {
                        std::cerr << "Failed to open web browser." << std::endl;
                    }

                break;
            }

            case 2:
            {
                string nome,endereco;
                int matricula;
                if (curso.getNome().empty()) {//verifica se curso esta vazio 
                    cout << "Erro: Crie um curso primeiro." << endl;
                } else {
                
                cout << "Nome do Aluno: ";
                cin.ignore();
                getline(cin,nome);
                cout << "Endereço do Aluno: ";
                getline(cin,endereco);
                while (true) {
                            cout << "Matricula do Aluno "<<endl;
                            cin >> matricula;
                        
                            if (cin.fail()) {
                                cin.clear();  // Limpa o estado de erro
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Descarta entrada inválida
                                cout << "Entrada inválida. Digite um número inteiro." << endl;
                            } else {
                                // Entrada válida, podemos sair do loop
                                break;
                            }
                }                
                if(curso.cadastrarAluno(Aluno(nome, endereco, matricula))){
                    cout<<"Aluno : "<<nome<< " Cadastrado com sucesso"<<endl;
                }
                }
                break;
            }
        

            case 3:
            {
                string cursoProfessor,titulacao,nome,endereco;
                if (curso.getNome().empty()) {//verifica se curso esta vazio
                    cout << "Erro: Crie um curso primeiro." << endl;
                } else {
                    cout << "Nome do Professor: ";
                    cin.ignore();
                    getline(cin,nome);
                    cout << "Endereço do Professor: ";
                    getline(cin,endereco);
                    cout << "Titulação do Professor: ";
                    getline(cin,titulacao);
                    cout << "Curso do Professor: ";
                    getline(cin,cursoProfessor);
                    if(curso.cadastrarProfessor(Professor(nome, endereco, titulacao, cursoProfessor))){
                        cout<<"Professor : "<<nome<<" Cadastrado com sucesso"<<endl;
                    }
                    }
                break;
            }
            case 4:
            {
                int cargaHoraria;
                string nomeProfessor, nomeDisciplina, nome;
                
                if (curso.getNome().empty()) {
                    cout << "Erro: Crie um curso primeiro." << endl;
                } else {
                    cout << "Nome da Disciplina: ";
                    cin.ignore();
                    getline(cin, nomeDisciplina);
                    
                    while (true) {
                        cout << "Carga Horária da Disciplina: ";
                        cin >> cargaHoraria;
                        
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Entrada inválida. Digite um número inteiro." << endl;
                        } else {
                            break;
                        }
                    }
                    
                    cin.ignore(); // Consuma a nova linha deixada pelo cin >> cargaHoraria
                    cout << "Nome do Professor da Disciplina: ";
                    getline(cin, nomeProfessor);
            
                    // Verifique se o professor existe antes de cadastrar a disciplina
                    if (curso.existeProfessor(nomeProfessor)) {
                        // Obtenha o professor existente do curso
                        Professor professor = curso.obterProfessor(nomeProfessor);
                        
                        // Crie uma nova disciplina com a lista de alunos vazi
                        Disciplina novaDisciplina(nomeDisciplina, cargaHoraria, professor);
                        
                        // Cadastre a disciplina no curso
                        if (curso.cadastrarDisciplina(novaDisciplina)) {
                            cout << "Disciplina: " << nomeDisciplina << " cadastrada com sucesso" << endl;
                        }
                    } else {
                        cout << "Erro: Professor não encontrado." << endl;
                    }
                }
                break;
            }


            case 5: 
            {
                string nome;
                if (curso.getNome().empty()) {//verifica se curso esta vazio
                    cout << "Erro: Crie um curso primeiro." << endl;
                } 
                else {
                    cout << "Nome do Aluno a ser excluído: ";
                    cin.ignore();
                    getline(cin,nome);
                    curso.excluirAluno(nome);
                    }
                break;
            }

            case 6:
            {
                string nome;
                if (curso.getNome().empty()) {//verifica se curso esta vazio
                    cout << "Erro: Crie um curso primeiro." << endl;
                } 
                else {
                     cout << "Nome do Professor a ser excluído: ";
                    cin.ignore();
                    getline(cin,nome);
                    curso.excluirProfessor(nome);
                    }
                break;
            }

            case 7:
            {
                string nome;
                if (curso.getNome().empty()) {//verifica se curso esta vazio
                    cout << "Erro: Crie um curso primeiro." << endl;
                } 
                else {
                    cout << "Nome da Disciplina a ser excluída: ";
                    cin.ignore();
                    getline(cin,nome);
                    curso.excluirDisciplina(nome);
                    }
                break;
            }

            case 8:
            {
                if (curso.getNome().empty()) {//verifica se curso esta vazio
                    cout << "Erro: Crie um curso primeiro." << endl;
                } else {
                    curso.imprimirListaAlunos();
                }
                break;
            }

            case 9:
            {
                if (curso.getNome().empty()) {//verifica se curso esta vazio
                    cout << "Erro: Crie um curso primeiro." << endl;
                } else {
                    curso.imprimirListaProfessores();
                }
                break;
            }

            case 10:
            {
                if (curso.getNome().empty()) {//verifica se curso esta vazio
                    cout << "Erro: Crie um curso primeiro." << endl;
                } else {
                    curso.imprimirListaDisciplinas();
                }
                break;
            }
            case 11:
            {
                string nome,nomeDisciplina;
                // Cadastro de aluno em uma disciplina
                if (curso.getNome().empty()) {
                    cout << "Erro: crie um curso primeiro." << endl;
                } else {
                    cout << "Digite o nome do aluno que deseja cadastrar: "<<endl;
                    cin.ignore();
                    getline(cin, nome);
                    
                    if (curso.existeAluno(nome)) 
                    {
                        cout << "Digite o nome da disciplina em que deseja cadastrar o aluno " << nome << ": "<<endl;
                    string nomeDisciplina;
                    getline(cin, nomeDisciplina);
                    
                    // Verifique se a disciplina existe
                    if (curso.existeDisciplina(nomeDisciplina)) {
                        // Cadastre o aluno na disciplina
                        Aluno aluno = curso.obterAluno(nome);
                        try {
                            if (curso.cadastrarAlunoNaDisciplina(nomeDisciplina, aluno)) {
                                cout << "Aluno cadastrado com sucesso." << endl;
                            } else {
                                cout << "Erro: Aluno já cadastrado na disciplina." << endl;
                            }
                        } catch (const std::runtime_error& e) {
                            cout << "Erro ao cadastrar aluno: " << e.what() << endl;
                        }
                    } 
                    else 
                    {
                        cout << "Erro: Não existem disciplinas cadastradas com o nome " << nomeDisciplina << endl;
                    }
                    } 
                    else {
                        cout << "Erro: Não existem alunos cadastrados com o nome " << nome << endl;
                        }
                }
                break;
            }


            case 12:
                cout<<"Saindo do programa ... "<<endl;
                return 0;

            default:
                cout << "Opção inválida. Tente novamente." << endl;
                break;
        }
    }

    return 0;
}