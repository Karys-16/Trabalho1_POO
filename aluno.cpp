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
    // cout << "Média Final: " << MF << endl;
    return MF;
}

bool Aluno::aprovado()
{
    return this->media(n1, n2, n3) >= 6.0;
}

bool Aluno::sac()
{
    if(this->media(n1, n2, n3) >= 5 && this->media(n1, n2, n3) < 6)
        return 1;
    else  
        return 0;
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
    if(this->aprovado())
        cout << "Aprovado com média final: " << this->media(n1, n2, n3) << endl;
    else if(this->sac())
        cout << "(SAC) Nota mínima para aprovação :" << this->notaSAC() << endl;
    else    
        cout << "Reprovado com média final: " << this->media(n1, n2, n3) << endl;
}