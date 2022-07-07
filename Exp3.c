#include<stdio.h>

void hanoi(int a,int b,int c,int disks)
{
    if(disks==1)
        printf("\nMoving 1 disk from %d to %d ",a,b);

    else
    {
        hanoi(a,c,b,disks-1);
        printf("\nMoving 1 disk from %d to %d ",a,b);
        hanoi(c,b,a,disks-1);
    }
}

int main()
{
    int disks;
    printf("Enter number of disks to move ");
    scanf("%d",&disks);
    hanoi(1,2,3,disks);
    return 0;
}