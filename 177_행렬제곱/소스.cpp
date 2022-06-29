#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> Cal_division(vector<vector<long long>>& v, vector<vector<long long>>& v2, long long n)
{
	vector<vector<long long>> result(n, vector<long long>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				result[i][j] += v[i][k] * v2[k][j];
			}
			result[i][j] %= 1000;
		}
	}
	return result;
}

vector<vector<long long>> Cal(vector<vector<long long>> v, int n, long long cnt)
{
	vector<vector<long long>> result(n, vector<long long>(n));

	// 단위행렬로 변환!
	for (long long i = 0; i < n; i++)
	{
		result[i][i] = 1;
	}

	while (cnt > 0)
	{
		if (cnt % 2 == 1)
		{
			result = Cal_division(result, v, n);
		}
		cnt /= 2;
		v = Cal_division(v, v, n);
	}

	return result;
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long n, m;
	cin >> n >> m;
	vector<vector<long long>> v(n, vector<long long>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v[i][j];
		}
	}

	vector<vector<long long>> v_result = Cal(v, n, m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << v_result[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}
