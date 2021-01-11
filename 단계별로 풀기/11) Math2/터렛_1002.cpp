#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x1, x2, y1, y2, r1, r2;
    int t;
    cin >> t;
    vector<int>ans;
    while (t-- > 0) {
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        double distance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
        int shortR = min(r1, r2); //짧은 반지름
        int longR = max(r1, r2); //긴 반지름

        if (distance <= longR) //원 안에 다른 원의 중심이 있을 경우
        {
            if (x1 == x2 && y1 == y2 && r1 == r2) //두 원 동일
                ans.push_back(-1);
            else if (distance + shortR < longR) //접점이 없는 경우
                ans.push_back(0);
            else if (distance + shortR == longR) //하나의 접점, 내적
                ans.push_back(1);
            else if (distance + shortR > longR) //두 개의 점점
                ans.push_back(2);
        }
        else // 원 밖에 다른 원의 중심이 있을 경우
        {
            if (distance > longR + shortR) //접점이 없는 경우
                ans.push_back(0);
            else if (distance == longR + shortR) //한개의 접점, 외적
                ans.push_back(1);
            else if (distance < longR + shortR) //두개의 접점
                ans.push_back(2);
        }
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << "\n";
}