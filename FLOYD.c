#include<stdio.h>
#define max 100

int mat[max][max];


void print(int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
}
void floyd(int n)
{
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(mat[i][j] < mat[i][k]+mat[k][j])	// minimum b/w mat[i][j] , mat[i][k] + mat[k][j]
					mat[i][j]=mat[i][j];
				else
					mat[i][j]=mat[i][k]+mat[k][j];
			}
		}
	}
	print(n);
}

int main()
{
	int n;
	printf("\nEnter no of vertex : ");
	scanf("%d",&n);
	printf("Enter graph elem : \n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&mat[i][j]);
		}
		printf("\n");
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
	printf("\nAll pairs shortest path \n");
	floyd(n);
}
