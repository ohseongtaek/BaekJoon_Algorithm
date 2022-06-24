#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int inArr[1001];
int DP[1001];
int RDP[1001];

int main()
{
	int a;
	int answer = 0;
	cin >> a;

	for (int i = 1; i <= a; i++)
	{
		int in;
		cin >> in;
		inArr[i] = in;
	}

	// 왼쪽에서 오른쪽으로 증가하는 부분수열 구하기 DP
	for (int i = 1; i <= a; i++)
	{
		DP[i] = 1;
		for (int j = 1; j <= i; j++)
		{
			// 크기가 작고 DP 누적된 값에서 현재 값보다 1개 큰 값인 경우 진입! 
			if (inArr[i] > inArr[j] && DP[i] < DP[j] + 1)
			{
				DP[i] = DP[j] + 1;
			}
		}
	}

	// 오른쪽에서 왼쪽으로 증가하는 부분수열 구하기 RDP
	for (int i = a; i >= 1; i--)
	{
		RDP[i] = 1;
		for (int j = a; j >= i; j--)
		{
			if (inArr[i] > inArr[j] && RDP[i] < RDP[j] + 1)
			{
				RDP[i] = RDP[j] + 1;
			}
		}
	}

	// 가장 큰 값 구하기 
	for (int i = 0; i <= a; i++)
	{
		if (answer < DP[i] + RDP[i] - 1)
		{
			answer = DP[i] + RDP[i] - 1;
		}
	}

	cout << answer << endl;
}