#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) 
{
    stack[++top] = c;
}

char pop() 
{
    return stack[top--];
}

int precedence(char op)
 {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

void infixToPostfix(char* exp)
 {
    char output[MAX];
    int k = 0;
    for (int i = 0; exp[i]; i++) {
        if (isalnum(exp[i])) {
            output[k++] = exp[i];
        } else if (exp[i] == '(') {
            push(exp[i]);
        } else if (exp[i] == ')') {
            while (top != -1 && stack[top] != '(')
                output[k++] = pop();
            pop();
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(exp[i]))
                output[k++] = pop();
            push(exp[i]);
        }
    }
    while (top != -1)
        output[k++] = pop();
    output[k] = '\0';
    printf("%s\n", output);
}

int main()
 {
    char exp[MAX];
    scanf("%s", exp);
    infixToPostfix(exp);
    return 0;
}