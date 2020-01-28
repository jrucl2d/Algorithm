#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
// 세그먼트 트리 : 세그먼트 트리의 노드에 최소값의 인덱스를 저장해야 한다.
// 1. 세그먼트 트리를 만들어서 각 노드에 최소값의 인덱스르 저장
// 2. query 함수를 통해 구간 내 제일 낮은 막대의 높이를 구한다.
// 여기서부터 findMax함수를 이용
// 3. query를 통해 구간 내 최소 높이를 갖는 막대 인덱스 구한다.
// 4. 해당 인덱스의 왼쪽에 막대가 존재하면 왼쪽 구간 살핀다.
// 5. 해당 인덱스의 오른쪽에 막대가 존재하면 오른쪽 구간 살핀다.

// 세그먼트 트리 만드는 함수 -> 1번 수행
void init(vector<ll>& arr, vector<ll>& tree, int node, int start, int end) {
    if (start == end) // 단말 노드에 도착하면 해당 값을 넣어준다.
        tree[node] = start;
    else {
        int mid = (start + end) / 2;
        init(arr, tree, node * 2, start, mid); // 왼쪽 자식 노드 : node * 2
        init(arr, tree, node * 2 + 1, mid + 1, end); // 오른쪽 자식 노드 : node * 2 + 1
        
        // 각 구간에서 최소 인덱스를 저장
        if (arr[tree[node * 2]] < arr[tree[node * 2 + 1]])
            tree[node] = tree[node * 2];
        else
            tree[node] = tree[node * 2 + 1];
    }
}
// 구간에서 제일 낮은 막대 인덱스 구하기 (구하고자 하는 범위 : left ~ right) -> 2번 수행
int query(vector<ll>& arr, vector<ll>& tree, int node, int start, int end, int left , int right) {
    if (end < left || start > right) // left, right와 아예 관련 없는 경우
        return -1;
    else if (left <= start && end <= right) // left, right 안에 포함되는 노드는 그 값을 리턴
        return tree[node];
    // left, right가 start, end 사이에 있거나 겹쳐져 있는 경우
    int mid = (start + end) / 2;
    int lQuery = query(arr, tree, node * 2, start, mid, left, right);
    int rQuery = query(arr, tree, node * 2 + 1, mid + 1, end, left, right);

    if (lQuery == -1) // 좌측 자식 노드가 관련이 없으면 우측 자식 노드 리턴
        return rQuery;
    else if (rQuery == -1) // 위와 반대
        return lQuery;
    else if (arr[lQuery] < arr[rQuery]) // 자식 노드들이 관련이 있다면 더 작은 것을 리턴
        return lQuery;
    else
        return rQuery;
}

ll findMax(vector<ll>& arr, vector<ll>& tree, int start, int end) {
    int n = arr.size() - 1; // 전체 구간
    int index = query(arr, tree, 1, 1, n, start, end); // 구간 내 최소 높이를 구함
    ll area = (end - start + 1) * arr[index];

    // 해당 인덱스 왼쪽에 막대가 존재하면
    if (start < index) {
        ll tmp = findMax(arr, tree, start, index - 1);
        area = max(area, tmp);
    }
    // 해당 인덱스 오른쪽에 막대가 존재하면
    if (index < end) {
        ll tmp = findMax(arr, tree, index + 1, end);
        area = max(area, tmp);
    }
    return area;
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(NULL);
    while (true) {
        int n;
        cin >> n;
        if (n == 0)
            break;
        vector<ll> arr(n + 1); // 1~n까지 값 입력
        for (int i = 1; i <= n; i++)
            cin >> arr[i];

        // 세그먼트 트리 크기를 구하는 공식
        // 2^k로 n보다 큰 가장 작은 수를 만드는 k를 구하고 2^k를 한 값에 2를 곱하면 세그먼트 크기 나옴.
        int h = (int)ceil(log2(n));
        int treeSize = (1 << (h + 1));
        vector<ll> tree(treeSize);
        init(arr, tree, 1, 1, n);
        cout << findMax(arr, tree, 1, n) << "\n";
    }
}