//quadratic probing
#include <stdio.h>
#include <string.h>
#define SIZE 7

typedef struct node
{
    int rNo;
    char name[25];
    int mark;
} NODE;

void initTable(NODE ht[], int *n);
int insertRecord(NODE ht[], int rNo, char name[], int *n);
int deleteRecord(NODE ht[], int rNo, int *n);
int searchRecord(NODE ht[], int rNo, char name[], int n);
void display(NODE ht[], int n);

int main()
{
    NODE ht[SIZE];
    int n;
    
    initTable(ht, &n);
    int choice, rNo;
    char name[25];
    
    do
    {
        printf("1.Insert 2.Delete 3.Search 4.Display\n");
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
                printf("Enter roll no.\n");
                scanf("%d", &rNo);
                fflush(stdin);
                printf("Enter name\n");
                scanf("%[^\n]", name);
                if (!insertRecord(ht, rNo, name, &n))
                    printf("Insertion failed\n");
                break;
            case 2:
                printf("Enter roll no.\n");
                scanf("%d", &rNo);
                if (!deleteRecord(ht, rNo, &n))
                    printf("Deletion failed\n");
                break;
            case 3:
                printf("Enter roll no.\n");
                scanf("%d", &rNo);
                if (searchRecord(ht, rNo, name, n))
                    printf("Record found, name is %s\n", name);
                else
                    printf("Record not found\n");
                break;
            case 4:
                display(ht, n);
                break;
        }
    } while (choice < 5);
}

void initTable(NODE ht[], int *n)
{
    for (int i = 0; i < SIZE; i++)
        ht[i].mark = -1;
    *n = 0;
}

int insertRecord(NODE ht[], int rNo, char name[], int *n)
{
    if (*n == SIZE)
        return 0;
    
    int index = rNo % SIZE;
    int i = 0;
    
    while (ht[(index + i * i) % SIZE].mark != -1)
        i++;
    
    index = (index + i * i) % SIZE;
    ht[index].rNo = rNo;
    strcpy(ht[index].name, name);
    ht[index].mark = 1;
    (*n)++;
    return 1;
}

int deleteRecord(NODE ht[], int rNo, int *n)
{
    if (*n == 0)
        return 0;
    
    int index = rNo % SIZE;
    int i = 0;
    
    while (i < SIZE && ht[(index + i * i) % SIZE].rNo != rNo)
    {
        if (ht[(index + i * i) % SIZE].mark == 1)
            i++;
        index = (index + i * i) % SIZE;
    }
    
    index = (index + i * i) % SIZE;
    if (ht[index].rNo == rNo && ht[index].mark == 1)
    {
        ht[index].mark = -1;
        (*n)--;
        return 1;
    }
    return 0;
}

int searchRecord(NODE ht[], int rNo, char name[], int n)
{
    if (n == 0)
        return 0;
    
    int index = rNo % SIZE;
    int i = 0;
    
    while (i < SIZE && ht[(index + i * i) % SIZE].rNo != rNo)
    {
        if (ht[(index + i * i) % SIZE].mark == 1)
            i++;
        index = (index + i * i) % SIZE;
    }
    
    index = (index + i * i) % SIZE;
    if (ht[index].rNo == rNo && ht[index].mark == 1)
    {
        strcpy(name, ht[index].name);
        return 1;
    }
    return 0;
}

void display(NODE ht[], int n)
{
    if (n == 0)
        printf("No records to display\n");
    else
    {
        for (int i = 0; i < SIZE; i++)
        {
            if (ht[i].mark == 1)
                printf("ht[%d]:%d %s\n", i, ht[i].rNo, ht[i].name);
            else
                printf("ht[%d]:\n", i);
        }
    }
}