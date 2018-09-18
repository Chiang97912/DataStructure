#include "link_list.h"
void main() {
	Head h;
	tail = &h;
	inital(&h);
	insert_by_head(&h,1);
	insert_by_head(&h,2);
	insert_by_head(&h,3);
	/*
	inser_after_tail(&h,4);
	inser_after_tail(&h,5);
	inser_after_tail(&h,6);
	*/
	del(&h,1);

	display(h);
}