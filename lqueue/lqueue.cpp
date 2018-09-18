#include "lqueue.h"

void main() {
	lqueue q;
	initial(&q);
	insert(&q,1);
	insert(&q,2);
	insert(&q,3);

	printf("%d\n",del(&q));
	printf("%d\n",del(&q));
	printf("%d\n",del(&q));
}