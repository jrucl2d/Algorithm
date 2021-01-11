#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(NULL);
    ll a, b, c;
    cin >> a >> b >> c;
    // Ȧ���� ���� C^n = C^(n-1)/2 * C^(n-1)/2 * C�̰� (�ϳ��� ���� �� ������ �� �� �� �� ����
    // ¦���� ���� C^n = C^(n/2) * (n/2) �̴�.
    ll ans = 1;
    ll index = b;
    while (index > 0) {
        if (index % 2 == 1) { // Ȧ���� ��
            ans *= a; // ����� ���� �� �� �����ش�.
            ans %= c;
        }
        a %= c;
        a *= a; // ¦��/Ȧ�� ��� ���� ���� �����Ѵ�.
        a %= c;
        index /= 2; // ������ ������ �ɰ���.
    }
    cout << ans % c;
}