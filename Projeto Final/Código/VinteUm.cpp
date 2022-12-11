/*
 * Name        : VinteUm.cpp
 * Author      : Laura Martin Werneck
 * Created on  : 28 de nov. de 2022
 */

#include "VinteUm.h"

#include <iomanip>

// Cria novos objetos de mesa e jogador.
VinteUm::VinteUm()                          //Classe = VinteUm  m�todo = VinteUm()
{
    mesa = new Mesa;
    jogador = new Jogador;
}

//Cria um novo objeto mesa e jogador com cartas
VinteUm::VinteUm(std::string n)             //Classe = VinteUm  m�todo = VinteUm(std::string n)
{
    mesa = new Mesa;
    jogador = new Jogador(n, mesa->cartaTopoBaralho(), mesa->cartaTopoBaralho());
}

// Exclui os objetos criados com o novo operador.
VinteUm::~VinteUm()
{
    delete mesa;                            // Apaga o objeto mesa
    delete jogador;                         // Apaga o objeto jogador
}

//Verifica se o baralho precisa ser redefinido e distribui as cartas conforme necess�rio.
void VinteUm::novaMao()             // novaMao() � um m�todo da classe VinteUm
{
    mesa->redefineDeck();             // Reinicializa��o do deck

    if(mesa->mao->obtemContagemCartas() == 0)          // Se o numero de cartas da m�o da mesa for igual a zero
        {
            mesa->adiciona(mesa->cartaTopoBaralho());                // Adiciona uma nova carta a mao da mesa
            mesa->adiciona(mesa->cartaTopoBaralho());                // Adiciona uma nova carta a mao da mesa
            jogador->adiciona(mesa->cartaTopoBaralho());             // Adiciona uma nova carta a mao do jogador
            jogador->adiciona(mesa->cartaTopoBaralho());             // Adiciona uma nova carta a mao do jogador
        }

}

// Exibe ambas as m�os sem mostrar a carta fechada da mesa.
void VinteUm::exibeAmbasMaos()                      // exibeAmbasMaos() � um m�todo da classe VinteUm
{
    cout << "\n---- MESA ----\n";
    cout << "M�O: " << setw(15) << left << mesa->cartaFechada() << "\n";

    cout << "\n---- JOGADOR ----\n";
    cout << "M�O: " << setw(15) << left << jogador->exibeMao() << "\n";
    cout << "SOMA: " << setw(15) << left << jogador->fica() << "\n\n";
}

// Exibe ambas as m�os em sua totalidade.
void VinteUm::exibeTodasMaos()                      // exibeTodasMaos() � um m�todo da classe VinteUm
{
    cout << "\n---- MESA ----\n";
    cout << "M�O: " << setw(15) << left << mesa->exibeMao() << "\n";
    cout << "SOMA: " << setw(15) << left << mesa->ficaMesa() << "\n\n";

    cout << "\n---- JOGADOR ----\n";
    cout << "M�O: " << setw(15) << left << jogador->exibeMao() << "\n";
    cout << "SOMA: " << setw(15) << left << jogador->fica() << "\n\n";
}

// Retorna o booleano para se o jogador tiver 21.
bool VinteUm::verificaJogadorVinteUm()              // verificaJogadorVinteUm() � um m�todo da classe VinteUm
{
    return jogador->mao->temVinteUm();
}

// Retorna o booleano para se a mesa tiver 21.
bool VinteUm::verificaMesaVinteUm()                 // verificaMesaVinteUm() � um m�todo da classe VinteUm
{
    return mesa->mao->temVinteUm();
}

// Adiciona uma carta � m�o do jogador.
void VinteUm::adicionaCartaJogador()            // adicionaCartaJogador() � um m�todo da classe VinteUm
{
    jogador->adiciona(mesa->cartaTopoBaralho());
}

// Retorna um booleano para se a m�o do jogador estourar (passar 21).
bool VinteUm::verificaEstouroJogador()
{
    return jogador->mao->temEstouro();
}

// Retorna um booleano se o jogador puder pegar uma carta.
bool VinteUm::podeJogadorAdicionarCarta()
{
    return jogador->mao->podePegarCarta();
}

// Exibe e implementa o resultado adequado do jogo.
void VinteUm::resultados()
{
     // Se o jogador n�o tiver 21 e a mesa tiver, o jogador perde.
    if(!(jogador->mao->temVinteUm()) && (mesa->mao->temVinteUm()))
    {
        cout << "A Mesa tem 21!\n";
        cout << "Voce perdeu.\n\n";
    }
    // Se o jogador tiver 21 e a mesa n�o, o resultado � "21", entao o jogador venceu.
    else if((jogador->mao->temVinteUm()) && !(mesa->mao->temVinteUm()))
        {
            cout << "Voce tem 21!\n\n";
        }
    // Se tanto o jogador quanto a mesa tiverem 21, � um empate.
    else if((jogador->mao->temVinteUm()) && (mesa->mao->temVinteUm()))
        {
            cout << "Deu empate! Ambos tem 21.'\n\n";
        }
    // Se a mao da mesa e maior que a mao do jogador, e nenhum deles estourou o valor, o jogador perde.
    else if((mesa->fica() > jogador->fica()) && !(jogador->mao->temEstouro()) && !(mesa->mao->temEstouro()))
        {
            cout << "A mesa � a ganhadora!\n";
            cout << "Voce perdeu.\n\n";
        }
    // Se a mao do jogador e maior que a mao damesa, e nenhum deles estourou o valor, o jogador ganha.
    else if((mesa->fica() < jogador->fica()) && !(jogador->mao->temEstouro()) && !(mesa->mao->temEstouro())
            && !(jogador->mao->temVinteUm()))
        {
            cout << "Voce ganhou!\n\n";
        }
    // Se a mao da mesa estourou o jogador vence.
    else if(!(jogador->mao->temEstouro()) && (mesa->mao->temEstouro()))
        {
            cout << "A mao da mesa estourou!\n";
            cout << "Voce ganhou!\n\n";
        }
    // Se a mao do jogador estoura ele perde.
    else if(jogador->mao->temEstouro())
        {
            cout << "A sua mao estourou!\n";
            cout << "Voce perdeu.\n\n";
        }
    // Se a pontua��o do jogador e da mesa for igual, o jogo � um empate.
    else if(mesa->fica() == jogador->fica())
        {
            cout << "Deu empate!\n\n";
        }
}

// Limpa as cartas do blackjackhands.
void VinteUm::limpaMaos()
{
    mesa->mao->limpaMao();              // Limpa as cartas da mao da mesa
    jogador->mao->limpaMao();           // Limpa as cartas da mao do jogador
}
