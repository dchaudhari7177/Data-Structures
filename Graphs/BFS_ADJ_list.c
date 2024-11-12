#include<stdio.h>
#include<stdlib.h>
#define MAX 20

typedef struct node
{
	int info;
	struct node *next;
}NODE;

void initGraph(NODE *V[]);
void createGraph(NODE *V[]);
void bfs(NODE *V[],int n,int visited[MAX],int src);

int main()
{
	NODE *V[MAX];
	int n;
	int visited[MAX]={0};
	int src;
	
	initGraph(V);
	
	printf("Enter the number of vertices\n");
	scanf("%d",&n);
	
	printf("Enter the adjacency information\n");
	createGraph(V);
	
	printf("Enter the source vertex\n");
	scanf("%d",&src);
	
	printf("BFS traversal\n");
	bfs(V,n,visited,src);
	
	
}

void initGraph(NODE *V[])
{
	for(int i=0;i<MAX;i++)
		V[i]=NULL;
}
void createGraph(NODE *V[])
{
	int src,dest;
	NODE *newNode;
	printf("Enter source and destination vertices of an edge\n");
	printf("Enter -1 -1 to stop adding edges\n");
	
	scanf("%d%d",&src,&dest);
	
	while(src!=-1 && dest!=-1)
	{
		newNode=malloc(sizeof(NODE));
		newNode->info=dest;
		newNode->next=V[src];
		V[src]=newNode;
		scanf("%d%d",&src,&dest);
	}
}
void bfs(NODE *V[],int n,int visited[MAX],int src)
{
	int q[MAX],front=0,rear=-1;	
	int v;
	NODE *p=NULL;
	
	q[++rear]=src;
	visited[src]=1;	
	
	while(front<=rear)
	{
		v=q[front++];	
		printf("%d ",v);	
		
		p=V[v];	
		
		while(p!=NULL)	
		{
			if(visited[p->info] == 0)	
			{
				q[++rear]=p->info;	
				visited[p->info]=1;	
			}	
			p=p->next;
		}
	}
	
}