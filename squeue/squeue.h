#include <stdio.h>
#include <stdlib.h>
#define Max 10
typedef int elemtype;

typedef struct  {
	elemtype * base;
	int front, rear;
	int size;
}squeue;

void initial(squeue *q) {
	q->base = (elemtype *)malloc(sizeof(elemtype)*Max);
	q->front = q->rear = 0;
	q->size = Max;
}

void insert(squeue *q,elemtype e) {
	if (q->rear >= q->size)
	{
		printf("reach the bottom of queue!");
		int new_size = q->size * 2;
		q->base = (elemtype *)realloc(q->base,sizeof(elemtype)*new_size);
	}
	q->base[(q->rear++)%q->size] = e;
}

elemtype del(squeue *q) {
	if (q->front > q->rear)
	{
		printf("Illegal operation!");
		return NULL;
	}
	return q->base[(q->front++)%q->size];
}

int isQueueEmpty(squeue q) {
	if (q.rear == q.front)
	{
		return 1;
	}
	else {
		return 0;
	}
}

int isQueueFull(squeue q) {
	if ((q.rear + 1)%q.size == q.front)
	{
		return 1;
	}
	else {
		return 0;
	}
}



































