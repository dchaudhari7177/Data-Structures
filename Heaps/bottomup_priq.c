#include<stdio.h>
#define MAX 50

void bottomUpHeap(int h[MAX],int n);
int maxDelete(int h[MAX],int *n);

int main()
{
	int h[MAX];
	int n;
	
	printf("Enter the no. of elements\n");
	scanf("%d",&n);
	
	printf("Enter the elements\n");
	for(int i=0;i<n;i++)
		scanf("%d",&h[i]);
		
	bottomUpHeap(h,n);

	for(int i=0;i<n;i++)
		printf("%d ",h[i]);
	
	int del=maxDelete(h,&n);
	printf("Deleted %d\n",del);
	printf("Priority Q after deletion\n");
	for(int i=0;i<n;i++)
		printf("%d",h[i]);
}

void bottomUpHeap(int h[MAX],int n)
{
	int c,p,key;
	
	for(int k=n/2-1;k>=0;k--)
	{
		p=k;
		c=2*p+1;
		key=h[p];
		
		while(c<n)
		{
			if(c+1 < n)
			{
				if(h[c+1]>h[c] )
					c=c+1;
			}
			if(key < h[c])
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

int maxDelete(int h[MAX],int *n)
{
	int ele=h[0];
	h[0]=h[*n-1];
	(*n)--;
	bottomUpHeap(h,*n);
	return ele;
		
}