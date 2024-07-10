#include<stdio.h>

void maxmin(int a[],int i,int j,int *max,int *min)
{
	
	int max1,min1,min2,max2;
	if(i==j)
	{
		*max=a[i];
		*min=a[i];
	}
	else if(i+1==j)
	{
		if(a[i]>=a[j])
		{
			*max=a[i];
			*min=a[j];
		}
		else
		{
			*max=a[j];
			*min=a[i];
		}
	}
	else
	{
		int mid=(i+j)/2;
		maxmin(a,i,mid,&max2,&min2);
		maxmin(a,mid+1,j,&max1,&min1);
		if(max1>max2)
			*max=max1;
		else
			*max=max2;
		if(min1<min2)
			*min=min1;
		else
			*min=min2;
	}
	
}

int main()
{
	int maximum=0;
	int minimum=10000;
	int n,i,j;
	int lb=0;
 	printf("\nSize of array :");
 	scanf("%d",&n);
 	int ar[n];
 	printf("\nEnter array elem : ");
 	for(i=0;i<n;i++)
	{
		scanf("%d\t",&ar[i]);
	}
	printf("\nArray : ");
	for(int i=0;i<n;i++)
	{
		printf("%d\t",ar[i]);
	}
	maxmin(ar,0,n-1,&maximum,&minimum);
	printf("\nmax = %d\nmin = %d",maximum,minimum);
}
