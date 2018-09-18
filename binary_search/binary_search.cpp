#include "binary_search.h"

void main() {
	S_TBL tbl;
	initial_TBL(&tbl);
	for (int i=0;i<10;i++)
	{
		tbl.elem[i] = i+1;
	}
	tbl.length = i;
	int result = binary_search(tbl,5,0,tbl.length-1);
	printf("%d\n",result);
}
