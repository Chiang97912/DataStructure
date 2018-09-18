#include <stdio.h>
#include <stdlib.h>
typedef int elemtype;
typedef struct node {
	elemtype data;
	struct node * next;
}Head;

struct node * tail;

void inital(Head * h) {
	h->next = NULL;
}

void insert_by_head(Head *h,elemtype data) {
	struct node *s = (node *)malloc(sizeof(node));
	s->data = data;
	s->next = h->next;
	h->next = s;
}

void inser_after_tail(Head * h,elemtype data) {
	struct node *s = (node *)malloc(sizeof(node));
	s->data = data;
	s->next = tail->next;
	tail->next = s;
	tail = s; //¸üÐÂÎ²Ö¸Õë
}

void del_(Head *h,elemtype data) {
	struct node *p,*pre;
	p = h->next;
	while(p->data != data) {
		pre = p;
		p = p->next;
	}
	pre->next = p->next;
	free(p);
}

void del(Head *h,elemtype data) {
	struct node *p,*q;
	p = h;
	while(p->next->data != data) {
		p = p->next;
	}
	q = p->next;
	p->next = p->next->next;
	free(q);
}

void find() {
	
}

void display(Head h) {
	node *p;
	p = h.next;
	while(p) {
		printf("%d\n",p->data);
		p = p->next;
	}
}