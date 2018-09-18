#include <stdio.h>
#include <stdlib.h>

int q[60]; //����
int front,rear; //����ָ��
typedef struct  {
	int **adjMat;
	int *vex;
	int n_V;
	int n_E;
}graph;

void creat(graph *g) {
	/************************************************************************/
	/* ����ͼ                                                                     */
	/************************************************************************/
	printf("Plz input the number of vertices:\n");
	scanf("%d",&g->n_V);
	printf("Plz input the number of edge:\n");
	scanf("%d",&g->n_E);
	g->adjMat = (int **)malloc(sizeof(int)g->n_V);
	for (int i=0;i<g->n_V;i++)
	{
		g->adjMat[i] = (int *)malloc(sizeof(int)* g->n_V);
	}
	g->vex = (int *)malloc(sizeof(int)* g->n_V);
	printf("Plz input the information of vertices:\n");
	for (i=0;i<g->n_V;i++)
	{
		scanf("%d",&g->vex[i]);
	}
	
	for (i=0;i<g->n_V;i++)
	{
		for (int j=0;j<g->n_V;j++)
		{
			g->adjMat[i][j] = 0;
		}
	}
	printf("Plz intput the information of matrix just like 1,2:\n");
	int row,col;
	for (i=0;i<g->n_E;i++)
	{
		scanf("%d,%d",&row,&col);
		g->adjMat[row-1][col-1] = 1;
	}
}

void dfs_explore(graph g,int i,int* visited) {
	printf("%d\n",g.vex[i]);
	visited[i] = 1;
	for (int j=0;j<g.n_V;j++)
	{
		if (g.adjMat[i][j] == 1 && visited[j] == 0)
		{
			dfs_explore(g,j,visited);
		}
	}
}
void dfs(graph g) {
	/************************************************************************/
	/* ������������㷨�����ڽӾ���                                                                     */
	/************************************************************************/
	int* visited = (int *)malloc(sizeof(int)*g.n_V);
	for (int i=0;i<g.n_V;i++)
	{
		visited[i] = 0;
	}
	for (i=0;i<g.n_V;i++)
	{
		if (visited[i] == 0)
		{
			dfs_explore(g,i,visited);
		}
	}
}

void bfs(graph g) {
	/************************************************************************/
	/* ������������㷨�����ڽӾ���                                                                     */
	/************************************************************************/
	front = rear = 0;
	int temp;
	int * visited = (int *)malloc(sizeof(int)*g.n_V);
	for (int i=0;i<g.n_V;i++)
	{
		visited[i] = 0;
	}
	for (i=0;i<g.n_V;i++) //���ѭ����֤ÿһ��Ԫ�ض������ʵ�
	{
		if (visited[i] == 0)
		{
			q[rear++] = i; //�����
			do {
				temp = q[front++]; //�����в���¼��ֵ
				printf("%d\n",g.vex[temp]);
				visited[temp] = 1; //�����е�ͬʱ�����ʱ�־
				for (int j=0;j<g.n_V;j++)
				{
					if (g.adjMat[temp][j] == 1 && visited[j] == 0)
					{
						q[rear++] = j; //����i���ڵ�������ӽڵ������
					}
				}
			} while(front != rear); //���в�Ϊ��
		}
	}
}
void display_matrix(graph g) {
	/************************************************************************/
	/* ��ӡ�ڽӾ���                                                                     */
	/************************************************************************/
	for (int i=0;i<g.n_V;i++)
	{
		for (int j=0;j<g.n_V;j++)
		{
			printf("%d\t",g.adjMat[i][j]);
		}
		printf("\n");
	}
}
