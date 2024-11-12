#include<stdio.h>
#define MAX 10
void readgraph(int a[MAX][MAX],int n);
void bfs(int a[MAX][MAX],int n,int visited[MAX],int source);
int main()
{
	int a[MAX][MAX],n,visited[MAX]={0},source;
	printf("enter the no of nodes\n");
	scanf("%d",&n);
	printf("enter the source\n");
	scanf("%d",&source);
	
	printf("enter the adjacency matrix");
	readgraph(a,n);
	
	printf("Bfs Traversal\n");
	bfs(a,n,visited,source);
	
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			printf("Graph is disconnected\n");
			return 0;
		}
	}
	printf("Graph is connected\n");
	return 0;
}

void readgraph(int a[MAX][MAX],int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	
}
void bfs(int a[MAX][MAX],int n,int visited[MAX],int source)
{
	int q[n];
	int f=0,r=-1;
	
	q[++r]=source;
	visited[source]=1;
	
	while(f<=r)
	{
		int v=q[f++];
		printf("%d",v);
		
		for(int i=0;i<n;i++)
		{
			if(a[v][i] && visited[i]==0)
			{
				q[++r]=i;
				visited[i]=1;
				
			}
		}
		
	}
	
	
}*/
//PATH
#include<stdio.h>
#define MAX 10
void readgraph(int a[MAX][MAX],int n);
int bfs(int a[MAX][MAX],int n,int visited[MAX],int source,int dest);
int main()
{
	int a[MAX][MAX],n,visited[MAX]={0},source,dest;
	printf("enter the no of nodes\n");
	scanf("%d",&n);
	printf("enter the source\n");
	scanf("%d",&source);
	
	printf("enter the dest\n");
	scanf("%d",&dest);
	
	printf("enter the adjacency matrix");
	readgraph(a,n);
	
	printf("Bfs Traversal\n");
	
	if(bfs(a,n,visited,source,dest))
		printf("path exists between source %d to dest %d",source,dest);
	else
		printf("path doesnot exists between source %d to dest %d",source,dest);
	return 0;
}

void readgraph(int a[MAX][MAX],int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	
}
int bfs(int a[MAX][MAX],int n,int visited[MAX],int source,int dest)
{
	int q[n];
	int f=0,r=-1;
	
	q[++r]=source;
	visited[source]=1;
	
	while(f<=r)
	{
		int v=q[f++];
		printf("%d",v);
		
		for(int i=0;i<n;i++)
		{
			if(a[v][i] && visited[i]==0)
			{
				q[++r]=i;
				visited[i]=1;
				
				if(i==dest)
					return 1;
				
			}
		}
		
	}
	
	return 0;
}