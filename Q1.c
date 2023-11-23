#include <stdio.h>
#include <string.h>

// Fun��o para determinar o valor correspondente a um caractere romano
int valor(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return -1; // Retorna -1 se o caractere romano for inv�lido
    }
}

// Fun��o para converter um n�mero romano em sua representa��o inteira
int numeroRomanoParaInteiro(char *s) {
    int resultado = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        int valorAtual = valor(s[i]);

        if (s[i + 1] != '\0') {
            int valorProximo = valor(s[i + 1]);

            if (valorAtual >= valorProximo) {
                // Se o valor atual � maior ou igual ao pr�ximo valor, adiciona ao resultado
                resultado += valorAtual;
            } else {
                // Se o pr�ximo valor � maior, subtrai o valor atual e avan�a para o pr�ximo
                resultado += valorProximo - valorAtual;
                i++;
            }
        } else {
            // Se n�o h� pr�ximo valor, apenas adiciona ao resultado
            resultado += valorAtual;
        }
    }

    return resultado;
}

// Fun��o para converter um n�mero decimal para bin�rio
void decimalParaBinario(int decimal) {
    if (decimal == 0) {
        printf("0"); // Se o n�mero decimal � zero, imprime '0'
        return;
    }

    int representacaoBinaria[1000];
    int indice = 0;

    // Converte o n�mero decimal para bin�rio
    while (decimal > 0) {
        representacaoBinaria[indice++] = decimal % 2;
        decimal /= 2;
    }

    // Imprime a representa��o bin�ria
    for (int j = indice - 1; j >= 0; j--) {
        printf("%d", representacaoBinaria[j]);
    }
    printf("\n");
}

// Fun��o para converter um n�mero decimal para hexadecimal
void decimalParaHexadecimal(int decimal) {
    if (decimal == 0) {
        printf("0"); // Se o n�mero decimal � zero, imprime '0'
        return;
    }

    char representacaoHexadecimal[20];
    int indice = 0;

    // Converte o n�mero decimal para hexadecimal
    while (decimal > 0) {
        int resto = decimal % 16;
        representacaoHexadecimal[indice++] = (resto < 10) ? resto + '0' : resto + 'a' - 10;
        decimal /= 16;
    }

    // Imprime a representa��o hexadecimal
    for (int i = indice - 1; i >= 0; i--) {
        printf("%c", representacaoHexadecimal[i]);
    }

    printf("\n");
}

int main() {
    char numeroRomano[20];
    scanf("%s", numeroRomano);

    // Converte o n�mero romano para inteiro e exibe em bin�rio, decimal e hexadecimal
    int resultado = numeroRomanoParaInteiro(numeroRomano);

    printf("%s na base 2: ");
    decimalParaBinario(resultado);

    printf("%s na base 10: %d\n", numeroRomano, resultado);

    printf("%s na base 16: ");
    decimalParaHexadecimal(resultado);

    return 0;
}
