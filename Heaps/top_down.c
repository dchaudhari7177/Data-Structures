#include<stdio.h>
#define MAX 50

void topdown(int h[MAX],int n);
int main()
{
	int h[MAX],n;
	printf("Enter the no of elements\n");
	scanf("%d",&n);
	
	topdown(h,n);
	
	printf("TOP down heap\n");
	for(int i=0;i<n;i++)
		printf("%d",h[i]);

	return 0;
}

void topdown(int h[MAX],int n)
{
	int c,p,key;
	printf("enter the element\n");
	scanf("%d",&h[0]);
	
	for(int i=1;i<n;i++)
	{
		scanf("%d",&h[i]);
		c=i;
		p=(c-1)/2;
		key=h[c];
		while(c>0 && h[p]<key)
		{
			h[c]=h[p];
			c=p;
			p=(c-1)/2;
						
		}
		h[c]=key;
		
	}
}