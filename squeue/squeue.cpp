#include "squeue.h"

void main() {
	squeue q;
	initial(&q);
	printf("isEmpty:%d\n",isQueueEmpty(q));
	insert(&q,1);
	insert(&q,2);
	insert(&q,3);
	printf("isEmpty:%d\n",isQueueEmpty(q));

	printf("%d\n",del(&q));
	printf("%d\n",del(&q));
	printf("%d\n",del(&q));
}