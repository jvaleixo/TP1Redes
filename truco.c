#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h> /*close*/
#include <arpa/inet.h> /*close*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h> /*FD_SET, FD_ISSET, FD_ZERO macros*/
#include "truco.h"



Baralho iniciaBaralho(){
    Baralho aux[CSBARALHO];
    int i = 0, vlr = 0, npe = 0;
    for(i = 0; i < CSBARALHO;i++){
        aux->carta[i].sel = 0;
        aux->carta[i].valor = vlr;
        aux->carta[i].naipe = npe;
        vlr++;
        if(vlr > 9){
            vlr = 0;
        } 
        if(i == 9 || i == 19 || i == 29){
            npe++;
        }

    }
    return *aux;
}
Jogadores distribuirCartas(Baralho B, Jogadores J){
    int j = 0, contador = 0, aux=0;
    srand(time(NULL));
        for(j = 0; j < CSBARALHO; j++){
            int r = rand() % CSBARALHO;
            /*printf("%d\n",r);*/
            /*printf("carta %d selecionada\n",j);
            nomedascartas(B.carta[r]);*/
            if(B.carta[r].sel == 0){
                J.js[aux].Cs[contador].valor = B.carta[r].valor;
                J.js[aux].Cs[contador].naipe = B.carta[r].naipe;
                /*printf("carta %d do jogador %d\n",contador,aux);
                nomedascartas(J.js[aux].Cs[contador]);*/
                B.carta[r].sel = 1;
                contador++;
            }
            if(contador == 3){
                contador = 0;
                aux++;
            }
            if(aux == 4){
                break;
            }
        }

    J.ptd1 = 0;
    J.ptd2 = 0;
    J.pr1 = 0;
    J.pr2 = 0;
    J.pj1 = 0;
    J.pj2 = 0;

    return J;
}
Jogadores verificavalor(Cartas c1, Cartas c2, Jogadores J,int valemais){
    /* 
        Cartas mais fortes:
        1 - 4 de paus - 0 3
        2 - 7 de copas - 3 2
        3 - As de espadas - 7 0
        4 - 7 de ouros - 3 1

        ordem das cartas restantes de mais valiosa para menos valiosa: 3 > 2 > A > k > J > Q > 7 > 6 > 5 > 4.
        duplas 1-3, 2-4
        se valemais = 0, a rodada vale 2;
        se valemais = 1, a rodada vale 4;
        se valemais = 2, a rodada vale 6;
        se valemais = 3, a rodada vale 10;
        se valemais = 4, a rodada vale 12;

    */
    int j = 0;
    if(c1.valor == c2.valor && ((c2.valor != 0 && c2.naipe != 3) || (c2.valor !=3 && c2.naipe !=2) || (c2.valor == 7 && c2.naipe == 0))){
        printf("Empate! ninguém ganha ponto nessa rodada\n");
        j = 0;
        J = distribuirPontos(J,j,valemais);
    } else if(c1.valor == 0 && c1.naipe == 3){
        printf("A carta 1 é maior carta do jogo\n");
        j=1;
        J = distribuirPontos(J,j,valemais);
    } else if(c2.valor == 0 && c2.naipe == 3){
        printf("A carta 2 é maior carta do jogo\n");
        j = 2;
        J = distribuirPontos(J,j,valemais);
    } else if((c1.valor == 3 && c1.naipe == 2) && (c2.valor != 0 && c2.naipe != 3)){
        printf("A carta 1 vence\n");
        j=1;
        J = distribuirPontos(J,j,valemais);
    } else if((c2.valor == 3 && c2.naipe == 2) && (c1.valor != 0 && c1.naipe != 3)){
        printf("A carta 2 vence\n");
        j = 2;
        J = distribuirPontos(J,j,valemais);
    } else if((c1.valor == 7 && c1.naipe == 0) && ((c2.valor != 0 && c2.naipe != 3) && (c2.valor !=3 && c2.naipe !=2))){
        printf("A carta 1 vence\n");
        j=1;
        J = distribuirPontos(J,j,valemais);
    } else if((c2.valor == 7 && c2.naipe == 0) && ((c1.valor != 0 && c1.naipe != 3) && (c1.valor !=3 && c1.naipe !=2))){
        printf("A carta 2 vence\n");
        j=2;
        J = distribuirPontos(J,j,valemais);
    } else if((c1.valor == 3 && c1.naipe == 1) && ((c2.valor != 0 && c2.naipe != 3) && (c2.valor !=3 && c2.naipe !=2) && (c2.valor == 7 && c2.naipe == 0))){
        printf("A carta 1 vence\n");
        j=1;
        J = distribuirPontos(J,j,valemais);
    } else if((c2.valor == 3 && c2.naipe == 1) && ((c1.valor != 0 && c1.naipe != 3) && (c1.valor !=3 && c1.naipe !=2) && (c1.valor == 7 && c1.naipe == 0))){
        printf("A carta 2 vence\n");
        j=2;
        J = distribuirPontos(J,j,valemais);
    } else if((c1.valor == 9 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) && ((c2.valor != 0 && c2.naipe != 3) || (c2.valor !=3 && c2.naipe !=2) || (c2.valor == 7 && c2.naipe == 0))){
        printf("A carta 1 vence\n");
        j=1;
        J = distribuirPontos(J,j,valemais);
    } else if((c2.valor == 9 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) && ((c1.valor != 0 && c1.naipe != 3) || (c1.valor !=3 && c1.naipe !=2) || (c1.valor == 7 && c1.naipe == 0))){
        printf("A carta 2 vence\n");
        j=2;
        J = distribuirPontos(J,j,valemais);
    } else if((c1.valor == 8 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) && ((c2.valor != 0 && c2.naipe != 3) || (c2.valor !=3 && c2.naipe !=2) || (c2.valor == 7 && c2.naipe == 0) || (c2.valor == 9 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)))){
        printf("A carta 1 vence\n");
        j=1;
        J = distribuirPontos(J,j,valemais);
    } else if((c2.valor == 8 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) && ((c1.valor != 0 && c1.naipe != 3) || (c1.valor !=3 && c1.naipe !=2) || (c1.valor == 7 && c1.naipe == 0) || (c1.valor == 9 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)))){
        printf("A carta 2 vence\n");
        j=2;
        J = distribuirPontos(J,j,valemais);
    } else if((c1.valor == 7 && (c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) && ((c2.valor != 0 && c2.naipe != 3) || (c2.valor !=3 && c2.naipe !=2) || (c2.valor == 7 && c2.naipe == 0) || (c2.valor == 9 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 8 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)))){
        printf("A carta 1 vence\n");
        j=1;
        J = distribuirPontos(J,j,valemais);
    } else if((c2.valor == 7 && (c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) && ((c1.valor != 0 && c1.naipe != 3) || (c1.valor !=3 && c1.naipe !=2) || (c1.valor == 7 && c1.naipe == 0) || (c1.valor == 9 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) || (c1.valor == 8 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)))){
        printf("A carta 2 vence\n");
        j=2;
        J = distribuirPontos(J,j,valemais);
    } else if((c1.valor == 6 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) && ((c2.valor != 0 && c2.naipe != 3) || (c2.valor !=3 && c2.naipe !=2) || (c2.valor == 7 && c2.naipe == 0) || (c2.valor == 9 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 8 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 7 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)))){
        printf("A carta 1 vence\n");
        j=1;
        J = distribuirPontos(J,j,valemais);
    } else if((c2.valor == 6 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) && ((c1.valor != 0 && c1.naipe != 3) || (c1.valor !=3 && c1.naipe !=2) || (c1.valor == 7 && c1.naipe == 0) || (c1.valor == 9 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) || (c1.valor == 8 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) || (c1.valor == 7 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)))){
        printf("A carta 2 vence\n");
        j=2;
        J = distribuirPontos(J,j,valemais);
    } else if((c1.valor == 5 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) && ((c2.valor != 0 && c2.naipe != 3) || (c2.valor !=3 && c2.naipe !=2) || (c2.valor == 7 && c2.naipe == 0) || (c2.valor == 9 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 8 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 7 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 6 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)))){
        printf("A carta 1 vence\n");
        j=1;
        J = distribuirPontos(J,j,valemais);
    } else if((c2.valor == 5 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) && ((c1.valor != 0 && c1.naipe != 3) || (c1.valor !=3 && c1.naipe !=2) || (c1.valor == 7 && c1.naipe == 0) || (c1.valor == 9 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) || (c1.valor == 8 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) || (c1.valor == 7 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) || (c1.valor == 6 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)))){
        printf("A carta 2 vence\n");
        j=2;
        J = distribuirPontos(J,j,valemais);
    } else if((c1.valor == 4 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) && ((c2.valor != 0 && c2.naipe != 3) || (c2.valor !=3 && c2.naipe !=2) || (c2.valor == 7 && c2.naipe == 0) || (c2.valor == 9 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 8 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 7 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 6 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 5 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)))){
        printf("A carta 1 vence\n");
        j=1;
        J = distribuirPontos(J,j,valemais);
    } else if((c2.valor == 4 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) && ((c1.valor != 0 && c1.naipe != 3) || (c1.valor !=3 && c1.naipe !=2) || (c1.valor == 7 && c1.naipe == 0) || (c1.valor == 9 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) || (c1.valor == 8 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) || (c1.valor == 7 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) || (c1.valor == 6 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) || (c1.valor == 5 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)))){
        printf("A carta 2 vence\n");
        j=2;
        J = distribuirPontos(J,j,valemais);
    } else if((c1.valor == 3 && (c1.naipe == 0 || c1.naipe ==3)) && ((c2.valor != 0 && c2.naipe != 3) || (c2.valor !=3 && c2.naipe !=2) || (c2.valor == 7 && c2.naipe == 0) || (c2.valor == 9 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 8 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 7 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 6 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 5 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 4 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)))){
        printf("A carta 1 vence\n");
        j=1;
        J = distribuirPontos(J,j,valemais);
    } else if((c2.valor == 3 && (c2.naipe == 0 || c2.naipe ==3)) && ((c1.valor != 0 && c1.naipe != 3) || (c1.valor !=3 && c1.naipe !=2) || (c1.valor == 7 && c1.naipe == 0) || (c1.valor == 9 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) || (c1.valor == 8 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) || (c1.valor == 7 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) || (c1.valor == 6 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) || (c1.valor == 5 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) || (c1.valor == 4 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)))){
        printf("A carta 2 vence\n");
        j=2;
        J = distribuirPontos(J,j,valemais);
    } else if((c1.valor == 2 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) && ((c2.valor != 0 && c2.naipe != 3) || (c2.valor !=3 && c2.naipe !=2) || (c2.valor == 7 && c2.naipe == 0) || (c2.valor == 9 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 8 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 7 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 6 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 5 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 4 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 3 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)))){
        printf("A carta 1 vence\n");
        j=1;
        J = distribuirPontos(J,j,valemais);
    } else if((c2.valor == 2 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) && ((c1.valor != 0 && c1.naipe != 3) || (c1.valor !=3 && c1.naipe !=2) || (c1.valor == 7 && c1.naipe == 0) || (c1.valor == 9 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) || (c1.valor == 8 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) || (c1.valor == 7 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) || (c1.valor == 6 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) || (c1.valor == 5 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) || (c2.valor == 4 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 3 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)))){
        printf("A carta 2 vence\n");
        j=2;
        J = distribuirPontos(J,j,valemais);
    } else if((c1.valor == 1 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) && ((c2.valor != 0 && c2.naipe != 3) || (c2.valor !=3 && c2.naipe !=2) || (c2.valor == 7 && c2.naipe == 0) || (c2.valor == 9 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 8 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 7 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 6 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 5 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 4 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 3 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 2 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)))){
        printf("A carta 1 vence\n");
        j=1;
        J = distribuirPontos(J,j,valemais);
    } else if((c2.valor == 1 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) && ((c1.valor != 0 && c1.naipe != 3) || (c1.valor !=3 && c1.naipe !=2) || (c1.valor == 7 && c1.naipe == 0) || (c1.valor == 9 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) || (c1.valor == 8 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) || (c1.valor == 7 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) || (c1.valor == 6 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) || (c1.valor == 5 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) || (c2.valor == 4 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 3 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c1.valor == 2 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)))){
        printf("A carta 2 vence\n");
        j=2;
        J = distribuirPontos(J,j,valemais);
    } else if((c1.valor == 0 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 )) && ((c2.valor != 0 && c2.naipe != 3) || (c2.valor !=3 && c2.naipe !=2) || (c2.valor == 7 && c2.naipe == 0) || (c2.valor == 9 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 8 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 7 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 6 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 5 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 4 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 3 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 2 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 1 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)))){
        printf("A carta 1 vence\n");
        j=1;
        J = distribuirPontos(J,j,valemais);
    } else if((c2.valor == 0 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 )) && ((c1.valor != 0 && c1.naipe != 3) || (c1.valor !=3 && c1.naipe !=2) || (c1.valor == 7 && c1.naipe == 0) || (c1.valor == 9 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) || (c1.valor == 8 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) || (c1.valor == 7 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) || (c1.valor == 6 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) || (c1.valor == 5 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) || (c2.valor == 4 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c2.valor == 3 && (c2.naipe == 0 || c2.naipe == 1 || c2.naipe == 2 || c2.naipe ==3)) || (c1.valor == 2 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)) || (c1.valor == 1 && (c1.naipe == 0 || c1.naipe == 1 || c1.naipe == 2 || c1.naipe ==3)))){
        printf("A carta 2 vence\n");
        j=2;
        J = distribuirPontos(J,j,valemais);
    }
    return J;
}
int pedirmaispts(int vlm){ /* pedir para a rodada valer mais pontos que o normal*/
    int valemais = 0;
    if(vlm == 1){
        valemais = 1;
    }
    return valemais;
}
Jogadores distribuirPontos(Jogadores J,int j, int valemais){ /*distribui os pontos entre as duplas após as jogadas*/
    if(j==0){
        J.ptd1 += 0;
        J.ptd2 += 0;
    }
    if(j == 1 && valemais == 0){
        J.ptd1 += 2;
    }
    if(j == 2 && valemais == 0){
        J.ptd2 += 2;
    }
    if(j == 1 && valemais == 1){
        J.ptd1 += 4;
    }
    if(j == 2 && valemais == 1){
        J.ptd2 += 4;
    }
    if(j == 1 && valemais == 2){
        J.ptd1 += 6;
    }
    if(j == 2 && valemais == 2){
        J.ptd2 += 6;
    }
    if(j == 1 && valemais == 3){
        J.ptd1 += 10;
    }
    if(j == 2 && valemais == 3){
        J.ptd2 += 10;
    }
    if(j == 1 && valemais == 4){
        J.ptd1 += 12;
    }
    if(j == 2 && valemais == 4){
        J.ptd2 += 12;
    }
    if(J.ptd1 > 12){
        J.pr1++;
    }
    if(J.ptd2 > 12){
        J.pr2++;
    }
    if(J.pr1 == 2){
        J.pj1++;
    }
    if(J.pr2 == 2){
        J.pj2++;
    }
    return J;
}
void printaPontos(Jogadores J){
    printf("Pontos da dupla 1 na rodada: %d\n",J.ptd1);
    printf("Pontos da dupla 2 na rodada: %d\n",J.ptd2);
}
Jogadores truco(Baralho B, Jogadores J){
    /*menu com opcoes chamando as funcoes*/
    int opt, contador = 0,i = 0,aux=0,ce =0,j=0,vlm=0,valemais=0;
    Cartas cartaEscolhida;
    opt = -1;
    while(opt != 0){
        printf("Jogo de truco!\n");
        printf("0 - Sair da rodada\n");
        printf("1 - Ver suas cartas\n");
        printf("2 - Ver pontos\n");
        printf("3 - Jogar uma carta\n");
        scanf("%d",&opt);
        switch(opt){
            case 0: 
                printf("Saindo da rodada\n");
                break;
            case 1:
                for(i = 0; i < MAXCARTAS; i++){
                    printf("Carta %d do jogador 0\n",contador+1);
                    nomedascartas(J.js[0].Cs[contador]); 
                    contador++;
                    if(contador == 3){
                            contador = 0;
                        }
                }
                break;
            case 2:
                printaPontos(J);
                break;
            case 3:
                printf("Escolha a carta para jogar, digite um numero entre 1 e 3\n");
                for(i = 0; i < MAXCARTAS; i++){
                    printf("Carta %d do jogador 0\n",contador+1);
                    nomedascartas(J.js[aux].Cs[contador]); 
                    contador++;
                    if(contador == 3){
                            contador = 0;
                        }
                }
                scanf("%d",&ce);
                cartaEscolhida = J.js[aux].Cs[ce-1];
                for(j =0 ; j < CSBARALHO ; j++){
                    if(cartaEscolhida.valor == B.carta[i].valor && B.carta[i].sel == 1){
                        B.carta[i].sel = 0;
                        J.js[aux].Cs[ce-1].valor = -1;
                        J.js[aux].Cs[ce-1].naipe = -1;
                    }
                }
                printf("A carta escolhida foi : ");
                nomedascartas(cartaEscolhida); 
                printf("Deseja aumentar os pontos dessa rodada? 0 - nao, 1 - sim\n");
                scanf("%d",&vlm);
                valemais = pedirmaispts(vlm);
                printf("cartas em jogo:\n");
                nomedascartas(cartaEscolhida);
                nomedascartas(J.js[aux+1].Cs[0]);
                J = verificavalor(cartaEscolhida,J.js[aux+1].Cs[0],J,valemais);
                break;
            default:
                printf("Digite uma opção válida\n");
                break;
        }
    } 
    return J;
}
void nomedascartas(Cartas carta){
    char aux[20];
        switch(carta.valor){
            case 0: 
                strcpy(aux,"Quatro"); 
                break;
            case 1: 
                strcpy(aux,"Cinco"); 
                break;
            case 2: 
                strcpy(aux,"Seis"); 
                break;
            case 3: 
                strcpy(aux,"Sete"); 
                break;
            case 4: 
                strcpy(aux,"Dama"); 
                break;
            case 5: 
                strcpy(aux,"Valete"); 
                break;
            case 6: 
                strcpy(aux,"Rei"); 
                break;
            case 7: 
                strcpy(aux,"As"); 
                break;
            case 8: 
                strcpy(aux,"Dois"); 
                break;
            case 9: 
                strcpy(aux,"Tres"); 
                break;
        };
        switch(carta.naipe){
            case 0: 
                strcat(aux," de espadas"); 
                break;
            case 1: 
                strcat(aux," de ouro"); 
                break;
            case 2: 
                strcat(aux," de copas"); 
                break;
            case 3: 
                strcat(aux," de paus"); 
                break;
        };
        printf("%s\n",aux);
}

