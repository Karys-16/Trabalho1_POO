#include "Pessoa.h"

using namespace std;

Pessoa::Pessoa(string cpf, string nome) : cpf(cpf), nome(nome) {}

string Pessoa::getCPF()
{   return this->cpf; }

void Pessoa::setCPF(string cpf)
{   this->cpf = cpf;    }

string Pessoa::getNome()
{   return this->nome;    }

void Pessoa::setNome(string nome)
{   this->nome = nome;  }

void Pessoa::imprime() const
{
    cout << "CPF: " << cpf << endl;
    cout << "Nome: " << nome << endl;
}
