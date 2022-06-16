#include <iostream>
using namespace std;

int main()
{
    int a, b, c;

    cin >> a >> b >> c;

    int out = 0;
    if (a == b && b == c && a == c)
    {
        out = 10000 + (a * 1000);
    }
    else if ((a == b) || (b == c) || (a == c))
    {
        if (a == b)
        {
            out = 1000 + (a * 100);
        }
        else if (b == c)
        {
            out = 1000 + (b * 100);
        }
        else if (a == c)
        {
            out = 1000 + (a * 100);
        }
    }
    else
    {
        if (a >= b && a >= c)
        {
            out = a * 100;
        }
        else if (b >= a && b >= c)
        {
            out = b * 100;
        }
        else if (c >= a && c >= b)
        {
            out = c * 100;
        }
    }

    cout << out << endl;

    return 0;
}