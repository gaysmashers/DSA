#include<stdio.h>
#define max 4
int mat[max][max], visited[max];
void display();
void dfs(int i);
void main()
{
	char replay;
	int i,j;
	for(i=0;i<max;i++)
	{
		for(j=0;j<max;j++)
		{
			printf("is there edge between v%d and v%d ?(y/n:",i+1,j+1);
			scanf("%c",&replay);
			if(replay=='y' || replay=='Y')
			{
				mat[i][j]=1;
			}
			else
			{
				mat[i][j]=0;
			}
		}
	}
	display();
	for(i=0;i<max;i++)
	{
		visited[i]=0;
	}
	printf("DFS traversal:");
	dfs(0);
	printf("\n");
	getch();
}
void display()
{
	int i,j;
	printf("\n----------------\n");
	printf("Adjecancy matrix:\n");
	for(i=0;i<max;i++)
	{
		for(j=0;j<max;j++)
		{
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
	printf("\n----------------\n");
}
void dfs(int i)
{
	int j;
	printf("%d\t",i+1);
	visited[i]=1;
	for(j=0;j<max;j++)
	{
		if(!visited[j] && mat[i][j]==1)
		{
			dfs(j);
		}
	}
}