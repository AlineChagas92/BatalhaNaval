#include <stdio.h>
#define tam 10
#define Tam_Navio 3

int main (){
// Declaração de tabuleiro

int tabuleiro[tam][tam];

//Inicializando o tabuleiro com 0 (Água)

for (int i = 0; i < tam; i++){
    for (int j = 0; j < tam; j++){
        tabuleiro[i][j] = 0;
    }
}

//Declaração dos Navios

int navioHorizontal[Tam_Navio] = {3, 3, 3};
int navioVertical[Tam_Navio] = {3, 3, 3};

//Coordenadas iniciais

int linhaH = 2, colunaH = 1; //Navio horizontal
int linhaV = 5, colunaV = 4; //Navio vertical

//Validação de limites

if (colunaH + Tam_Navio > tam){
    printf ("Erro: Navio horizontal ultrapassa os limites. \n");
    return 1;
}

if (linhaV + Tam_Navio > tam){
    printf ("Erro: Navio vertical ultrapassa os limites \n");
    return 1;
    }

//Posicionando Navio Horizontal

for (int i = 0; i <Tam_Navio; i++){

    //Verifica Sobreposição
    if (tabuleiro[linhaH][colunaH + i] != 0){
        printf ("Erro: Sobreposição detectada no navio horizontal.\n");
        return 1;
    }
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
}

//Posicionando Navio Vertical

for (int i = 0; i <Tam_Navio; i++){

    //Verifica Sobreposição
    if (tabuleiro[linhaV + i][colunaV] != 0){
        printf ("Erro: Sobreposição detectada no navio vertical.\n");
        return 1;
    }
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
}

//Exibindo o tabuleiro

printf ("\n Tabuleiro Batalha Naval - Nível Novato\n\n");
    for(int i = 0; i < tam; i++){
        for (int j= 0; j<tam; j++){
            printf ("%d", tabuleiro[i][j]);
        }
        printf ("\n");
    }

    return 0;
}
