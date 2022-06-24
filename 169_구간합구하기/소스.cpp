#include <iostream>
#include <vector>

#define endl '\n'
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a, b;
	cin >> a >> b;
	
	vector<long> v(a + 1);
	v[0] = 0;
	for (int i = 1; i <= a; i++)
	{
		long in;
		cin >> in;
		v[i] = v[i - 1] + in;
	}

	for (int i = 0; i < b; i++)
	{
		int start, end;
		cin >> start >> end;
		cout << v[end] - v[start - 1] << endl;
	}
}