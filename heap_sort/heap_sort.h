#include <stdio.h>

/**
/* ���ڶ������������ϣ�
/* ά���ٿƶ�����https://zh.wikipedia.org/wiki/%E5%A0%86%E6%8E%92%E5%BA%8F
/* ͼ�������https://www.cnblogs.com/chengxiao/p/6129630.html
**/

void heapify(int arr[], int start, int end) {
	/************************************************************************/
	/* �������Ķѻ�����ɸѡ�㷨                                                                     */
	/************************************************************************/
	int i = start; //i��ʾ���ڵ���±�
	int j = 2*i; //j��ʾ���ӽڵ���±�
	int x = arr[i]; //x�����ݴ���ڵ�ֵ
	while (j <= end)
	{
		if ((j < end) && (arr[j] > arr[j+1])) //�ҳ������ӽڵ�����С��
		{
			j++;
		}
		if (x > arr[j])
		{
			arr[i] = arr[j];
			i = j;
			j = 2*i; //�����ӽڵ��ƶ�
		}else {
			j = end + 1; //��С�������ӽڵ㣬�˳�ѭ��
		}
	}
	arr[i] = x;

}

void heap_sort(int arr[], int len) {
	/************************************************************************/
	/* �������㷨����Heap Sort                                                                     */
	/************************************************************************/
	
    int i,temp;
    for(i=len/2;i>=0;i--) { //����ʼ��:�ӵ�һ����Ҷ�ӽڵ㿪ʼ��������ڵ��ƶ�
        heapify(arr,i,len-1);
    }

    for(i=len-1;i>0;i--) { //����n-1��ѭ��������
        /* ��ʱ�Ķ�����Ϊһ���ѣ����ڵ���С�������ڵ��ֵ�����һ��Ҷ�ӽڵ��ֵ���� */
        temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr,0,i-1); //�±�i-1��len-1֮���ֵ��Ӧ��ֵ�������
    }
}