class Solution {
    public int solution(int n, int[][] computers) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (computers[i][j] == 1) {
                    dfs(n, computers, i, j);
                    ans += 1;
                }
            }
        }
        return ans;
    }
    void dfs(int n, int[][] arr, int i, int j) {
        arr[i][j] = 0;
        for (int a = 0; a < n; a++) {
            if (arr[i][a] == 1) dfs(n, arr, i, a);
        }
        for (int a = 0; a < n; a++) {
            if (arr[a][i] == 1) dfs(n, arr, a, j);
        }
    }
}
