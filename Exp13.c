#include<stdio.h>


void mergeSort(int a[],int start,int end)
{
    int i,j,mid=(start+end)/2,x[50],y[50],size1=0,size2=0,index=start;

    if(start<end)
    {
        mergeSort(a,start,mid);
        mergeSort(a,mid+1,end);

        for(i=start;i<=mid;i++)
            x[size1++]=a[i];

        for(i=mid+1;i<=end;i++)
            y[size2++]=a[i];


        i=j=0;

        while(i<size1 && j<size2)
        {
            if(x[i]<y[j])
            {
                a[index++]=x[i];
                i++;

            }

            else
            {
                a[index++]=y[j];
                j++;
            }
        }


        while(i<size1)
            a[index++]=x[i++];

        while(j<size2)
            a[index++]=y[j++];

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

    mergeSort(a,0,size-1);

    printf("\nThe sorted array is ");

    display(a,size);
    return 0;
}