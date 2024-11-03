#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 50

typedef struct node
{
	char info;
	struct node *left;
	struct node *right;
	
}NODE;

typedef struct tree
{
	NODE *root;
}TREE;	

typedef struct stack
{
	int top;
	NODE *s[MAX];
}STACK;

void initTree(TREE *pt);
void createTree(TREE *pt,char expr[MAX]);
int eval(TREE *pt);
void initStack(STACK *ps);
void push(STACK *ps, NODE *ele);
NODE* pop(STACK *ps);

int main()
{
	TREE tobj;
	initTree(&tobj);
	char expr[MAX];
	printf("enter the valid postfix expression\n");
	scanf("%s",expr);
	createTree(&tobj,expr);
	
	printf("evaluationTREE=%d\n",eval(&tobj));
}
void initStack(STACK *ps)
{
	ps->top=-1;
}
void push(STACK *ps, NODE *ele)
{
	ps->top++;
	ps->s[ps->top]=ele;
}
NODE* pop(STACK *ps)
{
	NODE *ele=ps->s[ps->top];
	ps->top--;	
	return ele;
}
void initTree(TREE *pt)
{
	pt->root=NULL;
}
void createTree(TREE *pt,char expr[MAX])
{
	STACK sobj;
	initStack(&sobj);
	for(int i=0;expr[i]!='\0';i++)
	{
		NODE *temp=malloc(sizeof(NODE));
		temp->info=expr[i];
		temp->left=temp->right=NULL;
		
		if(isdigit(expr[i]))
		{
			push(&sobj,temp);
		}
		else
		{
			temp->right=pop(&sobj);
			temp->left=pop(&sobj);
			push(&sobj,temp);
		}
	}
	pt->root=pop(&sobj);
	
}

int evalTree(NODE *r)
{
	switch(r->info)
	{
		case '+':return evalTree(r->left)+evalTree(r->right);
		         
		case '-':return evalTree(r->left)-evalTree(r->right);
		         
		case '*':return evalTree(r->left)*evalTree(r->right);
		         
		case '/':return evalTree(r->left)/evalTree(r->right);
		         		
		default:return r->info-'0';		 
	}
	
	
}

int eval(TREE *pt)
{
	return evalTree(pt->root);
}

