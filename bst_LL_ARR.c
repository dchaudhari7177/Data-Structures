
#include<stdio.h>
#define MAX 20

typedef struct node
{
	int info;
	int used;
}NODE;	

void initTree(NODE bst[MAX]);
void createTree(NODE bst[MAX]);
void levelorder(NODE bst[MAX]);
void inorder(NODE bst[MAX],int);
void preorder(NODE bst[MAX],int);
void postorder(NODE bst[MAX],int);

int main()
{
	NODE bst[MAX];
	initTree(bst);
	createTree(bst);
	printf("Tree in level order\n");
	levelorder(bst);
	
	printf("Tree in inorder \n");
	inorder(bst,0);
	
	printf("Tree in preorder \n");
	preorder(bst,0);
	
	printf("Tree in post\n");
	postorder(bst,0);
	return 0;
}


void initTree(NODE bst[MAX])
{
	for(int i=0;i<MAX;i++)
		bst[i].used=0;
}
void createTree(NODE bst[MAX])
{
	int ele,choice;
	printf("Enter root info\n");
	scanf("%d",&ele);
	bst[0].info=ele;
	bst[0].used=1;
	
	printf("Do you wnt to add one more node\n");
	scanf("%d",&choice);
	int i;
	while(choice)
	{
		printf("enter node\n");
		scanf("%d",&ele);
		i=0;
		while(i<MAX && bst[i].used)
		{
			if(ele<bst[i].info)
				i=2*i+1;
			else
				i=2*i+2;
			
		}
		
		if(i>=MAX)
		{
			printf("outside the array bound\n");
			break;
		}
		
		bst[i].info=ele;
		bst[i].used=1;
		
	printf("Do you wnt to add one more node\n");
	scanf("%d",&choice);
		
	}
	
	
	
}



void levelorder(NODE bst[MAX])
{
	for(int i=0;i<MAX;i++)
		if(bst[i].used)
			printf("%d",bst[i].info);
	printf("\n");	
}
void inorder(NODE bst[MAX],int i)
{
	if(i<MAX && bst[i].used)
	{
		inorder(bst,2*i+1);
		printf("%d",bst[i].info);
		inorder(bst,2*i+2);
	}
	
}
void preorder(NODE bst[MAX],int i)
{
	if(i<MAX && bst[i].used)
	{
		printf("%d",bst[i].info);
		preorder(bst,2*i+1);
		
		preorder(bst,2*i+2);
	}
}
void postorder(NODE bst[MAX],int i)
{
	if(i<MAX && bst[i].used)
	{
		postorder(bst,2*i+1);
		
		postorder(bst,2*i+2);
		printf("%d",bst[i].info);
	}
}