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
	int adjvex; //�洢�����±�
	struct arcnode *next;
}arcnode;

typedef struct edge {
	/************************************************************************/
	/* �߼�����Ļ���Ԫ��                                                                     */
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
	/* ����ͼ�����ڽӾ���                                                                     */
	/************************************************************************/
	//ע����ʱ��������ݼ������ź���ģ����������ľ���Ҫ���������㷨���˴������
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
	/* �����ַ�v�ڶ��������е��±�                                                                     */
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
	/* �ҳ�closeedges�����е�lowcost����Сֵ                                                                     */
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
	/* ��С��������������ķ�㷨                                                                     */
	/************************************************************************/
	char u0,v0;
	int k = locateVex(g,v);
	//closeedges������±��Ӧ��ͻ��ѱߵĳ���λ�ã���adjvex�������λ�ã���lowcostֵ������С����ֵ
	closeedge *closeedges = (closeedge *)malloc(sizeof(closeedge)*g.n_V);
	for (int i=0;i<g.n_V;i++) //��ʼ��closeedges����
	{
		if (i != k)
		{
			closeedges[i].adjvex = v;
			closeedges[i].lowcost = g.adjMat[k][i];
		}
	}
	closeedges[k].lowcost = 0; //lowcostֵ����Ϊ0��ʾ�Ѿ����ʹ�
	for (i=1;i<g.n_V;i++) //ѭ��n_V-1��
	{
		//�ҳ���ͻ��ѵĶ���
		k = min(g,closeedges);
		u0 = closeedges[k].adjvex;
		v0 = g.vex[k];
		printf("%c->%c\n",u0,v0);
		closeedges[k].lowcost = 0; //�Ե�k�����������ʱ�־

		//�����µı�֮���ٸ�����ͻ�������
		for (int j=0;j<g.n_V;j++)
		{
			if (closeedges[j].lowcost > g.adjMat[k][j]) //����k���������������ľ����ԭʼ��ͻ��������ֵ���бȽϣ����С��ԭʼֵ�͸���
			{
				//��ȷ���µ���ͻ��Ѷ���֮�����lowcostֵ
				closeedges[j].lowcost = g.adjMat[k][j];
				closeedges[j].adjvex = g.vex[k];
			}
		}
	}
}

void createEGraph(EGraph *g) {
	/************************************************************************/
	/* ����ͼ�����߼�����                                                                     */
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
	/* ��С������������³˹�����㷨                                                                     */
	/************************************************************************/
	int k = 0; //����߼������±�
	int d = 0; //�߼�����ѭ���±�
	int m1,m2; //�ݴ�fromvex��endvex���±꣬�����ж������Ƿ�����ͬһ������
	arcnode *p;
	arcnode **set;
	set= (arcnode **)malloc(sizeof(arcnode *)*g.n_V); //�±꼯�ϣ����ϵ�ÿ��Ԫ��Ϊһ������ͬһ�������е�adjvex��ʾ�໥��ͨ
	edge *resultEdges = (edge *)malloc(sizeof(edge)*(g.n_V-1)); //�������ս���ı߼�����
	for (int i=0;i<g.n_V;i++)
	{
		p = (arcnode *)malloc(sizeof(arcnode));
		p->adjvex = i;
		p->next = NULL;
		set[i] = p;
	}

	while (k < g.n_V-1) //ѭ��n_V-1��
	{
		for (i=0;i<g.n_V;i++)
		{
			/************************************************************************/
			/* �жϴ�ѡ�߼������еĵ�ǰ���fromvex��endvex�Ƿ���ͬһ��������                                                                     */
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

		if (m1 != m2) //from��endvex����ͬһ��������
		{
			resultEdges[k] = g.edges[d]; //����ѡ�߼������з�����������������߼�������
			k++; //����߼������±��ԉ�
			p = set[m1];
			while (p->next)
			{
				p = p->next;
			}
			p->next = set[m2];
			set[m2] = NULL;
		}
		d++; //�߼������±��ԉ�
	}
	for (i=0;i<g.n_V-1;i++)
	{
		printf("%c->%c\n",g.vex[resultEdges[i].fromvex],g.vex[resultEdges[i].endvex]);
	}
}