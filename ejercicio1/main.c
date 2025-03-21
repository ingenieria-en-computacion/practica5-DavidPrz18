#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int verificarEquilibrio(char *exp){ //se desarrolla esta función antes de realizar el int main()
    Pila p;
    initPila(&p);

for (int i = 0; exp[i] != '\0'; i++) {
    char c = exp[i];

    // Usamos switch para manejar los caracteres cuando abren y cierran
    switch (c) {
        // Casos cuando abren
        case '(':
        case '{':
        case '[':
            push(&p, c);
            break;

        // Casos cuando cierran
        case ')':
        case '}':
        case ']':
            // Si la pila está vacía, no hay símbolo de apertura para emparejar
            if (isEmpty(&p)) {
                return 0;
            }
            // Sacamos el último símbolo de apertura
            {
                char apertura = pop(&p);
                // Verificamos si el símbolo de cierre coincide con el de apertura correspondiente
                if ((c == ')' && apertura != '(') ||
                    (c == '}' && apertura != '{') ||
                    (c == ']' && apertura != '[')) {
                    return 0;
                }
            }
            break;

        // Otros caracteres se ignoran
        default:
            break;
    }
}

// Si la pila está vacía al final, la expresión está equilibrada
return isEmpty(&p);
}

int main() {
    char expresion[100];

    printf("Introduce la expresion: ");
    scanf(" %99[^\n]", expresion); // Lee la expresión de entrada

    if (verificarEquilibrio(expresion)) {
        printf("La expresion esta equilibrada.\n");
    } else {
        printf("La expresion no esta equilibrada.\n");
    }

    return 0;
}
