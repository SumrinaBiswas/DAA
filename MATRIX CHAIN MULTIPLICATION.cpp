#include<stdio.h>
# define max 100

int p[max]; // arry to store dimension of arrays
void print(int n,int a[max][max])
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}

void chain_mul(int n) // n= no of dimensions
{
	int cost[max][max], s[max][max];
	//initialize tables
	for(int i=0;i<n;i++) 			// i= 0 1 2 3 4 and
	{								// for i=0th row all elements are 0  and diagonal element of cost table always 0
		for(int j=0;j<n;j++)		// for j=0th coloumn's elem =0
		{
			cost[i][j]=0;
			s[i][j]=0;
		}
	}
	
	int diff,min,q;
	int c[n][n];
	for(diff=1;diff<n-1;diff++)	// differnce between i & j , j-i=diff
	{
		min=100000;
		for(int i=1;i<n-diff;i++) // i= row number
		{
			int j=i+diff; // j= column number
			for(int k=i;k<j;k++)
			{
				q=cost[i][k]+cost[k+1][j]+ p[i-1]*p[k]*p[j];
				if(q<min)
				{
					min=q;
					s[i][j]=k; // k-value
				}
			}
			cost[i][j]=min; // mincost
		}
	}
	print(n,cost);
	printf("\n k value \n");
	print(n,s);
	printf("\nTotal multiplication required : %d",cost[1][n-1]); // i=1 , j= n-1 = m (no of matrix)
	
}

void showparenthesis(int n)
{
	
}
int main()
{
	int n,m;
	printf("\nTotal matrix : ");
	scanf("%d",&m);
	n=m+1;		// total dimension = m+1 , m= no of matrices
	printf("\nEter Dimensions : ");  
	for(int i=0;i<m+1;i++)
	{
		scanf("%d",&p[i]);
	}
	chain_mul(n);
}
