import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Solution solution = new Solution();
        int n = Integer.valueOf(br.readLine());
        int [][] arr = new int[n][n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.valueOf(st.nextToken());
            }
        }
        String status = br.readLine();
        int p = Integer.valueOf(br.readLine());
        System.out.println(solution.solution(n, arr, status, p));
    }
    static class Solution {
        int n, MAX = 999654321;
        int[][] dp;
        public int solution(int nn, int[][] arr, String status, int p) {
            StringBuilder isNope = new StringBuilder();
            for (int i = 0; i < nn; i++) {
                isNope.append("N");
            }
            if (status.equals(isNope.toString())) {
                if (p == 0) return 0;
                return -1;
            }
            int now = 0;
            n = nn;
            int statusNow = 0;
            for (int i = 0; i < status.length(); i++) {
                if (status.charAt(i) == 'Y') {
                    now += 1;
                    statusNow += (1 << i);
                }
            }
            dp = new int[n][(1 << 16)]; // 총 i개가 가동중이고 상태가 j일 때 최소 값
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < (1 << 16); j++) dp[i][j] = MAX;
            }
            return dfs(now, p, statusNow, arr);
        }
        int dfs(int now, int end, int status, int[][] arr) {
            if (now >= end) {
                return 0;
            }
            if (dp[now][status] != MAX) return dp[now][status];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j) continue;
                    if ((status & (1 << i)) != (1 << i)) continue;
                    if ((status & (1 << j)) == (1 << j)) continue;
                    dp[now][status] = Math.min(dp[now][status],
                            dfs(now + 1, end, status + (1 << j), arr) + arr[i][j]);
                }
            }
            return dp[now][status];
        }
    }
}