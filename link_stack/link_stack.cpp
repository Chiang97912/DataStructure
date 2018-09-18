#include "link_stack.h"

void main() {
	LinkStack s;
	initial(&s);
	push(&s,1);
	push(&s,2);
	push(&s,3);

	int e1 = pop(&s);
	int e2 = pop(&s);
	printf("%d\n%d\n",e1,e2);
}