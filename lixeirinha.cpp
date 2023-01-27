#include "Pessoa.h"
#include "Aluno.h"

using namespace std;

Aluno::Aluno(string cpf, string nome, int ra, double n1, double n2, double n3):Pessoa(cpf, nome), ra(ra), n1(n1), n2(n2), n3(n3) {}

int Aluno::getRa()
{   return ra;   }

void Aluno::setRa(int ra)
{   this->ra = ra;   }

double Aluno::media(double n1, double n2, double n3)
{
    double MF = 0;
    MF = ((0.7 * n1) + (0.7 * n2) + (0.6 * n3))/2;
    //Se o retorno da função aprovado for verdadeiro
    if(this->aprovado())
    {
        //Imprime a nota da pessoa que já passou
        cout << "Aprovado com média: " << MF << endl;
        return MF;
    }
    //Caso não, ele vai ver se há chance de sac
    // else if(this->sac())
    // {
    //     //se houver possibilidade de sac ele retorna a nota que ele precisará tirar
    //     cout << "(SAC) a nota mínima aprovação: " << this->notaSAC() << endl;
    //     // return 0;
    // }
    // else 
    // {
    //     cout << "Reprovado com nota média: " <<  MF << endl;
    //     // return 0;
    // }
    return 0;
}

bool Aluno::aprovado()
{
    return this->media(n1, n2, n3) >= 6.0;
}

bool Aluno::sac()
{
    //se a média for maior que zero
    // if(this->media(n1, n2, n3) >= 0)
    // {
        if(this->media(n1, n2, n3) >= 5 && this->media(n1, n2, n3) < 6)
            // this->notaSAC();
            return 1;
        else  
            return 0;
    // }
    // else 
    //     return 0;
}

double Aluno::notaSAC()
{
    if(!this->sac())
        return 0;
    else 
        return 12 - this->media(n1, n2, n3);
}

void Aluno::imprime()
{
    
    Pessoa::imprime();
    cout << "RA: " << ra << endl;
    cout << "Média Final: " << this->media(n1, n2, n3) << endl;
    //"""FALTA IMPRIMIR A MÉDIA FINAL"""
}