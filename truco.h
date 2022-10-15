#define _GNU_SOURCE
#ifndef _H_TRUCO
#define _H_TRUCO

#include <stdio.h>
#include <string.h>
#define MAXCARTAS 3
#define CSBARALHO 40
#define MAXJOGADORES 4
#define MAXPTS 12


/*enum naipes{ESPADA,OURO,COPAS,PAUS};
enum cartas{QUATRO,CINCO,SEIS,SETE,DAMA,VALETE,REI,AS,DOIS,TRES,};*/

typedef struct TCarta{
    int naipe, valor, sel; /* sel = 0 carta no baralho, sel = 1 carta com algum jogador*/ 
}Cartas;
typedef struct TBaralho{
    Cartas carta[CSBARALHO];
}Baralho;
typedef struct TJogador{
    Cartas Cs[MAXCARTAS]; /* define o numero de cartas que cada jogadaor vai ter por rodada, no caso 3 como definido pelas regras do jogo*/
}Jogador;
typedef struct TJogadores{
    Jogador js[MAXJOGADORES];
    int ponts[2];/*cada posiçao define a pontuacao de cada dupla*/
}Jogadores;

Cartas truco(Cartas Baralho[], Jogadores j);
Baralho iniciaBaralho();
Cartas DistribuiCartas(Cartas Baralho[], Jogadores J);
int pedirmaispts(Jogadores J);
int distribuipontos(Jogadores J);
void nomedascartas(Baralho B);

#endif