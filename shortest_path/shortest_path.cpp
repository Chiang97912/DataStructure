#include "shortest_path.h"

void main() {
	graph g;
	create(&g);
	dijkstra(g,0);
}
/*
6 8
abcdef
test-data:
1 6 100
1 5 30
1 3 10
2 3 5
3 4 50
4 6 10
5 4 20
5 6 60
*/