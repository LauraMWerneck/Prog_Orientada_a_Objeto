/*
 * Name        : Mao.h
 * Author      : Laura Martin Werneck
 * Created on  : 28 de nov. de 2022
 *
 *
 */

#ifndef MAO_H_
#define MAO_H_

#include <string>
#include <iostream>
#include "Cartas.h"
using namespace std;

class Mao
	{
		private:

		static const int QUANTIDADE = 5;
		static const int VENCE = 21;

		Cartas* mao[QUANTIDADE];

		public:

		Mao();  // Construtor padrão
		Mao(Cartas *c1, Cartas *c2);

		// Metodos da classe
		bool adicionaCarta(Cartas *carta);
		int obtemContagemCartas();
		int obterMaximaPontuacao();
		int obterMinimaPontuacao();
		void limpaMao();
		bool temEstouro();
		bool estaCheia();
		bool podePegarCarta();
		bool temVinteUm();
		string obtemTodosCodigosCartas();

		// Destrutor
		virtual ~Mao();
	};

#endif /* MAO_H_ */
