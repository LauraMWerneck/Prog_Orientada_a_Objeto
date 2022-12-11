/*
 * Name        : Jogador.h
 * Author      : Laura Martin Werneck
 * Created on  : 28 de nov. de 2022
 */

#ifndef JOGADOR_H_
#define JOGADOR_H_

#include <string>
#include "Cartas.h"
#include "Mao.h"
#include "Deck.h"

class Mesa;

class Jogador
    {
        protected:

        // Membros do jogador para manter informações de atributos do jogador.
        std::string nome;

        static const int NUM_VENCE = 21;

        public:

        // Ponteiro para um objeto
        Mao* mao;

        // Construtor padrão
        Jogador();
        Jogador(std::string n, Cartas *c1, Cartas *c2);
        // Destrutor
        ~Jogador();

        // Metodos da classe
        string obtemNome();
        void adiciona(Cartas *h);
        int fica();
        std::string exibeMao();
    };

// Subclasse do Jogador
class Mesa:public Jogador
    {
        private:

        // A mesa cria e administra o deck
        Deck* deck;

        static const int NUM_MESA = 17;
        static const int NUM_EMB = 20;

        public:
        // Construtor padrão
        Mesa();
        // Destrutor
        ~Mesa();

        // Metodos da classe
        Cartas* cartaTopoBaralho();
        int ficaMesa();
        void redefineDeck();
        string cartaFechada();
    };

#endif /* JOGADOR_H_ */
