#include <iostream>
using namespace std;
typedef long long ll;
ll matrix[2][2] = { 1,1,1,0 }; // n+2, n+1�� �� ��İ� n+1, n�� ������ �� ���´�.
// ���� matrix�� n�� ���ϰ� 1,0�� ���ϸ� n + 1, n�� ���´�.
#define mod 1000000
ll tmp[2][2];

void mul(ll a[2][2], ll b[2][2]) { // matrix�� �����ϴ� �Լ�
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            tmp[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                tmp[i][j] += a[i][k] * b[k][j];
            }
            tmp[i][j] %= mod;
        }
    }
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            a[i][j] = tmp[i][j];
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(NULL);

    ll n;
    cin >> n;
    ll ans[2][2] = { 1,0,0,1 };
    while (n > 0) {
        if (n % 2 == 1) { // Ȧ���� ���
            mul(ans, matrix); // ���� �� �� �� �����ְ�
        }
        mul(matrix, matrix); // Ȧ,¦ ��� ���� ����
        n /= 2; // n�� ��������
    }
    // ans�� matrix�� n�� ������ ���� �������Ƿ� �� �� ���� 1, 0�� ���ϸ� n�� ���´�.
    // ���� ans�� [1][0]���� �����̴�.
    cout << ans[1][0];
}