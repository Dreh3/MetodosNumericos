#include "interpolacaoNumerica.h"

//float g1_log(float x){
//    return 1;
//};

float g_log(int k, float x){
    if(k==0)
        return 1;
    else
        return -x;
};

float g_aproximacao(float expoente, float x){
    return pow(x,expoente);
};

void executarInterpolacaoNumericaLinear(){

    //float matrizNormal[2][3];
    char dados_certos = 'n';
    int num_pontos;
    int tipo;

    int num_coeficientes = 0;
    int num_linhas = 0;
    int num_colunas = 0;

    //Solicitação de dados ao usuário
    while(dados_certos != 's' && dados_certos != 'S'){

        printf("\nSeleciona o tipo de aproximação:\n\t 1 - Linear\t2 - Parabólica\t3 - Exponencial\n\t-");
        scanf("%d", &tipo);
        setbuf(stdin,NULL);
        printf("\nDigite o número de pares ordenados: ");
        scanf("%d", &num_pontos);
        setbuf(stdin,NULL);
        //pedir o tipo de aproximação -- colocar um menu?
        printf("\n\nDados informados:\n\t Número de pontos: %d\tTipo de aproximação: %d", num_pontos, tipo);
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

    if(tipo==1 || tipo ==2 || tipo==3){
        switch(tipo){
        case 1:
            printf("\n\tAproximação linear");

            num_coeficientes = 2;
            num_linhas = 2;
            num_colunas = 3;
            break;
        case 2:
            printf("\n\tAproximação parabólica");
            num_coeficientes = 3;
            num_linhas = 3;
            num_colunas = 4;
            break;
        case 3:
            printf("\n\tAproximação exponencial");
            num_coeficientes = 2;
            num_linhas = 2;
            num_colunas = 3;
            break;
        default:
            break;
        };
        float r, s;
        float matriz[num_linhas][num_colunas];

        for (int i = 0; i < num_linhas; i++)
        {
            for (int j = 0; j < num_colunas; j++)
                matriz[i][j] = 0;
        };

        for (int k = 0; k < num_pontos; k++)
        {
            for (int i = 0; i < num_coeficientes; i++)
            {

                if(tipo == 3){
                    r = g_log(i, pontos[k].ponto_x);
                    matriz[i][num_colunas-1] += r * log(pontos[k].ponto_y);
                }else{
                    r = g_aproximacao(i, pontos[k].ponto_x);
                    matriz[i][num_colunas-1] += r * pontos[k].ponto_y;  //para os f(x)
                };
                for (int j = 0; j < num_coeficientes; j++)
                {
                    if(tipo == 3){
                        s = g_log(j, pontos[k].ponto_x);
                    }else{
                        s = g_aproximacao(j, pontos[k].ponto_x);
                    };
                    matriz[i][j] += r * s;
                };
            };
        };

        //devo reescrever a matriz pra ficar na formatação correta

        float *solucao = metodoGauss((float *) matriz, num_colunas, num_linhas, 1);

        if(tipo == 3){
             printf("\nA solução encontrada foi: \n\tg(x) = %8.4f * e ^ (%c%8.4f * x)", solucao[1],solucao[0]>0?'-':' ',solucao[0]);
        }else{
            printf("\nA solução encontrada foi: \n\tg(x) = %8.4f %c %8.4fx", solucao[0],solucao[1]>0?'+':' ',solucao[1]);
            if(num_coeficientes==3){
                printf(" %c %8.4fx^2",solucao[2]>0?'+':' ', solucao[2]);
            };
        };


    }else{
        printf("\n\tAproximação exponencial:");

    };

//            float soma_g1_g1 = num_pontos;
//            float soma_g1_g2 = 0;
//            float soma_g2_g2 = 0;
//            float soma_g1_y = 0;
//            float soma_g2_y = 0;
//
//            //construir matriz normal para função linear
//            //somatório de g1 x g1
//            for(int i = 0; i < num_pontos; i ++){
//                soma_g2_g2 = soma_g2_g2 + g2_linear(pontos[i].ponto_x)*g2_linear(pontos[i].ponto_x);
//                soma_g1_g2 = soma_g1_g2 + g1_linear(pontos[i].ponto_x)*g2_linear(pontos[i].ponto_x);
//                soma_g1_y = soma_g1_y + g1_linear(pontos[i].ponto_x)*pontos[i].ponto_y;
//                soma_g2_y = soma_g2_y + g2_linear(pontos[i].ponto_x)*pontos[i].ponto_y;
//            };
//
//            //escrevendo na matriz normal
//            matriz[1][0] = matriz[0][1] = soma_g1_g2;
//            matriz[0][0] = soma_g1_g1;
//            matriz[1][1] = soma_g2_g2;
//            matriz[1][2] = soma_g2_y;
//            matriz[0][2] = soma_g1_y;



     //teste

};
