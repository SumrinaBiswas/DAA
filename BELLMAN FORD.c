#include<stdio.h>
#define max 100
int dist[100];
int graph[100][100];
void initialize(int n)
{
	for(int i=0;i<n;i++)
	{
		dist[i]=10000;		// set dist of all vertices = infinite
	}
}
void print(int n)
{
	printf("\nVertex\t\tDistance from source\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t\t\t%d\n",i,dist[i]);
	}
}


void bellman(int n,int start)
{
	initialize(n);
	dist[start]=0; // set start vertex's dist = 0
	
	// relaxation
	for(int k=1;k<n;k++) 		//iteration n-1 times
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(graph[i][j]!=0 && dist[i]+graph[i][j] < dist[j])
				{
					dist[j]=dist[i]+graph[i][j];
				}
			}
		}
	}
	print(n);
	// negetive cycle
	
	for(int i=0;i<n;i++)  // iteration for nth time
	{
		for(int j=0;j<n;j++)
		{
			if(graph[i][j]!=0 && dist[i]+graph[i][j] < dist[j])
			{
				printf("-ve cycle detected, bellman fails ");
			}
		}
	}
}


int main()
{
	int n,s;
	printf("\nEnter no of vertex : ");
	scanf("%d",&n);
	printf("Enter graph elem : \n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&graph[i][j]);
		}
		printf("\n");
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d\t",graph[i][j]);
		}
		printf("\n");
	}
	printf("\nenter the source : ");
	scanf("%d",&s);
	bellman(n,s);
	
		
}
