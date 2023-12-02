#include <stdio.h>
#include <string.h>

int romano_decimal(char numeroRomano[]) {
    int decimal = 0;
    int v[7] = {1000, 500, 100, 50, 10, 5, 1};
    char numerais[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};

    for (int i = 0; i < strlen(numeroRomano); i++) {
        int atual = 0;
        for (int j = 0; j < 7; j++) {
            if (numeroRomano[i] == numerais[j]) {
                atual = v[j];
                break;
            }
        }

        if (i < strlen(numeroRomano) - 1 && atual < v[6] && atual < v[4] && numeroRomano[i + 1] == numerais[4]) {
            decimal -= atual;
        } else {
            decimal += atual;
        }
    }

    return decimal;
}

void decimal_binario(int decimal) {
    printf("%s na base 2: %s\n", "Número", decimal == 0 ? "0" : "");
    for (int i = 31; i >= 0; i--) {
        printf("%c", ((decimal >> i) & 1) + '0');
    }
    printf("\n");
}

void decimal_hexadecimal(int decimal) {
    printf("%s na base 16: %x\n", "Número", decimal);
}

int main() {
    char numeroRomano[13];
    scanf("%s", numeroRomano);

    int decimal = romano_decimal(numeroRomano);

    if (decimal >= 0) {
        printf("%s na base 10: %d\n", "Número", decimal);
        decimal_binario(decimal);
        decimal_hexadecimal(decimal);
    } else {
        printf("Número romano inválido.\n");
    }

    return 0;
}
