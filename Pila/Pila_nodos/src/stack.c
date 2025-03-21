#include "stack.h"
#include <stdlib.h>


/**
 * Crea una nueva pila vacía y la devuelve.
 * 
 * @return Un auntador a la nueva pila creada. Si la creación falla, devuelve NULL.
 * @details Esta función asigna memoria dinámicamente para una nueva pila utilizando `malloc`.
 *          Si la asignación de memoria falla, la función devuelve NULL. La pila creada
 *          está vacía y top apunta a NULL
 */
Stack *stack_create(){
    Stack* s = (Stack*)malloc(sizeof(Stack)); // Asignar memoria para la pila
    if (s == NULL) {
        return NULL; // Si la asignación falla, devolver NULL
    }
    s->top = NULL; // Inicializar la pila vacía
    return s;

}

/**
 * Inserta un elemento en la parte superior de la pila.
 * 
 * @param s Auntador a la pila donde se insertará el elemento.
 * @param d Dato que se insertará en la pila.
 * @details Esta función añade el dato `d` en la parte superior de la pila. Si la pila está llena
 *          o el puntero `s` es NULL, la función no realiza ninguna operación.
 */
void stack_push(Stack* s, Data d){
    if (s == NULL) {
        return; // Si la pila es NULL, no hacer nada
    }
    
    Node* new_node_ptr = new_node(d); // Crear un nuevo nodo con el dato
    if (new_node_ptr == NULL) {
        return; // Si no se pudo crear el nodo, no hacer nada
    }

    new_node_ptr->next = s->top; // El nuevo nodo apunta al nodo anterior
    s->top = new_node_ptr; // El nuevo nodo es el nuevo "top" de la pila

}

/**
 * Elimina y devuelve el elemento en la parte superior de la pila.
 * 
 * @param s Auntador a la pila de la cual se eliminará el elemento.
 * @return El dato que estaba en la parte superior de la pila. Si la pila está vacía o el puntero
 *         `s` es NULL, devuelve un valor que indica error (por ejemplo, -1 o un valor predeterminado).
 * @details Esta función elimina el elemento en la parte superior de la pila y lo devuelve.
 *          Si la pila está vacía, no se realiza ninguna operación y se devuelve un valor de error.
 */
Data stack_pop(Stack* s){
    if (s == NULL || s->top == NULL) {
        return -1; // Retornar un valor de error si la pila está vacía o es NULL
    }

    Node* temp = s->top; // Apuntar al nodo superior
    Data top_data = temp->data; // Guardar el dato que será retornado
    s->top = s->top->next; // El siguiente nodo pasa a ser el nuevo "top"
    delete_node(temp); // Eliminar el nodo antiguo

    return top_data; // Retornar el dato del nodo eliminado

}

/**
 * Verifica si la pila está vacía.
 * 
 * @param s Auntador a la pila que se desea verificar.
 * @return 1 si la pila está vacía, 0 si no lo está. Si el puntero `s` es NULL, devuelve -1.
 * @details Esta función comprueba si la pila no contiene elementos. Es útil para evitar operaciones
 *          como `stack_pop` en una pila vacía.
 */
int stack_is_empty(Stack* s){
    if (s == NULL) {
        return -1; // Si la pila es NULL, retornar error
    }
    return s->top == NULL; // Si el "top" es NULL, la pila está vacía

}

/**
 * Vacía la pila, eliminando todos sus elementos.
 * 
 * @param s Auntador a la pila que se desea vaciar.
 * @details Esta función elimina todos los elementos de la pila, dejándola vacía.
 *          Si el puntero `s` es NULL, la función no realiza ninguna operación.
 *          La memoria de los elementos eliminados se libera adecuadamente.
 */
void stack_empty(Stack* s){
    if (s == NULL) {
        return; // Si la pila es NULL, no hacer nada
    }

    while (s->top != NULL) {
        stack_pop(s); // Eliminar elementos hasta que la pila esté vacía
    }
}

/**
 * Elimina la pila y libera la memoria asociada a ella.
 * 
 * @param s Auntador a la pila que se desea eliminar.
 * @details Esta función libera la memoria asignada dinámicamente para la pila y todos sus elementos
 *          utilizando `free`. Si el puntero pasado es NULL, la función no realiza ninguna operación.
 *          Es responsabilidad del llamante asegurarse de que la pila ya no se utiliza después
 *          de ser eliminada.
 */
void stack_delete(Stack *s){
    if (s == NULL) {
        return; // Si la pila es NULL, no hacer nada
    }

    stack_empty(s); // Vaciar la pila
    free(s); // Liberar la memoria de la pila

}

/**
 * Imprime los elementos de la pila.
 * 
 * @param s Auntador a la pila que se desea imprimir.
 * @details Esta función imprime los elementos de la pila en orden, desde la parte superior
 *          hasta la base. Si la pila está vacía o el puntero `s` es NULL, la función imprime
 *          un mensaje indicando que la pila está vacía o es inválida. La salida se dirige a
 *          la salida estándar (stdout).
 */
void stack_print(Stack *s){
    if (s == NULL || s->top == NULL) {
        printf("La pila está vacía o es inválida.\n");
        return;
    }

    Node* current = s->top;
    while (current != NULL) {
        printf("%d ", current->data); // Imprimir los datos del nodo
        current = current->next; // Mover al siguiente nodo
    }
    printf("\n");

}