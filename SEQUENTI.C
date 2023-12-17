#include<Stdio.h>
void main()
{
	int a[100],data,i,n,res=0;
	clrscr();
	printf("How many elements do you want to insert?");
	scanf("%d",&n);
	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
	{
		printf("Enter the %d no element:",i+1);
		scanf("%d",&a[i]);
	}
	printf("Enter the element which you want to search:");
	scanf("%d",&data);
	for(i=0;i<n;i++)
	{
		if(data==a[i])
		{
			printf("%d is found at position %d",data,i+1);
			printf("\n");
			res=1;
			break;
		}
	}
	if(res==0)
	{
		printf("%d is not found......",data);
		printf("\n");
	}
	getch();
}