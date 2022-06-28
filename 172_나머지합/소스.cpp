#include <iostream>
#include <cstring>

using namespace std;

long mod[1005];
long sum = 0;
long result = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	memset(mod, 0, sizeof(mod));

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int in;
		cin >> in;
		sum += in;
		mod[sum % m]++;
	}
	
	for (int i = 0; i < m; i++) 
	{
		result += mod[i] * (mod[i] - 1) / 2;
	}
	result += mod[0];
	cout << result;
	return 0;
}