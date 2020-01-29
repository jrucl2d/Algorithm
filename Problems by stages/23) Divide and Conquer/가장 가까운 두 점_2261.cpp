#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <limits.h>

using namespace std;
#define INF INT_MAX
typedef long long ll;
// 라인 스위핑과 Map을 이용한 풀이
// 1. 모든 x,y 값을 받고, x에 대해서 정렬
// 2. 반복을 통해 한 점을 특정해서, 그 점과 비교 점과의 x 거리를 구하는데 그 거리가 
//    최단 거리보다 크면 map에서 지운다.(라인 스위핑)
// 3. 최단 거리보다 짧으면 탈출. 그 점을 기준으로 lowerBound, upperBound를 이용해서 
//    현재 최단 거리의 길이를 가지는 사각형 내부의 모든 점의 최솟값 조사
// 4. 최솟값을 찾아서 현재 점 i를 map에 추가

// 거리 구하는 함수
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
    // x에 대해서 정렬                                        <- 1번 수행
    sort(v.begin(), v.end());

    // 처음 두 값을 y, x 순으로 맵에 추가
    mp[{v[0].second, v[0].first}] = 0; // lower bound, upper bound를 위해 -INF와 INF 이내의 값 설정
    mp[{v[1].second, v[1].first}] = 0;

    // 처음 두 점을 이용해서 최솟값을 생성, 초기화
    ll ans = distance(v[0], v[1]);
    int finding = 0; // 비교할 때 탐색용 인덱스
    for (int i = 2; i < n; i++) {

        // while문을 이용해서 최솟값보다 x거리가 긴 것을 제거   <- 2번 수행(라인 스위핑)
        while (finding < i) {

            // i와 비교하고 싶은 finding의 x거리 차이
            int distX = v[i].first - v[finding].first;

            // 최소값보다 작거나 같으면 라인 스위핑 이루어지지 않음
            if (distX * distX <= ans) 
                break;
            
            // 최솟값보다 크면 맵에서 지워줌(후보에서 지워줌)
            mp.erase({ v[finding].second, v[finding].first });
            finding++;
        }
        ll real = sqrt(ans); // 실제 거리

        // y값을 기준으로 최솟값 기준으로 영역 설정             <- 3번 수행
        auto left = mp.lower_bound({ v[i].second - real, -INF });
        auto right = mp.upper_bound({ v[i].second + real, INF });
        
        // 영역 내의 최솟값
        for (auto l = left; l != right; l++) {
            ans = min(ans, distance({ l->first.second,l->first.first }, v[i]));
        }

        // map에 추가. i번째 점은 뒤에 확인할 것이 남아있음. 후보
        mp[{v[i].second, v[i].first}] = 0;
    }
    cout << (int)ans << '\n';
}