#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

//https://www.acmicpc.net/problem/9095
//���̳��� ���α׷��� = ��ȭ�� ���ϱ�, ������������ �ذ��ؼ� ū�� �ذ�, �޸������̼�

int getbiggest(int* a,int n)
{
	int i = a[0];
	for (int j = 1; j < n; j++)
	{
		if (i < a[j])
		{
			i = a[j];
		}
	}
	return i;
}

int main()
{
	int tnum = 0;
	int endnum = 0;
	printf("�׽�Ʈ ���̽� ������ �Է��ϼ���:");
	scanf("%d", &tnum);
	printf("\n");
	int* testcase = new int[tnum];

	printf("�׽�Ʈ ���̽��� �Է��ϼ���:\n");
	for (int i = 0; i < tnum; i++)
	{
		scanf("%d", &testcase[i]);
	}
	printf("\n");
	

	endnum = getbiggest(testcase, tnum);
	int* testing = new int[endnum];
	testing[0] = 1;
	testing[1] = 2;
	testing[2] = 4;
	
	for (int i = 3; i < endnum; i++)
	{
		testing[i] = testing[i-1] + testing[i-2] + testing[i-3];
	}
	int index = 0;
	for (int i = 0; i < tnum; i++)
	{
		printf("%d\n", testing[testcase[i]-1]);
	}

	

	return 0;
}

