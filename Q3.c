#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função para verificar se o caractere é um dígito
int ehDigito(char c) {
    return (c >= '0' && c <= '9');
}

// Função para converter uma string para minúsculas
void converterParaMinusculas(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Função para verificar a autorização com base no último caractere da placa e no dia da semana
int verificarAutorizacao(char placaVeiculo[], char diaDaSemana[]) {
    int tamanho = strlen(placaVeiculo);

    char ultimoCaractere = placaVeiculo[tamanho - 1];
    int digito = ultimoCaractere - '0';

    // Verificar se o carro pode circular com base no último caractere e no dia da semana
    if ((strcmp(diaDaSemana, "segunda-feira") == 0 && (digito == 0 || digito == 1)) ||
        (strcmp(diaDaSemana, "terca-feira") == 0 && (digito == 2 || digito == 3)) ||
        (strcmp(diaDaSemana, "quarta-feira") == 0 && (digito == 4 || digito == 5)) ||
        (strcmp(diaDaSemana, "quinta-feira") == 0 && (digito == 6 || digito == 7)) ||
        (strcmp(diaDaSemana, "sexta-feira") == 0 && (digito == 8 || digito == 9))) {
        return 0; // Não autorizado
    } else {
        return 1; // Autorizado para outros casos
    }
}

int main() {
    char placaVeiculo[20];
    char diaDaSemana[20];

    // Entrada da placa do carro
    scanf("%19s", placaVeiculo);  // Limita a leitura a 19 caracteres para evitar estouro de buffer

    // Entrada do dia da semana
    scanf("%19s", diaDaSemana);

    // Verifica se a placa tem um formato válido
    if (!((strlen(placaVeiculo) == 7 || strlen(placaVeiculo) == 8) &&
          (isalpha((unsigned char)placaVeiculo[0]) && isalpha((unsigned char)placaVeiculo[1]) && isalpha((unsigned char)placaVeiculo[2]) &&
           ehDigito(placaVeiculo[strlen(placaVeiculo) - 1])))) {
        printf("Placa invalida\n");

        // Verifica se o nome do dia da semana é inválido
        if (strcmp(diaDaSemana, "SEGUNDA-FEIRA") != 0 &&
            strcmp(diaDaSemana, "TERCA-FEIRA") != 0 &&
            strcmp(diaDaSemana, "QUARTA-FEIRA") != 0 &&
            strcmp(diaDaSemana, "QUINTA-FEIRA") != 0 &&
            strcmp(diaDaSemana, "SEXTA-FEIRA") != 0 &&
            strcmp(diaDaSemana, "SABADO") != 0 &&
            strcmp(diaDaSemana, "DOMINGO") != 0) {
            printf("Dia da semana invalido\n");
        }
        return 0;
    }

    // Verifica se o nome do dia da semana é válido
    if (strcmp(diaDaSemana, "SEGUNDA-FEIRA") != 0 &&
        strcmp(diaDaSemana, "TERCA-FEIRA") != 0 &&
        strcmp(diaDaSemana, "QUARTA-FEIRA") != 0 &&
        strcmp(diaDaSemana, "QUINTA-FEIRA") != 0 &&
        strcmp(diaDaSemana, "SEXTA-FEIRA") != 0 &&
        strcmp(diaDaSemana, "SABADO") != 0 &&
        strcmp(diaDaSemana, "DOMINGO") != 0) {
        printf("Dia da semana invalido\n");
        return 0;
    }

    // Converte o nome do dia da semana para minúsculas
    converterParaMinusculas(diaDaSemana);

    // Verifica a autorização para circular com base na placa e no dia da semana
    int autorizado = verificarAutorizacao(placaVeiculo, diaDaSemana);

    // Mensagens de saída com base na autorização
    if (strcmp(diaDaSemana, "sabado") == 0 || strcmp(diaDaSemana, "domingo") == 0) {
        printf("Nao ha proibicao no fim de semana\n");
    } else if (autorizado) {
        printf("%s pode circular %s\n", placaVeiculo, diaDaSemana);
    } else {
        printf("%s nao pode circular %s\n", placaVeiculo, diaDaSemana);
    }

    return 0;
}
