#define _GNU_SOURCE
#ifndef _H_TRUCO
#define _H_TRUCO

#include <stdio.h>
#include <string.h>
#define MAXCARTAS 3
#define CSBARALHO 40
#define MAXJOGADORES 4
#define MAXPTS 12


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
    int ptd1;
    int ptd2; 
    int pr1;
    int pr2;
    int pj1;
    int pj2;
}Jogadores;

Jogadores truco(Baralho B, Jogadores j);
Baralho iniciaBaralho();
Jogadores distribuirCartas(Baralho B, Jogadores J);
Jogadores verificavalor(Cartas c1, Cartas c2, Jogadores J, int valemais);
int pedirmaispts(Jogadores J);
Jogadores distribuirPontos(Jogadores J,int j,int valemais);
void nomedascartas(Cartas carta);
void printaPontos(Jogadores J);

#endif