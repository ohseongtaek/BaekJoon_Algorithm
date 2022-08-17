#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };


int map[501][501];
int dp[501][501];

int row, col;

int DFS(int x, int y)
{
	if (x == row - 1 && y == col - 1)
	{
		return 1;
	}
	else if (dp[x][y] == -1)
	{
		dp[x][y] = 0;
		for (int dir = 0; dir < 4; dir++)
		{
			int tx = x + dx[dir];
			int ty = y + dy[dir];

			if (0 <= tx && tx < row && 0 <= ty && ty < col && map[x][y] > map[tx][ty]) {
				dp[x][y] += DFS(tx, ty);
			}
		}
	}
	return dp[x][y];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> row >> col;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}

	cout << DFS(0, 0);
}