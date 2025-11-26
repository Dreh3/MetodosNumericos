#include "integracaoNumerica.h"

//implemeenta a Regra dos Trapézios Repetida
float regraDosTrapeziosRepetida(int num_pontos, PONTOS_ pontos[]){
    float soma_areas=0;             //Inicializa o valor final em 0
    //int contador = num_pontos;
    float somas =0;                 //Inicializa soma das áreas dos trpézios em 0
    float h = (pontos[1].ponto_x-pontos[0].ponto_x);               //supondo igualmente espaçado

    //Itera para calcular a área correpondente de cada intervalo
    for(int i = 1; i<num_pontos-1; i ++){
        //float h = (pontos[i+1]->ponto_x-pontos[i]->ponto_x); //supondo espaçado irregularmente
        somas = pontos[i].ponto_y + somas;
    };

    //Realiza o cálculo da área resultante
    soma_areas = (h/2)*(pontos[0].ponto_y + 2 *somas + pontos[num_pontos-1].ponto_y);
    return soma_areas;              //Retorna o valor calculado
};


float regraSimpsonRepetida(int num_pontos, PONTOS_ pontos[]){

    float soma_areas=0;
    if(num_pontos%2==0){                //Para garantir números de intervalos pares
        num_pontos=num_pontos-1;        //subtrae-se um intervalo
    };

    float h = (pontos[1].ponto_x-pontos[0].ponto_x); //supondo igualmente espaçado (Regra)

    //Salva o valor de: f(xo) + f(xm)
    float parcela1 = (pontos[0].ponto_y + pontos[num_pontos-1].ponto_y);

    float parcela2=0;       //Variável para salvar os valores dos índices ímpares
    float parcela3=0;       //Variável para salvar os valores dos índices pares

        for(int i = 1; i<num_pontos-1; i ++){
            if(i%2!=0 ){ // ímpares
              parcela2 = parcela2 + pontos[i].ponto_y;
            }else{ // pares
              parcela3 = parcela3 + pontos[i].ponto_y;
            };
        };

    //Realiza o cálculo final da área resultante
    soma_areas = (h/3) * (parcela1 + 4*parcela2 + 2* parcela3);

    return soma_areas;          //Retorna o valor calculado

};

void executarMetodoIntegracaoNumerica(){

    //Variáveis para dados inseridos pelo usuário
    float inicio_intervalo=0;
    float final_intervalo=0;
    int num_funcoes=0;
    int num_pontos=0;
    PONTOS_ *pontos = NULL;

    //Variável controle para permitir corrigir dados inseridos incorretamente
    char dados_certos = 'n';

    //printf("Iniciando execucao dos metodos de integracao numérica...\n");

    //Solicita ao usuário os dados de intervalo
    while(dados_certos != 's' && dados_certos != 'S'){
          printf("\nDigite o valor inicial do intervalo: ");
          scanf("%f", &inicio_intervalo);
          setbuf(stdin,NULL);
          printf("\nDigite o valor final do intervalo: ");
          scanf("%f", &final_intervalo);
          setbuf(stdin,NULL);
          printf("\n\nO intervalo informado foi [%.2f, %.2f]", inicio_intervalo, final_intervalo);
          printf("\nEstá correto? Digite 'S' para sim e 'N' para não: ");
          scanf("%c", &dados_certos);
          setbuf(stdin,NULL);
    };

    dados_certos = 'n';

    //Solicita ao usuário os dados gerais do problema
    while(dados_certos != 's' && dados_certos != 'S'){
          printf("\nDigite o número de funções: ");
          scanf("%d", &num_funcoes);
          setbuf(stdin,NULL);
          printf("\nDigite o número de pares ordenados: ");
          scanf("%d", &num_pontos);
          setbuf(stdin,NULL);
          printf("\n\nDados informados:\n\t Número de funções: %d\t Número de pontos: %d", num_funcoes, num_pontos);
          printf("\nEstá correto? Digite 'S' para sim e 'N' para não: ");
          scanf("%c", &dados_certos);
          setbuf(stdin,NULL);
    };

    dados_certos = 'n';

    if(num_funcoes>1){
      printf("\n\t AVISO: Informe as funções em ordem, sendo a mais externa primeiro");
    };

    float area_funcao_principal_RS = 0;             //Variáveis para armazenar dados a serem calculados
    float area_funcoes_secundarias_RS = 0;
    float area_funcao_principal_RT = 0;
    float area_funcoes_secundarias_RT = 0;

    //Solicita ao usuário os pares de pontos
    for(int i = 1; i<=num_funcoes; i++){

        //aloca os pontos para a função
        pontos = (PONTOS_ *) malloc (num_pontos*sizeof(PONTOS_));

        printf("\n\tInforme os pares ordenados da função %d\n", i);

        while(dados_certos != 's' && dados_certos != 'S'){
            for(int j = 0; j<num_pontos; j++){
                printf("\n\tx%d: ", j+1);
                scanf("%f", &pontos[j].ponto_x);
                setbuf(stdin,NULL);
                printf("\ty%d: ", j+1);
                scanf("%f", &pontos[j].ponto_y);
                setbuf(stdin,NULL);
            };

            //Exibe dados para conferência
            printf("\n\n\tOs pares ordenados da função %d são:", i);

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

        dados_certos = 'n';

        //chama o método e passa os dados salvando em uma variável inicial
        if(i==1){   //significa que é a função mais externa
            area_funcao_principal_RT = regraDosTrapeziosRepetida(num_pontos, pontos);
            area_funcao_principal_RS = regraSimpsonRepetida(num_pontos,pontos);
            //printf("\nArea principal: Regra Trapezios: %f Regra Simpson: %f", area_funcao_principal_RT,area_funcao_principal_RS );
        }else{
            //acumula os valores de áreas das funções internas
            area_funcoes_secundarias_RT = regraDosTrapeziosRepetida(num_pontos, pontos);

            area_funcoes_secundarias_RS = regraSimpsonRepetida(num_pontos, pontos);
            //printf("\nRS : %f", area_funcoes_secundarias_RS);
        };
        printf("\nArea secundaria %d: Regra Trapezios: %f Regra Simpson: %f", i,area_funcoes_secundarias_RT,area_funcoes_secundarias_RS );
        area_funcao_principal_RT = area_funcao_principal_RT - area_funcoes_secundarias_RT;
        area_funcao_principal_RS = area_funcao_principal_RS - area_funcoes_secundarias_RS;

        free(pontos);   //libera o espaço para os novos dados
    };

    //exibe o valor calculado
    printf("\n\t\t\tÁrea encontrada\n\tRegra dos trapézios: %f\n\tRegra de Simpson: %f",area_funcao_principal_RT, area_funcao_principal_RS);

};
