#include<stdio.h>
#include<stdlib.h>
#define max 5
int front=-1;
int rear=-1;
int queue[max];
void enqueue()
{
	int data;
	printf("Enter the data:");
	scanf("%d", &data);
	if(front==-1 && rear==-1)
	{
		front=rear=0;
		queue[rear]=data;
		printf("\n %d is inserted",data);
	}
	else if((rear+1)%max==front)
	{
		printf("queue is overflow.....");
	}
	else
	{
		rear=(rear+1)%max;
		queue [rear]=data;
		printf("\n %d is inserted" ,data);
	}
}
void dequeue()
{
	if(front==-1 && rear==-1)
	{
		printf("Queue is undeflow....");
	}
	else if(front==rear)
	{
		printf("Dequeue element:%d",queue[front]);
		front=rear=-1;
	}
	else
	{
		printf ("Dequeue element:%d", queue[front]);
		front=(front+1)%max;
	}
}
void display()
{
	int i=front;
	if(front==-1 && rear==-1)
	{
		printf("Queue is empty");
	}
	else
	{
		printf("Queue is:");
		while(i!=rear)
		{
			printf("d\t", queue[i]);
			i=(i+1)%max;
		}
		printf("d\t", queue[i]);
	}
}
void main()
{
	int ch;
	while(1)
	{
		printf("\n.....................\n");
		printf ("\n1. Enqueue");
		printf("\n2.Dequeue");
		printf("\n3.Display");
		printf("\n4.Exit");
		printf("\nEnter your choice:");
		scanf ("%d",&ch);
		printf("\n-------------------\n");
		switch (ch)
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
				exit (0);
			deafult:
				printf("\n ivalid choice......");
		}
	}
}

