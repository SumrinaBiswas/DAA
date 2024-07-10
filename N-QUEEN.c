
#include<stdio.h>
#include<conio.h>
#define m 100
int is_safe(int r,int c,int n,int arr[m][m])
{
	// for coloumns
	for(int row=0; row<r; row++)
	{
		if(arr[row][c]==1)
			return 0;
	}
	
	int x=r;
	int y=c;
	// for left diagonal
	while(x>=0 && y>=0)
	{
		if(arr[x][y]==1)
			return 0;
		x--;
		y--;
	}
	// for right diagonal
	while(x>=0 && y<n)
	{
		if(arr[x][y]==1)
			return 0;
		x--;
		y++;
	}
	return 1;
}

int nQueen(int arr[m][m],int r,int n) //r=row
{
	// base condition
	if(r>=n)
		return 1;
	
	//recursion
	for(int col=0; col<n; col++)
	{
		if(is_safe(r,col,n,arr))
		{
			arr[r][col]=1;
			if(nQueen(arr,r+1,n))
			{
				return 1;
			}
			// if false
			arr[r][col]=0; // backtracking
		}
	}
	return 0;
}
void initialize(int arr[m][m],int n)
{
	for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				arr[i][j]=0;
			}
			
		}
}

int main()
{
	int n;
	printf("\nEnter N = ");
	scanf("%d",&n);
	int arr[m][m];
	
	initialize(arr,n);
	
	if(nQueen(arr,0,n))
	{
	
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				printf("%d\t",arr[i][j]);
			}
			printf("\n");
		}
	}
}
