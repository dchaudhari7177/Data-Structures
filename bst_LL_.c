
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int info;
	struct node *left;
	struct node *right; 
}NODE;

typedef struct tree
{
	struct node *root;
}TREE;

void initTree(TREE *pt);
void createTree(TREE *pt);
void inorder(TREE *pt);
void preorder(TREE *pt);
void postorder(TREE *pt);

int searchRecursive(TREE *pt,int ele);
void deleteNode(TREE *pt,int ele);

int main()
{
	TREE tobj;
	
	initTree(&tobj);
	
	createTree(&tobj);
	
	printf("Inorder traversal\n");
	inorder(&tobj);
	
	printf("Preorder traversal\n");
	preorder(&tobj);
	
	printf("Postorder traversal\n");
	postorder(&tobj);
	/*
	int ele;
	printf("Enter an integer element\n");
    scanf("%d",&ele);
	
	if(searchRecursive(&tobj,ele))
	{
		printf("%d found\n",ele);
	    				 
	}
	else
	{
		printf("%d not found\n",ele);
	}
	*/
	
	
	int ele;
	printf("Enter an integer element\n");
    scanf("%d",&ele);
	if(searchRecursive(&tobj,ele))
	{
		//printf("%d not found\n",ele);
	    deleteNode(&tobj,ele);
		inorder(&tobj);
					 
	}
	
	
	
	
	
}


void initTree(TREE *pt)
{
	pt->root=NULL;
}

void createTree(TREE *pt)
{
	int choice;
	
	NODE *temp=malloc(sizeof(NODE));
	temp->left=temp->right=NULL;
	printf("enter the info\n");
	scanf("%d",&temp->info);
	
	pt->root=temp;
	
	printf("Do you want to add one more node\n");
	scanf("%d",&choice);
	
	while(choice)
	{
		temp=malloc(sizeof(NODE));
	    temp->left=temp->right=NULL;
	    printf("enter the info\n");
	    scanf("%d",&temp->info);
		
	
	    NODE *p=pt->root;
	    NODE *q=NULL;
	    while(p!=NULL)
	      {
	        if(temp->info<=p->info)
	         {
				 q=p;
		 		 p=p->left;
		     }
			 else
			 {
				 q=p;
				 p=p->right;
			 }
		
	      }
		  
		  if(temp->info<=q->info)
			  q->left=temp;
		  else
			  q->right=temp;
		  
		  printf("Do you want to add one more node\n");
	      scanf("%d",&choice);
		  
  }	
	
}



void inord(NODE *r)
{
	if(r!=NULL)
	{
		inord(r->left);
		printf("%d",r->info);
		inord(r->right);
	}
	
	
}

void inorder(TREE *pt)
{
	inord(pt->root);
}


void preord(NODE *r)
{
	if(r!=NULL)
	{
		printf("%d",r->info);
		preord(r->left);

		preord(r->right);
	}
	
	
}

void preorder(TREE *pt)
{
	preord(pt->root);
}

void postord(NODE *r)
{
	if(r!=NULL)
	{
		postord(r->left);
		
		postord(r->right);
		printf("%d",r->info);
	}
	
	
}

void postorder(TREE *pt)
{
	postord(pt->root);
}

int searchNode(NODE *r,int ele)
{
	if(r!=NULL)
	{
		if(ele==r->info)
			return 1;
		else if(ele<r->info)
			return searchNode(r->left,ele);
		else 
			return searchNode(r->right,ele);
	}
	return 0;
	
}

int searchRecursive(TREE *pt,int ele)
{
	return searchNode(pt->root,ele);
}

NODE* delNode(NODE *r,int ele)
{
	if(r==NULL)
		return r;
	NODE *temp=NULL,*p=NULL,*q=NULL;
	
	if(ele<r->info)
		r->left=delNode(r->left,ele);
	
	else if(ele>r->info)
		r->right=delNode(r->right,ele);
	
	else if(r->left==NULL)
	{
		temp=r->right;
		free(r);
		return temp;
	}
	else if(r->right==NULL)
	{
		temp=r->left;
		free(r);
		return temp;
	}
	else
	{
		p=r->right;
		while(p->left!=NULL)
		{
			q=p;
			p=p->left;
		}
		r->info=p->info;
		q->left=p->right;
		free(p);
	}
	return r;
}
	
void deleteNode(TREE *pt,int ele)
{
	pt->root=delNode(pt->root,ele);
}
