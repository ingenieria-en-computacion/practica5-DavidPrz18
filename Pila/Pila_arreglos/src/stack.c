#include "stack.h"
#

/**
 * Crea una nueva pila vacía y la devuelve.
 * 
 * @return Una nueva pila vacía. Si la creación falla, el estado de la cola es inválido.
 * @details Esta función inicializa una pila vacía.
 */
Stack stack_create(){
    Stack s;
    s.top = -1;
    return s;

}

/**
 * Inserta un elemento en la parte superior de la pila.
 * 
 * @param s Referencia a la pila donde se insertará el elemento.
 * @param d Dato que se insertará en la pila.
 * @details Esta función añade el dato `d` en la parte superior de la pila. Si la pila está llena, 
 *          la función no realiza ninguna operación.
 */
void stack_push(Stack* s, Data d){
    if (s->top < TAM - 1) {  // Verificar si la pila no está llena
        s->data[++(s->top)] = d;  // Incrementamos top y asignamos el dato
    } else {
        printf("Error: La pila está llena, no se puede insertar el dato %d\n", d);
    }

}

/**
 * Elimina y devuelve el elemento en la parte superior de la pila.
 * 
 * @param s Referencia a la pila de la cual se eliminará el elemento.
 * @return El dato que estaba en la parte superior de la pila. Si la pila está vacía 
 *         devuelve un valor que indica error (por ejemplo, -1 o un valor predeterminado).
 * @details Esta función elimina el elemento en la parte superior de la pila y lo devuelve.
 *          Si la pila está vacía, no se realiza ninguna operación y se devuelve un valor de error.
 */
Data stack_pop(Stack* s){
    if (stack_is_empty(s)) {  // Verificar si la pila está vacía
        printf("Error: Pila vacía.\n");
        return -1;  // Valor de error
    }
    return s->data[(s->top)--];  // Devolver el elemento y decrementar top

}

/**
 * Verifica si la pila está vacía.
 * 
 * @param s Referencia a la pila que se desea verificar.
 * @return 1 si la pila está vacía, 0 si no lo está. Si el puntero `s` es NULL, devuelve -1.
 * @details Esta función comprueba si la pila no contiene elementos. Es útil para evitar operaciones
 *          como `stack_pop` en una pila vacía.
 */
int stack_is_empty(Stack* s){
    return s->top == -1;  // Si top es -1, la pila está vacía

}

/**
 * Vacía la pila, eliminando todos sus elementos.
 * 
 * @param s Referencia a la pila que se desea vaciar.
 * @details Esta función hace que top sea igual a -1
 */
void stack_empty(Stack* s){
    s->top = -1;  // Poner el tope en -1, indicando que está vacía

}


/**
 * Imprime los elementos de la pila.
 * 
 * @param s Referencia a la pila que se desea imprimir.
 * @details Esta función imprime los elementos de la pila en orden, desde la parte superior
 *          hasta la base. Si la pila está vacía la función imprime
 *          un mensaje indicando que la pila está vacía o es inválida. La salida se dirige a
 *          la salida estándar (stdout).
 */
void stack_print(Stack *s){
    if (stack_is_empty(s)) {
        printf("La pila está vacía\n");
        return;
    }

    printf("Elementos de la pila:\n");
    for (int i = s->top; i >= 0; i--) {  // Imprimir desde el tope hasta la base
        printf("%d ", s->data[i]);
    }
    printf("\n");

}