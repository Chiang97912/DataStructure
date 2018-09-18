#include <stdio.h>

void hanoi(int n,int x,int y,int z) {
	if (n == 1)
	{
		printf("%d-->%d\n",x,z);
	}else {
		hanoi(n-1,x,z,y);
		printf("%d-->%d\n",x,z);
		hanoi(n-1,y,x,z);
	}
}

void main() {
	hanoi(3,1,2,3);
}