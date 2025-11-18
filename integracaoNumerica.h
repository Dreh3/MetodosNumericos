
//struct para salvar os dados dos pontos
typedef struct PONTOS{
    float ponto_x; //abcissa
    float ponto_y; //ordenada
}POINTS;

float regraDosTrapeziosRepetida(int num_pontos, POINTS pontos[]);
float regraDosTrapeziosRepetida2(int num_pontos, POINTS pontos[]);
float regraSimpsonRepetida(int num_pontos, POINTS pontos[]);
float regraSimpsonRepetida2(int num_pontos, POINTS pontos[]);
void executarMetodoIntegracaoNumerica(void);
