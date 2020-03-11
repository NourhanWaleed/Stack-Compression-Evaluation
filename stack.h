#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define Max 100
#define TYPE int

typedef union {
    float fData;
    char cData;
} Item;


typedef struct Stack{
    int top;
    Item stack[Max];
} Stack;

Stack *initialize();
int isEmpty(Stack *s);
char precedence(char symbol);
unsigned char isLower(char symbol1,char symbol2);
unsigned char is_operator(char symbol);
Item top(Stack *s);
Item pop(Stack *s);
void push(Stack *s,Item val);

#endif