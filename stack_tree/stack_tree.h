#include <stdio.h>
#include <stdlib.h>
#define MAX 20
typedef int elemtype;

typedef struct node {
	elemtype data;
	struct node *lchild,*rchild;
}btree;

btree* create_tree() {
	/************************************************************************/
	/* ����������                                                                     */
	/************************************************************************/
	elemtype num;
	scanf("%d",&num);
	if (num == 0)
	{
		return NULL;
	}
	else{
		btree *s = (btree *)malloc(sizeof(btree));
		s->data = num;
		s->lchild = create_tree();
		s->rchild = create_tree();
		return s;
	}
}

void preorder(btree *t) {
	/************************************************************************/
	/* ʹ�ö�ջʵ�ֶ������ı��������ȸ�����                                                                     */
	/************************************************************************/
	btree *stack[MAX+1];
	int top = 0;

	do {
		while (t)
		{
			printf("%d\n",t->data); //���ʸ��ڵ�
			if (top == MAX) //�ж϶�ջ�Ƿ�����
			{
				printf("stack full!");
				return;
			}
			stack[++top] = t; //��ָ���ջ
			t = t->lchild; //����������
		}
		if (top!=0)
		{
			t = stack[top--]; //ȡ����ָ��
			t = t->rchild; //����������
		}
	} while(top!=0||t!=NULL); //ջ�ǿջ�Ϊ�ǿ�����
}

void inorder(btree *t) {
	/************************************************************************/
	/* ʹ�ö�ջʵ�ֶ������ı��������и�����                                                                     */
	/************************************************************************/
	btree *stack[MAX+1];
	int top = 0;

	do {
		while (t)
		{
			if (top == MAX) //�ж϶�ջ�Ƿ�����
			{
				printf("stack full!");
				return;
			}
			stack[++top] = t; //��ָ���ջ
			t = t->lchild; //����������
		}
		if (top!=0)
		{
			t = stack[top--]; //ȡ����ָ��
			printf("%d\n",t->data); //���ʸ��ڵ�
			t = t->rchild; //����������
		}
	} while(top!=0||t!=NULL); //ջ�ǿջ�Ϊ�ǿ�����
}