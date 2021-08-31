#include <stdio.h>
#include "scanner.h"

int main() {
    char buffer[64];
    int token;

    while((token = get_token(buffer)) != FDT) {
        switch (token) {
            case SEP:
                printf("Separador: %s\n", buffer);
                break;
            case CAD:
                printf("Cadena: %s\n", buffer);
                break;
        }
    }

    printf("Fin de texto: \n");
    return 0;
}