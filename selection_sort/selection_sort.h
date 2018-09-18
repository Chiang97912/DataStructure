#include <stdio.h>

void selection_sort(int *arr, int len) {
	for (int i=0;i<len-1;i++)
	{
		int min = i; //对于为排好序的序列默认索引值i对应的元素最小
		for (int j=i+1;j<len;j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		int temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
}