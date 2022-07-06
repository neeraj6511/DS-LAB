#include<stdio.h>

void insert(int a[],int *size,int loc,int key)
{
	int i;

	for(i=*size-1;i>=loc-1;i--)
	a[i+1]=a[i];


	a[loc-1]=key;

	++(*size);

}


void display(int a[],int size)
{
	int i;

	putchar('\n');

	for(i=0;i<size;i++)
	printf("%d ",a[i]);





}


void del(int a[],int* size,int loc)
{
	int i;

	for(i=loc-1;i<*size-1;i++)
	a[i]=a[i+1];

	(*size)--;


}


void input(int a[],int size)
{
	int i;

	printf("\nEnter %d elements in the 2nd array ",size);

	for(i=0;i<size;i++)
	scanf("%d",&a[i]);

}


void bubbleSort(int a[],int size)
{
	int i,j,temp;

	for(i=0;i<size-1;i++)
	{
		for(j=0;j<size-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];

				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}

}


void merge(int a[],int size1,int b[],int size2)
{
	int c[200],i,j,k;

	i=j=k=0;

	while(i<size1 && j<size2)
	{
		if(a[i]<b[j])
		c[k++]=a[i++];

		else c[k++]=b[j++];

	}


	while(i<size1)
	c[k++]=a[i++];

	while(j<size2)
	c[k++]=b[j++];


	display(c,k);

}

int main()
{       int a[100],loc,key,choice=1,i,b[100],size1,size2;

	printf("\nEnter size of the array ");
	scanf("%d",&size1);

	printf("\nEnter %d values ",size1);

	for(i=0;i<size1;i++)
	scanf("%d",&a[i]);

	while(choice)
	{

		printf("\n\n1 - Insert\n2 - Delete\n3 - Merge Sorted Arrays\n4 - Display\n0 - Exit ");
		scanf("%d",&choice);

		switch(choice)
		{
		   case 1:printf("\nEnter location and key ");
			  scanf("%d%d",&loc,&key);
			  insert(a,&size1,loc,key);
			  break;

		   case 2:printf("\nEnter location for deletion ");
			  scanf("%d",&loc);
			  del(a,&size1,loc);
			  break;

		   case 3:printf("\nEnter number of elements in 2nd array ");
			  scanf("%d",&size2);

			  input(b,size2);
			  bubbleSort(a,size1);
			  bubbleSort(b,size2);
			  printf("\nCombined array is \n");
			  merge(a,size1,b,size2);
			  break;
		   case 4:display(a,size1);


		}



	}


	return 0;

}