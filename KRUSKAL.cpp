#include<stdio.h>
#include<stdlib.h>
# define max_v 100

void sort(int r,int graph[max_v][max_v])
{
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<r-i-1;j++)
		{
			int t=graph[j][2];
			if(graph[j][2]>graph[j+1][2]) // checking weights 
			{
				// arrange u v w in decresing order(as per decreasing weights)
				for (int k = 0; k < 3; k++) 
				{
                    int temp = graph[j][k];
                    graph[j][k] = graph[j + 1][k];
                    graph[j + 1][k] = temp;
                }
			}
		}
	}
}

void makeset(int parent[],int rank[],int row)
{
	int i;
	for(i=0;i<row;i++)
	{
		parent[i]=i;
		rank[i]=0;
	}
}

int findparent(int parent[],int node)
{
	if(parent[node]==node)
		return node;
	
	return parent[node]=findparent(parent,parent[node]);	
}

void unions(int s,int t,int parent[],int rank[],int row)
{
	s=findparent(parent,s);
	t=findparent(parent,t);
	
	if(rank[s]<rank[t])
		parent[s]=t;
	else if(rank[s]>rank[t])
		parent[t]=s;
	else
	{
		parent[t]=s;
		rank[s]++;
	}
}

void kruskal(int graph[max_v][max_v],int row)
{
	int parent[row],rank[row];
	int mincost=0;
	sort(row,graph); // sort edges with decreasing weights
	makeset(parent,rank,row);  // initiallize parent and rank
	
	for(int i=0;i<row;i++)
	{
		int wt=graph[i][2]; // coloumn = w
		int v1=findparent(parent,graph[i][0]); //coloumn = u
		int v2=findparent(parent,graph[i][1]); // coloumn = v
		if(v1 != v2)
		{
			unions(v1,v2,parent,rank,row);
			mincost = mincost+wt;
			printf("%d----%d \t %d\n",graph[i][0],graph[i][1],wt);
		}
	}
	printf("\nMin cost = %d",mincost);
}

int main()
{
	int v;
	printf("Enter row :");
	scanf("%d",&v);
	int graph[max_v][max_v];
	for(int i=0; i<v;i++)
	{
		for(int j=0;j<3;j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
	printf("u\tv\tw\n");
	for(int i=0; i<v;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("%d\t",graph[i][j]);
		}
		printf("\n");
	}
	
	kruskal(graph,v);
}




