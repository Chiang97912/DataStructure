#include "graph.h"

void main() {
	graph g;
	creat(&g);
	display_matrix(g);
	printf("深度优先搜索算法:\n");
	dfs(g);
	printf("广度优先搜索算法:\n");
	bfs(g);
}