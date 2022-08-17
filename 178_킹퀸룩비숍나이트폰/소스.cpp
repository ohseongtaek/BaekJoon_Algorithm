#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> v = { 1,1,2,2,2,8 };
	vector<int> v_in;
	vector<int> v_out;

	for (int i = 0; i < v.size(); i++)
	{
		int a;
		cin >> a;
		v_in.push_back(a);
	}

	for (int i = 0; i < v_in.size(); i++)
	{
		if (v[i] != v_in[i])
		{
			v_out.push_back(v[i] - v_in[i]);
		}
		else
		{
			v_out.push_back(0);
		}
	}

	for (int i = 0; i < v_out.size(); i++)
	{
		cout << v_out[i] << " ";
	}

}