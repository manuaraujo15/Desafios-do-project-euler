//gcc problema25.c -o fibi -Wall -lm
// 100-digit Fibonacci Number
// Problem 25
#include <stdio.h>
#include <string.h>

#define MAX_DIGITOS 1000

// Função para somar dois números Fibonacci armazenados como strings
void somar_fibonacci(char* a, char* b, char* resultado) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int carry = 0;  // Variável para o carry (transporte)
    int i, j, k;

    // A soma começa da última posição
    i = len_a - 1;
    j = len_b - 1;
    k = 0;

    // Soma os números digitando de trás para frente
    while (i >= 0 || j >= 0 || carry) {
        int digito_a = (i >= 0) ? a[i] - '0' : 0;
        int digito_b = (j >= 0) ? b[j] - '0' : 0;
        
        int soma = digito_a + digito_b + carry;
        resultado[k++] = (soma % 10) + '0';  // Armazena o dígito resultante
        carry = soma / 10;  // Atualiza o carry
        
        i--;
        j--;
    }
    
    resultado[k] = '\0';  // Finaliza a string
    // Reverte o resultado para obter o número correto
    for (int l = 0; l < k / 2; l++) {
        char temp = resultado[l];
        resultado[l] = resultado[k - l - 1];
        resultado[k - l - 1] = temp;
    }
}

// Função para verificar se o número de dígitos de uma string é maior ou igual a um valor
int tem_n_digitos(char* numero, int n) {
    return strlen(numero) >= n;
}

int main() {
    // Inicializando os dois primeiros números da sequência de Fibonacci
    char fib1[MAX_DIGITOS + 1] = "0";
    char fib2[MAX_DIGITOS + 1] = "1";
    char fib_resultado[MAX_DIGITOS + 1];

    int index = 2;  // Começamos do 2, já que F(0) e F(1) são conhecidos

    // Geramos Fibonacci até que um número tenha 1000 dígitos
    while (!tem_n_digitos(fib2, MAX_DIGITOS)) {
        somar_fibonacci(fib1, fib2, fib_resultado);  // Soma os dois números de Fibonacci
        strcpy(fib1, fib2);  // Atualiza fib1
        strcpy(fib2, fib_resultado);  // Atualiza fib2
        index++;  // Incrementa o índice
    }

    printf("O índice do primeiro termo de Fibonacci com 1000 dígitos é: %d\n", index);

    return 0;
}

