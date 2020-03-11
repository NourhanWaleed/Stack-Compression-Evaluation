#include "functions.h"
#include<stdlib.h>

void infixTopostfix(char *infix, char* postfix)
{
    //TODO:implement
    /*
     - Single digit numbers
     - Multi digit numbers
     - Brackets
     - Floating point numbers
     - Negative numbers
    */
    char num[7] = "";
    char ch;
    Item temp;
    Stack *s = initialize();
    //while (*infix)
    {
        while (isdigit(*infix ) || (*infix   == '.'))
        {
            //TODO:convert number in infix to float then to prefix
            ch = *(infix++);
            strncat(num,&ch, sizeof(char));
            //printf("%s",num);

        }
        printf("%s",num);

        if (strcmp(num,""))
        {
            strcat(postfix,num);
            strcat(postfix," ");
            strcpy(num,"");
        }else if (*infix == '(')
        {
            temp.cData = *(infix++);
            push(s,temp);
        } else if (*(infix++) == ')')
        {
            while(*(infix++) != '(')
            {
                temp = pop(s);
                strcat(postfix,&(temp.cData));
            }
        }else if (is_operator(*(infix)))
        {
            temp = top(s);
            if (isLower(temp.cData,*infix) || isEmpty(s) || (temp.cData == '('))
            {
                temp.cData = *infix;
                push(s,temp);
            } else
            {
                while (isLower(*infix,temp.cData) || precedence(*infix) == precedence(temp.cData))
                {
                    push(s,temp);
                }
            }
        }
    }
    //free(num);    //not needed since num is not allocated using malloc
}

char precedence (char symbol)
{
    switch (symbol)
    {
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;

        case '^':
            return 3;
    }
    return -1;
}
unsigned char isLower(char symbol1,char symbol2)
{
    return (precedence(symbol1)<precedence(symbol2))? 1 : 0;
}
unsigned char is_operator(char symbol)
{
    if(precedence(symbol)!= -1){ return 1;} else{ return 0;}
}