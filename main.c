//
// Created by
// Fatema Moharam 6655
// Nourhan Waleed 6609
//

#include <stdio.h>
#include<stdlib.h>
#include "stack.h"
#include "functions.h"

//TODO:The main should take a string as input from user, convert it to postfix
// notation using infixToPostfix(), and then call evaluatePostfix().

int main() {
    setbuf(stdout,NULL);setbuf(stdin,NULL);
    char *postfix = malloc(100* sizeof(char));
    infixTopostfix("122.6++",postfix);
    float number = evaluatePostfix("2 3 4 * +");
    printf("\nOutput: %f", number);
    free(postfix);
    return 0;
}
