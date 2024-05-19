#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "arraylist.h"
#include "stack.h"

List* crea_lista() {
    List* L = create_list();
    for (int i = 1; i <= 10; i++) {
        int *elemento = (int *)malloc(sizeof(int));
        *elemento = i;
        add(L, elemento);
    }
    return L;
}

int sumaLista(List *L) {
    int suma = 0;
    int *elemento;
    for (elemento = (int *)first(L); elemento != NULL; elemento = (int *)next(L)) {
        suma += *elemento;
    }
    return suma;
}

void eliminaElementos(List *L, int elem) {
    int *elemento;
    start_iteration(L);
    while ((elemento = (int *)current(L)) != NULL) {
        if (*elemento == elem) {
            free(removeCurrent(L));
        } else {
            next(L);
        }
    }
}

void copia_pila(Stack *P1, Stack *P2) {
    Stack *aux = create_stack();
    void *dato;
    while ((dato = pop(P1)) != NULL) {
        push(aux, dato);
    }
    while ((dato = pop(aux)) != NULL) {
        push(P2, dato);
        push(P1, dato); // Devolver los elementos a P1 en su orden original
    }
    destroy_stack(aux); // Liberar la memoria de la pila auxiliar
}

int parentesisBalanceados(char *cadena) {
    Stack *pila = create_stack();
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] == '(') {
            push(pila, &cadena[i]);
        } else if (cadena[i] == ')') {
            if (isEmpty(pila)) {
                destroy_stack(pila);
                return 0; // Hay un ')' sin su correspondiente '('
            } else {
                pop(pila);
            }
        }
    }
    int balanceados = isEmpty(pila); // Si la pila está vacía, los paréntesis están balanceados
    destroy_stack(pila);
    return balanceados;
}
