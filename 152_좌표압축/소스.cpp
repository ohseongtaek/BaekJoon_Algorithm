#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int n, x;
	int cnt = 0;
	cin >> n;

	vector<pair<int, int>> vp;
	vector<pair<int, int>> answer;

	for (int i = 0; i < n; i++)
	{
		cin >> x;
		vp.push_back(make_pair(x, i));
	}

	sort(vp.begin(), vp.end());
	answer.push_back(make_pair(vp[0].second, 0));

	for (int i = 1; i < n; i++)
	{
		if (vp[i - 1].first == vp[i].first)
		{
			answer.push_back(make_pair(vp[i].second, cnt));
		}
		else
		{
			answer.push_back(make_pair(vp[i].second, ++cnt));
		}
	}

	sort(answer.begin(), answer.end());

	for (int i = 0; i < n; i++)
	{
		cout << answer[i].second << " ";
	}
}