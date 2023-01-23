#ifndef PESSOA_H
#define PESSOA_H

#include <string.h>
#include <iostream>
using namespace std;

class Pessoa
{
    public:
        Pessoa(string cpf, string nome);
        string getCPF();
        string getNome();
        void setCPF(string cpf);
        void setNome(string nome);
        virtual void imprime() const;
    private:
        string nome;
        string cpf;
};

#endif