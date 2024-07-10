#include<stdio.h>
#include<conio.h>
#define max_v 100
int minkey(int mstset[], int key[], int vertices) 
{
	int min_idx=-1;
	int min=1000000;
	for(int i=0; i<vertices; i++)
	{
		if(!mstset[i] && key[i]<min)
		{
			min=key[i];
			min_idx=i;
		}
	}
	return min_idx;
}
void print(int vertices,int parent[],int graph[max_v][max_v])
{
	printf("Edge  \t Weight\n");
	for(int i=1;i<vertices;i++)
	{
		printf("%d-%d \t %d\n",parent[i],i,graph[i][parent[i]]);
	}
}
int prims(int graph[max_v][max_v],int vertices)
{
	int parent[max_v];
	int mstset[max_v];
	int key[max_v];
	
	// make mstset as false and set key value = infinite
	for(int i=0;i<vertices;i++)
	{
		mstset[i]=0;
		key[i]=1000000;
	}
	// keep 1st vertex's key=0 and parent=-1
	key[0]=0;
	parent[0]=-1;
	
	for(int c=0;c<vertices-1;c++)
	{
		// pick the min key from the set of vertices which not yet included in MST
		int u=minkey(mstset,key,vertices);
		// keep u in MST
		mstset[u]=1;
		for(int v=0;v<vertices;v++)
		{
			if(graph[u][v] && !mstset[v] && graph[u][v]<key[v])
			{
				parent[v]=u;
				key[v]=graph[u][v];	
		    }
		}
					
	}
	print(vertices,parent,graph);
}


int main()
{
	int v;
	printf("Enter vertex :");
	scanf("%d",&v);
	int graph[max_v][max_v];
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
	
	prims(graph,v);
}

