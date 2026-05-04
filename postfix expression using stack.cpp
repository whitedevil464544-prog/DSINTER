#include <stdio.h>
#include <ctype.h>

#define MAX 50

int stack[MAX];
int top = -1;

// PUSH (step-by-step)
void push(int value) {
    top = top + 1;
    stack[top] = value;
}

// POP (step-by-step)
int pop() {
    int value;
    value = stack[top];
    top = top - 1;
    return value;
}

// MAIN LOGIC
int evaluate(char exp[]) {
    int i = 0;

    while (exp[i] != '\0') {

        // STEP 1: If digit ? push
        if (isdigit(exp[i])) {
            int num = exp[i] - '0';
            push(num);
        }

        // STEP 2: If operator ? calculate
        else {
            int x1, x2, result;

            x1 = pop();   // first value
            x2 = pop();   // second value

            if (exp[i] == '+') {
                result = x2 + x1;
            }
            else if (exp[i] == '-') {
                result = x2 - x1;
            }
            else if (exp[i] == '*') {
                result = x2 * x1;
            }
            else if (exp[i] == '/') {
                result = x2 / x1;
            }
            else if (exp[i] == '%') {
                result = x2 % x1;
            }

            push(result);
        }

        i = i + 1;
    }

    return stack[top];
}

// DRIVER CODE
int main() {
    char exp[MAX];

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    int answer = evaluate(exp);

    printf("Result = %d\n", answer);

    return 0;
}
