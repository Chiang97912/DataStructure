#include <stdio.h>
#include <stdlib.h>

typedef struct arcnode {
	int adjvex;
	struct arcnode *nextarc;
}arcnode;

typedef struct vexnode {
	int vexdata;
	int indegree; //入度值
	struct arcnode *firstarc;
}vexnode;

typedef struct {
	vexnode *vex;
	int n_V;
	int n_E;
}graph;

void create(graph * g) {
	/************************************************************************/
	/* 创建图                                                                     */
	/************************************************************************/
	printf("Plz input the num of vertices and arcs:\n");
	scanf("%d%d",&g->n_V,&g->n_E);
	getchar();
	g->vex = (vexnode *)malloc(sizeof(vexnode)* g->n_V);
	printf("Plz input the information of vertices:\n");
	for (int i=0;i<g->n_V;i++)
	{
		scanf("%c",&g->vex[i].vexdata);
		g->vex[i].firstarc = NULL;
	}
	for (i=0;i<g->n_V;i++)
	{
		g->vex[i].indegree = 0; //初始化入度值
	}
	getchar();
	printf("Plz input the arcs just like 1,3:\n");
	int origin,destination;
	for (i=0;i<g->n_E;i++)
	{
		scanf("%d,%d",&origin,&destination);
		arcnode *p = (arcnode *)malloc(sizeof(arcnode));
		/*头插法*/
		p->adjvex = destination - 1;
		p->nextarc = g->vex[origin-1].firstarc;
		g->vex[origin-1].firstarc = p;
		g->vex[destination-1].indegree++; //destination-1位置顶点入度值加一
	}
}

void topsort(graph g) {
	/************************************************************************/
	/* 拓扑排序算法                                                                     */
	/************************************************************************/
	int stack[60];
	int top = 0;
	int v,k;
	struct arcnode *p;
	for (int i=0;i<g.n_V;i++)
	{
		if (g.vex[i].indegree == 0)
		{
			stack[++top] = i; //入度为零的顶点进栈
		}
	}
	while (top != 0)
	{
		v = stack[top--]; //出栈
		printf("%c\n",g.vex[v].vexdata);
		p = g.vex[v].firstarc;
		while (p)
		{
			k = p->adjvex;
			if (--g.vex[k].indegree == 0) //入度值递减的同时判断其是否为0
			{
				stack[++top] = k;
			}
			p = p->nextarc;
		}
	}
}