#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define TAM_HAB 5

int main (){

    int tabuleiro [TAM][TAM];

//Inicializa Tabuleiro
    for (int i = 0; i < TAM; i++){
        for(int j = 0; j< TAM; j++){
    tabuleiro [i][j] = 0;
        }
    }

    //Matrizes de Habilidade
    int cone [TAM_HAB][TAM_HAB];
    int cruz [TAM_HAB][TAM_HAB];
    int octaedro [TAM_HAB][TAM_HAB];

    int centro = TAM_HAB / 2;

    //Construção dinâmica das habilidades
    for (int i = 0; i < TAM_HAB; i++){
        for (int j = 0; j < TAM_HAB; j++){
            
            //Cone (Expande para baixo)
        if (j >= centro - i && j <= centro + i)
            cone [i][j] = 1;
        else
        cone [i][j] = 0;
        
            //Cruz
        if (i == centro || j == centro)
            cruz [i][j] = 1;
        else 
            cruz [i][j] = 0;     

            //Octaedro
        if (abs(i-centro)+ abs(j-centro)  <=centro)
        octaedro [i][j] = 1;
        else 
        octaedro [i][j] = 0;            
        }
    }

    //Pontos de Origem

    int origemConeLinha = 2, origemConeColuna = 2;
    int origemCruzLinha = 6, origemCruzColuna = 2;
    int origemOctLinha = 6, origemOctoColuna = 7;

    //Sobreposição de habilidades
    for (int i = 0; i < TAM_HAB; i++){
        for (int j=0; j < TAM_HAB; j++){

            int linhaTab = origemConeLinha - centro + i;
            int colunaTab = origemConeColuna - centro + j;

            if (linhaTab >= 0 && linhaTab < TAM &&
            colunaTab >= 0 && colunaTab < TAM &&
            cone [i][j] == 1) {
                tabuleiro [linhaTab][colunaTab] = 5;              
                }
            }
        }

        for (int i = 0; i < TAM_HAB; i++){
        for (int j=0; j < TAM_HAB; j++){

            int linhaTab = origemCruzLinha - centro + i;
            int colunaTab = origemCruzColuna - centro + j;

            if (linhaTab >= 0 && linhaTab < TAM &&
                colunaTab >= 0 && colunaTab < TAM &&
                cruz[i][j] == 1){
                    tabuleiro [linhaTab][colunaTab] = 5;
                }
            }
        }

        for (int i = 0; i < TAM_HAB; i++){
        for (int j = 0; j < TAM_HAB; j++){

            int linhaTab = origemOctLinha - centro + i;
            int colunaTab = origemOctoColuna - centro + j;

            if (linhaTab >= 0 && linhaTab < TAM &&
                colunaTab >= 0 && colunaTab < TAM &&
                octaedro[i][j] == 1){
                    tabuleiro [linhaTab][colunaTab] = 5;
                }
            }
        }
//Exibição Visual

printf ("\nTabuleiro - Nivel Mestre\n\n");

for (int i = 0; i < TAM; i++){
    for (int j = 0; j < TAM; j++){

        if (tabuleiro[i][j] == 0)
        printf ("~ ");
        else if (tabuleiro [i][j] == 5)
        printf ("* ");
        else 
        printf("3 ");
    }
        printf ("\n");

    } 


    return 0;
}