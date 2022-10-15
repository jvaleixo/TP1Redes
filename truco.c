#include <stdio.h>
#include <string.h>
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
Cartas DistribuiCartas(Cartas Baralho[CSBARALHO], Jogadores J){

}
Cartas verificavalor(Jogadores J){

}
int pedirmaispts(Jogadores J){ /* pedir para a rodada valer mais pontos que o normal*/

}
int distribuipontos(Jogadores J){ /*distribui os pontos entre as duplas após as jogadas*/

}
Cartas truco(Cartas Baralho[CSBARALHO], Jogadores J){

}
void nomedascartas(Baralho B){
    char aux[20];
    int i = 0;
    for(i = 0; i < CSBARALHO ; i++){
        switch(B.carta[i].valor){
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
        switch(B.carta[i].naipe){
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
        printf("Carta %d: %s\n",i,aux);
    }

}

int main(){
    Jogadores J; 
    int i = 0;
    Baralho Baralho = iniciaBaralho();
    nomedascartas(Baralho);
    return 0;
}