#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int DP[21][21][21];

int func(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return 1;
    }
    else if (a > 20 || b > 20 || c > 20)
    {
        return func(20, 20, 20);
    }
    else if (a < b && b < c)
    {
        if (DP[a][b][c] != 0)
        {
            return DP[a][b][c];
        }
        else
        {
            return DP[a][b][c] = func(a, b, c - 1) + func(a, b - 1, c - 1) - func(a, b - 1, c);
        }
    }
    else
    {
        if (DP[a][b][c] != 0)
        {
            return DP[a][b][c];
        }
        else
        {
            return DP[a][b][c] = func(a - 1, b, c) + func(a - 1, b - 1, c) + func(a - 1, b, c - 1) - func(a - 1, b - 1, c - 1);
        }
    }
}

int main()
{
    while (1)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == -1 && b == -1 && c == -1)
        {
            break;
        }

        int answer = func(a, b, c);
        cout << "w(" << a << ", " << b << ", " << c <<") = " << answer << endl;
    }
}