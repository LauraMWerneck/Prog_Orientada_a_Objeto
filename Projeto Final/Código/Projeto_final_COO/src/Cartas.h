/*
 * Name        : Cartas.h
 * Author      : Laura Martin Werneck
 * Created on  : 28 de nov. de 2022
 */

#ifndef CARTAS_H_
#define CARTAS_H_

#include <string>
using namespace std;

class Cartas {
private:

    char valor;
    char naipe;

public:
    // Construtor padrão
    Cartas();
    Cartas(char meuValor, char meuNaipe);

    // Metodos da classe
    bool defineCarta(char myValue, char mySuit);
    char obtemValor();
    char obtemNaipe();
    string obtemCodigoCarta();
    bool eValido();
	// Destrutor
	virtual ~Cartas();
};

#endif /* CARTAS_H_ */
