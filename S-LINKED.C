#include<stdio.h>
#include<conio.h>
struct node
{
	int data;
	struct node *next;
}*start=NULL,*temp, *move, *temp1;
void create(int num);
void display();
void insert_beg();
void insert_end();
void delete_beg();
void delete_end();
void insert_pos();
void delete_pos();
void main()
{
	int ch,num;
	char choice='Y';
	clrscr();
	while(1)
	{
		printf("\n-------------------\n");
		printf("\n1. Create");
		printf("\n2.Insert at begining");
		printf("\n3.Insert at end");
		printf("\n4.Delete at begining");
		printf("\n5. Delete at end");
		printf("\n6.Insert at specific position");
		printf("\n7.Delete at specific position");
		printf("\n8.Display");
		printf("\n9.Exit");
		printf("\nEnter your choice:");
		scanf ("%d",&ch);
		printf("\n-----------------------\n");
		switch(ch)
		{
			case 1:
				choice='Y';
				while(choice== 'y' || choice=='Y')
				{
					printf("Enter the no: ");
					scanf("%d",&num);
					create(num);
					display();
					flushall();
					printf("\nDo you want to continue(Y/y):");
					scanf("%c",&choice);
				}
			break;
			case 2:
				insert_beg();
			break;
			case 3:
				insert_end();
			break;
			case 4:
				delete_beg() ;
			break;
			case 5:
				delete_end();
			break;
			case 6:
				insert_pos();
			break;
			case 7:
				delete_pos();
			break;
			case 8:
				display() ;
			break;
			case 9:
				exit(0);
			default:
				printf("\n enter valid input......\n");
		}
	}
}
void create(int num)
{
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=num;
	temp->next=NULL;
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		move=start;
		while(move->next!=NULL)
		{
			move=move->next;

		}
		move->next=temp;
	}
}
void display()
{
	if(start==NULL)
	{
		printf("\nlist is empty....\n");
	}
	else
	{
		move=start;
		printf("List is:");
		while (move->next!=NULL)
		{
			printf("%d | %d->\t",move->data,move->next);
			move=move->next;
		}
		printf("%d | %d ->\t",move->data,move->next);
	}
}
void insert_beg()
{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the no:");
	scanf("%d",&temp->data);
	temp->next=start;
	start=temp;
	printf("Node inserted..");
}
void insert_end()
{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the no:");
	scanf("%d",&temp->data);
	temp->next=NULL;
	move=start;
	while (move->next!=NULL)
	{
		move=move->next;
	}
	move->next=temp;
	printf("Node inserted at end .....");
}
void delete_beg()
{
	temp=start;
	start=start->next;
	free(temp);
	printf("first node deleted....");
}
void delete_end()
{
	temp=start;
	while(temp->next!=NULL)
	{
		temp1=temp;
		temp=temp->next;
	}
	temp1->next=NULL;
	free(temp);
	printf("last node deleted....");
}
void insert_pos()
{
	int pos,i;
	printf("Enter the position:");
	scanf("%d",&pos);
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data:");
	scanf ("%d",&temp->data);
	temp->next=NULL;
	move=start;
	for(i=1;i<pos;i++)
	{
		move=move->next;
	}
	temp->next=move->next;
	move->next=temp;
	printf("node inserted.......");
}
void delete_pos()
{
	int pos,i;
	printf("Enter the position:");
	scanf("%d",&pos);
	move=start;
	for(i=1;i<pos;i++)
	{
		temp=move;
		move=move->next;
	}
	temp->next=move->next;
	free(move);
	printf("node deleted....");
}