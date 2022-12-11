/*
 * Name        : Mao.cpp
 * Author      : Laura Martin Werneck
 * Created on  : 28 de nov. de 2022
 */

#include "Mao.h"
using namespace std;

// Construtor padrão que inicializa a mao vazia
Mao::Mao()
    {
        // Enquanto i for menor que a quantidade máxima de cartas inicializa uma carta vazia na mão
        for(int i = 0; i <= QUANTIDADE; i++)
            {
                mao[i] = NULL;
            }
    }


// Inicializa a mao vazia e atribui aos dois primeiros elementos mao[0] e mao[1] as cartas c1 e c2, respectivamente.
Mao::Mao(Cartas *c1, Cartas *c2)
    {
        for(int i = 0; i <= QUANTIDADE; i++)
            {
                mao[i] = NULL;
            }
        mao[0] = c1;
        mao[1] = c2;
    }

// Verifica se e possivel adicionar uma carta nova e se for retorna verdadeiro,
// caso contrario informa ao jogador e retorna falso
bool Mao::adicionaCarta(Cartas *carta)
    {
        // Se não tem o maximo de cartas, e nao estourou a soma, ou se a soma nao deu igaual a 21
        if(podePegarCarta())
            {
                mao[obtemContagemCartas()] = carta;
                return true;
            }
        else
            {
                cout << "\nNão é possível adicionar mais uma carta!\n";
                return false;
            }
    }

// Retorna o número de cartas da mão atual.
int Mao::obtemContagemCartas()
    {
        int contagemCartas = 0;
        // Enquanto i for menor que a quantidade maxima de cartas faz a contagem
        for(int i = 0; i < QUANTIDADE; i++)
            {
                // Enquanto as cartas nao sao vazias faz a contagem das cartas
                if(mao[i] != NULL)
                    {
                        contagemCartas++;
                    }
            }
        return contagemCartas;
    }

// Esta função retorna a pontuação da mão atual contando o primeiro ás da mão como 11.
int Mao::obterMaximaPontuacao()
    {
        int maximaPontuacao = 0;
        bool primeiroAs = false;
        for(int i = 0; i < obtemContagemCartas(); i++)
            {
                // Se as cartas forem 10, J, Q ou K o valor e 10
                if((mao[i]->obtemValor() == 'T') || (mao[i]->obtemValor() == 'J') || (mao[i]->obtemValor() == 'Q') || (mao[i]->obtemValor() == 'K'))
                   {
                       maximaPontuacao += 10;
                   }
                // Se a carta for A e este for o primeiro o valor é 11
                else if(mao[i]->obtemValor() == 'A' && !primeiroAs)
                    {
                        maximaPontuacao += 11;
                        primeiroAs = true;
                    }
                // Se a carta for A e este nao for o primeiro o valor é 1
                else if(mao[i]->obtemValor() == 'A' && primeiroAs)
                    {
                        maximaPontuacao += 1;
                    }
                else
                    {
                        maximaPontuacao += (mao[i]->obtemValor() - '0');
                    }
            }
        return maximaPontuacao;
    }

// Retorna a pontuação da mão atual com todos os as avaliados em 1.
int Mao::obterMinimaPontuacao()
    {
        int minimaPontuacao = 0;

        for(int i = 0; i < obtemContagemCartas(); i++)
            {
                // Se as cartas forem 10, J, Q ou K o valor e 10
                if((mao[i]->obtemValor() == 'T') || (mao[i]->obtemValor() == 'J') || (mao[i]->obtemValor() == 'Q') || (mao[i]->obtemValor() == 'K'))
                   {
                       minimaPontuacao += 10;
                   }
                // Se a carta for A o valor é 1
                else if(mao[i]->obtemValor() == 'A')
                    {
                        minimaPontuacao += 1;
                    }
                else
                    {
                        minimaPontuacao += (mao[i]->obtemValor() - '0');
                    }
            }
        return minimaPontuacao;
    }

// Redefine contagemCartas para zero e redefine as cartas da mão como vazias.
void Mao::limpaMao()
    {
        for(int i = 0; i < QUANTIDADE; i++)
            {
                delete mao[i];
            }
        for(int i = 0; i <= QUANTIDADE; i++)
            {
                mao[i] = NULL;
            }
    }

// Retorna verdadeiro se a mão tiver estourado
// VENCE == 21 -> Maxima pontuacao
bool Mao::temEstouro()
    {
        return (obterMinimaPontuacao() > VENCE);
    }

// Retorna verdadeiro se a mão tiver cinco cartas.
// QUANTIDADE == 5 -> Maximo de cartas quese pode ter
bool Mao::estaCheia()
    {
        return (obtemContagemCartas() == QUANTIDADE);
    }

// Retorna verdadeiro se a mão for capaz de aceitar outra carta.
// Isso so pode ser feito se a soma for menor que 21 e se a mão
// nao tiver a quantidade maxima de cartas
bool Mao::podePegarCarta()
    {
        return ((!temEstouro() && !estaCheia()) && (obterMinimaPontuacao() != VENCE));
    }

// Verifica o valor das cartas da mao e se tiver 21 retorna verdadeiro
bool Mao::temVinteUm()
    {
        if(obtemContagemCartas() == 2)
            {
                return
                		(
                	      (mao[0]->obtemValor() == 'A')
						  &&
						  (
						     (mao[1]->obtemValor() == 'T')
							 ||
							 (mao[1]->obtemValor() == 'K')
							 ||
                             (mao[1]->obtemValor() == 'Q')
							 ||
							 (mao[1]->obtemValor() == 'J')
						  )
						  ||
						  (
							    (mao[1]->obtemValor() == 'A')
								&&
                                (
                                   (mao[0]->obtemValor() == 'T')
								   ||
								   (mao[0]->obtemValor() == 'K')
								   ||
								   (mao[0]->obtemValor() == 'Q')
								   ||
								   (mao[0]->obtemValor() == 'J')
								 )
						   )
						);
            }
        else
            {
                return false;
            }
    }

// Retorna uma string listando todas as cartas da mão atual.
string Mao::obtemTodosCodigosCartas()
    {
        string codigoCarta = "";
        for(int i = 0; i < obtemContagemCartas(); i++)
            {
                codigoCarta += mao[i]->obtemCodigoCarta() + " ";
            }
        return codigoCarta;
    }


Mao::~Mao() {
	// TODO Auto-generated destructor stub
}
