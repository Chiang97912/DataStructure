#include <stdio.h>
#include <stdlib.h>
#define Max 60

typedef struct {
	int *elem;
	int length;
	int size;
}S_TBL;

void initial_TBL(S_TBL *tbl) {
	tbl->size = Max;
	tbl->elem = (int *)malloc(sizeof(int)*tbl->size);
}

int binary_search(S_TBL tbl, int key, int low, int high) {
	int mid = (low + high)/2;
	if (key < tbl.elem[mid])
	{
		high = mid - 1;
		if (low < high)
		{
			return binary_search(tbl,key,low,high);
		}
	}
	else if (key > tbl.elem[mid])
	{
		low = mid + 1;
		if (low < high)
		{
			return binary_search(tbl,key,low,high);
		}
	}
	else {
		return mid;
	}
	return -1;
}