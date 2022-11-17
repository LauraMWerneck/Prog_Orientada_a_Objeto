# Projeto Final Programação Orientado à Objetos - Jogo de cartas Dante

## 1 - Regras do jogo
Este é um jogo o qual visa que os jogadores, a partir da troca e descarte de cartas, consiga eliminar as suas cartas 
e ficar com o menor valor de somatório do valores das cartas.
As cartas possuem os seguintes valores:

Carta | Naipe   |Valor
------|---------|------
A     | ♠ ♣ ♥ ♦ |1
2     | ♠ ♣ ♥ ♦ |2
3     | ♠ ♣ ♥ ♦ |3
4     | ♠ ♣ ♥ ♦ |4
5     | ♠ ♣ ♥ ♦ |5
6     | ♠ ♣ ♥ ♦ |6
7     | ♠ ♣ ♥ ♦ |7
8     | ♠ ♣ ♥ ♦ |8
9     | ♠ ♣ ♥ ♦ |9
10    | ♠ ♣ ♥ ♦ |10
J     | ♠ ♣ ♥ ♦ |10
Q     | ♠ ♣ ♥ ♦ |10
K     | ♠ ♣     |10
K     | ♥ ♦     |0

#### Símbolos das cartas e seus nomes: 
* Espadas(♠)
* Paus(♣)
* Copas(♥) 
* Ouro(♦) 

#### Cartas especiais 
* J : Quando um jogador descarta na mesa essa carta ele pode, se quiser, trocar uma de suas cartas com a de algum 
outro oponente. No entanto, ele não pode ver qual a informação da carta.
* Q : Quando um jogador descarta na mesa essa carta ele pode, se quiser, ver a informação de uma das suas cartas 
que estão viradas.

#### Iniciando o Jogo:

Inicialmente as cartas são embaralhadas e cada jogador recebe 4 cartas. As cartas são entregues aos jogadores todas
viradas com a informação da carta para baixo.
Após todos os jogadores receberem as cartas antes de iniciar a partida cada jogador tem direito de ver a informação 
de duas das quatro cartas. Após todos verem suas duas cartas o jogo se inicia. 
O jogador inicia comprando uma carta do monte e vendo se o valor dela é maior do que alguma das cartas que já conhece.
Se sim, ele pode trocar a uma de suas cartas pela carta do monte. Ou então, se ele achar que a carta tem um valor bom, 
pode trocar por uma das cartas que ainda não conhece. Assim ele vira a carta que deseja descartar na mesa, com seu valor 
à mostra. Caso deseje também é possível descartar a carta que foi comprada naquela rodada, caso o valor dela não seje 
interessante e vantajoso.
Quando uma carta é descartada na mesa, caso algum jogador tenha uma carta igual pode descartar essa em cima da anterioar 
contanto que seja antes do proximo jogador comprar sua carta.
Quando um jogador descarta a carta na mesa é a vez do próximo jogador, o qual compra uma carta do monte e faz a mesma análise.
Os jogadores podem descartar suas cartas conforme as regras, no entanto é obrigatório sempre ficar com no mínimo uma carta
consigo na mesa.
Quando um jogador acredita que está com a menor quantia de soma, ele, na sua vez de jogar, diz "Dante" em voz alta. Após isso, 
todos os jogadores jogam novamente até chegar de novo na pessoa que disse "Dante". Chegando nessa pessoa, todos os jogadores
irão mostrar as suas cartas e fazer a soma de seus valores. Vence o jogador que tiver a soma dos valores das cartas menor.

## 2 - Caso de Uso: Jogar Dante

Atores: Jogador

Descrição: O jogador inicia o jogo. O sistema seleciona quatro cartas aleatórias, de um baralho de 52 (desconsidera os coringas)
cartas, para cada jogador. O jogador então clica nas duas cartas que deseja saber inicialmete. Após isso, o jogador clica na carta 
novamente para voltar ela para baixo. Após isso o jogo começa. Quando está na vez do usuário, ele clica no monte no centro da mesa, 
e uma carta aleatória aparece em sua tela. Caso o jogador decida ficar com ela ele arrasta a carta até a carta que ele deseja trocar, 
caso contráio ele desliza a carta até o cetro da mesa, na área de descarte. Após isso é a vez do adversário.Caso um jogador queira descartar
uma carta por no descarte ter uma igual ele arrasta a carta até o descarte, e o jogo segue de onde parou. No entanto, para isso se tem um tempo
antes que o próximo jogador comrpre sua carta e , para descartar a carta igual, precisa fazer isso antes de o próximo jogador comprar a carta.
Este processo se repete até algum jogador clicar em um botão escrito "Dante". Após alguém  selecionar "Dante", mais uma rodada acontece até 
chegar na pessoa  que o selecionou. Quando isso ocorre, todas as cartas dos jogadores são viradas e é possivel ver o que cada um possuía. 
É feito o somatório do valor das cartas e então o sistema informa ao jogador se ele ganhou ou perdeu o jogo.


## 3 - Análise e Projeto Orientado a Objetos

* Modelagem conceitual do problema
* Modelagem de interação do caso de uso (diagramas de sequência)
* Modele o diagrama de classes do mesmo


Para abrir os diagramas: https://app.diagrams.net/


https://github.com/ocornut/imgui

## Exemplo para o QT

![image](https://user-images.githubusercontent.com/84626462/202525731-17b328ab-9887-4de1-b7fd-b1ad613717e4.png)

