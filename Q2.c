#include <stdio.h>
#include <math.h>

// Função para calcular o valor ao fim de cada mês
double calcularTotalMensal(double aporte, double taxaJuros, int tempo) {
    double total;
    total = aporte * (1 + taxaJuros) * ((pow((1 + taxaJuros), tempo) - 1) / taxaJuros);
    return total;
}

int main() {
    double aporte, taxaJuros;
    int tempo;

    //Input
    scanf("%d", &tempo);
    scanf("%lf", &aporte);
    scanf("%lf", &taxaJuros);

    // Cálculo e exibição do valor ao fim de cada mês
    for (int mes = 1; mes <= tempo; mes++) {
        double total = calcularTotalMensal(aporte, taxaJuros, mes);
        printf("Montante ao fim do mes %d: R$ %.2f\n", mes, total);
    }

    return 0;
}

