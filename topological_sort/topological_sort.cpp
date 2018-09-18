#include "topological_sort.h"

void main() {
	graph g;
	create(&g);
	topsort(g);
}
/*
12 16
abcdefghijkl
test-data:
1,4
1,2
1,3
1,12
4,5
2,3
3,5
3,7
3,8
5,7
9,12
9,10
9,11
10,12
11,6
6,8
*/