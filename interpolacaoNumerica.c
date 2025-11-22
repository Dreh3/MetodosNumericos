#include "interpolacaoNumerica.h"

float g1_linear(float x){
    return 1;
}

float g2_linear(float x){
    return x;
}

void executarInterpolacaoNumericaLinear(){

    //float matrizNormal[2][3];
    char dados_certos = 'n';
    int num_pontos;

    //Solicitação de dados ao usuário
    while(dados_certos != 's' && dados_certos != 'S'){
        printf("\nDigite o número de pares ordenados: ");
        scanf("%d", &num_pontos);
        setbuf(stdin,NULL);
        printf("\n\nDados informados:\n\t Número de pontos: %d", num_pontos);
        printf("\nEstá correto? Digite 'S' para sim e 'N' para não: ");
        scanf("%c", &dados_certos);
        setbuf(stdin,NULL);
    };

    PONTOS_ pontos[num_pontos];

    dados_certos = 'n';

    while(dados_certos != 's' && dados_certos != 'S'){
        for(int j = 0; j<num_pontos; j++){
            printf("\n\tx%d: ", j+1);
            scanf("%f", &pontos[j].ponto_x);
            setbuf(stdin,NULL);
            printf("\ty%d: ", j+1);
            scanf("%f", &pontos[j].ponto_y);
            setbuf(stdin,NULL);
        };

        printf("\n\n\tOs pares ordenados são:");

        //imprime x
        printf("\n x |");
        for(int j=0; j<num_pontos; j++){
          printf(" %8.4f |", pontos[j].ponto_x);
        };
        //imprime y
        printf("\n y |");
        for(int j=0; j<num_pontos; j++){
          printf(" %8.4f |", pontos[j].ponto_y);
        };

        printf("\nEstá correto? Digite 'S' para sim e 'N' para não: ");
        scanf("%c", &dados_certos);
        setbuf(stdin,NULL);
    };

    float matriz[2][3];
    float soma_g1_g1 = num_pontos;
    float soma_g1_g2 = 0;
    float soma_g2_g2 = 0;
    float soma_g1_y = 0;
    float soma_g2_y = 0;

    //construir matriz normal para função linear
    //somatório de g1 x g1
    for(int i = 0; i < num_pontos; i ++){
        soma_g2_g2 = soma_g2_g2 + g2_linear(pontos[i].ponto_x)*g2_linear(pontos[i].ponto_x);
        soma_g1_g2 = soma_g1_g2 + g1_linear(pontos[i].ponto_x)*g2_linear(pontos[i].ponto_x);
        soma_g1_y = soma_g1_y + g1_linear(pontos[i].ponto_x)*pontos[i].ponto_y;
        soma_g2_y = soma_g2_y + g2_linear(pontos[i].ponto_x)*pontos[i].ponto_y;
    };

    //escrevendo na matriz normal
    matriz[1][0] = matriz[0][1] = soma_g1_g2;
    matriz[0][0] = soma_g1_g1;
    matriz[1][1] = soma_g2_g2;
    matriz[1][2] = soma_g2_y;
    matriz[0][2] = soma_g1_y;

    float *solucao = metodoGauss((float *) matriz, 3, 2, 0);

    printf("\nA solução encontrada foi: \n\tg(x) = %8.4f + %8.4fx", solucao[0],solucao[1]);

};
