#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int cnt;
    cin >> cnt;

    for (int i = 0; i < cnt; i++)
    {
        long long answer = 1;
        int a, b;
        cin >> a >> b;

        // 조합 nCr 공식 => n!/(n-m)! * m!
        int r = 1;

        for (int j = b; j > b - a; j--)
        {
            answer *= j;
            answer /= r++;
        }
        
        cout << answer << endl;
    }
 
    return 0;
}