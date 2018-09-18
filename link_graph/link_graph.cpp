#include "link_graph.h"

void main() {
	graph g;
	create(&g);
	display_adjlist(g);
	printf("深度优先搜索算法:\n");
	dfs(g); 
	printf("广度优先搜索算法:\n");
	bfs(g);
	printf("深度优先搜索算法——非递归:\n");
	dfs_stack(g);
}