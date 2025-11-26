# Implementação de Métodos Numéricos

__Programa que implementa métodos numéricos diversos__<br>
Repositório foi criado com o intuito de desenvolver um projeto prático sobre os métodos numéricos estudados na Unidade 2 da disciplina de Cálculo Numérico ministrada na Universidade do Vale do São Francisco - UNIVASF.

__Responsável pelo desenvolvimento:__
Andressa Sousa Fonseca

## Detalhamento do Projeto
O programa desenvolvido permite ao usuário resolver diferentes problemas matemáticos utilizando os métodos estudados.

__Os métodos implementados foram:__
1) Método de Gauss para resolução de sistemas de equações lineares;
2) Método de Gauss-Seidel para resolução de sistemas de equações lineares de modo iterativo;
4) Método de Interpolação Polinomial para aproximação linear, por parábola e exponencial;
5) Método de Integração Numérica para cálculo de área entre curvas.

O programa permite conferir se os dados inseridos estão corretos. Se não, permite informar os dados novamente para todos os métodos.

## Detalhamento dos Métodos

### 1. Método de Gauss

O método de Gauss utiliza-se de escalonamento para ordenação da matriz normal do sistema, permitindo identificar a solução das equações. <br>

__Os parâmetros de entrada:__
1) Número de equações;
2) Número de Incógnitas;
3) Coeficientes e termo independente de cada equação. <br>

As soluções são exibidas em ordem.

### 2. Método de Gauss-Seidel

O método de Gauss Seidel utiliza-se de uma abordagem iterativa para identificar a solução das equações. <br>

__Os parâmetros de entrada:__
1) Ordem da matriz do sistema (considerando apenas coeficientes);
2) Coeficientes e termos independente de cada equação; <br>

As soluções são exibidas em ordem.

### 3. Método de Interpolação Polinomial

O método de Interpolação Polinomial permite identificar uma função linear, quadrática ou exponencial que fornece dados aproximados aos dados informados. <br>

__Os parâmetros de entrada:__
1) Tipo de aproximação desejada;
2) Número de pontos. <br>

A função encontrada é exibida, e o usuário pode optar por simular novos dados com base na função aproximada.

### 4. Métodos de Integração Numérica

O método de Integração Numérica permite calcular a área entre curvas utilizando dos seguintes métodos: Regra dos Trapézios Repetida e Regra de Simpson Repetida. <br>

__Os parâmetros de entrada:__
1) Valor inicial do intervalo;
2) Valor final do intervalo;
3) Número de funções/curvas;
4) Número de pontos.<br>

Ao final é exibido o resultado encontrada por cada um dos dois métodos utilizados.
