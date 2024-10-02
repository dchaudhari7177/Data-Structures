#include <stdio.h>
#include <stdbool.h>
#define MAX 30

typedef struct stack {
    int top;
    int s[MAX];
} STACK;

void initStack(STACK *ps);
void push(STACK *ps, int ele);
int pop(STACK *ps);
bool knows(int M[MAX][MAX], int a, int b, int n);
int findCelebrity(int M[MAX][MAX], int n);

int main() {
    int n;
    scanf("%d", &n);

    int M[MAX][MAX];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &M[i][j]);
        }
    }

    int celebrity = findCelebrity(M, n);
    if (celebrity == -1) {
        printf("There is no celebrity in the party\n");
    } else {
        printf("Celebrity is person %d\n", celebrity);
    }

    return 0;
}

bool knows(int M[MAX][MAX], int a, int b, int n) {
    return M[a][b] == 1;
}

int findCelebrity(int M[MAX][MAX], int n) {
    STACK s;
    initStack(&s);
    
    // Push all people onto the stack
    for (int i = 0; i < n; i++) {
        push(&s, i);
    }
    
    // Eliminate non-celebrities
    while (s.top > 0) {
        int a = pop(&s);
        int b = pop(&s);
        
        if (knows(M, a, b, n)) {
            // a knows b, so a cannot be a celebrity
            push(&s, b);
        } else {
            // a does not know b, so b cannot be a celebrity
            push(&s, a);
        }
    }
    
    // Potential celebrity
    int candidate = pop(&s);
    
    // Check if candidate is actually a celebrity
    bool rowCheck = true, colCheck = true;
    
    // Row check: The celebrity candidate should not know anyone
    for (int i = 0; i < n; i++) {
        if (M[candidate][i] != 0 && i != candidate) {
            rowCheck = false;
            break;
        }
    }
    
    // Column check: Everyone should know the celebrity candidate
    for (int i = 0; i < n; i++) {
        if (M[i][candidate] != 1 && i != candidate) {
            colCheck = false;
            break;
        }
    }
    
    // If both conditions hold true, return candidate as celebrity, else return -1
    if (rowCheck && colCheck) {
        return candidate;
    } else {
        return -1;
    }
}

void initStack(STACK *ps) {
    ps->top = -1;
}

void push(STACK *ps, int ele) {
    if (ps->top == MAX - 1) {
        printf("Stack overflow\n");
    } else {
        ps->top++;
        ps->s[ps->top] = ele;
    }
}

int pop(STACK *ps) {
    if (ps->top == -1) {
        printf("Stack underflow\n");
        return -1;
    } else {
        int res = ps->s[ps->top];
        ps->top--;
        return res;
    }
}
