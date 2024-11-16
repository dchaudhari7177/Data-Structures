//DFS traversal of a connected graph using adjacency list, recursive
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
void dfsRecur(NODE *V[],int n,int visited[MAX],int src);


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
	
	printf("DFS traversal\n");
	dfsRecur(V,n,visited,src);
	
	
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
void dfsRecur(NODE *V[],int n,int visited[MAX],int src)
{
	printf("%d ",src);	//Print src
	visited[src]=1;	//Mark src visited
	
	NODE *p=V[src];
	
	while(p!=NULL)	//To traverse the nodes adjacent to src
	{
		if(visited[p->info] == 0)	//if adjacent node is unvisited
			dfsRecur(V,n,visited,p->info);	//start exploring it
		p=p->next;
	}
}