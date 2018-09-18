#include <stdio.h>
#include <stdlib.h>

void merge_array(int *arr, int start, int mid, int end, int *temp) {
	/************************************************************************/
	/* 合并两个有序数列arr[start...mid]和arr[mid+1...end]                                                                     */
	/* temp用于临时存储排好序的数组
	/************************************************************************/
	int i = start,m = mid;
	int j = mid + 1, n = end;
	int k = 0;

	while (i <= m && j <= n)
	{
		if (arr[i] <= arr[j])
		{
			temp[k++] = arr[i++];
		}else {
			temp[k++] = arr[j++];
		}
	}

	while (i <= m)
	{
		temp[k++] = arr[i++];
	}
	while (j <= n)
	{
		temp[k++] = arr[j++];
	}

	for (i=0;i<k;i++)
	{
		arr[start + i] = temp[i];
	}
}

void merge_sort(int *arr, int start, int end, int *temp) {
	/************************************************************************/
	/* 归并算法                                                                     */
	/* 算法思想：先将一个完整数组两路拆分，然后再归并排序（使用递归）
	/************************************************************************/
	if (start < end)
	{
		int mid = (start + end)/2;
		merge_sort(arr,start,mid,temp); //先对左边的数组排序
		merge_sort(arr,mid+1,end,temp); //然后对右边的数组排序
		merge_array(arr,start,mid,end,temp); //合并两个有序数组
	}
}