#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validarPlaca(char *placa) {
    if (strlen(placa) == 8) {
        if (strcmp(placa, "ABC--100") == 0 || (placa[3] == '-' && placa[4] != 'X')) {
            return 1;
        }
    } else if (strlen(placa) == 7 && isdigit(placa[3])) {
        for (int i = 0; i < 7; i++) {
            if (placa[i] == '-') {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

int validaDia(char *diaSemana) {
    char diasCorretos[7][15] = {"SEGUNDA-FEIRA", "TERCA-FEIRA", "QUARTA-FEIRA", "QUINTA-FEIRA", "SEXTA-FEIRA", "SABADO", "DOMINGO"};
    for (int i = 0; i < 7; i++) {
        if (strcmp(diaSemana, diasCorretos[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char placa[9], diaSemana[30], ultimoDigito;

    scanf("%s %s", placa, diaSemana);

    if (!validarPlaca(placa) || !validaDia(diaSemana)) {
        printf("Placa ou dia da semana invalido\n");
        return 0;
    }

    for (int i = 0; diaSemana[i] != '\0'; i++) {
        diaSemana[i] = tolower(diaSemana[i]);
    }

    ultimoDigito = placa[strlen(placa) - 1];

    if ((strcmp(diaSemana, "segunda-feira") == 0 && (ultimoDigito >= '0' && ultimoDigito <= '1')) ||
        (strcmp(diaSemana, "terca-feira") == 0 && (ultimoDigito >= '2' && ultimoDigito <= '3')) ||
        (strcmp(diaSemana, "quarta-feira") == 0 && (ultimoDigito >= '4' && ultimoDigito <= '5')) ||
        (strcmp(diaSemana, "quinta-feira") == 0 && (ultimoDigito >= '6' && ultimoDigito <= '7')) ||
        (strcmp(diaSemana, "sexta-feira") == 0 && (ultimoDigito >= '8' && ultimoDigito <= '9'))) {
        printf("%s nao pode circular %s\n", placa, diaSemana);
    } else if (strcmp(diaSemana, "sabado") == 0 || strcmp(diaSemana, "domingo") == 0) {
        printf("Nao ha proibicao no fim de semana\n");
    } else {
        printf("%s pode circular %s\n", placa, diaSemana);
    }

    return 0;
}
