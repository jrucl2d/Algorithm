#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <limits.h>

using namespace std;
#define INF INT_MAX
typedef long long ll;
// ���� �����ΰ� Map�� �̿��� Ǯ��
// 1. ��� x,y ���� �ް�, x�� ���ؼ� ����
// 2. �ݺ��� ���� �� ���� Ư���ؼ�, �� ���� �� ������ x �Ÿ��� ���ϴµ� �� �Ÿ��� 
//    �ִ� �Ÿ����� ũ�� map���� �����.(���� ������)
// 3. �ִ� �Ÿ����� ª���� Ż��. �� ���� �������� lowerBound, upperBound�� �̿��ؼ� 
//    ���� �ִ� �Ÿ��� ���̸� ������ �簢�� ������ ��� ���� �ּڰ� ����
// 4. �ּڰ��� ã�Ƽ� ���� �� i�� map�� �߰�

// �Ÿ� ���ϴ� �Լ�
ll distance(pair<int, int> a, pair<int, int> b) {
    int x = b.first - a.first;
    int y = b.second - a.second;
    return x * (ll)x + y * (ll)y;
}

map<pair<int, int>, int> mp;
vector<pair<int, int>>v;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(NULL);
    int n;
    cin >> n;
    int tmp1, tmp2;

    for (int i = 0; i < n; i++) {
        cin >> tmp1 >> tmp2;
        v.push_back({ tmp1, tmp2 });
    }
    // x�� ���ؼ� ����                                        <- 1�� ����
    sort(v.begin(), v.end());

    // ó�� �� ���� y, x ������ �ʿ� �߰�
    mp[{v[0].second, v[0].first}] = 0; // lower bound, upper bound�� ���� -INF�� INF �̳��� �� ����
    mp[{v[1].second, v[1].first}] = 0;

    // ó�� �� ���� �̿��ؼ� �ּڰ��� ����, �ʱ�ȭ
    ll ans = distance(v[0], v[1]);
    int finding = 0; // ���� �� Ž���� �ε���
    for (int i = 2; i < n; i++) {

        // while���� �̿��ؼ� �ּڰ����� x�Ÿ��� �� ���� ����   <- 2�� ����(���� ������)
        while (finding < i) {

            // i�� ���ϰ� ���� finding�� x�Ÿ� ����
            int distX = v[i].first - v[finding].first;

            // �ּҰ����� �۰ų� ������ ���� ������ �̷������ ����
            if (distX * distX <= ans) 
                break;
            
            // �ּڰ����� ũ�� �ʿ��� ������(�ĺ����� ������)
            mp.erase({ v[finding].second, v[finding].first });
            finding++;
        }
        ll real = sqrt(ans); // ���� �Ÿ�

        // y���� �������� �ּڰ� �������� ���� ����             <- 3�� ����
        auto left = mp.lower_bound({ v[i].second - real, -INF });
        auto right = mp.upper_bound({ v[i].second + real, INF });
        
        // ���� ���� �ּڰ�
        for (auto l = left; l != right; l++) {
            ans = min(ans, distance({ l->first.second,l->first.first }, v[i]));
        }

        // map�� �߰�. i��° ���� �ڿ� Ȯ���� ���� ��������. �ĺ�
        mp[{v[i].second, v[i].first}] = 0;
    }
    cout << (int)ans << '\n';
}