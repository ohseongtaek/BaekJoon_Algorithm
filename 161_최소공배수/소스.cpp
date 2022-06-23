#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int maxdivision(int a, int b)
{
    int k = a % b;
    if (k == 0)
    {
        return b;
    }
    else
    {
        return maxdivision(b, k);
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int cnt;
    cin >> cnt;

    for (int i = 0; i < cnt; i++)
    {
        int a, b;
        int answer = 0;
        cin >> a >> b;

        answer = (a * b) / (maxdivision(a, b));

        cout << answer << endl;
    }

    return 0;
}