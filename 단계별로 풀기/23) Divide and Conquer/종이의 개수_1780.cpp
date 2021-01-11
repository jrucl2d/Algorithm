#include <iostream>
#include <string>
using namespace std;
#define MAX 2187 + 1
int arr[MAX][MAX];
int count1 = 0, count2 = 0, count3 = 0;

void func(int a, int b, int n) {
    // 탈출조건
    int num = arr[a][b];
    bool divide = false;
    for (int i = a; i < a + n; i++) {
        for (int j = b; j < b + n; j++) {
            if (arr[i][j] != num) { // 처음 숫자와 달라지면 분할
                divide = true; break;
            }
        }
    }
    if (divide) {
        n = n / 3;
        func(a, b, n); 
        func(a, b + n, n);
        func(a, b + 2 * n, n);
        func(a + n, b, n);
        func(a + n, b + n, n);
        func(a + n, b + 2 * n, n);
        func(a + 2 * n, b, n);
        func(a + 2 * n, b + n, n);
        func(a + 2 * n, b + 2 * n, n);
        return;
    }
    if (num == -1)
        count1++;
    else if (num == 0)
        count2++;
    else if (num == 1)
        count3++;
}


int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    func(0, 0, n);
    cout << count1 << "\n" << count2 << "\n" << count3 << "\n";
}
