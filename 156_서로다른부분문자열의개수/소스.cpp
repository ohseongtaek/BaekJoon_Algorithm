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

	string n;
	cin >> n;

	map<string, int> mp;
	for (int i = 0; i < n.size(); i++)
	{
		for (int j = 1; j < n.size() + 1; j++)
		{
			string temp = n.substr(i, j);
			mp[temp]++;
		}
	}

	cout << mp.size() << endl;

	return 0;
}