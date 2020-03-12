#include "functions.h"

char num[7] = "";char  tempchar;
unsigned char n = 1;
Item temp;

void operator();
void infixTopostfix(char *infix, char* postfix)
{
    //status: tested, working
    /*
     - Single digit numbers ×
     - Multi digit numbers ×
     - Brackets ×
     - Floating point numbers ×
     - Negative numbers ×
    */
    char ch = *infix;
    Stack *s = initialize();
    int length = strlen(infix);
    for (int i = 0; i < length; i++){
        /*for negative nums*/
        if (*infix == '-')
        {
            if (*infix == ch) //if its the first character in the expression then its a negative num
            {
                strcat(postfix,"-");
                infix++;
                continue;
            }else if(isdigit(*(infix+1))){
                /*if its followed by a number directly w/o a space then its negative*/
                strcat(postfix,"-");
                infix++;
                continue;
            }

            else if (*(infix-1) == ' '){ n = 2;} //if theres a space before it gotta check whats before the space

            if ((*(infix-n) != ')') && !isdigit(*(infix-n))) //n is 1 if theres no space so it checks the thing before the - sign
            {
                /*if we're here then its def. negative num*/
                strcat(postfix,"-");
                infix++;
                continue;
            }
            /*if not a negative then it'll go to the operator condition*/
        }
        /*for numbers*/
        while (isdigit(*infix ) || (*infix   == '.'))
        {
            ch = *(infix++);
            strncat(num,&ch, sizeof(char));
        }
        if (strcmp(num,""))
        {
            strcat(postfix,num);
            strcat(postfix," ");
            strcpy(num,"");
        }
        /*for brackets*/
        else if (*infix == '(')
        {
            temp.cData = *(infix++);
            push(s,temp);
        } else if (*(infix) == ')')
        {
            temp = pop(s);
            while(temp.cData != '(')
            {
                strcat(postfix,&(temp.cData));
                strcat(postfix," ");
                if (isEmpty(s)){ break;}
                else{temp = pop(s);}
            }
            infix++;
        }
        /*for operators*/
        else if (is_operator(*(infix)))
        {
            temp = top(s);
            if (isLower(temp.cData,*infix) || isEmpty(s) || (temp.cData == '('))
            {
                temp.cData = *infix;
                push(s,temp);
                infix++;
            } else
            {
                char space = ' ';
                while (isLower(*infix,temp.cData) || precedence(*infix) == precedence(temp.cData))
                {
                    tempchar = (pop(s).cData);
                    strncat(postfix,&tempchar, sizeof(char));
                    strcat(postfix,&space);
                }
                temp.cData = *infix;
                push(s,temp);
                infix++;
            }
        }
        /*for spaces*/
        else if (*infix == ' ')
        {
            infix++;
            continue;
        }
    }
    while (!isEmpty(s))
    {
        tempchar = pop(s).cData;
        strncat(postfix,&tempchar, sizeof(char));
        strcat(postfix," ");
    }
    printf("Postfix: %s",postfix);
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