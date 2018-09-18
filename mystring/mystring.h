#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char *str;
	int length;
}mystring;

void initial(mystring *s) {
	/************************************************************************/
	/* ��ʼ���ַ���                                                                     */
	/************************************************************************/
	s->str = NULL;
	s->length = 0;
}
int assign(mystring *s, char *ch) {
	/************************************************************************/
	/* �ַ�����ֵ                                                                     */
	/************************************************************************/
	//�ͷ�sԭ�пռ�
	if (s->str)
	{
		free(s->str);
	}

	//���ַ����ĳ���
	int count = 0;
	char *c = ch;
	while (*c++)
	{
		count++;
	}

	if (!count)
	{
		s->length = 0;
		s->str = NULL;
		return 1;
	}
	else {
		//�����ڴ�ռ�
		s->str = (char *)malloc(sizeof(char)*(count+1));
		if (!s->str)
		{
			return 0;
		}
		s->length = count;
		
		//��ֵ
		int i = 0;
		for (i=0;i<count;i++)
		{
			s->str[i] = ch[i];
		}
		s->str[s->length] = '\0';
		return 1;
	}

}

int equal(mystring s,mystring t) {
	/************************************************************************/
	/* �ж��ַ����Ƿ����                                                                     */
	/************************************************************************/
	int i = 0;
	int flag = 1;
	if (s.length != t.length)
	{
		return 0;
	}
	for (i=0;i<s.length && i<t.length;i++)
	{
		int value = s.str[i] - t.str[i];
		if (value != 0)
		{
			flag = 0;
			break;
		}
	}
	if (flag)
	{
		return 1;
	}
	else {
		return 0;
	}
}

int len(mystring s) {
	/************************************************************************/
	/* �����ַ����ĳ���                                                                     */
	/************************************************************************/
	return s.length;
}

int concat(mystring *s,mystring *t) {
	/************************************************************************/
	/* ���Ӻ���                                                                     */
	/************************************************************************/
	int new_length = s->length + t->length;
	s->str = (char *)realloc(s->str,sizeof(char)*(new_length+1));
	if (!s->str)
	{
		return 0;
	}
	for (int i=s->length,int j=0;i<new_length;i++,j++)
	{
		s->str[i] = t->str[j];
	}
	s->length = new_length;
	s->str[s->length] = '\0'; //�����ַ����ĺ�������ַ���������
	return 1;
}

mystring substr(mystring s,int start,int length) {
	/************************************************************************/
	/* ���Ӵ�                                                                     */
	/************************************************************************/
	mystring result;
	result.length = 0;
	result.str = "";
	if (start>=0 && start<=s.length-1 && length>0 && length <= s.length-start+1)
	{
		result.str = (char *)malloc(sizeof(char)*(length+1));
		for (int i=start,int j=0;i<s.length;i++,j++)
		{
			result.str[j] = s.str[i];
		}
	}
	result.length = length;
	result.str[length] = '\0';
	return result;
}

int index(mystring s,mystring t) {
	/************************************************************************/
	/* �Ӵ���λ����                                                                     */
	/************************************************************************/
	int n = len(s);
	int m = len(t);
	int i = 0;
	if (m == 0)
	{
		return -1;
	}
	while (i <= (n-m))
	{
		if (equal(substr(s,i,m),t))
		{
			return i;
		}
		i++;
	}
	return -1;
}

void replace(mystring *s,mystring t,mystring v) {
	/************************************************************************/
	/* �ַ����滻                                                                     */
	/************************************************************************/
	int idx = index(*s,t);
	if (idx >= 0)
	{
		int new_length = v.length + s->length - t.length;
		mystring new_s;
		new_s.str = (char *)malloc(sizeof(char)*(new_length+1));
		int i = 0,j=0;
		for (i=0;i<idx;i++)
		{
			new_s.str[i] = s->str[i];
		}
		new_s.length = idx+1;
		
		for (i=new_s.length-1,j=0;j<v.length;j++,i++)
		{
			new_s.str[i] = v.str[j];
		}
		new_s.length += v.length;

		for (i=new_s.length-1,j=idx+t.length;j<s->length;i++,j++)
		{
			new_s.str[i] = s->str[j];
		}
		new_s.length = new_length;
		new_s.str[new_s.length] = '\0';
		s->length = new_s.length;
		free(s->str);
		s->str = new_s.str;
		
		int idx = index(*s,t);
		if (idx >= 0)
		{
			replace(s,t,v);
		}
	}
}

void insert(mystring *s,int pos,mystring t) {
	/************************************************************************/
	/* �ַ�������                                                                     */
	/************************************************************************/
	mystring new_s;
	new_s.str = (char *)malloc(sizeof(char)*(s->length + t.length + 1));
	int i = 0,j=0;
	for (i=0;i<pos;i++)
	{
		new_s.str[i] = s->str[i];
	}
	new_s.length = pos;
	for (i=new_s.length,j=0;j<t.length;i++,j++)
	{
		new_s.str[i] = t.str[j];
	}
	new_s.length += t.length;
	for (i=new_s.length,j=pos;j<s->length;i++,j++)
	{
		new_s.str[i] = s->str[j];
	}
	new_s.length = s->length + t.length;
	new_s.str[new_s.length] = '\0';
	s->str = new_s.str;
	s->length = new_s.length;
}

void del(mystring *s,int pos,int length) {
	/************************************************************************/
	/* �ַ���ɾ��                                                                     */
	/************************************************************************/
	mystring new_s;
	new_s.str = (char *)malloc(sizeof(char)*(s->length - length + 1));
	int i=0,j=0;
	for (i=0;i<pos;i++)
	{
		new_s.str[i] = s->str[i];
	}
	new_s.length = pos;
	for (i=new_s.length,j=pos+length;j<s->length;i++,j++)
	{
		new_s.str[i] = s->str[j];
	}
	new_s.length = s->length - length;
	new_s.str[new_s.length] = '\0';
	s->str = new_s.str;
	s->length = new_s.length;
}

void display(mystring s) {
	/************************************************************************/
	/* ��ӡ�ַ���                                                                     */
	/************************************************************************/
	printf("%s\n",s);
}