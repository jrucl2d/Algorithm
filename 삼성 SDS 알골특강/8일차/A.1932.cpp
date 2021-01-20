#include <iostream>

using namespace std;

int n;
int arr[501][501];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> arr[i][j];
        }
        for (int j = i + 1; j < n; j++) {
            arr[i][j] = -1;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            int cand1 = -1, cand2 = -1;
            if (j - 1 >= 0 && arr[i - 1][j - 1] != -1) {
                cand1 = arr[i - 1][j - 1];
            }
            if (arr[i - 1][j] != -1) {
                cand2 = arr[i - 1][j];
            }
            arr[i][j] += max(cand1, cand2);
        }
    }
    int ans = -1;
    for (int j = 0; j < n; j++) {
        ans = max(ans, arr[n - 1][j]);
    }
    cout << ans;
    return 0;
}