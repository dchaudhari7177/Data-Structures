//DFS
/*
#include<stdio.h>
#define MAX 10

void readgraph(int a[MAX][MAX],int n);
void dfs(int a[MAX][MAX],int n,int visited[MAX],int source);

int main()
{
	int a[MAX][MAX];
	int n;
	int visited[MAX]={0};
	int source;
	printf("Enter the no of nodes\n");
	scanf("%d",&n);
	printf("Enter the adjacency matrix\n");
	readgraph(a,n);
	printf("Enter the source\n");
	scanf("%d",&source);
	
	printf("DSF Traversal\n");
	dfs(a,n,visited,source);
	
	return 0;
}


void readgraph(int a[MAX][MAX],int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	
}
void dfs(int a[MAX][MAX],int n,int visited[MAX],int source)
{
	int s[n];
	int top=-1;
	s[++top]=source;
	visited[source]=1;
	printf("%d",source);
	
	while(top!=-1)
	{
		int v=s[top];
		int i;
		for(i=0;i<n;i++)
		{
			if(a[v][i] && visited[i]==0)
				break;
		}
		
		if(i<n)
		{
			s[++top]=i;
			visited[i]=1;
			printf("%d",i);
			
		}
		else
			top--;
		
	}
	
	
}



#include<stdio.h>
#define MAX 10

void readgraph(int a[MAX][MAX],int n);
void dfs(int a[MAX][MAX],int n,int visited[MAX],int source);

int main()
{
	int a[MAX][MAX];
	int n;
	int visited[MAX]={0};
	int source;
	printf("Enter the no of nodes\n");
	scanf("%d",&n);
	printf("Enter the adjacency matrix\n");
	readgraph(a,n);
	printf("Enter the source\n");
	scanf("%d",&source);
	
	printf("DSF Traversal\n");
	dfs(a,n,visited,source);
	
	return 0;
}


void readgraph(int a[MAX][MAX],int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	
}
void dfs(int a[MAX][MAX],int n,int visited[MAX],int source)
{
	visited[source]=1;
	printf("%d",source);
	
	for(int i=0;i<n;i++)
	{
		if(a[source][i] && visited[i]==0)
			dfs(a,n,visited,i);
	}
	
}


//connected or not

#include<stdio.h>
#define MAX 10

void readgraph(int a[MAX][MAX],int n);
void dfs(int a[MAX][MAX],int n,int visited[MAX],int source);

int main()
{
	int a[MAX][MAX];
	int n;
	int visited[MAX]={0};
	int source;
	printf("Enter the no of nodes\n");
	scanf("%d",&n);
	printf("Enter the adjacency matrix\n");
	readgraph(a,n);
	printf("Enter the source\n");
	scanf("%d",&source);
	
	printf("DSF Traversal\n");
	dfs(a,n,visited,source);
	
	for(int i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			printf("graph is disconnected\n");
			return 0;
			
		}
	}
	printf("graph is connected\n");

	
	return 0;
}


void readgraph(int a[MAX][MAX],int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	
}
void dfs(int a[MAX][MAX],int n,int visited[MAX],int source)
{
	int s[n];
	int top=-1;
	s[++top]=source;
	visited[source]=1;
	printf("%d",source);
	
	while(top!=-1)
	{
		int v=s[top];
		int i;
		for(i=0;i<n;i++)
		{
			if(a[v][i] && visited[i]==0)
				break;
		}
		
		if(i<n)
		{
			s[++top]=i;
			visited[i]=1;
			printf("%d",i);
			
		}
		else
			top--;
		
	}
	
	
}

*/
//path
#include<stdio.h>
#define MAX 10

void readgraph(int a[MAX][MAX],int n);
int dfs(int a[MAX][MAX],int n,int visited[MAX],int source,int dest);

int main()
{
	int a[MAX][MAX],n,visited[MAX]={0},source,dest;
	printf("Enter the no of nodes\n");
	scanf("%d",&n);
	
	printf("Enter the adjacency matrix\n");
	readgraph(a,n);
	
	printf("Enter the source vertex\n");
	scanf("%d",&source);
	
	printf("Enter the dest vertex\n");
	scanf("%d",&dest);
	
	printf("BFS Traversal\n");
	if(dfs(a,n,visited,source,dest))
	{
		printf("path exists  from %d to %d\n",source,dest);
	}
	else
		printf("path doesnot exists  from %d to %d\n",source,dest);
	
	return 0;
}

void readgraph(int a[MAX][MAX],int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			scanf("%d",&a[i][j]);
	
}

int dfs(int a[MAX][MAX],int n,int visited[MAX],int source,int dest)
{
	int s[n];
	int top=-1;
	s[++top]=source;
	visited[source]=1;
	printf("%d",source);
	
	while(top!=-1)
	{
		int v=s[top];
		int i;
		for(i=0;i<n;i++)
		{
			if(a[v][i] && visited[i]==0)
				break;
		}
		
		if(i<n)
		{
			s[++top]=i;
			visited[i]=1;
			printf("%d",i);
			
			if(i==dest)
					return 1;

			
		}
		else
			top--;
		
	}
	
	return 0;
}