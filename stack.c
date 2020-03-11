#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

Stack* initialize() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = 0;
    return s;
}


int isEmpty(Stack* s) {
    if (s->top == 0) return 1;
    return 0;
}

Item top(Stack* s) {
    return s->stack[s->top-1];
}

Item pop(Stack* s) {
    if (s->top == 0)
        printf("Empty,can't pop item\n");
    else {
        return s->stack[--s->top];
    }
}

void push(Stack* s, Item val) {
    if (s->top == Max - 1)
        printf("Stack overflow,can't push item\n");
    else
        s->stack[s->top++] = val;
}