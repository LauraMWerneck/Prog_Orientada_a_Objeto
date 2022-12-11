/*
 * Name        : Deck.h
 * Author      : Laura Martin Werneck
 * Created on  : 28 de nov. de 2022
 */

#ifndef DECK_H_
#define DECK_H_

#include "Cartas.h"
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Deck {
private:

static const int BARALHO = 52;

Cartas* deck[BARALHO];

void criaDeck();

public:
// Construtor padrão
Deck();
Deck(int numEmbaralhos);
// Destrutor
~Deck();

Cartas* cartaTopoBaralho();

// Metodos da classe

bool embaralha(int numEmbaralhos);
void redefine();
string obterTodosCodigosCartas();
int obterContagemUsada();
int obtemCartasRestantes();
};

#endif /* DECK_H_ */
