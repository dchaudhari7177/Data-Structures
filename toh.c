#include<stdio.h>

void toh(int n,char src,char aux,char dest);

int main()
{
    int n;
    printf("Enter the number of disks\n");
    scanf("%d",&n);
    toh(n,'A','B','C');
}

void toh(int n,char src,char aux,char dest)
{
    if(n==1)
    {
        printf("move disk 1 from %c to %c\n",src,dest);
        return;
    }
    else{
        toh(n-1,src,dest,aux);
        printf("move disk %d from %c to %c\n",n,src,dest);
        toh(n-1,aux,src,dest);
    }