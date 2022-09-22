#include <stdio.h>
#include <string.h>
typedef struct TCarta{
    char nome[1];
    char naipe[10];  
}Cartas;
typedef struct TJogador{
    int id;
    Cartas Cs[3];
}Jogador;

int main(){
    int i;   
    Jogador jogador1;
    jogador1.id = 1;
    strcpy(jogador1.Cs[0].nome,"K");
    strcpy(jogador1.Cs[1].nome,"J");
    strcpy(jogador1.Cs[2].nome,"5");
    strcpy(jogador1.Cs[0].naipe,"Copas");
    strcpy(jogador1.Cs[1].naipe,"Ouros");
    strcpy(jogador1.Cs[2].naipe,"Espadas");

    printf("Jogador %d\n",jogador1.id);
    for(i=0; i < 3; i++){
        printf("Carta %d\n",i+1);
        printf("Valor: %s Naipe: %s\n",jogador1.Cs[i].nome,jogador1.Cs[i].naipe);
    }
    return 0;
}