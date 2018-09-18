#include <stdio.h>
#include <stdlib.h>

void merge_array(int *arr, int start, int mid, int end, int *temp) {
	/************************************************************************/
	/* �ϲ�������������arr[start...mid]��arr[mid+1...end]                                                                     */
	/* temp������ʱ�洢�ź��������
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
	/* �鲢�㷨                                                                     */
	/* �㷨˼�룺�Ƚ�һ������������·��֣�Ȼ���ٹ鲢����ʹ�õݹ飩
	/************************************************************************/
	if (start < end)
	{
		int mid = (start + end)/2;
		merge_sort(arr,start,mid,temp); //�ȶ���ߵ���������
		merge_sort(arr,mid+1,end,temp); //Ȼ����ұߵ���������
		merge_array(arr,start,mid,end,temp); //�ϲ�������������
	}
}