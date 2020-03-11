#include "functions.h"

void infixTopostfix(char *infix, char* postfix)
{
    //TODO:Test and debug : why does it terminate after the '*' ???????
    /*
     - Single digit numbers ×
     - Multi digit numbers ×
     - Brackets ×
     - Floating point numbers ×
     - Negative numbers ×
    */
    char num[7] = "";char ch = *infix;
    unsigned char n = 1;
    Item temp;
    Stack *s = initialize();
    //int i = 0;
    for (int i = 0; i < strlen(infix); i++)
    //while (*infix != '\0')
    {
        //i++;
        /*for negative nums*/
        if (*infix == '-')
        {
            if (*infix == ch) //if its the first character in the expression the its a negative num
            {
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
            //printf("%s",num);

        }
        //printf("%s",num);

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
            while(*(infix++) != '(')
            {
                temp = pop(s);
                strcat(postfix,&(temp.cData));
            }
        }
        /*for operators*/
        else if (is_operator(*(infix)))
        {
            temp = top(s);
            if (isLower(temp.cData,*infix) || isEmpty(s) || (temp.cData == '('))
            {
                temp.cData = *infix;
                push(s,temp);
                puts("blaBlabla");
                infix++;
                puts("blablabla");
            } else
            {
                while (isLower(*infix,temp.cData) || precedence(*infix) == precedence(temp.cData))
                {
                    push(s,temp);
                    infix++;
                }
            }
        }
        /*for spaces*/
        else if (*infix == ' ')
        {
            infix++;
            continue;
        }
        printf("i: %d\n",i);
        printf("temp: %c, postfix: %s\n",temp.cData,postfix);
    }
    //printf("postfix: %s",postfix);
    printf("empty: %d, top: %c,postfix: %s",(isEmpty(s))?1:0,top(s).cData,postfix);
    //free(num);
}

char precedence (char symbol)
{
    switch (symbol)
    {
        case '+':
            return 1;
        case '-':
            return 1;

        case '*':
            return 2;
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