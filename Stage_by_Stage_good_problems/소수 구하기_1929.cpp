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
    int a, b;
    cin >> a >> b;
    vector<int>ans;
    int range = b - a + 1;
    int* arr = new int[range];
    for (int i = 0; i < range; i++) {
        arr[i] = i + a;
        if (arr[i] == 1) continue; // 1일 경우 생략
        int divide = sqrt(arr[i]);
        for (int j = 2; j <= divide; j++) { // 1과 자신은 이미 나눈다고 가정
            // 여기서 나눠지는 것이 없어야 함
            if (arr[i] % j == 0)
                arr[i] = 0; // 나누어지는 경우 0으로 만듦
        }
        if (arr[i] != 0) ans.push_back(arr[i]); // 0이 아닐 경우 push
    }
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << "\n";
}