#include "bubble_sort.h"

void main() {
	int r[8] = {60,71,49,11,82,24,3,66};
	bubble_sort(r,8);
	
	for (int i=0;i<8;i++)
	{
		printf("%d ",r[i]);
	}
	printf("\n");
}