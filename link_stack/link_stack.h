#include <stdio.h>
#include <stdlib.h>
typedef int elemtype;
/************************************************************************/
/* ��ʽ��ջ                                                                     */
/************************************************************************/

typedef struct stacknode{
	elemtype data;
	struct stacknode *next;
}stacknode;

typedef struct {
	stacknode * top;
}LinkStack;

void initial(LinkStack *s) {
	s->top = (stacknode *)malloc(sizeof(stacknode));
}

void push(LinkStack *s, elemtype e) {
	/************************************************************************/
	/* ѹջ                                                                     */
	/************************************************************************/
	stacknode *n= (stacknode *)malloc(sizeof(stacknode));
	n->data = e;
	n->next = s->top->next;
	s->top->next = n;
}

elemtype pop(LinkStack *s) {
	/************************************************************************/
	/* ��ջ                                                                     */
	/************************************************************************/
	int e = s->top->next->data;
	s->top->next = s->top->next->next;
	return e;
}