int main(int argc , char *argv[]){ 

    int i = 0,j = 0;
    int opt = TRUE;
	int master_socket , addrlen , new_socket , client_socket[30] ,
		max_clients = 30 , activity, valread , sd;
	int max_sd;
	struct sockaddr_in address;
		
	char buffer[1025]; /*data buffer of 1K*/
		
	/*set of socket descriptors*/
	fd_set readfds;
		
	/*a message*/
	char *message = "Jogo de truco \r\n";

	/*initialise all client_socket[] to 0 so not checked*/
	for (i = 0; i < max_clients; i++)
	{
		client_socket[i] = 0;
	}
		
	/*create a master socket*/
	if( (master_socket = socket(AF_INET , SOCK_STREAM , 0)) == 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}
	
	/*set master socket to allow multiple connections ,
	/this is just a good habit, it will work without this*/
	if( setsockopt(master_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt,
		sizeof(opt)) < 0 )
	{
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	
	/*type of socket created*/
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons( PORT );
		
	/*bind the socket to localhost port 8888*/
	if (bind(master_socket, (struct sockaddr *)&address, sizeof(address))<0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	printf("Listener on port %d \n", PORT);
		
	/*try to specify maximum of 3 pending connections for the master socket*/
	if (listen(master_socket, 3) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}
		
	/*accept the incoming connection*/
	addrlen = sizeof(address);
	puts("Waiting for connections ...");
		
	while(TRUE)
    {

		/*clear the socket set*/
		FD_ZERO(&readfds);
	
		/*add master socket to set*/
		FD_SET(master_socket, &readfds);
		max_sd = master_socket;
			
		/*add child sockets to set*/
		for ( i = 0 ; i < max_clients ; i++)
		{
			/*socket descriptor*/
			sd = client_socket[i];
				
			/*if valid socket descriptor then add to read list*/
			if(sd > 0)
				FD_SET( sd , &readfds);
				
			/*highest file descriptor number, need it for the select function*/
			if(sd > max_sd)
				max_sd = sd;
		}
		/*wait for an activity on one of the sockets , timeout is NULL ,
		so wait indefinitely*/
		activity = select( max_sd + 1 , &readfds , NULL , NULL , NULL);
	
		if ((activity < 0) && (errno!=EINTR))
		{
			printf("select error");
		}
		
		/*If something happened on the master socket ,
		then its an incoming connection*/
		if (FD_ISSET(master_socket, &readfds))
		{
			if ((new_socket = accept(master_socket,
					(struct sockaddr *)&address, (socklen_t*)&addrlen))<0)
			{
				perror("accept");
				exit(EXIT_FAILURE);
			}
			
			/*inform user of socket number - used in send and receive commands*/
			printf("New connection , socket fd is %d , ip is : %s , port : %d\n" , new_socket , inet_ntoa(address.sin_addr) , ntohs(address.sin_port));
		
			/*send new connection greeting message*/
			if( send(new_socket, message, strlen(message), 0) != strlen(message) )
			{
				perror("send");
			}
				
			puts("Welcome message sent successfully");
				
			/*add new socket to array of sockets*/
			for (i = 0; i < max_clients; i++)
			{
				/*if position is empty*/
				if( client_socket[i] == 0 )
				{
					client_socket[i] = new_socket;
					printf("Adding to list of sockets as %d\n" , i);
						
					break;
				}
			}
		}
			
		/*else its some IO operation on some other socket*/
		for (i = 0; i < max_clients; i++)
		{
			sd = client_socket[i];
				
			if (FD_ISSET( sd , &readfds))
			{
				/*Check if it was for closing , and also read the
				incoming message*/
				if ((valread = read( sd , buffer, 1024)) == 0)
				{
					/*Somebody disconnected , get his details and print*/
					getpeername(sd , (struct sockaddr*)&address , 
						(socklen_t*)&addrlen);
					printf("Host disconnected , ip %s , port %d \n" ,
						inet_ntoa(address.sin_addr) , ntohs(address.sin_port));
						
					/*Close the socket and mark as 0 in list for reuse*/
					close( sd );
					client_socket[i] = 0;
				}
					
				/*Echo back the message that came in*/
				else
				{
					/*set the string terminating NULL byte on the end
					of the data read*/
					buffer[valread] = '\0';
					send(sd , buffer , strlen(buffer) , 0 );
				}
			}
		}
	}
    
    /*int i = 0, aux = 0, contador = 0;*/
    /*J.js[0].Cs[0].valor = 0;
    J.js[0].Cs[0].naipe = 3; 
    for(i = 0; i < MAXJOGADORES*3; i++){
       printf("Carta %d do jogador %d\n",contador+1,aux);
       nomedascartas(J.js[aux].Cs[contador]); 
       contador++;
       if(contador == 3){
            contador = 0;
            aux++;
        }
        if(aux == 4){
            break;
        }
    }
    J = verificavalor(J.js[0].Cs[0],J.js[1].Cs[0],J);
    printaPontos(J); apenas para teste se as funções distribuirCartas e distribuirPontos funcionam corretamente*/
    /*for(i = 0; i < CSBARALHO; i++){
       printf("Carta %d: ",i);
       nomedascartas(Baralho.carta[i]); 
    } apenas para teste se a função inicia baralho funciona corretamente*/

    return 0;
}