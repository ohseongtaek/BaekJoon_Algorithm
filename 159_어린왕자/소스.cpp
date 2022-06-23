#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

double getEclipseRange(int len)
{
    double b = sqrt(pow(len, 2)/2);
    return b;
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int cnt;
    cin >> cnt;

    for (int i = 0; i < cnt; i++)
    {
        int answer = 0;
        int start_x;
        int start_y;
        int end_x;
        int end_y;
        int galaxyCnt;
        
        cin >> start_x;
        cin >> start_y;
        cin >> end_x;
        cin >> end_y;
        cin >> galaxyCnt;
        

        for (int j = 0; j < galaxyCnt; j++)
        {
            int x;
            int y;
            int len;

            cin >> x;
            cin >> y;
            cin >> len;

            bool include_start = false;
            bool include_end = false;

            if (pow(start_x - x, 2) + pow(start_y - y, 2) < pow(len, 2))
            {
                include_start = true;
            }
           
            if (pow(end_x - x, 2) + pow(end_y - y, 2) < pow(len, 2))
            {
                include_end = true;
            }

            // 시작점과 종료점 둘다 원에 포함되는 경우 
            if (include_start == true && include_end == true)
            {
                // nothing
            }
            // 시작점만 원에 포함되는 경우 
            else if (include_start == true && include_end == false)
            {
                answer++;
            }
            // 종료점만 원에 포함되는 경우 
            else if (include_start == false && include_end == true)
            {
                answer++;
            }
            // 둘다 원에 포함되지 않는 경우 
            else
            {
                // nothing
            }
        }

        cout << answer << endl;
    }

    return 0;
}