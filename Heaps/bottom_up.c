#include<stdio.h>
#define MAX 50

void bottomup(int h[MAX],int n);
int main()
{
	int h[MAX],n;
	printf("enter the no of elements\n");
	scanf("%d",&n);
	printf("enter the elements\n");
	for(int i=0;i<n;i++)
		scanf("%d",&h[i]);
	bottomup(h,n);
	
	printf("Bottom up heap\n");
	for(int i=0;i<n;i++)
		printf("%d",h[i]);
	
	return 0;
}


void bottomup(int h[MAX],int n)
{
	int c,p,key;
	for(int k=n/2-1;k>=0;k--)
	{
		p=k;
		key=h[p];
		c=2*p+1;
		
		while(c<n)
		{
			if(c+1<n)
				if(h[c+1]>h[c])
					c=c+1;
				
				if(key<h[c])
		        {
					h[p]=h[c];
					p=c;
					c=2*p+1;
				}
				else
					break;
		}
		h[p]=key;
		
		
	}
}