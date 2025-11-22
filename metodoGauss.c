#include "metodoGauss.h"



//fazer retornar um vetor de float com os valores em ordem das soluções
float* metodoGauss(float *matriz, int num_colunas, int num_linhas, boolean detalhes){  //faz uma conversão da matriz para ponteiro float ao chamar a função

    //calculo a quntidade de pivores
    int num_pivo = num_colunas-2;
    int linha_pivo = 0;             //primeiro pivô sempre está na linha 1 da coluna 1
    int coluna_pivo = 0;

    for (int k =1; k<= num_pivo; k++){ //percorro cada coluna separadamente para zerar de acordo com o pivô

        //percorro a linha toda utilizando a regra
        for(int i = linha_pivo+1; i< num_linhas; i++){     //escalonamento
            float m = (matriz[i*num_colunas + coluna_pivo]/matriz[linha_pivo*num_colunas + coluna_pivo]);
            for(int j = 0; j< num_colunas; j ++){
                matriz[i*num_colunas + j] = matriz[i*num_colunas + j] - (matriz[linha_pivo*num_colunas + j] * m);
            };
        };

        linha_pivo = linha_pivo+1;
        coluna_pivo = linha_pivo;
    };

    if(detalhes){
        printf("\nMatriz encontrada:\n");
        for(int i = 0; i<num_linhas; i ++){
            for(int j=0; j<num_colunas;j++){
                printf("%8.2f", matriz[i*num_colunas + j]);
            };
            printf("\n");
        };
    };


    //encontra os valores
    float* solucao = (float *) malloc ((num_colunas-1)*sizeof(float));

    for(int i = num_linhas-1;i>=0; i--){
        float soma = 0;
        for(int j = num_colunas-2; j>=0;j--){
            if(matriz[i*num_colunas + j]==0 && i==j)
                continue;
            if(i==num_linhas-1)
                soma = matriz[i*num_colunas + j];
            else
                soma = soma + matriz[i*num_colunas +j]*solucao[j];
        };
        solucao[i] = (matriz[i*num_colunas + num_colunas-1]-soma)/matriz[i*num_colunas + i]; //- soma porque troca o sinal
    };

    if(detalhes){
        printf("\nA solução encontrada foi: ");
        //int a = 'a';
        for(int i =0; i<num_colunas-1;i++){
            printf("%8.2f | ",solucao[i]);
        };
    };



    return solucao;

};

void executaMetodoGauss(){

    int num_colunas = 0;
    int num_linhas = 0;
    int num_equacoes = 0;
    int num_incognitas = 0;

    char dados_certos = 'n';

    while(dados_certos != 's' && dados_certos!='S'){
        printf("\nDigite o número de equações: ");
        scanf("%d", &num_equacoes);
        setbuf(stdin,NULL);
        printf("Digite o número de incógnitas: ");
        scanf("%d", &num_incognitas);
        setbuf(stdin,NULL);
        printf("\nOs dados informados foram: \n\tNúmero de equações: %d \tNúmero de incógnitas: %d", num_equacoes, num_incognitas);
        printf("\nEstá correto? Digite 'S' para sim e 'N' para não: ");
        scanf("%c", &dados_certos);
        setbuf(stdin,NULL);

    };

    dados_certos = 'n';

    num_linhas = num_equacoes;
    num_colunas = num_incognitas +1;

    float matriz[num_linhas][num_colunas];

    while(dados_certos != 's' && dados_certos!='S'){

        for(int i = 0; i < num_linhas; i++){

            printf("\n\tInfome os dados da equação %d\n", i);

            for(int j = 0; j < num_colunas; j++){
                if(j==num_colunas-1)
                    printf("Resultado: ");
                else
                    printf("Coeficiente %d: ", j+1);
                scanf("%f", &matriz[i][j]);
                setbuf(stdin,NULL);
            };
        };

        LIMPA_TELA;

        printf("O sistema informado é: ");

        int a = 'a';

        for(int i = 0; i< num_linhas; i ++){
            printf("\n\t");
          for(int j = 0; j< num_colunas; j ++){
            if(j==num_colunas-1)
                printf("= %8.2f\n",matriz[i][j]);
            else
                printf("%8.2f%c ", matriz[i][j], a);
            a+=1;
          };
          a='a';
        };

        printf("\nEstá correto? Digite 'S' para sim e 'N' para não: ");
        scanf("%c", &dados_certos);
        setbuf(stdin,NULL);

    };

        //executa o método
    metodoGauss((float *)matriz, num_colunas, num_linhas, 1);

};
