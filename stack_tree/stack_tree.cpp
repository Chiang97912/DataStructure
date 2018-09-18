#include "stack_tree.h"

void main() {
	btree *t = create_tree();
	//preorder(t);
	inorder(t);
	//test data:1 2 4 0 0 0 3 5 0 0 6 0 0
}