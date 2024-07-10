#include<stdio.h>
#include<stdlib.h>
#define V 100

void print(int dist[],int vertices)
{
	printf("vertices \t distance\n");
	for(int i=0;i<vertices;i++)
	{
		printf("%d \t\t %d\n",i,dist[i]);
	}
}
int minkey(int mstset[],int key[],int vertices)
{
	int min=10000;
	int min_idx=-1;
	for(int i=0;i<vertices;i++)
	{
		if(!mstset[i] && key[i]<min)
		{
			min=key[i];
			min_idx=i;
		}
	}
	return min_idx;
}
void dj(int vertices,int graph[V][V],int src)
{
	int mstset[V];
	int dist[V];
	
	for(int i=0;i<vertices;i++)
	{
		mstset[i]=0;
		dist[i]=100000;
	}
	dist[0]=0;
	
	for(int c=0;c<vertices-1;c++)
	{
		int u=minkey(mstset,dist,vertices);
		int v;
		mstset[u]=1;
		for(v=0;v<vertices;v++)
		{
			if(graph[u][v] && !mstset[v] && dist[u]!=100000 && (dist[u]+graph[u][v])<dist[v])
			{
				dist[v]=dist[u]+graph[u][v];
			}
		}
	}
	print(dist,vertices);
}

int main()
{
	int v;
	printf("Enter vertex :");
	scanf("%d",&v);
	int graph[V][V];
	printf("\nEnter elem \n");
	for(int i=0; i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
	for(int i=0; i<v;i++)
	{
		for(int j=0;j<v;j++)
		{
			printf("%d\t",graph[i][j]);
		}
		printf("\n");
	}
	
	dj(v,graph,0);
}
