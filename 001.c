#include <stdio.h>
#include <math.h>

int main() {
    int meses;
    double aporte, retorno, valorFinal;

    // Entrada de dados
    scanf("%d %lf %lf", &meses, &aporte, &retorno);

    // Verificação para evitar divisão por zero
    if (retorno == 0) {
        printf("A taxa de retorno não pode ser zero.\n");
        return 1;
    }

    for (int i = 1; i <= meses; i++) {
        valorFinal = aporte * ((pow(1 + retorno, i) - 1) / retorno);
        printf("Montante ao fim do mes %d: R$ %.2f\n", i, valorFinal);
    }

    return 0;
}
