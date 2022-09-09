//============================================================================
// Name        : DiceGame.cpp
// Author      : Hugo Marcondes
// Version     :
// Copyright   :
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ctime>

using namespace std;

/* Definição da classe
   Nome geralmente com a primeira letra maiuscula */
class Dice {

/* Encapsulamento: no padrao esta com metodo de acessibilidade privado */
private:
	int faceValue;           //Atributo da classe

public:                      //É possivel mandar mensagens para os objetos pelos mtodos no modo publico
	Dice() {                 //Construtor - Método sem valor de retorno que tem o mesmo noma da classe
		srand(time(NULL));   //Inicializa a semente do roll/numero aleatorio
		roll();
	}

	// Metodos da classe (roll e getFaceValue)
	void roll(){ // Metodo da classe
		faceValue = (rand() % 6) + 1;
	}
	int  getFaceValue(){
		return faceValue;
	}
};

/* Implementação da calsse de forma separada
    Declaração como se fosse função
    Ex: Função roll da classe Die

void Die::roll{
}
*/

/*Classe DiceGame que tem como atributos o dado 1 e o dado 2 (dice1 e dice2)
  Os dados são objetos da classe Dice*/
class DiceGame {
private:
	Dice dice1;
	Dice dice2;

public:
    /*Método play*/
	int play(){
		dice1.roll();  //Manda uma mensagem roll para o dice1 (objeto da classe)
		int fv1 = dice1.getFaceValue();
		dice2.roll();
		int fv2 = dice2.getFaceValue();

		return fv1 + fv2;
	}
};

int main() {
	cout << "Dice Game" << endl; // prints Dice Game

	DiceGame game; // Cria um objeto do tipo DiceGame

	int result = game.play();

	if(result == 7){
		cout << "Congrats! You win (" << result << ")" << endl;
	} else {
		cout << "Sorry! You lose (" << result << ")" << endl;
	}

	cout << "Running win percentage simulation!" << endl;
	const int times = 1000000;
	int wins = 0;
	for (int i = 0; i < times; i++) {
		if(game.play() == 7)
			wins++;
	}
	cout << " Win percentage after " << times << "times is " << ((float)wins/times)*100 << "%" << endl;

	return 0;
}

