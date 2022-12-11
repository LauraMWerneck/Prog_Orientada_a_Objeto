/*
 * Name        : VinteUm.h
 * Author      : Laura Martin Werneck
 * Created on  : 28 de nov. de 2022
 */

#ifndef VINTEUM_H_
#define VINTEUM_H_

#include "Jogador.h"
#include "Cartas.h"
#include "Mao.h"
#include "Deck.h"

class VinteUm
	{
		protected:

		// Ponteiros para os objetos
		Jogador* jogador;
		Mesa* mesa;

		public:
		// Construtor padrão
		VinteUm();
		VinteUm(std::string name);

		//Destrutor
		~VinteUm();

		// Metodos da classe
		void novaMao();
		void exibeAmbasMaos();
		void exibeTodasMaos();
		bool verificaJogadorVinteUm();
		bool verificaMesaVinteUm();
		void adicionaCartaJogador();
		bool verificaEstouroJogador();
		bool podeJogadorAdicionarCarta();
		void resultados();
		void limpaMaos();
	};

#endif /* VINTEUM_H_ */
