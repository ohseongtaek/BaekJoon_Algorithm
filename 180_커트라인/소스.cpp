#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int h, c;
	cin >> h >> c;

	vector<int> v;

	for (int i = 0; i < h; i++)
	{
		int k;
		cin >> k;
		v.push_back(k);
	}

	sort(v.begin(), v.end());

	cout << v[v.size() - c] << endl;

}