#include<stdio. h> 
#include<conio.h>
void main()
{
	int a[5][5];
	int row, col,i,j,cnt=0;
	clrscr();
	printf("Enter the row size:");
	scanf ("%d",&row);
	printf("Enter the coloum size:");
	scanf("%d",&col);
	for (i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			printf("\nEnter the a[%d][%d]:",i,j);
			scanf("%d",&a[i][j]);
			if(a[i][j]==0)
			{
				cnt++;
			}
		}
	}
	printf("\nMatrix is: \n");
	for(i=0;i<row;i++)
	{	
		for(j=0;j<col;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n") ;
	}
	if(cnt<(row*col/2))
	{
		printf("\nThis matrix is not sparse matrix......");
	}
	else
	{
		printf("\n fast transpose of sparse matrix is:\n");
		for (i=0;i<row;i++)
		{
			for(j=0;j<col;j++)
			{
				printf("%d",a[j][i]);
			}
			printf("\n");
		}
	}
	getch();
}