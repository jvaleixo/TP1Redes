#include <stdio.h>
#include <string.h>
#include "truco.h"


Cartas iniciaBaralho(Cartas Baralho){
    int i = 0, vlr = 0, npe = 0;
    for(i =0; i < CSBARALHO;i++){
        Baralho.carta.valor = vlr;
        Baralho.carta.naipe = npe;
        vlr++;
        npe++;
        if(npe > 3){
            npe = 0;   
        } 
        if(vlr > 9){
            vlr = 0;
        }     
    }
    return Baralho;
};
Cartas DistribuiCartas(Cartas Baralho, Jogadores J){

};
Cartas verificavalor(Jogadores J){

};
int pedirmaispts(Jogadores J){ /* pedir para a rodada valer mais pontos que o normal*/

};
int distribuipontos(Jogadores J){ /*distribui os pontos entre as duplas após as jogadas*/

};
Cartas truco(Cartas Baralho, Jogadores J){

};
void nomedascartas(Cartas carta){
    switch(carta.valor){
        char aux[20]
        case 0: 
            strcpy(str,"Quatro"); 
            break;
        case 1: 
            strcpy(str,"Cinco"); 
            break;
        case 2: 
            strcpy(str,"Seis"); 
            break;
        case 3: 
            strcpy(str,"Sete"); 
            break;
        case 4: 
            strcpy(str,"Dama"); 
            break;
        case 5: 
            strcpy(str,"Valete"); 
            break;
        case 6: 
            strcpy(str,"Rei"); 
            break;
        case 7: 
            strcpy(str,"As"); 
            break;
        case 8: 
            strcpy(str,"Dois"); 
            break;
        case 9: 
            strcpy(str,"Tres"); 
            break;
    }
    switch(carta.naipe){
        case 0: 
            strcat(str," de espadas"); 
            break;
        case 1: 
            strcat(str," de ouro"); 
            break;
        case 2: 
            strcat(str," de copas"); 
            break;
        case 3: 
            strcat(str," de paus"); 
            break;
    }
};

int main(){
    Cartas Baralho[CSBARALHO];
    Jogadores J; 
    return 0;
};