#include<stdio.h>
#include<malloc.h>
#include<math.h>
struct node
{
    int info;
    struct node *left,*right;
}*root=NULL;

struct node* add(struct node* a,int item)
{
    if(a==NULL)
    {
        a=(struct node*)malloc(sizeof(struct node));
        a->info=item;
        a->left=a->right=NULL;

    }

    else if(item<a->info)
        a->left=add(a->left,item);

    else a->right=add(a->right,item);


    return a;
}


void inorder(struct node* a)
{
    if(a==NULL)
        return;

    inorder(a->left);
    printf("%d ",a->info);
    inorder(a->right);
}

void preorder(struct node* a)
{
    if(a==NULL)
        return;

    printf("%d ",a->info);
    preorder(a->left);
    preorder(a->right);
}

void postorder(struct node* a)
{
    if(a==NULL)
        return;

    postorder(a->left);
    postorder(a->right);
    printf("%d ",a->info);
}

int main()
{
    int choice,item;

    choice=1;

    while(choice)
    {
        printf("\n\n1 - Add\n2 - Inorder\n3 - Preorder\n4 - Postorder\n0 - Exit ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("\nEnter item to add ");
                    scanf("%d",&item);
                    root=add(root,item);
                    break;
            case 2: printf("\n");
                    inorder(root);
                    break;
            case 3: printf("\n");
                    preorder(root);
                    break;
            case 4: printf("\n");
                    postorder(root);
                    break;

            case 0: break;
            default: printf("\nInvalid input ");
        }
    }
    return 0;
}