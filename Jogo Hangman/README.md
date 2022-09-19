# Exemplo - Análise e Projeto Orientado à Objetos
## 1 - Caso de Uso: Jogar Hangman

Atores: Jogador

Descrição: O jogador inicia o jogo. O sistema seleciona uma palavra de um dicionário de palavras e
apresenta ao jogador o número de letras que essa palavra possui e uma dica sobre a palavra. O jogador
então informa uma letra do alfabeto ao sistema. O sistema verifica se a letra informada está presente
na palavra e informa a posição em que essa letra se encontra, ou se não presente, decrementa o número
de erros que o Jogador pode cometer. Este processo se repete até que o jogador descubra a palavra
selecionada, ou acabe o seu número de tentativas erradas. Em ambos os casos o sistema informa ao
jogador se ele ganhou ou perdeu o jogo, e no caso de vitória, é apresentado o numero de pontos, que deve
ser calculado em função do número de erros do jogador e o tamanho da palavra.

## 2 - Análise e Projeto Orientado a Objetos

Dado o caso de uso do jogo Hangman, realize modelagem conceitual do problema, a modelagem de
interação do caso de uso (diagramas de sequência) e modele o diagrama de classes do mesmo.
