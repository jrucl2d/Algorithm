class Solution {
    public int solution(int n, int[] lost, int[] reserve) {
        int[] st = new int[n + 1];
        for (int i = 1; i < n + 1; i++) st[i] = 1;
        for (int l : lost) {
            st[l] -= 1;
        }
        for (int r : reserve) {
            st[r] += 1;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (st[i] != 0) { ans += 1; continue; }
            if (i != 1 && st[i - 1] > 1) { st[i - 1] -= 1; st[i] += 1; ans += 1; continue; }
            if (i != n && st[i + 1] > 1) { st[i + 1] -= 1; st[i] += 1; ans += 1; }
        }
        return ans;
    }
}
