#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#define MAX 30

void push(int s, int* top, int stack[MAX]);
int pop(int stack[MAX], int* top);
void eval(int stack[MAX], int* top, char postfix[MAX]);
void disp(int stack[MAX], int* top);

int main() {
    int stack[MAX];
    int top = -1;
    char postfix[30];
    scanf("%s", postfix);
    eval(stack, &top, postfix);
    disp(stack, &top);
    return 0;
}

void push(int s, int* top, int stack[MAX]) {
    if (*top == MAX - 1) {
        printf("Stack is full\n");
        return;
    }
    stack[++(*top)] = s;
}

int pop(int stack[MAX], int* top) {
    if (*top == -1) {
        printf("Stack is empty\n");
        return -1; 
    }
    return stack[(*top)--];
}

void eval(int stack[MAX], int* top, char postfix[MAX]) {
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0', top, stack);
        } 
        else {
            int val2 = pop(stack, top);
            int val1 = pop(stack, top);

            if (val1 == -1 || val2 == -1) {
                return;
            }

            switch (postfix[i]) {
                case '+': push(val1 + val2, top, stack); break;
                case '-': push(val1 - val2, top, stack); break;
                case '*': push(val1 * val2, top, stack); break;
                case '/': 
                    if (val2 == 0) {
                        return;
                    }
                    push(val1 / val2, top, stack); 
                    break;
                default: break;
                    return;
            }
        }
    }
}

void disp(int stack[MAX], int* top) {
    if (*top == 0) {
        printf("%d\n", stack[*top]);
    } 
}