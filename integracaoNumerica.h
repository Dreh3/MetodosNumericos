#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <windows.h>

//Para poder limpar a tela
#ifdef _WIN32 // Verifica se o sistema é Windows
    #define LIMPA_TELA system("cls");
#else // Para outros sistemas (Linux, macOS, etc.)
    #define LIMPA_TELA system("clear");
#endif

//struct para salvar os dados dos pontos
typedef struct PONTOS{
    float ponto_x; //abcissa
    float ponto_y; //ordenada
}PONTOS_;

float regraDosTrapeziosRepetida(int num_pontos, PONTOS_ pontos[]);
float regraSimpsonRepetida(int num_pontos, PONTOS_ pontos[]);
void executarMetodoIntegracaoNumerica(void);
