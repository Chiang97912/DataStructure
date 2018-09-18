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
	/* 创建二叉树                                                                     */
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
	/* 使用堆栈实现二叉树的遍历——先根遍历                                                                     */
	/************************************************************************/
	btree *stack[MAX+1];
	int top = 0;

	do {
		while (t)
		{
			printf("%d\n",t->data); //访问根节点
			if (top == MAX) //判断堆栈是否已满
			{
				printf("stack full!");
				return;
			}
			stack[++top] = t; //根指针进栈
			t = t->lchild; //移向左子树
		}
		if (top!=0)
		{
			t = stack[top--]; //取出根指针
			t = t->rchild; //移向右子树
		}
	} while(top!=0||t!=NULL); //栈非空或为非空子树
}

void inorder(btree *t) {
	/************************************************************************/
	/* 使用堆栈实现二叉树的遍历——中根遍历                                                                     */
	/************************************************************************/
	btree *stack[MAX+1];
	int top = 0;

	do {
		while (t)
		{
			if (top == MAX) //判断堆栈是否已满
			{
				printf("stack full!");
				return;
			}
			stack[++top] = t; //根指针进栈
			t = t->lchild; //移向左子树
		}
		if (top!=0)
		{
			t = stack[top--]; //取出根指针
			printf("%d\n",t->data); //访问根节点
			t = t->rchild; //移向右子树
		}
	} while(top!=0||t!=NULL); //栈非空或为非空子树
}