#include "functions.h"
#include<string.h>
#include<stdio.h>
#include<math.h>

float doMath(float operand1, float operand2, char operator);

float evaluatePostfix(const char* postfix)
{
	//TODO:takes a postfix expression as input and shows the
	// value of the value of the expression as output.

	/* prepare the string by adding ")" to the end */
	char* expression = postfix;
	char* token;
	unsigned char boolean;
	float intermediateValue;

	/* init the stack instance */
	Stack* stack = initialize();
	Item item;

	token = strtok(expression, " ");
	while (NULL != token)
	{
		
		boolean = is_operator(*token);
		
		if (strlen(token) > 1)	//to make sure negative numbers are not evaluated as operators
		{
			boolean = 0;
		}

		{

		}
		if (boolean == 1)
		{
			item.fData = doMath(pop(stack).fData,
				pop(stack).fData,
				*token);

			push(stack, item);
		}
		else if (boolean == 0)
		{
			item.fData = atof(token);
			push(stack, item);
		}
		else {
			perror("Unknown token");
		}

		token = strtok(NULL, " ");
	} 

	item = pop(stack);
	return item.fData;

}

float doMath(float operand1, float operand2, char operator) {
	switch (operator)
	{
	case '+':
		return operand1 + operand2;
	case '-':
		return operand1 - operand2;
	case '*':
		return operand1 * operand2;
	case '/':
		return operand1 / operand2;
	case '^':
		return pow(operand1, operand2);
	default:
		perror("invalid operator");
		break;
	}
	return 0;
}