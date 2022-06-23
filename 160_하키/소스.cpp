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

    int answer = 0;
    int W;
    int H;
    int x;
    int y;
    int p;
    int radius;
    cin >> W >> H >> x >> y >> p;

    // Get eclipse left right pos
    pair<int, int> left_c(x, y + H / 2);
    pair<int, int> right_c(x + W, y + H / 2);

    // Get Start Rect And End Rect
    pair<int, int> left_r(x, y);
    pair<int, int> right_r(x + W, y + H);

    // Get Radius
    radius = H / 2;

    // Get Person pos
    vector<pair<int, int>> vp;
    for (int i = 0; i < p; i++)
    {
        int px, py;
        cin >> px >> py;
        vp.push_back(make_pair(px, py));
    }
    
    for (int i = 0; i < vp.size(); i++)
    {
        int person_x = vp[i].first;
        int person_y = vp[i].second;

        // 왼쪽원에 포함되는 경우 
        if (pow(left_c.first - person_x, 2) + pow(left_c.second - person_y, 2) <= pow(radius, 2))
        {
            answer++;
            continue;
        }

        // 가운데 사각형에 포함되는 경우 
        if (left_r.first <= person_x && person_x <= right_r.first && left_r.second <= person_y && person_y <= right_r.second)
        {
            answer++;
            continue;
        }
        
        // 오른쪽원에 포함되는 경우 
        if (pow(right_c.first - person_x, 2) + pow(right_c.second - person_y, 2) <= pow(radius, 2))
        {
            answer++;
            continue;
        }
    }

    cout << "seongtaek " << answer << endl;
    return 0;
}