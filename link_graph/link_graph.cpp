#include "link_graph.h"

void main() {
	graph g;
	create(&g);
	display_adjlist(g);
	printf("������������㷨:\n");
	dfs(g); 
	printf("������������㷨:\n");
	bfs(g);
	printf("������������㷨�����ǵݹ�:\n");
	dfs_stack(g);
}