#include "DataHorario.h" //Inclusão do arquivo com os headers de métodos da classe DataHorario

using namespace std;

/*Construtor da classe*/
DataHorario::DataHorario(int dia, int mes, int ano, int hora, int minuto, int segundo) : dia(dia), mes(mes), ano(ano), hora(hora), minuto(minuto), segundo(segundo)
{
    //verificando se o ano é bissexto ou não 
    bool bisex;
    //Variável booleana para casos em que algum elemento é falso
    bool invalida = false;

    bisex = (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0));

    //Vê valores possíveis para cada mês do ano
    if(dia > 0){
    switch(mes)
    {
        case 01: 
            if(dia > 31) invalida = true;
        break;
        case 2: 
            //caso o ano não seja bissexto e tiver mais dias que 28 está inválida
            if(!bisex && dia > 28) invalida = true;
            //caso o ano seja bissexto e fevereiro tenha mais de 29 dias tambéms será inválida
            else if(bisex && dia > 29) invalida = true;
        break;
        case 3: 
            if(dia > 31)invalida = true;
        break;
        case 4: 
            if(dia > 30)invalida = true;
        break;
        case 5: 
            if(dia > 31)invalida = true;
        break;
        case 6: 
            if(dia > 30)invalida = true;
        break;
        case 7: 
            if(dia > 31)invalida = true;
        break;
        case 8: 
            if(dia > 31)invalida = true;
        break;
        case 9: 
            if(dia > 30)invalida = true;
        break;
        case 10: 
            if(dia > 31)invalida = true;
        break;
        case 11: 
            if(dia > 30)invalida = true;
        break;
        case 12: 
            if(dia > 31)invalida = true;
        break;
        //se o usuário inserir qualquer data que não seja de 01 a 12, será enviado automaticamente para a invalidez
        default: invalida = true;
    }
    }
    else invalida = true;

    //Horas negativas serão consideradas inválidas; 
    //Não pode horas maiores que 24, minutos e segundos maiores que 60, ou seja, inválida será considerada como true
    if(hora < 0 || hora > 23 || minuto < 0 || minuto > 60 || segundo < 0 || segundo > 60) invalida = true;

    if(invalida)
    {
        this->dia = 01;
        this->ano = 01;
        this->mes = 0001; 
        this->hora = 00;
        this->minuto = 00;
        this->segundo = 00;
    }

};

/*Destrutor da classe*/
DataHorario::~DataHorario(){}; 

/*Método de comparação das datas*/
int DataHorario::compare(DataHorario& d2) {
    //Se os anos forem diferentes e o ano da segunda data for maior o retorno será como pedido, negativo
    //Caso sejam iguais, serão verificados os meses, e caso o do segundo objeto seja maior, será retorno negativo
    //Mesma logica aplicada aos demais atributos
    if(d2.ano != this->ano) return this->ano - d2.ano;
    else
    {
        if(d2.mes != this->mes) return this->mes - d2.mes;
        else
        {
            if(d2.dia != this->dia) return this->dia - d2.dia;
            else 
            {
                if(d2.hora != this->hora) return this->hora - d2.hora;
                else 
                {
                    if(d2.minuto != this->minuto) return this->minuto - d2.minuto;
                    else return this->segundo - d2.segundo;
                }
            }
        }
    }

    
}


//Métodos get e set para os atributos da classe
int DataHorario::getDia()
{
    return this->dia;
}

void DataHorario::setDia(int dia)
{
    this->dia = dia;
}

int DataHorario::getMes()
{
    return this->mes;
}

void DataHorario::setMes(int mes)
{
    this->mes = mes;
}

int DataHorario::getAno()
{
    return this->ano;
}

void DataHorario::setAno(int ano)
{
    this->ano = ano;
}

int DataHorario::getHora()
{
    return this->hora;
}

void DataHorario::setHora(int hora)
{
    this->hora = hora;
}

int DataHorario::getMinuto()
{
    return this->minuto;
}

void DataHorario::setMinuto(int minuto)
{
    this->minuto = minuto;
}

int DataHorario::getSegundo()
{
    return this->segundo;
}

void DataHorario::setSegundo(int segundo)
{
    this->segundo = segundo;
}


//Método de impressão da classe
void DataHorario::imprime(bool padrao)
{
    //Variável para armazenar am/pm
    string p;
    //Se for verdadeiro ele imprime na versão 24horas
    if(padrao)
        cout << dia << "/" << mes << "/" << ano << " " << hora << ":" << minuto << ":" << segundo << endl;
    //Senão, será no formato 12h com am/pm
    else
    {
        if(hora > 12)
        {   
            //se a hora fornecida for maior ou igual a 12 significa, no padrão 24h, que é após o meio-dia e por isso, deve ser usado pm nesse padrão
            hora = hora - 12;
            p = "PM";
        } 
        else if(hora == 12) p = "PM";
        else p = "AM"; //Caso não, a hora fornecida será mantida e somente será acrescentado am ao final

        cout << dia << "/" << mes << "/" << ano << " " << hora << ":" << minuto << ":" << segundo << " " << p << endl;
    }

}

void DataHorario::imprimePorExtenso()
{
    //string para armazenar o valor por extenso do mês de acordo com o seu 'índice'
    string mext;

    //switch variando de acordo com o valor atribuido a variável mes
    switch(mes)
    {
        case 1: 
            mext = "Janeiro";
        break;
        case 2: 
            mext = "Fevereiro";
        break;
        case 3: 
            mext = "Março";
        break;
        case 4: 
            mext = "Abril";
        break;
        case 5: 
            mext = "Maio";
        break;
        case 6: 
            mext = "Junho";
        break;
        case 7: 
            mext = "Julho";
        break;
        case 8: 
            mext = "Agosto";
        break;
        case 9: 
            mext = "Setembro";
        break;
        case 10: 
            mext = "Outubro";
        break;
        case 11: 
            mext = "Novembro";
        break;
        case 12: 
            mext = "Dezembro";
        break;
    }

    //Impressão por extenso e concatenada com a data e hora
    cout << dia << " de " << mext << " de " << ano << " - " << hora << " horas, " << minuto << " minutos e " << segundo << " segundos." << endl;
}