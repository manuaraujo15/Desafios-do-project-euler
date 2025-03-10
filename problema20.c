//gcc problema20.c -o problema20 -Wall

//Factorial Digit Sum

#include <stdio.h>

#define MAX_DIGITOS 1000 // Definindo o tamanho máximo para armazenar grandes números

// Função para calcular o fatorial de 100
void fatorial(int n, int resultado[]) {
    resultado[0] = 1; // O fatorial de 0 ou 1 é 1

    int tamanho = 1; // Inicializa o número com um dígito

    for (int i = 2; i <= n; i++) {
        int carry = 0; // Carry para o próximo dígito
        for (int j = 0; j < tamanho; j++) {
            int produto = resultado[j] * i + carry;
            resultado[j] = produto % 10; // Armazena o dígito da unidade
            carry = produto / 10; // Armazena o carry
        }

        // Coloca o carry no vetor, se necessário
        while (carry) {
            resultado[tamanho] = carry % 10;
            carry /= 10;
            tamanho++;
        }
    }
}

// Função para somar os dígitos do fatorial
int soma_digitos(int resultado[]) {
    int soma = 0;
    for (int i = 0; i < MAX_DIGITOS; i++) {
        soma += resultado[i];
    }
    return soma;
}

int main() {
    int resultado[MAX_DIGITOS] = {0}; // Array para armazenar o fatorial
    int numero = 100;

    // Calcular o fatorial de 100
    fatorial(numero, resultado);

    // Somar os dígitos do fatorial
    int soma = soma_digitos(resultado);

    // Exibir o resultado
    printf("A soma dos dígitos do fatorial de %d é: %d\n", numero, soma);

    return 0;
}