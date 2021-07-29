import java.util.*;
class Solution {
    int[] parent = new int[100];
    public int solution(int n, int[][] costs) {
        for (int i = 1; i < 100; i++) parent[i] = i;
        int ans = 0;
        
        Arrays.sort(costs, (a, b) -> a[2] - b[2]);
        int nn = costs.length;
        for (int i = 0; i < nn; i++) {
            int a = costs[i][0];
            int b = costs[i][1];
            if (find_p(a) == find_p(b)) continue;
            union_p(a, b);
            ans += costs[i][2];
        }
        return ans;
    }
    void union_p(int a, int b) {
        a = find_p(a);
        b = find_p(b);
        if (a < b) {
            parent[b] = a;
        } else {
            parent[a] = b;
        }
    }
    int find_p(int a) {
        if (parent[a] == a) return a;
        parent[a] = find_p(parent[a]);
        return parent[a];
    }
}
