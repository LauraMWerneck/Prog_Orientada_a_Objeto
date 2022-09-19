//============================================================================
// Name        : Exercicio_STL.cpp
// Author      : Laura Martin Werneck
// Version     : 19/09/2022
// Copyright   : Your copyright notice
// Description : Fazer um programa no qual:
//              � Solicita para o usu�rio um conjunto de n�meros inteiros
//               (quantidade arbitr�ria)
//              � Imprime este conjunto na ordem em que o usu�rio digitou
//              � Apresenta qual � o menor n�mero digitado
//              � Apresenta qual � o maior n�mero digitado
//              � Imprime os n�meros digitados em ordem crescente
//============================================================================

/* Defini��es do c�digo:
 *
 * cout << " " << endl; -> Escreve na tela uma mensagem.
 *
 * cout << variavel << " "; -> Imprime uma vari�vel.
 *
 * cout << "  " << i << " "; -> Imprime uma mensagem e uma vari�vel.
 *
 * cin >> variavel;	-> Recebe uma vari�vel.
 *
 * vetor.push_back -> Adds a new element at the end of the vector, after its current last element.
 *
 * vetor.begin() -> Returns an iterator pointing to the first element in the vector.
 *
 * vetor.end() -> Returns an iterator referring to the past-the-end element in the vector container.
 *
 * min_element( , ) -> Returns an iterator pointing to the element with the smallest value in the range [first,last).
 *
 * max_element( , ) -> Returns an iterator pointing to the element with the largest value in the range [first,last).
 *
 * sort( , ) -> Sorts the elements in the range [first,last) into ascending order.
 *
 * reverse_iterator -> This class reverses the direction in which a bidirectional or random-access iterator iterates through a range.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {

	int q; 																      // q = quantidade de numeros do conjunto
	int i;                                                                    // i = variavel para pegar os n�meros do conjunto
	int n;                                                                    // n = n�meros do conjunto

	vector<int> conjunto;													  //Cria um vetor de inteiros chamado conjunto
	vector<int>::iterator v;


	cout << "Informe quantos n�meros tem o seu conjunto de n�meros:" << endl; //Pergunta ao usu�rio a quantidade de n�meros do conjunto
	cin >> q;																  //Recebe a quantidade de n�meros
	//cout << q << " ";

	for(i = 0; i < q; i++){                                                   //For para receber todos os numeros do conjunto

		cout << "Informe o n�mero  " << i << " ";                             //Pede ao usuario o numero x do conjunto
		cin >> n;                                                             //Recebe o n�mero
		conjunto.push_back(n);                                                //Cria a sequencia de n�meros
	}

	cout << "O conjunto de n�meros informado foi: ";
	for (v = conjunto.begin(); v != conjunto.end(); v++) {                    //For inicia no primeiro elemento do vetor e vai ate o ultimo
	   cout << *v << " ";												      //Imprime a sequencia do conjunto a partir da leitura do vetor
	}
	cout << endl;

	/*An�lise do vetor at� achar o menor valor, usando a fun��o min_element( , ), e imprime no console esse valor*/
	cout << "O menor numero informado �: " << *min_element(conjunto.begin(), conjunto.end()) << endl;

	/*An�lise do vetor at� achar o maior valor, usando a fun��o max_element( , ), e imprime no console esse valor*/
	cout << "O maior numero informado �: " << *max_element(conjunto.begin(), conjunto.end()) << endl;


	sort(conjunto.begin(), conjunto.end());								      //Ordena o vetor em ordem crescente
	cout << "Conjunto de n�meros informado em ordem crescente: ";
	for (v = conjunto.begin(); v != conjunto.end(); v++) {				      //For para imprimir o vetor rearanjado em ordem crescente
		cout << *v << " ";
	}
	cout << endl;

	cout << "Conjunto de n�meros informado em ordem decrescente: ";
	std::vector<int>::reverse_iterator rit;									  //Cria outro vetor com a ordem decrescente
	for (rit = conjunto.rbegin(); rit!= conjunto.rend(); rit++){              //For para imprimir o novo vetor em ordem decrescente
		cout << *rit << " ";
	}
	cout << endl;

	return 0;
}
