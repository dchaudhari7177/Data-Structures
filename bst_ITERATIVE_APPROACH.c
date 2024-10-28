#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct node
{
	int info;
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

typedef struct queue
{
	int front,rear;
	NODE *a[MAX];
}QUEUE;
void initTree(TREE *pt);
void insertNode(TREE *pt,int ele);
void inorderTraversal(TREE *pt);
void preorderTraversal(TREE *pt);
void postorderTraversal(TREE *pt);
void destroyTree(TREE *pt);
void levelorderTraversal(TREE *pt);



int main()
{
	TREE tobj;
	initTree(&tobj);
	int choice;
	int ele;
	NODE *res=NULL;
	do
	{
		printf("\n1.Insert 2.Inorder 3.Preorder 4.Postorder 5.Levelorder\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:printf("Enter an integer element\n");
					scanf("%d",&ele);
					insertNode(&tobj,ele);
					break;
			case 2:printf("Inorder:\n");
					inorderTraversal(&tobj);
					break;
			case 3:printf("Preorder:\n");
					preorderTraversal(&tobj);
					break;
			case 4:printf("Postorder\n");
					postorderTraversal(&tobj);
					break;	
			case 5:printf("Levelorder\n");
					levelorderTraversal(&tobj);
					break;
		}
	}while(choice<6);
	destroyTree(&tobj);
}



void initTree(TREE *pt)
{
	pt->root=NULL;
}

NODE* createNode(int ele)
{
	NODE *newNode=malloc(sizeof(NODE));
	
	newNode->info=ele;
	newNode->left=NULL;
	newNode->right=NULL;
	
	return newNode;
}

void insertNode(TREE *pt,int ele)
{
	NODE *p=pt->root;
	NODE *q=NULL;
	
	NODE *newNode=createNode(ele);
	
	if(pt->root==NULL)
		pt->root=newNode;
	else
	{
		while(p!=NULL)
		{
			q=p;
		
			if(newNode->info < p->info)
				p=p->left;
			else
				p=p->right;
		}
		if(newNode->info < q->info)
			q->left=newNode;
		else
			q->right=newNode;
	}	
}

void initStack(STACK *ps)
{
	ps->top=-1;
}
void push(STACK *ps,NODE *pn)
{
	ps->s[++(ps->top)]=pn;
}

NODE* pop(STACK *ps)
{
	return ps->s[(ps->top)--];
}

int isEmpty(STACK *ps)
{
	return ps->top==-1;
}
void inorderTraversal(TREE *pt)
{
	NODE *p=pt->root;
	STACK s;
	initStack(&s);
	while(p!=NULL || !isEmpty(&s))
	{
		if(p!=NULL)
		{
			push(&s,p);
			p=p->left;
		}
		else
		{
			p=pop(&s);
			printf("%d",p->info);
			p=p->right;
		}
	}
	
}

void preorderTraversal(TREE *pt)
{
	NODE* p=pt->root;
	
	if(p==NULL)
		return;
	
	STACK s;
	initStack(&s);
	
	push(&s,p);
	while(!isEmpty(&s))
	{
		p=pop(&s);
		printf("%d",p->info);
		
		if(p->right!=NULL)
			push(&s,p->right);
		if(p->left!=NULL)
			push(&s,p->left);
		
		
	}
	
}

void postorderTraversal(TREE *pt)
{
	STACK s1,s2;
	initStack(&s1);
	initStack(&s2);
	
	NODE* p=pt->root;
	if(p==NULL)
		return;
	
	push(&s1,p);
	
	while(!isEmpty(&s1))
	{
		p=pop(&s1);
		push(&s2,p);
		
		if(p->left!=NULL)
			push(&s1,p->left);
		if(p->right!=NULL)
			push(&s1,p->right);
	}
	while(!isEmpty(&s2))
	{
		p=pop(&s2);
		printf("%d",p->info);
		
	}
	
	
	
	
}
void destroyNode(NODE *p)
{
	if(p!=NULL)
	{
		destroyNode(p->left);
		destroyNode(p->right);
		free(p);
	}
}
void destroyTree(TREE *pt)
{
	if(pt->root!=NULL)
		destroyNode(pt->root);
	
	pt->root=NULL;
}


void initQueue(QUEUE *pq)
{
	pq->front=0;
	pq->rear=-1;
}
void enqueue(QUEUE *pq,NODE* ele)
{
	pq->a[++pq->rear]=ele;
}
NODE* dequeue(QUEUE *pq)
{
	return pq->a[pq->front++];	
}

int isEmptyQ(QUEUE *pq)
{
	return pq->front>pq->rear;
}
void levelorderTraversal(TREE *pt)
{
	QUEUE qobj;
	initQueue(&qobj);
	NODE *p=pt->root;
	
	if(p==NULL)
		return;
	
	enqueue(&qobj,p);
	while(!isEmptyQ(&qobj))
	{
		p=dequeue(&qobj);
		printf("%d ",p->info);
		if(p->left!=NULL)
			enqueue(&qobj,p->left);
		if(p->right!=NULL)
			enqueue(&qobj,p->right);
	}
	
}





