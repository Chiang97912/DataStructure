#include <stdio.h>

void selection_sort(int *arr, int len) {
	for (int i=0;i<len-1;i++)
	{
		int min = i; //����Ϊ�ź��������Ĭ������ֵi��Ӧ��Ԫ����С
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