#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int DP[101];

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.first < b.first;
}

int main()
{
	int answer = 0;
	int a;
	cin >> a;

	vector<pair<int, int>> vp;

	for (int i = 0; i < a; i++)
	{
		int l, r;
		cin >> l >> r;
		vp.push_back(make_pair(l, r));
	}

	sort(vp.begin(), vp.end(), cmp);

	for (int i = 0; i < a; i++)
	{
		DP[i] = 1;

		for (int j = 0; j < i; j++)
		{
			if (vp[i].second > vp[j].second)
			{
				DP[i] = max(DP[i], DP[j] + 1);
			}
		}
		answer = max(answer, DP[i]);
	}

	cout << a - answer << endl;
}
