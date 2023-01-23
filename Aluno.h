#ifndef ALUNO_H
#define ALUNO_H

#include <iostream>
#include <string.h>
#include "Pessoa.h"

using namespace std;

class Aluno : public Pessoa
{
    public: 
        Aluno(string cpf, string nome, int ra, double n1, double n2, double n3); //Construtor
        int getRa();
        void setRa(int ra);

        double media(double n1, double n2, double n3);
        bool aprovado();    
        bool sac();
        double notaSAC();
        void imprime();

    private:
        int ra;
        double n1, n2, n3;
};

#endif