#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int all, cnt;
	cin >> all >> cnt;

	vector<pair<int, int>> vp;

	for (int i = 0; i < cnt; i++)
	{
		int value, vcnt;
		cin >> value >> vcnt;

		vp.push_back(make_pair(value, vcnt));
	}

	int sum = 0;

	for (int i = 0; i < vp.size(); i++)
	{
		sum = sum + (vp[i].first * vp[i].second);
	}

	if (all == sum)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}


}