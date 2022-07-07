#include<stdio.h>
#include<math.h>
#define MAX 10

int queue[MAX],front=-1,rear=-1;

void enqueue(int item)
{
    if(front==-1)
    {
        front=rear=0;

        queue[rear]=item;
    }

    else if(rear==MAX-1)
    {
        printf("\nQueue is Overflowing ");
        return;
    }

    else
    {
        rear++;
        queue[rear]=item;

        printf("\n%d was enqueued ",item);
    }
}

int dequeue()
{
    int item;

    if(front==-1)
    {
        printf("\nQueue is Underflowing ");
        return -1;
    }

    else if(front==rear)
    {
        printf("\n%d was dequeued ",queue[front]);
        item=queue[front];
        front=rear=-1;
        return item;
    }
    else
    {
        printf("\n%d was dequeued ",queue[front]);
        item=queue[front++];
        return item;
    }
}

void display()
{
    int i;
    if(front==-1)
        return;
    printf("\nThe queue is \n");
    for(i=front;i<=rear;i++)
    printf("%d ",queue[i]);
}

int main()
{
    int item,choice;

    choice=1;

    while(choice)
    {
        printf("\n\n1 - Enqueue (Add)\n2 - Dequeue (Delete)\n3 - Display\n0 - Exit ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("\nEnter item to add ");
                    scanf("%d",&item);
                    enqueue(item);
                    break;
            case 2: dequeue();
                    break;

            case 3: display();
                    break;

            case 0: break;

            default: printf("\nInvalid input ");
        }
    }
    return 0;
}