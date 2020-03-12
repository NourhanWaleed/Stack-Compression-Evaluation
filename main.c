//
// Created by
// Fatema Moharam 6655
// Nourhan Waleed 6609
//

#include <stdio.h>
#include "stack.h"
#include "functions.h"

//TODO:The main should take a string as input from user, convert it to postfix
// notation using infixToPostfix(), and then call evaluatePostfix().

int main() {
    setbuf(stdout,NULL);setbuf(stdin,NULL);
    char *postfix = malloc(100* sizeof(char));
    infixTopostfix("2 + ( -2.5 + 3.14 ) * ( -5.4 + 8.1 ) ^ ( -0.5 )",postfix);
    //float result = evaluatePostfix("22 3 +");
    //printf("result: %f\n",result);
    free(postfix);
    return 0;
}
