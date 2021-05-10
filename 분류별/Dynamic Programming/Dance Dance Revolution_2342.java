import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Solution solution = new Solution();
        List<Integer> list = new ArrayList<>();
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        while(st.hasMoreTokens()) {
            int now = Integer.valueOf(st.nextToken());
            if (now == 0) break;
            list.add(now);
        }
        System.out.println(solution.solution(list));
    }
    static class Solution {
        int[][] move = new int[5][5];
        // l, r일 때의 최소값
        int[][][] dp;
        public int solution(List<Integer> list) {
            for (int i = 0; i < 5; i++) {
                for (int j = 1; j < 5; j++) {
                    if (i == 0) {
                        move[i][j] = 2;
                        continue;
                    }
                    if (i - j == 2 || i - j == -2) {
                        move[i][j] = 4;
                        continue;
                    }
                    move[i][j] = 3;
                }
            }
            dp = new int[list.size()][5][5];
            for (int i = 0; i < list.size(); i++) {
                for (int j = 0; j < 5; j++) {
                    for (int k = 0; k < 5; k++) {
                        dp[i][j][k] = -1;
                    }
                }
            }
            return dfs(0, 0, list, 0);
        }
        int dfs(int l, int r, List<Integer> list, int index) {
            if (index == list.size()) {
                return 0;
            }
            int next = list.get(index);
            if (dp[index][l][r] != -1) return dp[index][l][r];
            if (l == next) {
                dp[index][l][r] = dfs(next, r, list, index + 1) + 1;
                return dp[index][l][r];
            }
            if (r == next) {
                dp[index][l][r] = dfs(l, next, list, index + 1) + 1;
                return dp[index][l][r];
            }
            dp[index][l][r] = Integer.MAX_VALUE;
            dp[index][l][r] = Math.min(dp[index][l][r], dfs(next, r, list, index + 1) + move[l][next]);
            dp[index][l][r] = Math.min(dp[index][l][r], dfs(l, next, list, index + 1) + move[r][next]);
            return dp[index][l][r];
        }
    }
}