#include<stdio.h>
#include<conio.h>
struct node
{
	int data;
	struct node *next,*prev;
}*start=NULL,*end=NULL, *temp, *move;
void insert();
void display();
void insert_beg();
void delete_beg(); 
void delete_end();
void rev();
void delete_pos();
void main()
{
	int ch;
	clrscr();
	while(1)
	{
		printf("\n--------\n");
		printf("1.Insert");
		printf("\n2.Insert at beginnig");
		printf("\n3.Delete at beginnig");
		printf("\n4. Delete at end");
		printf("\n5. Reverse display list");
		printf("\n6.Delete at specified position");
		printf("\n7.Display");
		printf("\n8. Exit");
		printf("\nEnter your choice:");
		scanf("%d",&ch);
		printf("\n----------------\n");
		switch(ch)
		{
			case 1:
				insert();
			break;
			case 2:
				insert_beg();
			break;
			case 3:
				delete_beg();
			break;
			case 4:
				delete_end();
			break;
			case 5:
				rev();
			break;
			case 6:
				delete_pos();
			break;
			case 7:
				display();
			break;
			case 8:
				exit(0);
			break;
			default:
				printf("\n enter valid choice.....\n");
		}
	}
	//getch();
}
void insert()
{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data:");
	scanf ("%d",&temp->data);
	temp->next=NULL;
	temp->prev=NULL;
	if(start==NULL)
	{
		start=temp; 
		end=temp;
	}
	else
	{
		move=start;
		while(move->next!=NULL)
		{
			move=move->next;
		}
		move->next=temp;
		temp->prev=move;
		end=temp;
	}
	printf("\n node inserted......");
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
		printf("List is: ");
		while (move->next!=NULL)
		{
			printf("%d \t",move->data);
			move=move->next;
		}
		printf("%d \t",move->data);
	}
}
void insert_beg()
{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the no:");
	scanf("%d",&temp->data);
	temp->next=start;
	temp->prev=NULL;
	start=temp;
	printf("Node inserted at beginning..");
}
void delete_beg()
{
	temp=start;
	start=start->next;
	start->prev=NULL;
	free(temp);
	printf("first node deleted....");
}
void delete_end()
{
	move=start;
	while(move->next!=NULL)
	{
		temp=move;
		move=move->next;
	}
	temp->next=NULL;
	free(move);
	printf("last node deleted....");
}
void rev()
{
	move=end;
	printf("reverse list is: ");
	while(move->prev!=NULL)
	{
		printf("%d\t",move->data);
		move=move->prev;
	}
	printf("%d",move->data);
}
void delete_pos()
{
	int pos,i;
	struct node *temp1;
	printf("Enter the position:");
	scanf("%d",&pos);
	move=start;
	for(i=1;i<=pos;i++)
	{
		temp=move;
		move=move->next;
	}
	temp->next=move->next;
	temp1=move->next;
	temp1->prev=move->prev;
	free(move);
	printf("node deleted....");
}