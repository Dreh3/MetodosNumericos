#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//#include "integracaoNumerica.h"
//#include "metodoGauss.h"
#include "metodoGaussSiedel.h"


int main()
{

    //Habilitar caracteres especiais
    //SetConsoleOutputCP(CP_UTF8);
    setlocale(LC_ALL, "");

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
                executarMetodoGaussSiedel();
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
};
