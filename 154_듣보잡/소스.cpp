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

	int n, m;
	cin >> n;
	cin >> m;

	map<string, int> nmap;
	vector<string> mvec;
	for (int i = 0; i < n; i++)
	{
		string in;
		cin >> in;
		nmap[in]++;
	}

	for (int i = 0; i < m; i++)
	{
		string in2;
		cin >> in2;
		mvec.push_back(in2);
	}

	vector<string> v;
	for (int i = 0; i < mvec.size(); i++)
	{
		string value = mvec[i];

		if (nmap[value] >= 1)
		{
			v.push_back(value);
		}
	}

	cout << v.size() << endl;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	return 0;
}