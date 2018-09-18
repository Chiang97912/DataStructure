#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
	int **adjMat;
	char *vex;
	int n_V;
	int n_E;
}graph;

typedef struct {
	int *base;
	int front,rear;
	int size;
}queue;

void create(graph *g) {
	/************************************************************************/
	/* 创建图——邻接矩阵                                                                     */
	/************************************************************************/
	printf("Plz input the number of vertices and arcs:\n");
	scanf("%d%d",&g->n_V,&g->n_E);
	g->adjMat = (int **)malloc(sizeof(int)g->n_V);
	for (int i=0;i<g->n_V;i++)
	{
		g->adjMat[i] = (int *)malloc(sizeof(int)* g->n_V);
	}
	g->vex = (char *)malloc(sizeof(char)* g->n_V);
	printf("Plz input the information of vertices:\n");
	getchar();
	for (i=0;i<g->n_V;i++)
	{
		scanf("%c",&g->vex[i]);
	}

	for (i=0;i<g->n_V;i++)
	{
		for (int j=0;j<g->n_V;j++)
		{
			g->adjMat[i][j] = INT_MAX;
		}
	}
	printf("Plz intput the value of the two vexteies and it's weight just like 1 2 1:\n");
	int row,col,weight;
	for (i=0;i<g->n_E;i++)
	{
		scanf("%d%d%d",&row,&col,&weight);
		g->adjMat[row-1][col-1] = weight;
	}
}

void dijkstra(graph g,int v) {
	/************************************************************************/
	/* 最短路径——迪杰斯特拉算法                                                                     */
	/************************************************************************/

	/* v表示源点 */
	queue *q = (queue *)malloc(sizeof(queue)*g.n_V); //路径队列
	int *set = (int *)malloc(sizeof(int)*g.n_V); //该数组用于判断是否找到索引值对应顶点的最短路径
	int *dist = (int *)malloc(sizeof(int)*g.n_V); //存储最短距离
	int min,index;

	for (int i=0;i<g.n_V;i++) //初始化set数组和队列的尾指针
	{
		set[i] = 0;
		q[i].rear = 0;
		q[i].base = (int *)malloc(sizeof(int)*g.n_V);
	}
	for (i=1;i<g.n_V;i++)
	{
		dist[i] = g.adjMat[v][i];
		if (dist[i]<INT_MAX)
		{
			/*将源点和当前顶点加入路径队列*/
			q[i].base[q[i].rear++] = v;
			q[i].base[q[i].rear++] = i;
		}
	}
	set[v] = 1; //对源点作访问标志
	for (int k=0;k<g.n_V-1;k++) //循环n_V-1次
	{
		index = v;
		min = INT_MAX;
		for (i=1;i<g.n_V;i++)
		{
			if (set[i]==0 && dist[i] < min) //寻找路径最短顶点的下标
			{
				index = i; //纪录最短顶点对应索引
				min = dist[i]; //纪录距离值
			}
		}
		if (set[index] == 0)
		{
			set[index] = 1; //对index顶点作访问标志
			printf("the %c's shortest distance is %d\n",g.vex[index],min);
			for (i=0;i<q[index].rear;i++)
			{
				printf("%c->",g.vex[q[index].base[i]]); //打印从源点到index的最短路径
			}
			printf("end\n");
			for (i=1;i<g.n_V;i++)
			{
				//printf("%d %d %d\n",dist[index] , g.adjMat[index][i] , dist[i]);
				if (set[i]==0 && dist[index] < INT_MAX && g.adjMat[index][i] < INT_MAX && dist[index] + g.adjMat[index][i] < dist[i]) //判断距离是否变短
				{ //条件dist[index] < INT_MAX 和 g.adjMat[index][i] < INT_MAX是为了防止数据溢出
					dist[i] = dist[index] + g.adjMat[index][i]; //更新距离数组
					/*更新路径*/
					for (int j=0;j<q[index].rear;j++)
					{
						q[i].base[j] = q[index].base[j];
					}
					q[i].rear = q[index].rear;
					q[i].base[q[i].rear++] = i;
				}
			}
		}
	}
}

void display_matrix(graph g) {
	/************************************************************************/
	/* 打印邻接矩阵                                                                     */
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