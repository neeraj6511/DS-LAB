#include<stdio.h>

void insertionSort(int a[],int size)
{
    int temp,i,prev,key;

    for(i=1;i<size;i++)
    {
        key=a[i];
        prev=i-1;

        while(key<a[prev] && prev>=0)
        {
            a[prev+1]=a[prev];
            prev--;
        }

        a[prev+1]=key;

    }
}

void display(int a[],int size)
{
    int i;

    putchar('\n');

    for(i=0;i<size;i++)
        printf("%d ",a[i]);
}

int main()
{
    int a[50],i,size;

    printf("\nEnter number of elements to store:- ");
    scanf("%d",&size);

    printf("Enter %d elements ",size);

    for(i=0;i<size;i++)
    scanf("%d",&a[i]);

    insertionSort(a,size);

    printf("\nThe sorted array is ");

    display(a,size);
    return 0;
}