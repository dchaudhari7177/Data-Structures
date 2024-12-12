#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    int top;
    char arr[100];
};  

void initStack(struct stack *s){
    s->top=-1;
}

void push(struct stack *s,char val){
    s->top++;    
    s->arr[s->top]=val;
}

char pop(struct stack *s){
    char val=s->arr[s->top];
    s->top--;
    return val;
}

int precedence(char op1,char op2){
    if(op1=='(' || op1==')'){
        return 0;
    }
    if(op1=='+' || op1=='-'){
        if(op2=='*' || op2=='/'){
            return 0;
        }
        else{
            return 1;
        }
    }
    else{
        return 0;
    }
}
int isempty(struct stack *s){
    if(s->top==-1){
        return 1;
    }
    return 0;
}


void postfix(char infix[],char postfix[]){
    stack s;
    initStack(&s);
    char dummy[];
    int k=0;

    for(int i=0;infix[i]!='\0';i++){
        if(isdigit(infix[i])){
            postfix[k++]=infix[i];
        
        }
        while(!isempty(&s) || precedence(STACKTOP(&s),infix[i])){
            postfix[k++]=pop(&s);

        if(infix[i]==')'){
            dummy = infix[i];
        }
        else{
            push(&s,infix[i]);
        }

            
       
        }
        while(!isempty(&s)){
            postfix[k++]=pop(&s);
        }

    }
}

void reverse_string(char *a, char *b){
    int i,j;
    i=strlen(a)-1;
    j=0;
    while(i>=0){
       if(a[i])=='('
             b[j++]=")";
       else if(a[i])==')'
             b[j++]="(";
        else
             b[j++]=a[j];
        i--;
    }
    b[j]='\0';

}

int main(){
    char infix[100],postfix[100];
    printf("Enter the Infix Expression");
    scanf("%s",infix);
    postfix(infix,postfix);
    printf("The Postfix Expression is %s",postfix);
}