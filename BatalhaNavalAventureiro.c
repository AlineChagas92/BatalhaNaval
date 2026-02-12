#include <stdio.h>
#define TAM 10
#define TAM_NAVIO 3

int main (){

    // Declaração de tabuleiro
    int tabuleiro[TAM][TAM];
    //Inicializando o tabuleiro com 0 (Água)
    for (int i = 0; i < TAM; i++){
        for (int j = 0; j < TAM; j++){
            tabuleiro[i][j] = 0;
        }
    }

    //Declaração dos Navios
    int navio [TAM_NAVIO] = {3, 3, 3};

    //Coordenadas iniciais 
    //Horizontal
    int linhaH = 1, colunaH = 1;
    //Vertical
    int linhaV = 4, colunaV = 2;
    //Diagonal Principal
    int linhaD1 = 0, colunaD1 = 6;
    //Diagonal Secundária
    int linhaD2 = 6, colunaD2 = 7;

    //Validação de limites
    if (colunaH + TAM_NAVIO > TAM){
        printf ("Erro: Navio horizontal ultrapassa os limites. \n");
        return 1;
    }
    if (linhaV + TAM_NAVIO > TAM){
        printf ("Erro: Navio vertical ultrapassa os limites \n");
        return 1;
    }
    if (linhaD1 + TAM_NAVIO > TAM || colunaD1 + TAM_NAVIO > TAM){
        printf ("Erro: Navio diagonal principal ultrapassa os limites \n");
        return 1;
    }
    if (linhaD2 - (TAM_NAVIO -1) <0 || colunaD2 + (TAM_NAVIO -1) > TAM -1){
        printf ("Erro: Navio diagonal secundaria ultrapassa os limites \n");
        return 1;
    }

    //Posicionando Navio Horizontal
    for (int i = 0; i <TAM_NAVIO; i++){
        if (tabuleiro[linhaH][colunaH+i] != 0){
            printf ("Erro: Sobreposição detectada no navio horizontal.\n");
            return 1;
        }
        tabuleiro[linhaH][colunaH + i] = navio[i];
    }

    //Posicionando Navio Vertical
    for (int i = 0; i <TAM_NAVIO; i++){
        if (tabuleiro[linhaV + i][colunaV] != 0){
            printf ("Erro: Sobreposição detectada no navio vertical.\n");
            return 1;
        }
        tabuleiro[linhaV + i][colunaV] = navio[i];
    }

    //Posicionando Navio Diagonal Principal
    for (int i = 0; i <TAM_NAVIO; i++){
        if (tabuleiro[linhaD1 + i][colunaD1 + i] != 0){
            printf ("Erro: Sobreposição detectada no navio diagonal principal.\n");
            return 1;
        }
        tabuleiro[linhaD1 + i][colunaD1 + i] = navio[i];
    }

    //Posicionando Navio Diagonal Secundária
    for (int i = 0; i <TAM_NAVIO; i++){
        if (tabuleiro[linhaD2 - i][colunaD2 + i]
            != 0){
            printf ("Erro: Sobreposição detectada no navio diagonal secundaria.\n");
            return 1;
        }
        tabuleiro[linhaD2 - i][colunaD2 + i] = navio[i];

    }
    //Exibindo o tabuleiro
    printf ("Tabuleiro - Aventureiro:\n");
    for (int i = 0; i < TAM; i++){
        for (int j = 0; j < TAM; j++){
            printf ("%2d ", tabuleiro[i][j]);
        }
        printf ("\n");
    }
return 0;
}

