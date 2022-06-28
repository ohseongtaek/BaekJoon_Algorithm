#include <iostream>
#include <cstring>

using namespace std;

int arr[1025][1025], DP[1025][1025];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(arr, 0, sizeof(arr));

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int k;
			cin >> k;
			arr[i][j] = k;
			// ���ʰ� ���ʰ� ���� ���� ���� �׸��� ���ʰ� ���ʿ� �����ϰ� ���� ���� �ߺ��� ��(������ �밢��)�� ���� 
			DP[i][j] = DP[i - 1][j] + DP[i][j - 1] + arr[i][j] - DP[i - 1][j - 1]; 
		}
	}
	
	for (int i = 0; i < m; i++)
	{
		int result = 0;
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;

		// ���� �� 2���� ��� �ϱ� 
		result = DP[ex][ey] - DP[sx - 1][ey] - DP[ex][sy - 1] + DP[sx - 1][sy - 1];


		cout << result << '\n';
	}
}