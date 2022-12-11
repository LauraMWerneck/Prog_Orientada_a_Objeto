/*============================================================================
Name        : Projeto_final_COO.cpp
Author      : Laura Martin Werneck
Version     : 05/12/2022
Copyright   : Your copyright notice
Description : O sistema dá ao jogador a opcão de começar o jogo ou sair. Quando
o jogador escolhe começar o jogo o programa pergunta à ele seu nome e inicia o jogo.
São dadas ao jogador duas cartas com seus valores a mostra. São dadas também duas
cartas à mesa, uma com valor a mostra e outra com valor escondido. A partir das suas
cartas o jogador escolhe se ele quer adicionar uma nova carta ao seu conjunto de cartas
ou se ele quer ficar com as que já tem.
Caso ele escolha adicionar, uma nova carta é adicionada à sua mão. Se já de primeira o
jogador tenha a soma de 21 o sistema decide pelo jogador automaticamente que ele irá
ficar com as cartas, para não passar o valor de 21. Enquanto o jogador nao tiver a soma
de cartas igual a 21, o programa fica em loop perguntando se o jogador quer adicionar
uma nova carta ou então ficar com as que tem.
Caso a soma das cartas ultrapasse 21, ao adicionar uma carta, é dito que houve estouro,
e o programa sai automaticamente deste loop.
Quando o jogador escolher ficar com as cartas, as cartas da mesa são exibidas em sua
totalidade e com isso ambas as mãos vão para análise para ver o resultado do jogo.
Após a análise do resultado, ambas as mãos são limpas e há a opção para o jogador de
iniciar um novo jogo ou sair do jogo.
============================================================================*/
#include <iostream>
#include "VinteUm.h"          // Include da classe separada
#include <iomanip>

using namespace std;

int main()
    {
        // Variável ​​para entrada do nome do usuário.
        string nomeJogador = "";

        // Variável ​​para entrada das escolhas do usuário.
        char escolha = 'x';

        cout << "Bem vindo ao Jogo 21!\n\n";
        cout << "O objetivo deste jogo e ter a soma de cartas mais proxima de 21.\n\n";
        cout << "Digite (P/p) para dar o play e comecar o jogo, ou digite (S/s) para sair do jogo.\n";
        cin >> escolha;         // Obtem a escolha do usuario

        // Verifica se o usuário colocou uma das opcoes validas, caso contrário
        // informa o erro e pergunta novamente a escolha
        while((escolha != 'P') && (escolha != 'p') && (escolha != 'S') && (escolha != 's'))
            {
                cout << "Entrada Invalida. Escolha entre (P/p) para dar o play e comecar o jogo, ou digite (S/s) para sair do jogo.\n";
                cin >> escolha;         // Obtem a escolha do usuario
            }

        // Comeca o jogo caso o usuário escolha play
        if((escolha == 'P') || (escolha == 'p'))
            {
                cout << "\n\nInforme o seu nome:"; 	// Pergunta o nome do jogador
                cin >> nomeJogador;         		// Obtem o nome do jogador

                // Ver o que isso faz
                VinteUm* jogo = new VinteUm(nomeJogador);

                cout << "Bem vindo " << nomeJogador << "!\n";    // Imprime Bem vindo 'Jogador x'

                // do - while -> loop para o jogo rodar enquanto o jogador não decidir sair do jogo
                do
                {
                    // Inicia o jogo distribuindo cartas para a mãos vazias do jogador
                    jogo->novaMao();

                    // Exibe ambas as mãos com a carta fechada da mesa baixa.
                    jogo->exibeAmbasMaos();
                    //cout << "A soma deu" << jogador->fica() <<"\n";

                    // Caso o jogador tiver a soma igaul a 21
                    if(jogo->verificaJogadorVinteUm())              // Retorna o booleano se o jogador tiver 21.
                        {
                            cout << "A soma deu 21!!\n";        // Informa o jogador
                            system("Pause"); //To slow down the action
                            escolha = 'f';                  // Escolha automatica para o jogador ficar com 21
                        }

                    // Caso o jogador não tiver a soma das cartas igausl a 21
                    else
                        {
                    			// do - while -> loop para enquanto a soma nao estourar e enquanto o jogador nao decida ficar com o que ja tem
                                do //Begin loop for player to continue to take cards.
                                     {
                                        cout << "Gostaria de pegar uma nova carta (N/n) ou ficar (F/f) com as que ja tem? : ";
                                        cin >> escolha;    // Obtem a escolha do usuario


                                        // Valida a entrada da escolha
                                        while((escolha != 'N') && (escolha != 'n') && (escolha != 'F') && (escolha != 'f'))
                                            {
                                                cout << "Entrada invalida, escolha entre nova carta (N/n) ou ficar (F/f) com as que ja tem.\n";
                                                cin >> escolha;   // Obtem a escolha do usuario

                                            }
                                        // Caso o jogador escolha uma nova carta
                                        if((escolha == 'N') || (escolha == 'n'))
                                            {
                                                jogo->adicionaCartaJogador();       // Adiciona uma nova carta a mao do jogador
                                                jogo->exibeAmbasMaos();             // Mostra as cartas da mão do jogador

                                            }

                                        // Depois de pegar uma carta, determine se a soma da mão do jogador estourou
                                        // em caso afirmativo, escolha é definido como 'f' para sair do loop do.
                                        if(jogo->verificaEstouroJogador())  //Retorna um booleano caso o jogador tenha estourado.
                                            {
                                                cout << "\n--->A SOMA ULTRAPASSOU 21!!<---\n";
                                                escolha = 'f';          // Escolha automatica para o jogador ficar com as cartas que já tem
                                                system("Pause"); //To slow down the action
                                            }

                                     //Continua o loop enquanto a soma nao estourar e enquanto o jogador nao decida ficar com o que ja tem
                                     }while(((escolha == 'N') || (escolha == 'n')) &&
                                            (jogo->podeJogadorAdicionarCarta()));
                        }

                    // Depois que o jogador escolher ficar com as cartas que tem, a mesa(dealer) mostra as suas cartas.
                    cout << "\n\nCartas da mesa:\n";

                    jogo->exibeTodasMaos();  // Exibe ambas as mãos mostrando as cartas da mesa

                    system("Pause"); //To slow down the action

                    // Determina o resultado do jogo.
                    jogo->resultados();

                    // Depois que o resultado é determinado, as mãos do jogador e da mesa são limpas.
                    jogo->limpaMaos();

                    // Verifica se o jogador deseja continuar jogando.
                    cout << "Digite (C/c) para continuar jogando, ou (S/s) para sair do jogo.\n";

                    cin >> escolha;             // Obtem a escolha do usuario

                    // Verifica se o usuário colocou uma das opcoes validas, caso contrário
                    // informa o erro e pergunta novamente a escolha
                    while((escolha != 'C') && (escolha != 'c') && (escolha != 'S') && (escolha != 's'))
                        {
                            cout << "Entrada Invalida. Digite (C/c) para continuar, ou (S/s) para sair do jogo.\n";
                            cin >> escolha;         // Obtem a escolha do usuario
                        }

                }while((escolha == 'C') || (escolha == 'c'));  // Enquanto o jogador escolher continuar jogado continua no loop

                // Após o fim do jogo apaga o DMA game object.
                delete jogo;
            }

        return 0;
    }
