#include "graph.h"

void main() {
	graph g;
	creat(&g);
	display_matrix(g);
	printf("������������㷨:\n");
	dfs(g);
	printf("������������㷨:\n");
	bfs(g);
}