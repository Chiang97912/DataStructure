#include "tree.h"

void main() {
	btree *t = create_tree();
	preorder(t);
	//test data:1 2 4 0 0 0 3 5 0 0 6 0 0
	int depth = get_depth(t);
	printf("depth:%d\n",depth);

	int leaf_num = countleaf(t);
	printf("leaf_num:%d\n",leaf_num);
}