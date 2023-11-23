#include <stdio.h>
#include <math.h>

// Fun��o para calcular o valor ao fim de cada m�s
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

    // C�lculo e exibi��o do valor ao fim de cada m�s
    for (int mes = 1; mes <= tempo; mes++) {
        double total = calcularTotalMensal(aporte, taxaJuros, mes);
        printf("Montante ao fim do mes %d: R$ %.2f\n", mes, total);
    }

    return 0;
}

