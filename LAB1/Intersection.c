/**problem:-
 ---Write a C program to find the common elements in both the arrays and store them in a new array. The new array must contain only unique elements and should store them in non- decreasing (ascending) order.Print the elements of the new array. Print -1 if it is empty.
*/
#include <stdio.h>
#include <stdlib.h>

int *findIntersection(int arr1[], int size1, int arr2[], int size2, int *resultSize)
{
    int temp[100];
    int k = 0;

    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                int f = 0;
                for (int m = 0; m < k; m++)
                {
                    if (temp[m] == arr1[i])
                    {
                        f = 1;
                        break;
                    }
                }
                if (!f)
                {
                    temp[k++] = arr1[i];
                }
            }
        }
    }

    int *result = (int *)malloc(k * sizeof(int));
    for (int i = 0; i < k; i++)
    {
        result[i] = temp[i];
    }

    *resultSize = k;
    return result;
}

void sortArray(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    int n1, n2;

    scanf("%d", &n1);
    int arr1[n1];

    scanf("%d", &n2);
    int arr2[n2];

    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &arr1[i]);
    }

    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &arr2[i]);
    }

    int resultSize;
    int *result = findIntersection(arr1, n1, arr2, n2, &resultSize);

    sortArray(result, resultSize);

    if (resultSize > 0)
    {
        for (int i = 0; i < resultSize; i++)
        {
            printf("%d ", result[i]);
        }
        printf("\n");
    }
    else
    {
        printf("-1\n");
    }

    return 0;
}
