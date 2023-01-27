#include "Voo.h"

using namespace std;

//
Voo::Voo(int num, DataHorario& data_voo) : num(num), data_voo(data_voo)
{
    //definindo o espaço da memória que será utilizado para as posições do avião como sendo nulas
    memset(posi, 0, 100 * sizeof(Pessoa*));
    for(int i = 0; i < 100; i++)
    {
        posi[i] = NULL;
    }
}


//Assento para verificar qual é o próximo assento livre
int Voo::proximoLivre()
{
    for(int i = 0; i < 100; i++)
    {   
        //Se a posição for igual a vazia, então retorna a sua posição + 1 indicando o número do assento
        if(posi[i] == NULL) return (i + 1);
    }
    //visto que no for não foi encontrado nenhuma poltrona vazia, quer dizer que o voo já está cheio e o retorno será zero
    return 0;
}

//Verifica se o assento está livre ou não 
bool Voo::verifica(int assento)
{
    //Se o assento passado estiver com NULL, então retornará falso
    if(posi[assento - 1] == NULL)
    {
        // cout << "Assendo disponível" << endl;
        return false;  
    } 
    //caso não, quer dizer que o assento está ocupado
    // cout << "Assento Indisponível" << endl;
    return true;

}

//Vai tornar o assento ocupado
bool Voo::ocupa(int assento, Pessoa& passageiro)
{
    //Se assento estiver nulo
    if(!this->verifica(assento))
    {
        //Então o passageiro poderá ocupá-lo
        this->posi[assento - 1] = &passageiro;
        // cout << "Assento ocupado com sucesso!" << endl;
        return true;
    }
    //Consequentemente, caso não, retorna falso
    // cout << "Não foi possível ocupar este assento :(" << endl;
    return false;

}

bool Voo::desocupa(int assento)
{
    //Chama a função para verificar se realmente tem alguém ocupando
    //Desocupa
    if(this->verifica(assento)) {
        posi[assento - 1] = NULL;   //se ta ocupado, desocupa
        return true;
    }
    else
    {
        // cout << "Erro ao remover passageiro" << endl;
        return 0;
    }
}

//Método para mostrar quantas vagas há 
int Voo::vagas()
{
    int counter = 0;
    for(int i = 0; i < 100; i++)
    {
        //verifica posição a posição quais estão livres
        if(this->posi[i] == NULL) counter++;
    }
    return counter;
}

//Método sem retorno apenas para a escrita das informações necessárias desejadas
void Voo::imprime()
{
    cout << "Informações sobre o voo " << this->num  << endl;
    cout << "Partirá ";
    data_voo.imprimePorExtenso();
    cout << endl;
    cout << "Possui " << this->vagas() << " assentos livres" << endl;
    
    // cout << "================== Passageiros ==================" << endl;
    for(int i = 0; i < 100; i++)
    {
        if(this->posi[i] != NULL)
        {
            cout << "Assento " << (i+1) << endl;
            this->posi[i]->imprime();
        }
    }
}


//getters and setters
int Voo::getAssento()
{   return this->assento;   }

void Voo::setAssento(int assento)
{   this->assento = assento;    }

int Voo::getNum()
{   return this->num;   }

void Voo::setNum(int num)
{   this->num = num; }


//Destrutor da classe
Voo::~Voo(){}
