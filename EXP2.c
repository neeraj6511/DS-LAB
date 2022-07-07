#include<stdio.h>
#define MAX 10
int stack[MAX],top=-1;

void push(int item)
{
    if(top==MAX-1)
    {
        printf("\nStack is overflowing ");
        return;
    }

    printf("\n%d was pushed ",item);

    stack[++top]=item;
}

int pop()
{
    if(top==-1)
    {
        printf("\nStack is Underflowing ");
        return -1;
    }

    printf("\n%d was popped ",stack[top]);

    return stack[top--];
}

void display()
{
    int i;
    if(top==-1)
        return;
    printf("\n\nThe stack is \n");

    for(i=top;i>=0;i--)
    {
        printf("%d",stack[i]);

        if(i==top)
            printf(" <-- TOP ");

        printf("\n");

    }
}

int main()
{
    int item,choice;

    choice=1;

    while(choice)
    {
        printf("\n\n1 - Push\n2 - Pop\n3 - Display\n0 - Exit ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("\nEnter item to push ");
                    scanf("%d",&item);
                    push(item);
                    break;

            case 2: pop();
                    break;

            case 3: display();
                    break;

            case 0: break;

            default: printf("\nInvalid input ");
        }
    }
    return 0;
}