#include "metodoGaussSiedel.h"

//Código desenvolvido por Maria Luísa

int N;
float A[30][30], B[30], X0[30], X1[30];
float Maxdif;

//lê o sistema A e B
void LeMatriz()
{
    int i, j;

    printf("Ordem do sistema (Obs: máximo é 30): ");
    scanf("%d", &N);
    setbuf(stdin,NULL);

    //printf("\nDigite cada linha com os %d coeficientes e o termo independente.\n", N);
    //printf("Exemplo: a11 a12 ... a1N b1\n\n");

    for(i = 0; i < N; i++){                 //Iteração para leitura dos dados
        printf("\n\tEquação %d:\n", i+1);
        for(j = 0; j < N; j++){
            printf("Coeficiente %d: ", j+1);
            scanf("%f", &A[i][j]);
            setbuf(stdin,NULL);
        }
        printf("Resultado: ");
        scanf("%f", &B[i]);
        setbuf(stdin,NULL); //limpar buffer antes da próxima linha
    };

};

//calcula max |X1 - X0|
float Maximo()
{
    int i;
    float d, m = 0;

    for(i = 0; i < N; i++){
        d = fabs(X1[i] - X0[i]);
        if(d > m) m = d;
    };
    return m;
};

// imprime vetor solução
void Imprime(float *X, int P)
{
    int i;
    printf("\nSolução encontrada:\n");
    for(i = 0; i < N; i++)
        printf("x(%d) = %10.6f\n", i+1, X[i]);
};

//realiza uma iteração do método
void Iteracao()
{
    int i, j;
    float soma;

    for(i = 0; i < N; i++){
        soma = B[i];

        for(j = 0; j < N; j++){
            if(j != i){
                if(j < i)
                    soma -= A[i][j] * X1[j];   // usa valor novo
                else
                    soma -= A[i][j] * X0[j];   // usa valor anterior
            }
        }

        X1[i] = soma / A[i][i];                //Salva novo valor de X1
    };
};



void executarMetodoGaussSiedel(){

    char dados_certos = 'n';

    //lê os dados
    while(dados_certos!='s' && dados_certos != 'S'){

        LeMatriz();                         //Função para leitura dos dados

        LIMPA_TELA;

        //imprime para conferência
        printf("O sistema informado é: ");
        int a = 'a';
        for(int i = 0; i< N; i ++){
            printf("\n\t");
            for(int j = 0; j< N; j ++){
                printf("%8.2f%c ", A[i][j], a);
                a+=1;
            };
            printf("= %8.2f", B[i]);
            a='a';
        };

        printf("\nOs dados informados estão corretos? Digite 'S' para sim e 'N' para não: ");
        scanf("%c", &dados_certos);
        setbuf(stdin,NULL);
    };


    //Execução do método
    int i,k=0;

    for(i=0;i<N;i++) X0[i]=0.0;

    //Imprime(X0,K,1);
    do {
        Iteracao();
        Maxdif = Maximo();
        for(i=0;i<N;i++)
        X0[i]=X1[i];
        k++;
    }while (Maxdif> 1.0e-3);

    Imprime(X1,0);              //Mostra a solução encontrada

};
