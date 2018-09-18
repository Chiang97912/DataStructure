#include "sqlist.h"

void main() {
	sqlist L;
	initial(&L);
	insert(&L,0,1);
	insert(&L,1,2);
	insert(&L,2,3);
	insert(&L,3,4);
	display(L);
	
	int value = del(&L,1);
	display(L);
	int res = find(L,4);
	printf("%d\n",res);
}