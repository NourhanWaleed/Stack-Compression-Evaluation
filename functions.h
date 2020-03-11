
#ifndef STACK_MYVERSION_FUNCTIONS_H
#define STACK_MYVERSION_FUNCTIONS_H

#include "stack.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
void infixTopostfix(char *infix, char* postfix);
float evaluatePostfix(char* postfix);

#endif //STACK_MYVERSION_FUNCTIONS_H
