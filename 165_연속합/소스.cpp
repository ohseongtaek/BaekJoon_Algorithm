#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int DP[100001];
int N[100001];

int main()
{
	int a;
	int answer = 0;
	cin >> a;

	for (int i = 0; i < a; i++)
	{
		int in;
		cin >> in;
		N[i] = in;
	}

	answer = N[0];
	DP[0] = N[0];
	for (int i = 1; i < a; i++)
	{
		DP[i] = max(N[i] + DP[i-1], N[i]);
		answer = max(DP[i], answer);
	}

	cout << answer << endl;

}