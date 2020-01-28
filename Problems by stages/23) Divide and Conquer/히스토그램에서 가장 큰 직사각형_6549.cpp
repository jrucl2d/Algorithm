#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
// ���׸�Ʈ Ʈ�� : ���׸�Ʈ Ʈ���� ��忡 �ּҰ��� �ε����� �����ؾ� �Ѵ�.
// 1. ���׸�Ʈ Ʈ���� ���� �� ��忡 �ּҰ��� �ε����� ����
// 2. query �Լ��� ���� ���� �� ���� ���� ������ ���̸� ���Ѵ�.
// ���⼭���� findMax�Լ��� �̿�
// 3. query�� ���� ���� �� �ּ� ���̸� ���� ���� �ε��� ���Ѵ�.
// 4. �ش� �ε����� ���ʿ� ���밡 �����ϸ� ���� ���� ���ɴ�.
// 5. �ش� �ε����� �����ʿ� ���밡 �����ϸ� ������ ���� ���ɴ�.

// ���׸�Ʈ Ʈ�� ����� �Լ� -> 1�� ����
void init(vector<ll>& arr, vector<ll>& tree, int node, int start, int end) {
    if (start == end) // �ܸ� ��忡 �����ϸ� �ش� ���� �־��ش�.
        tree[node] = start;
    else {
        int mid = (start + end) / 2;
        init(arr, tree, node * 2, start, mid); // ���� �ڽ� ��� : node * 2
        init(arr, tree, node * 2 + 1, mid + 1, end); // ������ �ڽ� ��� : node * 2 + 1
        
        // �� �������� �ּ� �ε����� ����
        if (arr[tree[node * 2]] < arr[tree[node * 2 + 1]])
            tree[node] = tree[node * 2];
        else
            tree[node] = tree[node * 2 + 1];
    }
}
// �������� ���� ���� ���� �ε��� ���ϱ� (���ϰ��� �ϴ� ���� : left ~ right) -> 2�� ����
int query(vector<ll>& arr, vector<ll>& tree, int node, int start, int end, int left , int right) {
    if (end < left || start > right) // left, right�� �ƿ� ���� ���� ���
        return -1;
    else if (left <= start && end <= right) // left, right �ȿ� ���ԵǴ� ���� �� ���� ����
        return tree[node];
    // left, right�� start, end ���̿� �ְų� ������ �ִ� ���
    int mid = (start + end) / 2;
    int lQuery = query(arr, tree, node * 2, start, mid, left, right);
    int rQuery = query(arr, tree, node * 2 + 1, mid + 1, end, left, right);

    if (lQuery == -1) // ���� �ڽ� ��尡 ������ ������ ���� �ڽ� ��� ����
        return rQuery;
    else if (rQuery == -1) // ���� �ݴ�
        return lQuery;
    else if (arr[lQuery] < arr[rQuery]) // �ڽ� ������ ������ �ִٸ� �� ���� ���� ����
        return lQuery;
    else
        return rQuery;
}

ll findMax(vector<ll>& arr, vector<ll>& tree, int start, int end) {
    int n = arr.size() - 1; // ��ü ����
    int index = query(arr, tree, 1, 1, n, start, end); // ���� �� �ּ� ���̸� ����
    ll area = (end - start + 1) * arr[index];

    // �ش� �ε��� ���ʿ� ���밡 �����ϸ�
    if (start < index) {
        ll tmp = findMax(arr, tree, start, index - 1);
        area = max(area, tmp);
    }
    // �ش� �ε��� �����ʿ� ���밡 �����ϸ�
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
        vector<ll> arr(n + 1); // 1~n���� �� �Է�
        for (int i = 1; i <= n; i++)
            cin >> arr[i];

        // ���׸�Ʈ Ʈ�� ũ�⸦ ���ϴ� ����
        // 2^k�� n���� ū ���� ���� ���� ����� k�� ���ϰ� 2^k�� �� ���� 2�� ���ϸ� ���׸�Ʈ ũ�� ����.
        int h = (int)ceil(log2(n));
        int treeSize = (1 << (h + 1));
        vector<ll> tree(treeSize);
        init(arr, tree, 1, 1, n);
        cout << findMax(arr, tree, 1, n) << "\n";
    }
}