/*
 * Name        : Cartas.cpp
 * Author      : Laura Martin Werneck
 * Created on  : 28 de nov. de 2022
 */

#include "Cartas.h"
using namespace std;

// Construtor padrão, define valor como '0', define naipe como '0'
Cartas::Cartas()
    {
        valor = '0';
        naipe = '0';
    }

// Verifica se meuValor e meuNaipe sao válidos.
// Se forem válidos, ele define o valor e se adequa a esses valores.
// Se algum deles não for válido, ele define ambos como '0'.
Cartas::Cartas(char meuValor, char meuNaipe)
    {
        valor = meuValor;
        naipe = meuNaipe;
        if(!eValido())
            {
                valor = '0';
                naipe = '0';
            }
    }

// Verifica se há meuValor e meuNaipe válidos.
// Se forem válidos, ele define o valor e se adequa a esses valores.
// Se algum deles não for válido, retorna falso e não altera nenhum valor.
bool Cartas::defineCarta(char meuValor, char meuNaipe)
    {
        valor = meuValor;
        naipe = meuNaipe;

        if(eValido())
            {
                return true;
            }
        else
            {
                valor = '0';
                naipe = '0';
                return false;
            }
    }

// Retorna o valor da carta.
char Cartas::obtemValor()
	{
     return valor;
    }

// Retorna o naipe da carta.
char Cartas::obtemNaipe()
    {
        return naipe;
    }

// Retorna uma string contendo os 2 caracteres associados acarta.
// Por exemplo, para o 7 de espadas, ele retornaria a string "7S".
// OBS: Não inclui nenhum espaço.
string Cartas::obtemCodigoCarta()
    {
        string codigoCarta = "";
        codigoCarta += valor;
        codigoCarta += naipe;
        return codigoCarta;
    }

// Retorna verdadeiro se o cartão for válido ou falso se não for.
bool Cartas::eValido()
    {
        return (((valor >= 50) && (valor <= 57)) || (valor == 'T') || (valor == 'A') || (valor == 'J') || (valor == 'Q') || (valor == 'K'))
                        && ((naipe == 'C') || (naipe == 'H') || (naipe == 'S') || (naipe == 'D'));
    }


Cartas::~Cartas() {
	// TODO Auto-generated destructor stub
}

