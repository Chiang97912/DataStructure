#include <stdio.h>
#include <stdlib.h>
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
	/* �������                                                                     */
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
	/* �������                                                                     */
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
	/* �������                                                                     */
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
	/* ������������                                                                     */
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
	/* �����������Ҷ��                                                                     */
	/************************************************************************/
	int i;
	if (root == NULL)
	{
		//�ն�����
		i = 0;
	}
	else if (root->lchild == NULL && root->rchild == NULL)
	{
		//���и��ڵ�Ķ�����
		i = 1;
	}
	else {
		i = countleaf(root->lchild) + countleaf(root->rchild);
	}

	return i;
}