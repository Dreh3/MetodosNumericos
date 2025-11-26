#include "interpolacaoNumerica.h"

//Funções para a aproximação exponencial
float g_log(int k, float x){
    if(k==0)
        return 1;
    else
        return x;
};

//Funções para as aproximações: linear e parábola
float g_aproximacao(float expoente, float x){
    return pow(x,expoente);                     //1 = x^0; x = x^1 ...
};


            //Funções para possibilitar calcular valores aproximados a partir de entrada do usuário

//Formato da função linear aproximada
float aproximacao_linear(float a, float b, float x){
    return (a*x + b);
};

////Formato da função quadrática aproximada
float aproximacao_parabola(float a, float b, float c, float x){
    return (a*pow(x,2) + b*x + c);
};

//Formato da função expoencial aproximada
double aproximacao_exponencial(float a1, float a2, float x){ //log 10
    return (pow(10, a2 + a1*x));
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

    PONTOS_ pontos[num_pontos];                         //Cria vetor de POINT_ com base nos dados do usuário

    dados_certos = 'n';

    //Solicita os pares de dados ao usuário
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

    //Define os dados básicos de acordo com o tipo de aproximação
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

    //Dados para executar o método
    float r, s;
    float matriz[num_linhas][num_colunas];

    //Inicializa a matriz com zeros
    for (int i = 0; i < num_linhas; i++)
    {
        for (int j = 0; j < num_colunas; j++)
            matriz[i][j] = 0;
    };

    //Executa o método
    for (int k = 0; k < num_pontos; k++)
    {
        for (int i = 0; i < num_coeficientes; i++)
        {
            //Para a exponencial é necessário utilizar uma função específica com log
            if(tipo == 3){
                r = g_log(i, pontos[k].ponto_x);
                matriz[i][num_colunas-1] += r * log10f(pontos[k].ponto_y);
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
                matriz[i][j] += r * s;                              //Salva o dado na matriz
            };
        };
    };


        //Executa o método de Gauss para resolver o sistema
        float *solucao = metodoGauss((float *) matriz, num_colunas, num_linhas, 0);

        //Exibe a solução e a função aproximada
        if(tipo == 3){
             printf("\nCoeficiente encontrados: \n\ta1 = %8.4f e a2 = %8.4f", solucao[1],solucao[0]);
             printf("\nA solução final: \n\tg(x) = (10 ^ %8.4f) * (%8.4f ^ x)", solucao[0],pow(10,solucao[1]));
        }else{
            printf("\nA solução encontrada foi: \n\tg(x) = %8.4f %c %8.4fx",solucao[0],solucao[1]>0?'+':' ',solucao[1]);
            if(num_coeficientes==3){
                printf(" %c %8.4fx^2",solucao[2]>0?'+':' ', solucao[2]);
            };
        };

        char utilizar_funcao = 'n';

        //Pergunta ao usuário se ele gostaria de utilizar a função encontrada para testar novos valores
        printf("\nDeseja simular um ponto? Digite 'S' para sim e 'N' para não: ");
        scanf("%c", &utilizar_funcao);
        setbuf(stdin,NULL);
        //float y_aproximado = 0;
        float x=0;
        while(utilizar_funcao=='s' || utilizar_funcao=='S'){
            printf("\nDigite o valor de x: ");
            scanf("%f", &x);
            setbuf(stdin,NULL);

            //Exibe o resutado da função
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
