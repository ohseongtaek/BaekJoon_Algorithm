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
	
	vector<int> v(n);
	map<int, int> m;
	map<int, int>::iterator iter;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		v[i] = a;
	}


	double avg = 0;
	int center = 0;
	int min_num = 2e9;
	int max_num = -2e9;

	int center_idx = v.size() / 2 + 1;

	for (int i = 0; i < v.size(); i++)
	{
		avg += v[i];

		m[v[i]]++;

		min_num = min(v[i], min_num);
		max_num = max(v[i], max_num);
	}

	double one = round((avg / v.size()) * 1) / 1;
	
	sort(v.begin(), v.end());
	center = v[v.size() / 2];

	int kk = 0;

	for (iter = m.begin(); iter != m.end(); iter++)
	{
		kk = max(kk, iter->second);
	}

	vector<int> a;

	for (iter = m.begin(); iter != m.end(); iter++)
	{
		if (kk == iter->second)
		{
			a.push_back(iter->first);
		}
	}

	sort(a.begin(), a.end());



	if (one == 0)
	{
		cout << abs(one) << endl;
	}
	else
	{
		cout << one << endl;
	}

	
	cout << center << endl;
	if (a.size() > 1)
	{
		cout << a[1] << endl;
	}
	else
	{
		cout << a[0] << endl;
	}
	
	cout << max_num - min_num << endl;



	return 0;
}