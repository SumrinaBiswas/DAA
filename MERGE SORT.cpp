#include<stdio.h>
# define m 100

void merge(int a[],int low,int mid,int high)
{
	int i=low;
	int j=mid + 1;
	int k=low;
	int b[high];
	while(i<=mid && j<=high)
	{
		if(a[i]<=a[j])
		{
			b[k]=a[i];
			i++;
		}
		else
		{
			b[k]=a[j];
			j++;
		}
		k++;
	}
	if(i>mid)
	{
		while(j<=high)
		{
			b[k]=a[j];
			j++;
			k++;
		}
	}
	else
	{
		while(i<=mid)
		{
			b[k]=a[i];
			i++;
			k++;
		}
	}
	for(int i=low;i<=high;i++) // iteration upto i==high and starting is low
	{
		a[i]=b[i];
	}
	
}
void mergesort(int a[],int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
	}
	
}
int main()
{
	int n,i,j;
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
	mergesort(ar,0,n-1);
	printf("\nSorted array : ");
	for(int i=0;i<n;i++)
	{
		printf("%d\t",ar[i]);
	}
}

