#include <stdio.h>
#include <stdlib.h>
#include "integracaoNumerica.h"

int main()
{
    int op=0;


    while(op!=0){
            printf("\t\t\t\nMENU\n\tSelecione o método que deseja utilizar");
            printf("\n\t\t1 - Métodos diretos para Sistemas de Equações Lineares\n\t\t2 - Métodos iterativos para Sistemas de Equações Lineares");
            printf("\n\t\t3 - Interpolação Polinomial por Mínimos Quadrados\n\t4 - Integração Numérica");
            scanf("%d", &op);
            switch (op){
            case 1:
                printf("\n\tVocê selecionou a opção 1: Métodos diretos para Sistemas de Equações Lineares\n");
                break;
            case 2:
                printf("\n\tVocê selecionou a opção 2: Métodos iterativos para Sistemas de Equações Lineares\n");
                break;
            case 3:
                printf("\n\tVocê selecionou a opção 3: Interpolação Polinomial por Mínimos Quadrados\n");
                break;
            case 4:
                printf("\n\tVocê selecionou a opção 4: Integração Numérica\n");

                break;
            default:
                break;
            }
    };


    return 0;
}


//    POINTS pares_ordenados[7];
//    pares_ordenados[0].ponto_x = 3.0;
//    pares_ordenados[1].ponto_x = 3.1;
//    pares_ordenados[2].ponto_x = 3.2;
//    pares_ordenados[3].ponto_x = 3.3;
//    pares_ordenados[4].ponto_x = 3.4;
//    pares_ordenados[5].ponto_x = 3.5;
//    pares_ordenados[6].ponto_x = 3.6;
//    pares_ordenados[0].ponto_y = 0.3333;
//    pares_ordenados[1].ponto_y = 0.3225;
//    pares_ordenados[2].ponto_y = 0.3135;
//    pares_ordenados[3].ponto_y = 0.3030;
//    pares_ordenados[4].ponto_y = 0.2941;
//    pares_ordenados[5].ponto_y = 0.2857;
//    pares_ordenados[6].ponto_y = 0.2778;
//
//    float resultadoRT = regraDosTrapeziosRepetida2(7, pares_ordenados);
//    printf("O valor encontrado foi %f\n", resultadoRT);
//    resultadoRT = regraSimpsonRepetida2(7, pares_ordenados);
//    printf("\nO valor encontrado em Simpson foi %f", resultadoRT);
