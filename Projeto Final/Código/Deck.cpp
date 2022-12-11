/*
 * Name        : Deck.cpp
 * Author      : Laura Martin Werneck
 * Created on  : 28 de nov. de 2022
 */

#include "Deck.h"
using namespace std;

// Construtor padr�o. Cria um baralho n�o embaralhado de 52 cartas.
Deck::Deck()
    {
        // Gerador de n�meros aleat�rios de sementes com o tempo
        srand(time(0));
        criaDeck();
    }

// Construtor que embaralha o baralho numEmbaralhos vezes.
Deck::Deck(int numEmbaralhos)
    {
       srand(time(0));
       criaDeck();
       embaralha(numEmbaralhos);
    }

// Destrutor. Isso � necess�rio devido � aloca��o din�mica de mem�ria.
// Quando um baralho � exclu�do, as cartas restantes no baralho devem ser exclu�das.
Deck::~Deck()
    {
        // Exclui todos os objetos de cartas
        for(int i = 0; i < BARALHO; i++)
            {
                delete deck[i];
            }
    }

// Cria um baralho n�o embaralhado
void Deck::criaDeck()
    {
        // Arrays de caracteres para os naipes e valores de objetos de cartas
        char naipe[] = {'D','C', 'H', 'S'};     //Naipes: clubs [paus], diamonds [ouros], hearts[copas] and spades [espadas].

        char valores[] = {'A', '2', '3', '4',
                        '5', '6', '7', '8',
                        '9', 'T', 'J', 'Q',
                        'K'};

        int i = 0;
        int n;
        int v;
        // cria objetos de cartas do jogo com os naipes e valores adequados
        for(n = 0; n < (sizeof(naipe)/sizeof(char)); n++)
            for(v = 0; v < (sizeof(valores)/sizeof(char)); v++)
                {
                    deck[i] = new Cartas(valores[v], naipe[n]);
                    i++;
                }
    }

// Retorna um ponteiro para um objeto de carta retirado "do topo" do baralho.
// Se n�o houver mais cartas no baralho, ele retorna um ponteiro nulo (ou seja, 0)
// e exibe um aviso
Cartas* Deck::cartaTopoBaralho()
    {
        // Ponteiro tempor�rio para segurar o ponteiro que est� sendo distribu�do
        Cartas* temp;

        // Atribui o subn�mero do ponteiro no topo do deck
        int contagemCartas = 0;

        // Contas para fora por 1
        if(obterContagemUsada() == BARALHO)
            {
                contagemCartas = (BARALHO - 1);
            }
        else
            {
                contagemCartas = obterContagemUsada();
            }

        // Se o ponteiro para o objeto do cart�o existir
        if(deck[contagemCartas] != NULL)
            {
                // Atribuir o ponteiro a temp
                // Atribuir NULL ao ponteiro e retorna temp
                temp = deck[contagemCartas];
                deck[contagemCartas] = NULL;
                return temp;
            }
        else
            {
                // Exibir aviso se n�o houver cart�es restantes
                cout << "\nN�o h� cart�es restantes no deck!\n";
                return NULL;
            }
    }

// O embaralhamento s� deve ser embaralhado se nenhuma carta tiver sido distribu�da do baralho.
// Se uma ou mais cartas foram distribu�das, a fun��o deve retornar false
// e nenhum embaralhamento deve ser feito.
bool Deck::embaralha(int numEmbaralhos)
    {
        // ponteiro tempor�rio para segurar o ponteiro que est� sendo trocado
        Cartas* temp;

        // Inicializar e atribuir vari�vel para manter o n�mero aleat�rio
        int numAleatorio = 0;

        // Valor m�nimo para obter um bom embaralhamento aleat�rio
        const int MIN_EMBARALHO = 200;

        // Garante que nenhuma carta foi usada antes de embaralhar
        if(obterContagemUsada() == 0)
            {
                for(int i = 0; i < numEmbaralhos * MIN_EMBARALHO; i++)
                    {
                        //Bubble sort aleatorio para embaralhar
                        numAleatorio = rand() % (BARALHO - 1);
                        temp = deck[numAleatorio];
                        deck[numAleatorio] = deck[numAleatorio + 1];
                        deck[numAleatorio + 1] = temp;
                    }
                return true;
            }
        else
            {
                // Exibe um erro se as cartas foram distribu�das e n�o embaralhadas
                cout << "\nN�o � poss�vel embaralhar o baralho!\n";
                return false;
            }
    }

// Redefine o baralho para um baralho completo de 52 cartas n�o embaralhadas. Lembre-se que quando
void Deck::redefine()
    {
        // Exclui todos os objetos de cartas de baralho
        for(int i = 0; i < BARALHO; i++)
            {
                delete deck[i];
            }

        criaDeck();
    }


// Cria e retorna uma string com todos os c�digos de valor e naipe do baralho.
string Deck::obterTodosCodigosCartas()
    {
        string todosCodigosCartas = "";

        const int NAIPES = 4,    // Quatro naipes
                  VALORES = 13;  // Treze valores para cada naipe

        int carta = 0;

        for(int n = 0; n < NAIPES; n++)
            {
                for(int v = 0; v < VALORES; v++)
                    {
                        if(deck[carta] != NULL)
                            {
                                todosCodigosCartas += deck[carta]->obtemCodigoCarta();
                                todosCodigosCartas += "  ";
                                carta++;
                            }
                        else
                            {
                                carta++;
                            }
                    }
                todosCodigosCartas += "\n";
            }

        return todosCodigosCartas;

    }


// Retorna o n�mero de cartas j� distribu�das do baralho.
// Pesquisa na matriz do baralho e conta quantas cartas s�o NULL
int Deck::obterContagemUsada()
    {
        int cartaUsada = 0;

        for(int i = 0; i < BARALHO; i++)
            {
                if(deck[i] == NULL)
                    {
                        cartaUsada++;
                    }
            }

        return cartaUsada;
    }


// Retorna o n�mero de cartas restantes no baralho.
// Pesquisa na matriz do baralho e conta quantas cartas n�o s�o NULL
int Deck::obtemCartasRestantes()
    {

        return BARALHO - obterContagemUsada();
    }
