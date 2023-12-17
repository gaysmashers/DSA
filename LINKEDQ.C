#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*rear=NULL, *front=NULL, *temp, *move;
void enqueue();
void dequeue(); 
void display();
void main()
{
	int ch;
	while(1)
	{
		printf("\n...................\n");
		printf("1.Enqueue");
		printf("\n2.Dequeue");
		printf("\n3.Display");
		printf("\n4.Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch) ;
		printf("\n------------\n");
		switch(ch)
		{
			case 1:
				enqueue();
			break;
			case 2:
				dequeue();
			break;
			case 3:
				display();
			break;
			case 4:
				exit(0);
			default:
				printf("\n invalid choice......");
		}
	}
}
void enqueue()
{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("\nEnter the data:");
	scanf("%d",&temp->data);
	temp->next=NULL;
	if(front==NULL && rear==NULL)
	{
		front=temp; 
		rear=temp;
		printf("Data inserted...\n");
	}
	else
	{
		rear->next=temp;
		rear=temp;
		printf("data inserted.....\n");
	}
}
void dequeue()
{
	if(front == NULL)
	{
		printf("Queue is empty....");
	}
	else
	{
		temp=front;
		front=front->next;
		free(temp);
		printf("data deleted");
	}
}
void display()
{
	if(front==NULL)
	{
		printf("Queue is empty....");
	}
	else
	{
		printf("Queue is: ");
		temp=front;
		while(temp!=NULL)
		{
			printf("%d\t", temp->data);
			temp=temp->next;
		}
	}
}