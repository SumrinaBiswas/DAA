#include<stdio.h>
#include<stdlib.h>
# define max 100
int front=-1;
int rear=-1;
int queue[max];
int graph[max][max];
int isempty()
{
	if(front>rear || front==-1)
		return 1;
	return 0;
}
int isfull()
{
	if(rear==max-1)
		return 1;
	return 0;
}

void enq(int v)
{
	if(front==-1 && rear==-1)
		front=0;
	queue[++rear]=v;
}

int peek()
{
	return queue[front];
}

void dequeue()
{
	if(!isempty())
		front++;
}


void bfs(int n,int start)
{
	int visited[n];
	//int visited[n]={0};
	for (int i = 0; i < n; i++)
        visited[i] = 0;
	visited[start] = 1; // Marking start node as visited
	enq(start);
	
	while(!isempty())
	{
		int current=peek();
		dequeue();
		printf("%d\t",current);
		for(int i=0;i<n;i++)
		{
			if(graph[current][i]==1 && visited[i]==0)
			{
				visited[i]=1;
				enq(i);
			}
		}
	}
}


int main()
{
	int n;
	int s=0;
	printf("\nEnter the no of vertices :");
	scanf("%d",&n);
	//graph[n][n];
	printf("\nEnter the elem :");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d",&graph[i][j]);
		}
	}
	printf("\n Graph:\n");
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d\t",graph[i][j]);
		}
		printf("\n");
	}
	printf("\nBFS Traversal starting from vertex %d:\n", s);
	bfs(n, 0);
	
}
