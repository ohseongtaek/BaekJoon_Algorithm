#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int cnt;
    cin >> cnt;

    vector<pair<int, int>> vp;
    pair<int, int> pone(0,0);
    
    int x_max_value = 0;
    int x_min_value = 501;
    int y_max_value = 0;
    int y_min_value = 501;

    for (int i = 0; i < 6; i++)
    {
        int dir, value;
        cin >> dir;
        cin >> value;

        // 1 µ¿ , 2 ¼­ , 3 ³², 4 ºÏ
        if (dir == 1)
        {
            pone.first += value;
            x_max_value = max(x_max_value, pone.first);
            x_min_value = min(x_min_value, pone.first);
        }
        else if (dir == 2)
        {
            pone.first -= value;
            x_max_value = max(x_max_value, pone.first);
            x_min_value = min(x_min_value, pone.first);
        }
        else if (dir == 3)
        {
            pone.second -= value;
            y_max_value = max(y_max_value, pone.second);
            y_min_value = min(y_min_value, pone.second);
        }
        else if (dir == 4)
        {
            pone.second += value;
            y_max_value = max(y_max_value, pone.second);
            y_min_value = min(y_min_value, pone.second);
        }

        vp.push_back(pone);
    }

    // center pos 
    pair<int, int> centerpos;
    for (int i = 0; i < vp.size(); i++)
    {
        int x = vp[i].first;
        int y = vp[i].second;

        if (x_min_value < x && y_min_value < y && x < x_max_value && y < y_max_value)
        {
            centerpos.first = x;
            centerpos.second = y;
            break;
        }
    }

    // small rect cal
    int small_rect_x = 0;
    int small_rect_y = 0;

    bool x_flag = false;
    bool y_flag = false;
    
    for (int i = 0; i < vp.size(); i++)
    {
        if (vp[i].first == centerpos.first && vp[i].second == centerpos.second)
        {
            continue;
        }

        if (vp[i].first == centerpos.first)
        {
            small_rect_y = abs(abs(centerpos.second) - abs(vp[i].second));
            y_flag = true;
        }

        if (vp[i].second == centerpos.second)
        {
            small_rect_x = abs(abs(centerpos.first) - abs(vp[i].first));
            x_flag = true;
        }

        if (x_flag == true && y_flag == true)
        {
            break;
        }
    }

    // ALL Cal
    int answer = ((abs(x_max_value) + abs(x_min_value)) * (abs(y_max_value) + abs(y_min_value)) * cnt) - (small_rect_x * small_rect_y * cnt);
    
    cout << answer << endl;


    return 0;
}