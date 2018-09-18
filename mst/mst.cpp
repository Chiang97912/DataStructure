#include "mst.h"

void main() {
	AMGraph g;
	creatAMGraph(&g);
	prim(g,'a');
	/*EGraph gr;
	createEGraph(&gr);
	kruscal(gr);*/
}
/*
6 10
abcdef
prim-data:
1 2 6
1 3 1
1 4 5
2 3 5
3 4 5
2 5 3
3 5 6
3 6 4
4 6 2
5 6 6

6 10
abcdef
kruscal-data:
0 4 4
1 2 5
1 3 8
2 3 10
1 5 12
3 5 15
0 1 18
3 4 20
0 5 23
4 5 25
*/