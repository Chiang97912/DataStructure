#include <stdio.h>
#include <stdlib.h>

int q[30]; //队列
int front,rear; //队列指针

int s[30]; //堆栈
int top; //栈顶指针
typedef struct arcnode {
	/************************************************************************/
	/* 普通边节点                                                                     */
	/************************************************************************/
	int adjvex; //顶点值
	struct arcnode * nextarc; //下一条边节点
}arcnode;

typedef struct vexnode {
	/************************************************************************/
	/* 顶点                                                                     */
	/************************************************************************/
	int vexdata; //顶点值
	arcnode *firstarc; //第一条边节点
}vexnode;

typedef struct  {
	/************************************************************************/
	/* 图的结构体                                                                     */
	/************************************************************************/
	vexnode *vex; //顶点数组
	int n_V; //顶点数量
	int n_E; //边数量
}graph;

/************************************************************************/
/* 领接表法实现图                                                                     */
/************************************************************************/
void create(graph * g) {
	/************************************************************************/
	/* 创建图                                                                     */
	/************************************************************************/
	printf("Plz input the num of vertices and arcs:\n");
	scanf("%d%d",&g->n_V,&g->n_E);
	getchar(); //吸收掉回车符
	g->vex = (vexnode *)malloc(sizeof(vexnode)* g->n_V);
	printf("Plz input the information of vertices:\n");
	for (int i=0;i<g->n_V;i++)
	{
		scanf("%c",&g->vex[i].vexdata);
		g->vex[i].firstarc = NULL;
	}
	getchar(); //吸收掉回车符
	printf("Plz input the arcs just like 1,3:\n");
	int origin,destination;
	for (i=0;i<g->n_E;i++)
	{
		scanf("%d,%d",&origin,&destination);
		arcnode *p = (arcnode *)malloc(sizeof(arcnode));
		//头插法
		p->adjvex = destination - 1;
		p->nextarc = g->vex[origin-1].firstarc;
		g->vex[origin-1].firstarc = p;
	}
}

void dfs_explore(graph g,int i,int *visited) {
	visited[i] = 1; //访问标志
	printf("%c\n",g.vex[i].vexdata);
	arcnode *p = g.vex[i].firstarc;
	while (p && visited[p->adjvex] ==0)
	{
		dfs_explore(g,p->adjvex,visited); //先递归第一个顶点
		p = p->nextarc; //再递归邻接点
	}
}

void dfs(graph g) {
	/************************************************************************/
	/* 深度优先搜索算法——函数递归实现                                                                     */
	/************************************************************************/
	int *visited = (int *)malloc(sizeof(int)*g.n_V);
	for (int i=0;i<g.n_V;i++)
	{
		visited[i] = 0; //初始化标志数组
	}
	for (i=0;i<g.n_V;i++)
	{
		if (visited[i] == 0)
		{
			dfs_explore(g,i,visited);
		}
	}
}

void dfs_stack(graph g) {
	/************************************************************************/
	/* 深度优先搜索算法——非递归方法实现（堆栈）                                                                     */
	/************************************************************************/
	top = 0;
	int temp;
	int* visited = (int *)malloc(sizeof(int)g.n_V);
	for (int i=0;i<g.n_V;i++)
	{
		visited[i] = 0;
	}
	for (i=0;i<g.n_V;i++) //外层循环保证每个顶点都被访问到
	{
		if (visited[i] == 0) //当前顶点未被访问
		{
			s[++top] = i; //压栈
			visited[i] = 1;
			printf("%c\n",g.vex[i].vexdata);
			arcnode *p = g.vex[i].firstarc;
			//do...while循环为核心代码
			do {
				while (p && visited[p->adjvex] == 0) //一直访问当前顶点的第一条边知道指针为空或者被访问过
				{
					printf("%c\n",g.vex[p->adjvex].vexdata);
					visited[p->adjvex] = 1;
					s[++top] = p->adjvex;
					p = g.vex[p->adjvex].firstarc;
				}
				if (top != 0)
				{
					temp = s[top--]; //弹栈
					if (g.vex[temp].firstarc) 
					{
						p = g.vex[temp].firstarc->nextarc;
					}
				}

			} while(top != 0 && p); //保证堆栈非空——栈空则深度遍历结束
		}
	}
}

void bfs(graph g) {
	/************************************************************************/
	/* 广度优先搜索算法——队列实现                                                                     */
	/************************************************************************/
	front,rear = 0;
	arcnode *p;
	int temp;
	int *visited = (int *)malloc(sizeof(int)*g.n_V);
	for (int i=0;i<g.n_V;i++)
	{
		visited[i] = 0; //初始化标志数组
	}
	for (i=0;i<g.n_V;i++) //外层循环保证每个顶点都被访问到
	{
		if (visited[i] == 0)
		{
			q[rear++] = i; //进队列
			do {
				temp = q[front++]; //出队列
				printf("%c\n",g.vex[temp].vexdata);
				visited[temp] = 1;
				p = g.vex[temp].firstarc;
				while (p && visited[p->adjvex] == 0)
				{
					q[rear++] = p->adjvex;
					p = p->nextarc;
				}
			} while(front != rear);
		}
	}
}

void display_adjlist(graph g) {
	/************************************************************************/
	/* 打印领接表                                                                     */
	/************************************************************************/
	arcnode *p;
	for (int i=0;i<g.n_V;i++)
	{
		printf("%c:\t",g.vex[i].vexdata);
		p = g.vex[i].firstarc;
		while (p)
		{
			printf("%d\t",p->adjvex);
			p = p->nextarc;
		}
		printf("\n");
	}
}