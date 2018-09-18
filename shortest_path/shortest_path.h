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
	/* ����ͼ�����ڽӾ���                                                                     */
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
	/* ���·�������Ͻ�˹�����㷨                                                                     */
	/************************************************************************/

	/* v��ʾԴ�� */
	queue *q = (queue *)malloc(sizeof(queue)*g.n_V); //·������
	int *set = (int *)malloc(sizeof(int)*g.n_V); //�����������ж��Ƿ��ҵ�����ֵ��Ӧ��������·��
	int *dist = (int *)malloc(sizeof(int)*g.n_V); //�洢��̾���
	int min,index;

	for (int i=0;i<g.n_V;i++) //��ʼ��set����Ͷ��е�βָ��
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
			/*��Դ��͵�ǰ�������·������*/
			q[i].base[q[i].rear++] = v;
			q[i].base[q[i].rear++] = i;
		}
	}
	set[v] = 1; //��Դ�������ʱ�־
	for (int k=0;k<g.n_V-1;k++) //ѭ��n_V-1��
	{
		index = v;
		min = INT_MAX;
		for (i=1;i<g.n_V;i++)
		{
			if (set[i]==0 && dist[i] < min) //Ѱ��·����̶�����±�
			{
				index = i; //��¼��̶����Ӧ����
				min = dist[i]; //��¼����ֵ
			}
		}
		if (set[index] == 0)
		{
			set[index] = 1; //��index���������ʱ�־
			printf("the %c's shortest distance is %d\n",g.vex[index],min);
			for (i=0;i<q[index].rear;i++)
			{
				printf("%c->",g.vex[q[index].base[i]]); //��ӡ��Դ�㵽index�����·��
			}
			printf("end\n");
			for (i=1;i<g.n_V;i++)
			{
				//printf("%d %d %d\n",dist[index] , g.adjMat[index][i] , dist[i]);
				if (set[i]==0 && dist[index] < INT_MAX && g.adjMat[index][i] < INT_MAX && dist[index] + g.adjMat[index][i] < dist[i]) //�жϾ����Ƿ���
				{ //����dist[index] < INT_MAX �� g.adjMat[index][i] < INT_MAX��Ϊ�˷�ֹ�������
					dist[i] = dist[index] + g.adjMat[index][i]; //���¾�������
					/*����·��*/
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