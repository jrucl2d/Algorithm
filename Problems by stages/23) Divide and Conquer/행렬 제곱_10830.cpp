#include <iostream>
using namespace std;
typedef long long ll;
#define arrMAX 5 + 1
ll arr[arrMAX][arrMAX];
ll ans[arrMAX][arrMAX];
ll n, b;
ll tmp[arrMAX][arrMAX];

void cal(ll a[arrMAX][arrMAX], ll b[arrMAX][arrMAX]) {
    for (int i = 0; i < n; i++) { // ����� �� (1000���� ���� ��������)
        for (int j = 0; j < n; j++) {
            tmp[i][j] = 0;
            for (int k = 0; k < n; k++) {
                tmp[i][j] += a[i][k] * b[k][j];
            }
            tmp[i][j] %= 1000;
        }
    }
    for (int i = 0; i < n; i++) // ���� ����� ġȯ
        for (int j = 0; j < n; j++)
            a[i][j] = tmp[i][j];
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(NULL);

    cin >> n >> b;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    //  1�� ������ �ϴ� ��� ����(���)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                ans[i][j] = 1;
            else
                ans[i][j] = 0;
        }
    }
    // ���� ���� ������� �ŵ����� ����
    while (b > 0) {
        if (b % 2 == 1) { // Ȧ���� ���
             // ����� ���� �� �� �����ش�.
            cal(ans, arr);
        }
        // ¦��, Ȧ���� ��� ���� ���� ����
        cal(arr, arr);
        b /= 2; // ������ ������ �����.
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
}