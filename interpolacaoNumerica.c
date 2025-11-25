#include "interpolacaoNumerica.h"

//float g1_log(float x){
//    return 1;
//};

float g_log(int k, float x){
    if(k==0)
        return 1;
    else
        return x;
};

float g_aproximacao(float expoente, float x){
    return pow(x,expoente);
};

float aproximacao_linear(float a, float b, float x){
    return (a*x + b);
};

float aproximacao_parabola(float a, float b, float c, float x){
    return (a*pow(x,2) + b*x + c);
};

double aproximacao_exponencial(float a1, float a2, float x){ //log 10
    return (pow(10, a2) * (pow(pow(10,a1),x)));
};


void executarInterpolacaoNumerica(){

    //float matrizNormal[2][3];
    char dados_certos = 'n';
    int num_pontos;
    int tipo;

    int num_coeficientes = 0;
    int num_linhas = 0;
    int num_colunas = 0;

    //Solicitação de dados ao usuário
    while(dados_certos != 's' && dados_certos != 'S'){
        printf("\n\n\t 1 - Linear\t2 - Parabólica\t3 - Exponencial\nSeleciona o tipo de aproximação: ");
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
            //int c;
            //setbuf(stdin,NULL);
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
                matriz[i][num_colunas-1] += r * log10(pontos[k].ponto_y);
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

        float *solucao = metodoGauss((float *) matriz, num_colunas, num_linhas, 0);

        if(tipo == 3){
             printf("\nCoeficiente encontrados: \n\ta1 = %8.4f e a2 = %8.4f", solucao[1],solucao[0]);
             printf("\nA solução final: \n\tg(x) = (10 ^ %8.4f) * (%8.4f ^ x)", pow(10,solucao[0]),pow(10,solucao[1]));
        }else{
            printf("\nA solução encontrada foi: \n\tg(x) = %8.4f %c %8.4fx",solucao[0],solucao[1]>0?'+':' ',solucao[1]);
            if(num_coeficientes==3){
                printf(" %c %8.4fx^2",solucao[2]>0?'+':' ', solucao[2]);
            };
        };

        char utilizar_funcao = 'n';

        printf("\nDeseja simular um ponto? Digite 'S' para sim e 'N' para não: ");
        scanf("%c", &utilizar_funcao);
        setbuf(stdin,NULL);
        //float y_aproximado = 0;
        float x=0;
        while(utilizar_funcao=='s' || utilizar_funcao=='S'){
            printf("\nDigite o valor de x: ");
            scanf("%f", &x);
            setbuf(stdin,NULL);
            switch (tipo){
                case 1:
                    printf("\nO valor de y encontrado foi: %8.4f",aproximacao_linear(solucao[1],solucao[0],x));
                    break;
                case 2:
                    printf("\nO valor de y encontrado foi: %8.4f",aproximacao_parabola(solucao[2],solucao[1],solucao[0],x));
                    break;
                case 3:
                    printf("\nO valor de y encontrado foi: %f",aproximacao_exponencial(solucao[1],solucao[0],x));
                    break;
                default:
                    break;

            };

            printf("\nDeseja continuar? Digite 'S' para sim e 'N' para não: ");
            scanf(" %c", &utilizar_funcao);
            setbuf(stdin,NULL);
        };

};
