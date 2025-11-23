#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//#include "integracaoNumerica.h"
//#include "metodoGauss.h"
#include "interpolacaoNumerica.h"


int main()
{

    //Habilitar caracteres especiais
    SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int op=1;

    while(op!=0){
            printf("\n\t\t\t\t\tMENU\n");
            printf("\n\t\t1 - Métodos diretos para Sistemas de Equações Lineares\n\t\t2 - Métodos iterativos para Sistemas de Equações Lineares");
            printf("\n\t\t3 - Interpolação Polinomial por Mínimos Quadrados\n\t\t4 - Integração Numérica\n\t\t0 - Encerrar\n\n\tSelecione o método que deseja utilizar: ");
            scanf("%d", &op);
            setbuf(stdin,NULL);

            LIMPA_TELA;

            //limpar tela aqui
            switch (op){
            case 1:
                printf("\n\tVocê selecionou a opção 1: Métodos diretos para Sistemas de Equações Lineares\n");
                executaMetodoGauss();
                break;
            case 2:
                printf("\n\tVocê selecionou a opção 2: Métodos iterativos para Sistemas de Equações Lineares\n");
                break;
            case 3:
                printf("\n\tVocê selecionou a opção 3: Interpolação Polinomial por Mínimos Quadrados\n");
                executarInterpolacaoNumerica();
                break;
            case 4:
                printf("\n\tVocê selecionou a opção 4: Integração Numérica\n");
                executarMetodoIntegracaoNumerica();
                break;
            case 0:
                printf("\n\tEncerrando\n");
                break;
            default:
                printf("\n\t ALERTA: Opção inexistente");
                break;
            };

//            printf("\n\t\t\t\t\tMENU\n");
//            printf("\n\t\t1 - Métodos diretos para Sistemas de Equações Lineares\n\t\t2 - Métodos iterativos para Sistemas de Equações Lineares");
//            printf("\n\t\t3 - Interpolação Polinomial por Mínimos Quadrados\n\t\t4 - Integração Numérica\n\n\tSelecione o método que deseja utilizar: ");
//            scanf("%d", &op);
//            setbuf(stdin,NULL);
            //limpa tela aqui
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
