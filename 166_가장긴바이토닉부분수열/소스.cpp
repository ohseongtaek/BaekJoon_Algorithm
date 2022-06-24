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

	// ���ʿ��� ���������� �����ϴ� �κм��� ���ϱ� DP
	for (int i = 1; i <= a; i++)
	{
		DP[i] = 1;
		for (int j = 1; j <= i; j++)
		{
			// ũ�Ⱑ �۰� DP ������ ������ ���� ������ 1�� ū ���� ��� ����! 
			if (inArr[i] > inArr[j] && DP[i] < DP[j] + 1)
			{
				DP[i] = DP[j] + 1;
			}
		}
	}

	// �����ʿ��� �������� �����ϴ� �κм��� ���ϱ� RDP
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

	// ���� ū �� ���ϱ� 
	for (int i = 0; i <= a; i++)
	{
		if (answer < DP[i] + RDP[i] - 1)
		{
			answer = DP[i] + RDP[i] - 1;
		}
	}

	cout << answer << endl;
}