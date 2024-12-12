#include<stdio.h>   

struct stack{
    int top;
    char arr[100];   
};

void initstack(struct stack *s){
    s->top=-1;
}

void push(struct stack *s,char val){
    s->top++;
    s->arr[s->top]=val;
}

char top(struct stack *s){
    return s->arr[s->top];  
}

int isEmpty(struct stack *s){
    if(s->top==-1){
        return 1;
    }
    else{
        return 0;
}


int chkbalparanthesis(char str[]){
    stack s;
    initstack(&s);

    for(int i=0;str[i]!='\0';i++){
        if(str[i]=='(' || str[i]=='{' || str[i]=='['){
            push(&s,str[i]);
        }
        else if(str[i]==')' || str[i]=='}' || str[i]==']'){
            if(isEmpty(&s)){
                return 0;
            }
            else{
                switch(str[i]){
                    case ')':
                        if(top(&s)=='('){
                            pop(&s);
                        }   
                        break;
                    case '}':
                        if(top(&s)=='{'){
                            pop(&s);
                        }
                        break;
                    case ']':
                    if(top(&s)=='['){
                        pop(&s);
                    }
                    break;
                    }
                    }
                    }
            }
        }
    int main(){
        char str[100];
        scanf("%s",str);
        printf("%d",chkbalparanthesis(str));
        return 0;
    }