#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int DP[1001][1001];

int main()
{
	// LCS ¹®Á¦ !
	int answer = 0;
	string a, b;
	cin >> a;
	cin >> b;

	for (int i = 1; i <= a.size(); i++)
	{
		for (int j = 1; j <= b.size(); j++)
		{
			if (a[i - 1] == b[j - 1])
			{
				DP[i][j] = DP[i - 1][j - 1] + 1;
			}
			else
			{
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
			}
		}
	}

	answer = DP[a.size()][b.size()];
	cout << answer << endl;
}