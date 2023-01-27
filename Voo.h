#ifndef VOO_H
#define VOO_H

#include <iostream>
#include <string.h>
#include "Pessoa.h"
#include "DataHorario.h"

using namespace std;

class Voo
{
    public:
        Voo(int num, DataHorario& data_voo); //Construtor da classe recebendo como argumentos o número do voo e um objeto de datahorario
        ~Voo(); // Destrutor da classe
        int proximoLivre();
        bool verifica(int assento);
        bool ocupa(int assento, Pessoa& passageiro);
        bool desocupa(int assento);
        int vagas();
        void imprime();
        int getNum();
        void setNum(int num);
        int getAssento();
        void setAssento(int assento);

    private: 
        int num, assento; //número do voo
        DataHorario& data_voo; // data do voo
        Pessoa* posi[100]; //Total de assentos disponíveis: 100. Alocação estática de posições do avião
};


#endif