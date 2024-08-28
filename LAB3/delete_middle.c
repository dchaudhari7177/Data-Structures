/*
---Write a C function ‘middle’ that takes a Singly Linked List, finds the middle element in the list and deletes it. On deletion, print the linked list. If the linked list is empty, print -1.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node* next;
}NODE;
int size;
void input(NODE **head, int size);
NODE* middle(NODE **head);
void disp(NODE *r);
void destroy(NODE **head);

int main()
{
    NODE* head= NULL;

    
    scanf("%d", &size);
    input(&head, size);
    NODE *mid= middle(&head);
    disp(mid);
    destroy(&mid);
      
}




void input(NODE **head, int size)
{
    NODE *p=NULL;
    NODE *q=NULL;
    int count =0;
    int num;
    while(count< size)
    {
        NODE* newNode = (NODE*)malloc(sizeof(NODE));
        p = newNode;
        scanf("%d", &num);
        newNode->info = num;
        newNode->next = NULL;
        if(*head== NULL) 
        {
            *head= p;
            q =p;
        }
        else
        {
            q->next =p;
            q = p;  
        }
        count++;
        
    }
}

NODE* middle(NODE **head)
{
if(size==0)
{
*head = NULL;
return *head;
}
else if(size==1)
{
*head = NULL;
return *head;
}
else if(size==2)
{
*head = (*head)->next;
return *head;
}
else if(size%2==0)
{
int pos = size/2;
    NODE *temp = *head;
    NODE *a = NULL;
int i = 0;
    while(i<pos-1)
    {
    a = temp;
    temp = temp->next;
    i++;
    }
a->next = temp->next;
free(temp);
return *head;
}
else{
int pos = size/2+1;
NODE *temp = *head;
NODE *a = NULL;
int i = 0;
    while(i<pos-1)
    {
    a = temp;
    temp = temp->next;
    i++;
    }
  a->next = temp->next;
  free(temp);
return *head;
}
}
void disp(NODE *r)
{
    if(r == NULL)
    {
        printf("-1");
    }
    while(r!=NULL)
    {
        printf("%d ",r->info);
        r = r->next;
    }

}

void destroy(NODE **head)
{
    NODE *p=*head;
    while(*head!=NULL)
    {
        *head = (*head)->next;
        free(p);
        p = *head;
    }}
