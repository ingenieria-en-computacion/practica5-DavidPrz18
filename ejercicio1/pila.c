#include "pila.h"
#include <stdio.h>


// Inicializa la pila 
void initPila(Pila *p){
    p->top = -1;
}

// Verifica si la pila está vacía 
int isEmpty(Pila *p){
    return p->top == -1;

}

void push(Pila *p, char item){
    if (p->top < MAX -1){
        p->items[++(p->top)] = item;
    } else {
        printf("error: pila llena \n");
    }
}


// Inserta un elemento en la pila 
char pop(Pila *p){
    if (!isEmpty(p)){
        return p->items[(p->top)--];
    } else {
        return -1;
    }
}

// Extrae un elemento de la pila
char peek(Pila *p){
    if (!isEmpty(p)) {
        return p->items[p->top];
    } else {
        return -1;
    }
}
