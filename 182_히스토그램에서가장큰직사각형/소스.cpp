#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int* tree;
long long arr[100000];
long long result, curH;
int num;

int init(int node, int start, int end)
{
	if (start == end)
	{
		return tree[node] = start;
	}
	int mid = start + (end - start) / 2;
	int lidx = init(2 * node, start, mid);
	int ridx = init(2 * node + 1, mid + 1, end);
	return tree[node] = arr[lidx] > arr[ridx] ? ridx : lidx;
}

int findmaxidx(int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
	{
		return -1;
	}

	if (left <= start && end <= right)
	{
		return tree[node];
	}

	int mid = start + (end - start) / 2;
	int lidx = findmaxidx(node * 2, start, mid, left, right);
	int ridx = findmaxidx(node * 2 + 1, mid + 1, end, left, right);

	if (lidx == -1)
	{
		return ridx;
	}
	else if (ridx == -1)
	{
		return lidx;
	}

	return arr[lidx] > arr[ridx] ? ridx : lidx;
}

void findmax(int left, int right)
{
	int minidx = findmaxidx(1, 0, num - 1, left, right);
	long long temp = arr[minidx] * (right - left + 1);

	result = max(result, temp);

	if (left < minidx)
	{
		findmax(left, minidx - 1);
	}
	if (minidx < right)
	{
		findmax(minidx + 1, right);
	}
}


int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int h;

	while (1)
	{
		cin >> num;
		if (num == 0)
		{
			break;
		}

		h = ceil(log2(num));

		tree = new int[1 << (h + 1)];

		for(int i=0; i<num; i++)
		{
			cin >> arr[i];
		}

		init(1, 0, num - 1);

		result = 0;

		findmax(0, num - 1);

		cout << result << endl;
	}

	return 0;
}