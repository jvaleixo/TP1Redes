#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "truco.h"


Baralho iniciaBaralho(){
    Baralho aux[CSBARALHO];
    int i = 0, j = 0, vlr = 0, npe = 0;
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
    srand(time(NULL));
    int i = 0, j = 0, contador = 0, aux=0;
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
        return J;
    }
Cartas verificavalor(Jogadores J){

}
int pedirmaispts(Jogadores J){ /* pedir para a rodada valer mais pontos que o normal*/

}
int distribuipontos(Jogadores J){ /*distribui os pontos entre as duplas após as jogadas*/

}
Cartas truco(Baralho B, Jogadores J){

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

int main(){ 
    int i = 0, j = 0, aux = 0, contador = 0;
    Baralho B = iniciaBaralho();
    Jogadores J = distribuirCartas(B,J); 
    /*for(i = 0; i < MAXJOGADORES*3; i++){
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
    apenas para teste se a função distribuirCartas funciona corretamente*/
    /*for(i = 0; i < CSBARALHO; i++){
       printf("Carta %d: ",i);
       nomedascartas(Baralho.carta[i]); 
    } apenas para teste se a função inicia baralho funciona corretamente*/
    return 0;
}