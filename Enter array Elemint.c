#include <stdio.h>
int main()
{
    int a[10], Sum=0,i;
    printf("Enter array Element:");
    for(i=0; i<10; i++)
    {
        scanf("%d", & a[i]);
    }
    printf("Sum of array Element;");
    for(i=0; i<10; i++)
    {
         Sum=Sum+a[i];
    }
    printf("%d",Sum);
    return 0;
}
