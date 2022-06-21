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

	map<int, int> nmmap;
	map<int, int>::iterator iter;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		nmmap[a]++;
	}

	for (int i = 0; i < m; i++)
	{
		int a;
		cin >> a;
		nmmap[a]++;
	}

	int cont = 0;
	for (iter = nmmap.begin(); iter != nmmap.end(); iter++)
	{
		if (iter->second == 1)
		{
			cont++;
		}
	}

	cout << cont << endl;

	
	return 0;
}