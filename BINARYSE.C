#include<stdio.h>
int bsearch(int a[],int data,int low,int high);
void main()
{
	int a[100],data,i,n,pos;
	clrscr();
	printf("How many elements do you want to insert?");
	scanf("%d",&n);
	printf("Enter the elements in accending order:\n");
	for(i=0;i<n;i++)
	{
		printf("Enter the %d no elements:",i+1);
		scanf("%d",&a[i]);
	}
	printf("Enter the element which you want to search:");
	scanf("%d",&data);
	pos=bsearch(a,data,0,n-1);
	if(pos == -1)
	{
		printf("%d is not found.....",data);
		printf("\n");
	}
	else
	{
		printf("%d is found at %d position ",data,pos+1);
		printf("\n");
	}
	getch();
}
int bsearch(int a[],int data,int low,int high)
{
	int mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==data)
		{
			return mid;
		}
		else if(a[mid]<data)
		{
			low=mid+1;
		}
		else
		{
			high=mid-1;
		}
	}
	return -1;
}