#include <stdio.h>
#include <stdlib.h>
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
	/* 先序遍历                                                                     */
	/************************************************************************/
	if (t)
	{
		printf("%d\n",t->data);
		preorder(t->lchild);
		preorder(t->rchild);
	}
}

void inorder(btree *t) {
	/************************************************************************/
	/* 中序遍历                                                                     */
	/************************************************************************/
	if (t)
	{
		preorder(t->lchild);
		printf("%d\n",t->data);
		preorder(t->rchild);
	}
}

void postorder(btree *t) {
	/************************************************************************/
	/* 后序遍历                                                                     */
	/************************************************************************/
	if (t)
	{
		preorder(t->lchild);
		preorder(t->rchild);
		printf("%d\n",t->data);
	}
}

int get_depth(btree *t) {
	/************************************************************************/
	/* 求二叉树的深度                                                                     */
	/************************************************************************/
	int m,n;
	if (!t)
	{
		return 0;
	}
	else {
		m = get_depth(t->lchild);
		n = get_depth(t->rchild);
		if (m > n)
		{
			return m+1;
		}
		else {
			return n+1;
		}
		//return (m>n?m:n) + 1
	}
}

int countleaf(btree *root) {
	/************************************************************************/
	/* 求二叉树的子叶树                                                                     */
	/************************************************************************/
	int i;
	if (root == NULL)
	{
		//空二叉树
		i = 0;
	}
	else if (root->lchild == NULL && root->rchild == NULL)
	{
		//仅有根节点的二叉树
		i = 1;
	}
	else {
		i = countleaf(root->lchild) + countleaf(root->rchild);
	}

	return i;
}