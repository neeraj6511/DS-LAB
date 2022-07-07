#include <stdio.h>
#include <math.h>
void bubbleSort(int a[],int size)
{
    int temp,i,j;

    for(i=0;i<size-1;i++)
    {
        for(j=0;j<size-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
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

    bubbleSort(a,size);

    printf("\nThe sorted array is:- ");

    display(a,size);
    return 0;
}