#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	map<long long, long long> mll;
	for (int i = 0; i < n; i++)
	{
		long long a;
		cin >> a;
		mll[a]++;
	}

	int n2;
	cin >> n2;
	
	vector<long long> vll;
	for (int i = 0; i < n2; i++)
	{
		long long a2;
		cin >> a2;
		vll.push_back(a2);
	}

	for (int i = 0; i < vll.size(); i++)
	{
		long long value = vll[i];

		if (mll[value] >= 1)
		{
			cout << "1" << " ";
		}
		else
		{
			cout << "0" << " ";
		}
	}

	return 0;
}