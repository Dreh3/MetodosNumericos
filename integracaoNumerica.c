#include <stdio.h>
#include <string.h>
#include "integracaoNumerica.h"
//função para solicitar dados - será que deveria vai ser chato usando ponteiros para alocar espaço

/*
-- tem que fazer o método separado e passar os pontos por parâmetro

1° pede o número de funções- começando pela mais exterior - para gerar um laço que vai pedindo os pontos
antes disso, intervalo, n° de pontos (aloco o espaço do vetor com base nisso), vetor para salvar área de funções em ordem
2° ao final subtrair todos as áreas seguintes da área inicial

--exibir dados dos diferentes métodos

//colocar verificação de dados a cada conjunto de pontos para a pessoa pode repetir

//devo implementar validação para não encerrar o programa caso o tipo de dado inserido esteja incorreto?

if(scanf()!=1){
    printf("\nAlgum dado foi inserido incorretamente. Por favor, informe os dados novamente.");
    continue;
}

*/

float regraDosTrapeziosRepetida(int num_pontos, POINTS *pontos[]){
    float soma_areas=0;
    //int contador = num_pontos;
    float somas =0;
    float h = (pontos[1]->ponto_x-pontos[0]->ponto_x); //supondo igualmente espaçado
        for(int i = 1; i<num_pontos-1; i ++){
            //float h = (pontos[i+1]->ponto_x-pontos[i]->ponto_x); //supondo espaçado irregularmente
            somas = pontos[i]->ponto_y + somas;
        };
    printf("h = %f", h);
    printf("y0 = %f", pontos[0]->ponto_y);
    soma_areas = h/2*(pontos[0]->ponto_y + 2 *somas + pontos[num_pontos-1]->ponto_y);
    return soma_areas;
};

//versão correta - no teste ficou: 0.182435
float regraDosTrapeziosRepetida2(int num_pontos, POINTS pontos[]){
    float soma_areas=0;
    //int contador = num_pontos;
    float somas =0;
    float h = (pontos[1].ponto_x-pontos[0].ponto_x); //supondo igualmente espaçado
        for(int i = 1; i<num_pontos-1; i ++){
            //float h = (pontos[i+1]->ponto_x-pontos[i]->ponto_x); //supondo espaçado irregularmente
            somas = pontos[i].ponto_y + somas;
        };
    printf("h = %f", h);
    printf("y0 = %f", pontos[0].ponto_y);
    soma_areas = h/2*(pontos[0].ponto_y + 2 *somas + pontos[num_pontos-1].ponto_y);
    return soma_areas;
};


float regraSimpsonRepetida(int num_pontos, POINTS *pontos[]){

    float soma_areas=0;
    if(num_pontos%2==0){                //Para garantir números de intervalos pares
        int contador = num_pontos-1;
        num_pontos=num_pontos-1;
    }else{
        int contador = num_pontos;
    };

    float h = (pontos[1]->ponto_x-pontos[0]->ponto_x); //supondo igualmente espaçado

    //f(xo) + f(xm)
    float parcela1 = (pontos[0]->ponto_y - pontos[num_pontos-1]->ponto_y);

    float parcela2=0;
    float parcela3=0;

        for(int i = 0; i<num_pontos; i ++){
            //float h = (pontos[i+1]->ponto_x-pontos[i]->ponto_x); //supondo espaçado irregularmente
            //parcela 2
            if(i%2!=0 && i<num_pontos-1){
              parcela2 = parcela2 + pontos[i]->ponto_y;
            }else if (i%2==0 && i<num_pontos-2){
              parcela3 = parcela3 + pontos[i]->ponto_y;
            };
        };

    soma_areas = h/3* (parcela1 + 4*parcela2 + 2* parcela3);

    return soma_areas;

};


//certo no testo ficou : 0.182370
float regraSimpsonRepetida2(int num_pontos, POINTS pontos[]){
    float soma_areas=0;
    if(num_pontos%2==0){                //Para garantir números de intervalos pares
        int contador = num_pontos-1;
        num_pontos=num_pontos-1;
    }else{
        int contador = num_pontos;
    };

    float h = (pontos[1].ponto_x-pontos[0].ponto_x); //supondo igualmente espaçado

    //f(xo) + f(xm)
    float parcela1 = (pontos[0].ponto_y - pontos[num_pontos-1].ponto_y);

    float parcela2=0;
    float parcela3=0;

        for(int i = 0; i<num_pontos; i ++){
            //float h = (pontos[i+1]->ponto_x-pontos[i]->ponto_x); //supondo espaçado irregularmente
            //parcela 2
            if(i%2!=0){                                 //índices ímpares
              parcela2 = parcela2 + pontos[i].ponto_y;
            }else if (i%2==0 && i !=0){                 //índices pares
              parcela3 = parcela3 + pontos[i].ponto_y;
            };
        };

    soma_areas = h/3* (parcela1 + 4*parcela2 + 2* parcela3);

    return soma_areas;

};

void executarMetodoIntegracaoNumerica(){

    //Variáveis para dados inseridos pelo usuário
    float inicio_intervalo;
    float final_intervalo;
    int num_funcoes;
    int num_pontos;
    POINTS *pontos;

    //Variável controle para permitir corrigir dados inseridos incorretamente
    char erro_dado = 'n';

    //printf("Iniciando execucao dos metodos de integracao numérica...\n");

    //Solicita ao usuário os dados de intervalo
    while(erro_dado != 's' || erro_dado != 'S'){
          printf("\nDigite o valor inicial do intervalo: ");
          scanf("%f", &inicio_intervalo);
          printf("\nDigite o valor final do intervalo: ");
          scanf("%f", &inicio_intervalo);
          printf("\n\nO intervalo informado foi [%.2f, %.2f]", inicio_intervalo, final_intervalo);
          printf("\nEstá correto? Digite 'S' para sim e 'N' para não");
          scanf("%c", erro_dado);
    };

    erro_dado = 'n';

    //Solicita ao usuario os dados gerais do problema
    while(erro_dado != 's' || erro_dado != 'S'){
          printf("\nDigite o número de funções: ");
          scanf("%d", &num_funcoes);
          printf("\nDigite o número de pares ordenados: ");
          scanf("%d", &num_pontos);
          printf("\n\nDados informados:\n\t Número de funções: %d\t Número de pontos: %d", num_funcoes, num_pontos);
          printf("\nEstá correto? Digite 'S' para sim e 'N' para não");
          scanf("%c", erro_dado);
    };

    if(num_funcoes>1){
      printf("\n\t AVISO: Informe as funções em ordem, sendo a mais externa primeiro");
    };

    //Solicita ao usuario os pares de pontos
    for(int = 0; i<num_funcoes; i++){
        printf("\nInforme os pares ordenados da função %d", i);
        while(contador<= num_pontos){

        };
    };

      //mostrar dados para permitir correção
      printf("\nDigite o número de pontos: ");
      scanf("%f", &inicio_intervalo);




};
