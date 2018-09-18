#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct closeedge {
	char adjvex; 
	int lowcost;
}closeedge;

typedef struct AMGraph {
	int **adjMat;
	char *vex;
	int n_V;
	int n_E;
}AMGraph;

typedef struct arcnode {
	int adjvex; //存储顶点下标
	struct arcnode *next;
}arcnode;

typedef struct edge {
	/************************************************************************/
	/* 边集数组的基本元素                                                                     */
	/************************************************************************/
	int fromvex; 
	int endvex;
	int weight;
}edge;

typedef struct EGraph {
	char *vex;
	edge *edges;
	int n_V;
	int n_E;
}EGraph;

void creatAMGraph(AMGraph *g) {
	/************************************************************************/
	/* 创建图——邻接矩阵                                                                     */
	/************************************************************************/
	//注：此时输入的数据假设是排好序的，如果是乱序的就需要引入排序算法，此处不再深究
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
		g->adjMat[col-1][row-1] = weight;
	}
}

int locateVex(AMGraph g,char v) {
	/************************************************************************/
	/* 查找字符v在顶点数组中的下标                                                                     */
	/************************************************************************/
	for (int i=0;i<g.n_V;i++)
	{
		if (g.vex[i] == v)
		{
			return i;
		}
	}
	return -1;
}

int min(AMGraph g,closeedge *closeedges) {
	/************************************************************************/
	/* 找出closeedges数组中的lowcost的最小值                                                                     */
	/************************************************************************/
	int __min__ = INT_MAX;
	int index = -1;
	for (int i=0;i<g.n_V;i++)
	{
		if (__min__>closeedges[i].lowcost && closeedges[i].lowcost != 0)
		{
			__min__ = closeedges[i].lowcost;
			index = i;
		}
	}
	return index;
}

void prim(AMGraph g,char v) {
	/************************************************************************/
	/* 最小生成树——普里姆算法                                                                     */
	/************************************************************************/
	char u0,v0;
	int k = locateVex(g,v);
	//closeedges数组的下标对应最低花费边的出度位置，而adjvex代表入度位置，而lowcost值代表最小花费值
	closeedge *closeedges = (closeedge *)malloc(sizeof(closeedge)*g.n_V);
	for (int i=0;i<g.n_V;i++) //初始化closeedges数组
	{
		if (i != k)
		{
			closeedges[i].adjvex = v;
			closeedges[i].lowcost = g.adjMat[k][i];
		}
	}
	closeedges[k].lowcost = 0; //lowcost值设置为0表示已经访问过
	for (i=1;i<g.n_V;i++) //循环n_V-1次
	{
		//找出最低花费的顶点
		k = min(g,closeedges);
		u0 = closeedges[k].adjvex;
		v0 = g.vex[k];
		printf("%c->%c\n",u0,v0);
		closeedges[k].lowcost = 0; //对第k个顶点做访问标志

		//连接新的边之后再更新最低花费数组
		for (int j=0;j<g.n_V;j++)
		{
			if (closeedges[j].lowcost > g.adjMat[k][j]) //将第k个顶点和其它顶点的距离和原始最低花费数组的值进行比较，如果小于原始值就更新
			{
				//在确定新的最低花费顶点之后更新lowcost值
				closeedges[j].lowcost = g.adjMat[k][j];
				closeedges[j].adjvex = g.vex[k];
			}
		}
	}
}

void createEGraph(EGraph *g) {
	/************************************************************************/
	/* 创建图——边集数组                                                                     */
	/************************************************************************/
	printf("Plz input the number of vertices and arcs:\n");
	scanf("%d%d",&g->n_V,&g->n_E);
	g->edges = (edge *)malloc(sizeof(edge)*g->n_V);
	g->vex = (char *)malloc(sizeof(char)* g->n_V);
	printf("Plz input the information of vertices:\n");
	getchar();
	for (int i=0;i<g->n_V;i++)
	{
		scanf("%c",&g->vex[i]);
	}
	getchar();
	printf("Plz intput the value of the two vexteies and it's weight just like 1 2 1:\n");
	int fromvex,endvex,weight;
	for (i=0;i<g->n_E;i++)
	{
		scanf("%d%d%d",&fromvex,&endvex,&weight);
		g->edges[i].fromvex = fromvex;
		g->edges[i].endvex = endvex;
		g->edges[i].weight = weight;
	}
}

void kruscal(EGraph g) {
	/************************************************************************/
	/* 最小生成树——克鲁斯卡尔算法                                                                     */
	/************************************************************************/
	int k = 0; //结果边集数组下标
	int d = 0; //边集数组循环下标
	int m1,m2; //暂存fromvex和endvex的下标，用于判断他们是否属于同一个集合
	arcnode *p;
	arcnode **set;
	set= (arcnode **)malloc(sizeof(arcnode *)*g.n_V); //下标集合，集合的每个元素为一个链表，同一个链表中的adjvex表示相互连通
	edge *resultEdges = (edge *)malloc(sizeof(edge)*(g.n_V-1)); //保存最终结果的边集数组
	for (int i=0;i<g.n_V;i++)
	{
		p = (arcnode *)malloc(sizeof(arcnode));
		p->adjvex = i;
		p->next = NULL;
		set[i] = p;
	}

	while (k < g.n_V-1) //循环n_V-1次
	{
		for (i=0;i<g.n_V;i++)
		{
			/************************************************************************/
			/* 判断待选边集数组中的当前项的fromvex和endvex是否在同一个集合中                                                                     */
			/************************************************************************/
			p = set[i];
			while (p)
			{
				if (p->adjvex == g.edges[d].fromvex)
				{
					m1 = i;
				}
				if (p->adjvex == g.edges[d].endvex)
				{
					m2 = i;
				}
				p = p->next;
			}
		}

		if (m1 != m2) //from和endvex不在同一个集合中
		{
			resultEdges[k] = g.edges[d]; //将待选边集数组中符合条件的项加入结果边集数组中
			k++; //结果边集数组下标自増
			p = set[m1];
			while (p->next)
			{
				p = p->next;
			}
			p->next = set[m2];
			set[m2] = NULL;
		}
		d++; //边集数组下标自増
	}
	for (i=0;i<g.n_V-1;i++)
	{
		printf("%c->%c\n",g.vex[resultEdges[i].fromvex],g.vex[resultEdges[i].endvex]);
	}
}