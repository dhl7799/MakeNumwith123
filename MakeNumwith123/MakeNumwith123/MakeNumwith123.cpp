#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

//https://www.acmicpc.net/problem/9095
//다이나믹 프로그래밍 = 점화식 구하기, 작은문제들을 해결해서 큰걸 해결, 메모이제이션

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
	printf("테스트 케이스 개수를 입력하세요:");
	scanf("%d", &tnum);
	printf("\n");
	int* testcase = new int[tnum];

	printf("테스트 케이스를 입력하세요:\n");
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

