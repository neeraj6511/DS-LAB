#include<stdio.h>
#include<math.h>
void heapify(int arr[], int size, int i)
{
    int temp,largest=i,left=2*i+1,right=2*i+2;

    if (left<size && arr[left]>arr[largest])
        largest=left;

    if (right<size && arr[right]>arr[largest])
        largest=right;

    if (largest!=i)
    {

    temp=arr[i];
    arr[i]=arr[largest];
    arr[largest]=temp;

    heapify(arr, size, largest);

    }

}

void heapSort(int arr[], int size)
{
    int temp,i;

    for (i=size/2-1;i>=0;i--)
      heapify(arr,size,i);

    for (i=size-1;i>=0;i--)
    {
      temp=arr[0];
      arr[0]=arr[i];
      arr[i]=temp;

      heapify(arr,i,0);

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

    printf("\nEnter number of elements to store ");
    scanf("%d",&size);

    printf("Enter %d elements ",size);

    for(i=0;i<size;i++)
    scanf("%d",&a[i]);

    heapSort(a,size);


    printf("\nThe sorted array is ");


    display(a,size);
    return 0;
}