#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int arr[2001];
bool palindrom[2001][2001] = { false, };

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);


	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) 
	{
		cin >> arr[i];
	}

	// 2개인 팰린드롭 찾기 
	for (int i = 1; i <= n - 1; i++) 
	{
		if (arr[i] == arr[i + 1]) 
		{
			palindrom[i][i + 1] = true;
		}
	}

	// 1개인 팰린드롭 찾기 
	for (int i = 1; i <= n; i++) 
	{
		palindrom[i][i] = true;
	}

	// 다른 값들에 대한범위 계산 
	for (int i = n - 1; i >= 1; i--) 
	{
		for (int j = i + 2; j <= n; j++) 
		{
			if (arr[i] == arr[j] && palindrom[i + 1][j - 1] == true) 
			{
				palindrom[i][j] = true;
			}
		}
	}

	int m, s, e;
	cin >> m;

	for (int i = 0; i < m; i++) 
	{
		cin >> s >> e;
		cout << palindrom[s][e] << '\n';
	}
}



