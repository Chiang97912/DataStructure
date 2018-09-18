#include <stdio.h>
#include <stdlib.h>
#define Max 10
typedef int elemtype;

typedef struct  {
	elemtype *base;
	int top;
	int size;
}sqstack;

void initial(sqstack *s) {
	s->base = (elemtype *)malloc(sizeof(elemtype)*Max);
	s->size = Max;
	s->top = 0;
}

void push(sqstack *s, elemtype e) {
	/************************************************************************/
	/* ѹջ                                                                     */
	/************************************************************************/
	if (s->top > s->size)
	{
		printf("The top out of bounds!");
		int new_size = s->size * 2;
		s->base = (elemtype *)realloc(s->base,sizeof(elemtype)*new_size);
	}
	s->base[s->top] = e;
	s->top++;
}

elemtype pop(sqstack *s) {
	/************************************************************************/
	/* ��վ                                                                     */
	/************************************************************************/
	if (s->top == 0)
	{
		printf("reach the bottom of stack!");
		return NULL;
	}
	s->top--;
	return s->base[s->top];
}