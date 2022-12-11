/*
 * Name        : Jogador.cpp
 * Author      : Laura Martin Werneck
 * Created on  : 28 de nov. de 2022
 */

#include "Jogador.h"


// Cria novo objeto mao
Jogador::Jogador()
{
    nome = "Jogador";  // Ver se está certo
    mao = new Mao;
}

// Cria um objeto Jogador com o nome de entrada e distribui duas cartas para a mão.
Jogador::Jogador(std::string n, Cartas *c1, Cartas *c2)
{
    nome = n;
    mao = new Mao(c1, c2);
}

// Destrutor
Jogador::~Jogador()
{
    delete mao;
}

// Retorna a variável do nome do jogador
std::string Jogador::obtemNome()
{
    return nome;
}

// Leva um ponteiro para uma CartaJogo e adiciona a carta na mão do jogador.
void Jogador::adiciona(Cartas *h)
{
    mao->adicionaCarta(h);
}

// Retorna a 'melhor' pontuação para a mão do jogador.
// Esta 'melhor' pontuação depende dos As
int Jogador::fica()
{   // Se a pontuacao for menor que 21 considera o As como 11
    if(mao->obterMaximaPontuacao() <= NUM_VENCE)
        {
            return mao->obterMaximaPontuacao();
        }
    // Caso contrario considera o As como 1
    else
        {
            return mao->obterMinimaPontuacao();
        }
}

// Retorna uma sequência de códigos, ou seja, as cartas da mao do jogador.
std::string Jogador::exibeMao()
    {
        return mao->obtemTodosCodigosCartas();
    }


// Definicoes da Mesa, uma subclasse do Jogador

// Cria um baralho de cartas embaralhadas e adiciona duas cartas à mão da mesa
Mesa::Mesa()
{
    deck = new Deck(NUM_EMB);
    mao->adicionaCarta(cartaTopoBaralho());             // Adiciona a primeira carta
    mao->adicionaCarta(cartaTopoBaralho());             // Adiciona a segunda carta
}

// Exclui o objeto de baralho da mesa
Mesa::~Mesa()
{
    delete deck;
}

//Retorna um ponteiro para uma carta a ser adicionado a mesa e a mão do jogador.
Cartas* Mesa::cartaTopoBaralho()
{
    return deck->cartaTopoBaralho();
}


// Retorna a 'melhor' pontuação para o dealer.
// A logica da melhor carta é a mesma da do jogador, dos As
int Mesa::ficaMesa()
{
    if(mao->obterMinimaPontuacao() >= NUM_MESA)
        {
            return mao->obterMinimaPontuacao();
        }
    else
        {
            return mao->obterMaximaPontuacao();
        }
}

// Determina se o deck precisa ser redefinido.
// Checa o numero de cartas do deck e se tiver menos do que 10 cartas chama a funcao de reset do deck
void Mesa::redefineDeck()
{
    if(deck->obtemCartasRestantes() <= 10)          //10 é especificado nas instruções para reiniciar o deck.
        {
            deck->redefine();
            deck->embaralha(NUM_EMB);
        }
}

// Retorna uma string onde os primeiros codigos de carta da mão são removidos e
// substituídos por XX para representar a carta fechada
string Mesa::cartaFechada()
{
    string cartaFechada = "XX";                             // Representacao da carta fechada
    string maoTemporaria = mao->obtemTodosCodigosCartas();

    maoTemporaria.erase(0,2);                               // Apaga o valor da carta fechada na mao temporaria
    maoTemporaria.insert(0,cartaFechada);                   // Insere a carta fechada como XX na mao temporaria
    return maoTemporaria;
}
