#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

//Para poder limpar a tela
#ifdef _WIN32 // Verifica se o sistema é Windows
    #define LIMPA_TELA system("cls");
#else // Para outros sistemas (Linux, macOS, etc.)
    #define LIMPA_TELA system("clear");
#endif

float* metodoGauss(float *matriz, int num_colunas, int num_linhas, boolean detalhes);
void executaMetodoGauss(void);
