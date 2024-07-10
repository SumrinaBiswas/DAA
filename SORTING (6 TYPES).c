#include<stdio.h>
#include<conio.h>


void display(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		printf("\t%d",a[i]);
	}
}

void swap(int a[],int i,int j)
{
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
 void bubble(int a[],int n)
 {
 	int i,j;
 	for(i=0;i<n-1;i++)
 	{
 		for(j=0;j<n-i-1;j++)
 		{
 			if(a[j+1]<a[j])
 			{
 				swap(a,j,j+1);
			}
		}
	 }
	 display(a,n);
 }
 
void selection(int a[],int n)
{
	int i,j,c;
 	for(i=0;i<n-1;i++)
 	{
 		int min=i;
 		for(j=i;j<n;j++)
 		{
 			if(a[j]<a[min])
			{
				min=j;				/// working with idx value , not with arrray elem
				
			}

		}
		swap(a,i,min);
	}
	display(a,n);
}
void insertion(int a[],int n)
{
	int i,j,key;
	for(i=1;i<n;i++)
	{
		key=i;
		j=i-1;
		while(j>=0 && a[j]>a[key])
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=a[key];
	}
	display(a,n);
}

int partition(int a[],int low, int high)		// low=lowest idx || high=highest idx
{
	int pivot=a[low];
	int start=low;
	int end=high;
	while(start>end)
	{
		while(pivot>a[start])
			start++;
		while(pivot<=a[end])
			end--;
		if(start>end)
			swap(a,low,end);
		else
			swap(a,start,end);
	}
	return end;
}

void quicksort(int a[],int low,int high)
{
	int n=high;
	if(low<high)
	{
		int loc=partition(a,low,high);
		quicksort(a,low,loc-1);
		quicksort(a,loc+1,high);
	}
	
}

void merge(int a[],int l,int mid,int h)
{
	int i=l;
	int j=mid+1;
	int b[h], k=l;
	while(i<=mid && j<=h)
	{
		if(a[i]<=a[j])
		{
			b[k]=a[i];
			i++;
		}
		if(a[i]>a[j])
		{
			b[k]=a[j];
			j++;
		}
		k++;
	}
	if(i>mid)
	{
		while(j<=h)
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
	for(k=l;k<=h;k++)
		a[k]=b[k];
	return ;
}

void mergesort(int a[],int lb,int ub)
{
	if(lb<ub)
	{
		int mid=(lb+ub)/2;
		mergesort(a,lb,mid);
		mergesort(a,mid+1,ub);
		merge(a,lb,mid,ub);
	}
}
void maxheapify(int a[],int i,int n)	// i= checking each level parent node
{
	int l=2*i;
	int r=2*i+1;
	int largest=i;
	while(l<=n && a[largest]<a[l])	// checking for left child
	{
		largest=l;
	}
	while(r<=n && a[largest]<a[r])
	{
		largest=r;
	}
	if(largest!=i)
	{
		swap(a,i,largest);
		maxheapify(a,largest,n);
	}
}
void heapsort(int a[], int n)
{
	//build maxheap
	for(int i=n/2;i>1;i--)
	{
		maxheapify(a,i,n);
	}
	//making sorted maxheap using deletion method
	for(int i=n;i>1;i--)
	{
		swap(a,i,1);
		maxheapify(a,1,i-1);
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
	display(ar,n);

	while(1)
	{
		printf("\n1.Bubble Sort\n2.Selection\n3.Quick\n4.Insertion\n5.Merge\n6.heap sort\n0.exit\n");
		int ch;
		printf("\nenter ch :");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("Sorted array :");
			bubble(ar,n);
		}
		else if(ch==2)
		{
			printf("Sorted array :");
			selection(ar,n);
		}
		else if(ch==3)
		{
			printf("Sorted array :");
			quicksort(ar,0,n-1);			// n= size of array, high==(n-1)
			display(ar,n);
			
		}
		else if(ch==4)
		{
			printf("Sorted array :");
			insertion(ar,n);
		}
		else if(ch==5)
		{
			printf("Sorted array :");
			mergesort(ar,0,n-1);
			display(ar,n);
		}
		else if(ch==6)
		{
			printf("Sorted array :");
			heapsort(ar,n);
			display(ar,n);
		}
		else if(ch==0)
			break;
		else
			printf("\ninvalid");
	}
 }
