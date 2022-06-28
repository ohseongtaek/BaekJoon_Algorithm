#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

int DP[200000][26];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
   

    memset(DP, 0, sizeof(DP));

    string n;
    cin >> n;

    for (int i = 0; i < n.size(); i++)
    {
        if (i != 0)
        {
            for (int j = 0; j < 26; j++)
            {
                DP[i][j] = DP[i - 1][j];
            }
        }
        DP[i][n[i] - 'a']++;
    }


    int query = 0;
    cin >> query;

    for (int i = 0; i < query; i++)
    {
        int count = 0;
        char c;
        int s, e;
        cin >> c >> s >> e;

        int start, end;

        if (s == 0)
        {
            start = 0;
        }
        else
        {
            start = DP[s - 1][c - 'a'];
        }

        end = DP[e][c - 'a'];

        cout << end - start << '\n';

    }

    return 0;
}