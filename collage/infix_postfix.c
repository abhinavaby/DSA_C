#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

/*========================
  Stack Operations
========================*/

// Push an element onto the stack
void push(char ch)
{
    stack[++top] = ch;
}

// Remove and return the top element
char pop()
{
    return stack[top--];
}

// Return the top element without removing it
char peek()
{
    return stack[top];
}

// Check whether a character is an operand
int isOperand(char ch)
{
    return ((ch >= 'a' && ch <= 'z') ||
            (ch >= 'A' && ch <= 'Z') ||
            (ch >= '0' && ch <= '9'));
}

// Check whether a character is an operator
int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' ||
            ch == '/' || ch == '^');
}

// Return precedence of operators
int precedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

// Check if an operator is right associative
int isRightAssociative(char op)
{
    return (op == '^');
}

/*========================
  Infix to Postfix
========================*/

void infixToPostfix(char infix[], char postfix[])
{
    int i, k = 0;
    char ch;

    top = -1;

    for (i = 0; i < strlen(infix); i++)
    {
        ch = infix[i];

        if (ch == ' ')
            continue;

        if (isOperand(ch))
        {
            postfix[k++] = ch;
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (top != -1 && peek() != '(')
                postfix[k++] = pop();

            if (top != -1)
                pop();
        }
        else if (isOperator(ch))
        {
            while (top != -1 && isOperator(peek()) &&
                   ((precedence(ch) < precedence(peek())) ||
                    (precedence(ch) == precedence(peek()) &&
                     !isRightAssociative(ch))))
            {
                postfix[k++] = pop();
            }

            push(ch);
        }
    }

    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';
}

/*========================
  Evaluation Stack
========================*/

int valueStack[MAX];
int topValue = -1;

void pushValue(int x)
{
    valueStack[++topValue] = x;
}

int popValue()
{
    return valueStack[topValue--];
}

/*========================
  Power Function
========================*/

int power(int a, int b)
{
    int result = 1;

    for (int i = 1; i <= b; i++)
        result *= a;

    return result;
}

/*========================
  Variable Storage
========================*/

int variables[26];

int getValue(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
        return variables[ch - 'A'];
    else if (ch >= 'a' && ch <= 'z')
        return variables[ch - 'a'];
    else
        return ch - '0';
}

/*========================
  Postfix Evaluation
========================*/

int evaluatePostfix(char postfix[])
{
    int op1, op2;
    char ch;

    topValue = -1;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];

        if (isalnum(ch))
        {
            pushValue(getValue(ch));
        }
        else if (isOperator(ch))
        {
            op2 = popValue();
            op1 = popValue();

            switch (ch)
            {
            case '+':
                pushValue(op1 + op2);
                break;

            case '-':
                pushValue(op1 - op2);
                break;

            case '*':
                pushValue(op1 * op2);
                break;

            case '/':
                pushValue(op1 / op2);
                break;

            case '^':
                pushValue(power(op1, op2));
                break;
            }
        }
    }

    return popValue();
}

/*========================
  Main Function
========================*/

int main()
{
    char infix[MAX], postfix[MAX];
    char ch;
    int n, value;

    for (int i = 0; i < 26; i++)
        variables[i] = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    printf("Enter number of variables: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter variable and value (Example A 10 or a 10): ");
        scanf(" %c %d", &ch, &value);

        if (ch >= 'A' && ch <= 'Z')
            variables[ch - 'A'] = value;
        else if (ch >= 'a' && ch <= 'z')
            variables[ch - 'a'] = value;
    }

    infixToPostfix(infix, postfix);

    printf("\nPostfix Expression : %s", postfix);

    printf("\nEvaluation Result : %d\n",
           evaluatePostfix(postfix));

    return 0;
}