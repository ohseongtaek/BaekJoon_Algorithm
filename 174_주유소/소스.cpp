#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() 
{

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	// 2 3 1
	vector<long> city_len(n-1,0);
	for (int i = 0; i < n-1; i++)
	{
		long len;
		cin >> len;
		city_len[i] = len;
	}

	// 5 2 4 1
	vector<pair<long,long>> pr_city_len_value;
	int k = 0;
	for (int i = 0; i < n-1; i++)
	{
		long value;
		cin >> value;

		if (k == 0)
		{
			pr_city_len_value.push_back(make_pair(city_len[i], value));
		}
		else
		{
			if (value < pr_city_len_value[k - 1].second)
			{
				pr_city_len_value.push_back(make_pair(city_len[i], value));
			}
			else
			{
				pr_city_len_value[k - 1].first += city_len[i];
				k--;
			}
		}
		k++;
	}

	long result = 0;
	for (int i = 0; i < pr_city_len_value.size(); i++)
	{
		result += pr_city_len_value[i].first * pr_city_len_value[i].second;
	}

	cout << result << '\n';
	
}