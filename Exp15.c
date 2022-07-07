#include<stdio.h>
int graph[50][50];
int size;

void addEdge(int a,int b)
{
    if(a<0 || a>=size || b<0 || b>=size)
        return;

    graph[a][b]=1;

}

void removeEdge(int a,int b)
{

    if(a<0 || a>=size || b<0 || b>=size)
        return;

    graph[a][b]=0;
}


void removeVertex(int a)
{
    int i;


    if(a<0 || a>=size)
        return;

    for(i=0;i<size;i++)
    {
        graph[a][i]=0;
        graph[i][a]=0;
    }
}

int allZeroes(int rowIndex)
{
    int i;

    for(i=0;i<size;i++)
    {
        if(graph[rowIndex][i]!=0)
            return 0;
    }

    return 1;
}

void display()
{

    int i,j;

    printf("\n\n");

    for(i=0;i<size;i++)
    {
            if(!allZeroes(i))
            {
                printf("\n%d is adjacent to ",i);

                for(j=0;j<size;j++)
                {
                    if(graph[i][j])
                        printf("%d ",j);
                }

                printf("\n");
            }
    }


}

int main()
{
    int choice,a,b;

    printf("\nEnter number of vertices in the graph ");
    scanf("%d",&size);

    choice=1;

    while(choice)
    {
        printf("\n\n1 - Add Edge ");
        printf("\n2 - Remove Edge ");
        printf("\n3 - Remove Vertex ");
        printf("\n4 - Display using adjacency matrix");
        printf("\n0 - Exit ");

        scanf("%d",&choice);

        switch(choice)
        {
            case 1: printf("\nEnter source and destination vertices ");
                    scanf("%d%d",&a,&b);
                    addEdge(a,b);
                    break;
            case 2: printf("\nEnter source and destination vertices ");
                    scanf("%d%d",&a,&b);
                    removeEdge(a,b);
                    break;
            case 3: printf("\nEnter vertex to delete ");
                    scanf("%d",&a);
                    removeVertex(a);
                    break;
            case 4: display();

        }
    }



    return 0;
}