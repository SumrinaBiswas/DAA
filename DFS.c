#include<stdio.h>
#include<stdlib.h>
# define max 100
int top=-1;
int stack[max];
int graph[max][max];

int isempty()
{
	if(top==-1)
		return 1;
	return 0;
}
int isfull()
{
	if(top==max-1)
		return 1;
	return 0;
}

void push(int v)
{
	if(isfull())
		printf("Stack is full");
	else
	{
		stack[++top]=v;
	}
}

void pop()
{
	if(!isempty())
		top--;
}
int peek()
{
	return stack[top];
}

void dfs(int start,int n)
{
	int visited[n];
	
	for(int i=0;i<n;i++)
		visited[i]=0;
	
	visited[start]=1;
	push(start);
	while(!isempty())
	{
		int current=peek();
		pop();
		printf("%d\t",current);
		for(int i=0;i<n;i++)
		{
			if(graph[current][i]==1 && visited[i]==0 )
			{
				visited[i]=1;
				push(i);
			}
		}
	}
}

int main()
{
	int n;
	int s=0;
	printf("\nEnter the no of vertices : ");
	scanf("%d",&n);
	printf("\nEnter the elem : ");
	
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
	printf("\nDFS Traversal starting from vertex %d:\n", s);
	dfs(0, n);
}
