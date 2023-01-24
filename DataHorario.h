#ifndef DATAHORARIO_H
#define DATAHORARIO_H

#include <iostream>
#include <string.h>

using namespace std;

class DataHorario
{
    public:
        DataHorario(int dia, int mes, int ano, int hora, int minuto, int segundo); //Construtor da classe
        ~DataHorario(); // Destrutor da classe
        int compara(DataHorario&);
        int getDia();
        void setDia(int dia);
        int getMes();
        void setMes(int mes);
        int getAno();
        void setAno(int ano);
        int getHora();
        void setHora(int hora);
        int getMinuto();
        void setMinuto(int minuto);
        int getSegundo();
        void setSegundo(int segundo);

        void imprime(bool padrao);
        void imprimePorExtenso();
        
    private:
        int dia, mes, ano, hora, segundo, minuto;
        bool padrao;
};

#endif