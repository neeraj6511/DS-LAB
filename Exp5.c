#include<stdio.h>
#include<math.h>
#define MAX 5

int queue[MAX],front=-1,rear=-1;

void enqueue(int item)
{
    if((rear+1)%MAX == front)
    {
        printf("\nQueue is Overflowing ");
        return;
    }

    else if(front==-1)
    {
        front=rear=0;

        queue[rear]=item;
        printf("\n%d was enqueued ",item);
    }

    else
    {
        rear=(rear+1)%MAX;
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
        item=queue[front];
        front=rear=-1;

        printf("\n%d was dequeued ",item);
        return item;
    }

    else
    {
        item=queue[front];
        printf("\n%d was dequeued ",item);

        front=(front+1)%MAX;
        return item;
    }
}
void display()
{
    int i;

    if(front==-1)
        return;

    for(i=front;i!=rear; i=(i+1)%MAX )
    printf("%d ",queue[i]);

    printf("%d ",queue[rear]);
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