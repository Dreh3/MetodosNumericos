#include "metodoGauss.h"



//retorna um ponteiro para vetor de float com os valores em ordem das soluções
float* metodoGauss(float *matriz, int num_colunas, int num_linhas, boolean detalhes){

    int num_pivo = num_colunas-2;   //cálculo da quantidade de pivores
    int linha_pivo = 0;             //inicializa os índices do primeiro pivô
    int coluna_pivo = 0;            //primeiro pivô sempre está na linha 0 da coluna 0

    for (int k =1; k<= num_pivo; k++){ //itera de acordo com a quantidades de pivores

        //percorre a linha toda utilizando a regra de Gauss
        for(int i = linha_pivo+1; i< num_linhas; i++){    //a contagem de linhas começa abaixo da linha do pivô
            //para cada linha calcula-se o termo da divisão
            float m = (matriz[i*num_colunas + coluna_pivo]/matriz[linha_pivo*num_colunas + coluna_pivo]);
            for(int j = 0; j< num_colunas; j ++){       //executa a regra para cada termo nas diferentes colunas da linha
                matriz[i*num_colunas + j] = matriz[i*num_colunas + j] - (matriz[linha_pivo*num_colunas + j] * m);
            };
        };

        //atualiza o índice do pivô
        linha_pivo = linha_pivo+1;
        coluna_pivo = linha_pivo;
    };

    if(detalhes){                           //Exibe a matriz encontrada após a execução do método
        printf("\nMatriz encontrada:\n");
        for(int i = 0; i<num_linhas; i ++){
            for(int j=0; j<num_colunas;j++){
                printf("%8.2f", matriz[i*num_colunas + j]);
            };
            printf("\n");
        };
    };


    //Aloca memória para o vetor de solução
    float* solucao = (float *) malloc ((num_colunas-1)*sizeof(float));

    for(int i = num_linhas-1;i>=0; i--){   //Pecorre cada linha de baixo para cima
        float soma = 0;                    //Inicializa acumulador de valores de termos já descobertos
        for(int j = num_colunas-2; j>=0;j--){           //Não considera a coluna dos termos independentes
            if(matriz[i*num_colunas + j]==0 && i==j)    //Se for um termo zerado ou estiver na diagonal principal
                continue;                               //não é considerado para a soma;
            if(i==num_linhas-1)
                soma = matriz[i*num_colunas + j];       //Se for a última linha, só será adicionado um termo à soma
            else
                soma = soma + matriz[i*num_colunas +j]*solucao[j];  //Soma os coeficentes multiplicados pelas incógnitas já descobertas
        };

        //Divide o termo independente pela soma para encontrar o valor de uma nova incógnita
        solucao[i] = (matriz[i*num_colunas + num_colunas-1]-soma)/matriz[i*num_colunas + i]; //- soma porque troca o sinal
    };

    if(detalhes){                               //Exibe a solução encontrada
        printf("\nA solução encontrada foi: ");
        //int a = 'a';
        for(int i =0; i<num_colunas-1;i++){
            printf("%8.2f | ",solucao[i]);
        };
    };

    return solucao;                         //Retorna o ponteiro

};

void executaMetodoGauss(){

    int num_colunas = 0;                //Variáveis para armazenar dados dos usuários
    int num_linhas = 0;
    int num_equacoes = 0;
    int num_incognitas = 0;

    char dados_certos = 'n';

    while(dados_certos != 's' && dados_certos!='S'){        //Solicitação de dados ao usuário
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

            printf("\n\tInfome os dados da equação %d\n", i);   //Lê os dados das equações

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

        printf("O sistema informado é: ");                      //Exibe o sistema informado para conferência

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


    metodoGauss((float *)matriz, num_colunas, num_linhas, 1);           //executa o método

};
