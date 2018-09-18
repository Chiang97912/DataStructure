#include <stdio.h>
#include <stdlib.h>
typedef int elemtype;

typedef struct  NODETYPE{
	elemtype data;
	struct NODETYPE *next;
}nodetype;

typedef struct  {
	nodetype * front;
	nodetype * rear;
	
}lqueue;

void initial(lqueue * q) {
	q->front = (nodetype *)malloc(sizeof(nodetype));
	q->front->next = NULL;
	q->rear = q->front;
}

void insert(lqueue * q, elemtype e) {
	nodetype * n = (nodetype *)malloc(sizeof(nodetype));
	n->data = e;
	n->next = q->rear->next;
	q->rear->next = n;
}

elemtype del(lqueue * q) {
	elemtype e = q->front->next->data;
	q->front->next = q->front->next->next;
	return e;
}