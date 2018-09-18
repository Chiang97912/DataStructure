#include "merge_sort.h"

void main() {
	int r[8] = {60,71,49,11,82,24,3,66};
	int *t = (int *)malloc(sizeof(int)*8);
	merge_sort(r,0,8,t);
	
	for (int i=0;i<8;i++)
	{
		printf("%d ",r[i]);
	}
	printf("\n");
}