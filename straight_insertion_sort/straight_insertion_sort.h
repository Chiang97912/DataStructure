#include <stdio.h>

void insertion_sort(int *arr, int n) {
	int i,j,temp;
	for (i=1;i<n;i++)
	{
		temp = arr[i];
		//j = i - 1;
		for (j=i;j>0 && arr[j-1] > temp; j--)
		{
			arr[j] = arr[j-1];
		}
		arr[j] = temp;
	}
}
