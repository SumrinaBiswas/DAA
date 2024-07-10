#include<stdio.h>
#define m 100
int is_safe(int g[m][m],int node,int colour[m],int col, int V)
{
	for(int i=0;i<V;i++)
	{
		if(i!=node && g[node][i]==1 && colour[i]==col)
			return 0;
	}
	return 1;
}


int m_colour(int g[m][m],int colour[m],int V,int node,int c) // c= no of colour
{
	//base condition
	if(node>=V)
		return 1;
	
	for(int i=1;i<=c;i++)
	{
		if(is_safe(g,node,colour,i,V))
		{
			colour[node]=i;
			
			if(m_colour(g,colour,V,node+1,c))
				return 1;
			
			//if false
			colour[node]=0;	//backtracking
		}
	}
	return 0; // if no of colour is not sufficient
}

void solution(int colour[m],int c,int V)
{
	printf("\nsuccesfully colored by %d colours\n",c);
	for(int i=0;i<V;i++)
	{
		printf("%d\t",colour[i]);
	}
}

void initialize(int colour[m],int V)
{
	for(int i=0;i<V;i++)
		{
			colour[i]=0;
		}
}
int main()
{
	int graph[m][m];
	int colour[m];
	int V;
	int c;
	printf("\nEnter vertices : ");
	scanf("%d",&V);
	printf("\nEnter colour : ");
	scanf("%d",&c);	
	printf("Enter graph elem : \n");
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			scanf("%d",&graph[i][j]);
		}
		printf("\n");
	}
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			printf("%d\t",graph[i][j]);
		}
		printf("\n");
	}
	
	initialize(colour,V);
	
	int x=m_colour(graph,colour,V,0,c);
	if(x!=0)
		solution(colour,c,V);
	else
		printf("can't be coloured by %d colours",c);	
}
