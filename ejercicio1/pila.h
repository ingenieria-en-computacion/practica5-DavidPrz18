#ifndef __PILA_H__
#define __PILA_H__

#define MAX 100

typedef struct {

    char items[MAX];
    int top;
} Pila;

void initPila(Pila *P);
int isEmpty(Pila *p);
void push(Pila *p, char item);
char pop(Pila *p);
char peek(Pila *p);


#endif