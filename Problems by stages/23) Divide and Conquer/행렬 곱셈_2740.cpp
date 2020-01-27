#include <iostream>
#include <string>
using namespace std;
#define MAX 101
int first[MAX][MAX];
int second[MAX][MAX];
int ans[MAX][MAX];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(NULL);
    int n, m, k;
    // 입력 받는 부분
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> first[i][j];
    cin >> m >> k;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < k; j++)
            cin >> second[i][j];
    // 계산하는 부분
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < m; j++) 
            for (int l = 0; l < k; l++) 
                ans[i][l] += first[i][j] * second[j][l];
    // 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
}
