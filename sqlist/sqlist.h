#include <stdio.h>
#include <stdlib.h>
#define Max 10
typedef int elemtype;
typedef struct  {
	elemtype *base;
	int len;
	int size;
}sqlist;

void initial(sqlist *L) {
	/************************************************************************/
	/* 初始化顺序表sqlist                                                                     */
	/************************************************************************/
	L->base = (elemtype *)malloc(sizeof(elemtype)*L->size);
	L->len = 0;
	L->size = Max;
}

void insert(sqlist *L,int pos,elemtype e) {
	/************************************************************************/
	/* 在顺序表sqlist的pos位置插入元素e                                                                     */
	/************************************************************************/
	if (pos<0 || pos > L->len)
	{
		printf("The pos value is illegal.\n");
		return;
	}
	if (L->len>=L->size)
	{
		//重新分配内存
		int new_size = L->size * 2;
		L->base = (elemtype *)realloc(L->base,sizeof(elemtype)*new_size);
		L->size = new_size;
		printf("The memory had been realloc.\n");
	}
	for (int i=L->len;i>=pos;i--)
	{
		L->base[i+1] = L->base[i];
	}
	L->base[pos] = e;
	L->len++;
}

elemtype del(sqlist *L,int pos) {
	if (pos < 0 || pos > L->len)
	{
		printf("The pos value is illegal.\n");
		return -1;
	}
	elemtype value = L->base[pos];
	for (int i=pos;i<L->len;i++)
	{
		L->base[i] = L->base[i+1];
	}
	L->len--;
	return value;
}

int find(sqlist L, elemtype e) {
	for (int i=0;i<L.len;i++)
	{
		if (L.base[i] == e)
		{
			return i;
		}
	}
	return -1;
}

void display(sqlist L) {
	/************************************************************************/
	/* 打印顺序表                                                                     */
	/************************************************************************/
	printf("元素：");
	for(int i=0;i<L.len;i++) {
		printf("%d ",L.base[i]);
	}
	printf("\n");

	printf("len:%d\n",L.len);
	printf("size:%d\n",L.size);
}