#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX 100

// Stack for operators
char stack[MAX];
int top = -1;

// Push operator
void push(char x) {
    stack[++top] = x;
}

// Pop operator
char pop() {
    if (top == -1)
        return -1;
    return stack[top--];
}

// Peek operator
char peek() {
    if (top == -1)
        return -1;
    return stack[top];
}

// Precedence function
int precedence(char x) {
    if (x == '^')
        return 3;
    else if (x == '*' || x == '/')
        return 2;
    else if (x == '+' || x == '-')
        return 1;
    return 0;
}

// Infix to Postfix Conversion
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    char symbol;

    for (i = 0; infix[i] != '\0'; i++) {
        symbol = infix[i];

        if (isdigit(symbol)) {
            postfix[j++] = symbol;
        }
        else if (symbol == '(') {
            push(symbol);
        }
        else if (symbol == ')') {
            while (peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); // remove '('
        }
        else {
            while (top != -1 &&
                   precedence(peek()) >= precedence(symbol)) {
                postfix[j++] = pop();
            }
            push(symbol);
        }
    }

    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

// Stack for postfix evaluation
int evalStack[MAX];
int evalTop = -1;

void pushEval(int x) {
    evalStack[++evalTop] = x;
}

int popEval() {
    return evalStack[evalTop--];
}

// Evaluate Postfix Expression
int evaluatePostfix(char postfix[]) {
    int i;
    char symbol;
    int op1, op2, result;

    for (i = 0; postfix[i] != '\0'; i++) {
        symbol = postfix[i];

        if (isdigit(symbol)) {
            pushEval(symbol - '0');
        }
        else {
            op2 = popEval();
            op1 = popEval();

            switch (symbol) {
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '/':
                    result = op1 / op2;
                    break;
                case '^':
                    result = pow(op1, op2);
                    break;
            }

            pushEval(result);
        }
    }

    return popEval();
}

int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);

    printf("Evaluation Result: %d\n", result);

    return 0;
}
