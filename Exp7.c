#include<stdio.h>
#include<malloc.h>
#include<math.h>
struct node
{
    int info;
    struct node* next;
}*first=NULL,*last=NULL;

void add()
{
    int item;

    printf("\nEnter item to add ");
    scanf("%d",&item);

    struct node* n=(struct node*)malloc(sizeof(struct node));
    n->info=item;
    n->next=NULL;

    if(first==NULL)
        first=last=n;

    else
    {
        last->next=n;
        last=n;
    }
}
void display()
{
    struct node* n=first;
    printf("\n");

    while(n!=NULL)
    {
        printf("%d ",n->info);
        n=n->next;
    }
}

void insert()
{
    int item,loc;

    struct node* n=(struct node*)malloc(sizeof(struct node)),*temp;
    int i;


    printf("\nEnter item to insert ");
    scanf("%d",&item);

    n->info=item;
    n->next=NULL;

    printf("\nEnter location for insertion ");
    scanf("%d",&loc);


    if(first==NULL)
    {
        first=last=(struct node*)malloc(sizeof(struct node));
        first->info=item;
        first->next=NULL;
        return;
    }

    if(loc==1)
    {
        n->next=first;
        first=n;

    }

    else
    {
        temp=first;

        for(i=1;i<=loc-2;i++)
        {

            temp=temp->next;

                if(temp==NULL)
                    return;
        }

        n->next=temp->next;
        temp->next=n;

    }

    printf("\n%d was inserted ",item);

}

void del()
{
    int loc;
    struct node* temp=first,*a;
    int i;

    if(first==NULL)
        return;


    else if(first==last)
    {
        temp=first;

        first=last=NULL;

        printf("\n%d was deleted ",temp->info);
        free(temp);
        return;
    }

    printf("\nEnter location for deletion ");
    scanf("%d",&loc);

    if(loc==1)
    {
        a=first;
        first=first->next;
        printf("\n%d was deleted ",temp->info);
        free(a);
        return;
    }

    else
    {
        for(i=1;i<=loc-2;i++)
            {
                temp=temp->next;

                if(temp==NULL)
                return;
            }

        a=temp->next;

        if(a==NULL)
            return;
        temp->next=a->next;

        printf("\n%d was deleted ",a->info);

        free(a);

        if(a==last)
            last=temp;
    }
}
int main()
{
    int choice=1,item;

    while(choice)
    {
        printf("\n\n1 - Add\n2 - Insert\n3 - Delete\n4 - Display\n0 - Exit ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: add(); break;
            case 2: insert(); break;
            case 3: del(); break;
            case 4: display(); break;
            case 0: break;
            default: printf("\nInvalid input");
        }
    }
    return 0;
}