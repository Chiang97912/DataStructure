#include "heap_sort.h"

int main() {
	int r[8] = {60,71,49,11,82,24,3,66};
	heap_sort(r,8);

	for (int i=0;i<8;i++)
	{
		printf("%d ",r[i]);
	}
	printf("\n");
    return 0;
}
