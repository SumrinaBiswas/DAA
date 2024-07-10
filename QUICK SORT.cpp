#include<stdio.h>
void swap(int a[],int i,int j)
{
	int t=a[i];
	a[i]=a[j];
	a[j]=t;
}
int partition(int a[],int low,int high)
{
	int pivot=a[low];
	int s=low;
	int e=high;
	while(s<e)
	{
		while(pivot>=a[s])  
			s++;
		while(pivot<a[e])
			e--;
		if(s<e)
			swap(a,s,e);
	}
	swap(a,low,e);
	return e;
}
void quicksort(int a[],int start,int end)
{
	if(start<end)
	{
		int loc=partition(a,start,end);
		quicksort(a,start,loc-1);
		quicksort(a,loc+1,end);
	}

}
int main()
{
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
	quicksort(ar,lb,n-1);
	printf("\nSorted array : ");
	for(int i=0;i<n;i++)
	{
		printf("%d\t",ar[i]);
	}
}

