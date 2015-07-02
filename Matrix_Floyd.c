/*
 ************************************************
 *Name : Matrix_Floyd.c                         *
 *Date : 2015-06-17                             *
 *Author : sniper                               *
 *Aim : Floyd algrithm to get the shortest route*
 *      each node to others in the graph        *
 ************************************************
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MATRIX_NUMBER 100
#define INF 32768

int main()
{
	int i,j,k,l; 
	int node_count,edge_count;
	int node_pair1,node_pair2,weight;
	int Distance[MAX_MATRIX_NUMBER][MAX_MATRIX_NUMBER];
	int edge[MAX_MATRIX_NUMBER][MAX_MATRIX_NUMBER];
	int Path[MAX_MATRIX_NUMBER][MAX_MATRIX_NUMBER];

	node_count=edge_count=node_pair1=node_pair2=weight=0;	
	printf("please input the number of node and edge: ");
	scanf("%d %d",&node_count,&edge_count);	
	memset(Distance,0,sizeof(Distance));
	memset(edge,0,sizeof(edge));
	memset(Path,0,sizeof(Path));

	/*
	 *Create the graph
	 */
	for(i=0;i<edge_count;i++)
	{
		printf("please input the node pair: ");  
		/*
		 *node_pair1 node_pair2 two side of edge and 
		 *the weight means the weight of edge
		 */
		scanf("%d %d %d",&node_pair1,&node_pair2,&weight); 					
		edge[node_pair1][node_pair2] = weight;
	}
	printf("after create the graph is :\n");  
	for(i=0;i<node_count;i++)
	{
		for(j=0;j<node_count;j++)
		{
			if(i!=j && edge[i][j]==0)
				edge[i][j]=INF;
			printf(" %d ",edge[i][j]);
		}
		printf("\n");
	}

	/*
	 *Floyd
	 */
	for(i=0;i<node_count;i++)
	{
		for(j=0;j<node_count;j++)
		{
			Distance[i][j]=edge[i][j];
				printf(" %d ",Distance[i][j]);
			for(k=0;k<node_count;k++)
				if(Distance[i][j]>0)
				{
					(Path+i)[j][i]=1;
					(Path+i)[j][j]=1;
				}
		}
		printf("\n");
	}
	printf("+++++++++++++++++++++++++++++++++\n");
	for(i=0;i<node_count;i++)
		for(j=0;j<node_count;j++)
			for(k=0;k<node_count;k++)
				if(Distance[j][i]+Distance[i][k]<Distance[j][k])
				{
					Distance[j][k]=Distance[j][i]+Distance[i][k];
					for(l=0;l<node_count;l++)
						(Path+j)[k][l] = (Path+j)[i][l]||(Path+i)[k][l];
				}
	for(i=0;i<node_count;i++)
	{
		for(j=0;j<node_count;j++)
		{
			if(Distance [i][j]!=0 && Distance[i][j]!=32768 && (j==0 || j==8 || j==9 || j==17))			
			{
				printf("%c -> %c = %d \n",i+'A',j+'A',Distance[i][j]);
			}
		}
	}
	return 0;
}
