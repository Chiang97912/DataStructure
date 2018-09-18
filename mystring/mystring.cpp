#include "mystring.h"

void main() {
	mystring s;
	initial(&s);
	int result = assign(&s,"hello");
	printf("length:%d\n",s.length);

	mystring t;
	initial(&t);
	result = assign(&t,"world");
	int is_equal = equal(s,t);
	printf("is_equal:%d\n",is_equal);

	int length = len(s);
	printf("len:%d\n",length);

	result = concat(&s,&t);
	printf("%d\n",s.length);
	display(s);

	mystring n = substr(s,1,3);
	display(n);
	
	result = assign(&s,"hello,world");
	int idx = index(s,t);
	printf("index:%d\n",idx);

	result = assign(&s,"abdabd");
	result = assign(&t,"ab");
	mystring v;
	initial(&v);
	result = assign(&v,"e");
	replace(&s,t,v);
	display(s);

	result = assign(&s,"abdabd");
	result = assign(&t,"c");
	del(&s,0,2);
	display(s);
}