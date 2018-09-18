#include <stdio.h>
#include <stdlib.h>

int q[30]; //����
int front,rear; //����ָ��

int s[30]; //��ջ
int top; //ջ��ָ��
typedef struct arcnode {
	/************************************************************************/
	/* ��ͨ�߽ڵ�                                                                     */
	/************************************************************************/
	int adjvex; //����ֵ
	struct arcnode * nextarc; //��һ���߽ڵ�
}arcnode;

typedef struct vexnode {
	/************************************************************************/
	/* ����                                                                     */
	/************************************************************************/
	int vexdata; //����ֵ
	arcnode *firstarc; //��һ���߽ڵ�
}vexnode;

typedef struct  {
	/************************************************************************/
	/* ͼ�Ľṹ��                                                                     */
	/************************************************************************/
	vexnode *vex; //��������
	int n_V; //��������
	int n_E; //������
}graph;

/************************************************************************/
/* ��ӱ�ʵ��ͼ                                                                     */
/************************************************************************/
void create(graph * g) {
	/************************************************************************/
	/* ����ͼ                                                                     */
	/************************************************************************/
	printf("Plz input the num of vertices and arcs:\n");
	scanf("%d%d",&g->n_V,&g->n_E);
	getchar(); //���յ��س���
	g->vex = (vexnode *)malloc(sizeof(vexnode)* g->n_V);
	printf("Plz input the information of vertices:\n");
	for (int i=0;i<g->n_V;i++)
	{
		scanf("%c",&g->vex[i].vexdata);
		g->vex[i].firstarc = NULL;
	}
	getchar(); //���յ��س���
	printf("Plz input the arcs just like 1,3:\n");
	int origin,destination;
	for (i=0;i<g->n_E;i++)
	{
		scanf("%d,%d",&origin,&destination);
		arcnode *p = (arcnode *)malloc(sizeof(arcnode));
		//ͷ�巨
		p->adjvex = destination - 1;
		p->nextarc = g->vex[origin-1].firstarc;
		g->vex[origin-1].firstarc = p;
	}
}

void dfs_explore(graph g,int i,int *visited) {
	visited[i] = 1; //���ʱ�־
	printf("%c\n",g.vex[i].vexdata);
	arcnode *p = g.vex[i].firstarc;
	while (p && visited[p->adjvex] ==0)
	{
		dfs_explore(g,p->adjvex,visited); //�ȵݹ��һ������
		p = p->nextarc; //�ٵݹ��ڽӵ�
	}
}

void dfs(graph g) {
	/************************************************************************/
	/* ������������㷨���������ݹ�ʵ��                                                                     */
	/************************************************************************/
	int *visited = (int *)malloc(sizeof(int)*g.n_V);
	for (int i=0;i<g.n_V;i++)
	{
		visited[i] = 0; //��ʼ����־����
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
	/* ������������㷨�����ǵݹ鷽��ʵ�֣���ջ��                                                                     */
	/************************************************************************/
	top = 0;
	int temp;
	int* visited = (int *)malloc(sizeof(int)g.n_V);
	for (int i=0;i<g.n_V;i++)
	{
		visited[i] = 0;
	}
	for (i=0;i<g.n_V;i++) //���ѭ����֤ÿ�����㶼�����ʵ�
	{
		if (visited[i] == 0) //��ǰ����δ������
		{
			s[++top] = i; //ѹջ
			visited[i] = 1;
			printf("%c\n",g.vex[i].vexdata);
			arcnode *p = g.vex[i].firstarc;
			//do...whileѭ��Ϊ���Ĵ���
			do {
				while (p && visited[p->adjvex] == 0) //һֱ���ʵ�ǰ����ĵ�һ����֪��ָ��Ϊ�ջ��߱����ʹ�
				{
					printf("%c\n",g.vex[p->adjvex].vexdata);
					visited[p->adjvex] = 1;
					s[++top] = p->adjvex;
					p = g.vex[p->adjvex].firstarc;
				}
				if (top != 0)
				{
					temp = s[top--]; //��ջ
					if (g.vex[temp].firstarc) 
					{
						p = g.vex[temp].firstarc->nextarc;
					}
				}

			} while(top != 0 && p); //��֤��ջ�ǿա���ջ������ȱ�������
		}
	}
}

void bfs(graph g) {
	/************************************************************************/
	/* ������������㷨��������ʵ��                                                                     */
	/************************************************************************/
	front,rear = 0;
	arcnode *p;
	int temp;
	int *visited = (int *)malloc(sizeof(int)*g.n_V);
	for (int i=0;i<g.n_V;i++)
	{
		visited[i] = 0; //��ʼ����־����
	}
	for (i=0;i<g.n_V;i++) //���ѭ����֤ÿ�����㶼�����ʵ�
	{
		if (visited[i] == 0)
		{
			q[rear++] = i; //������
			do {
				temp = q[front++]; //������
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
	/* ��ӡ��ӱ�                                                                     */
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