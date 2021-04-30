import java.io.*;
import java.util.*;

public class Main {
    static final int MOD = 100000;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.valueOf(st.nextToken());
        int m = Integer.valueOf(st.nextToken());
        int[][][][] dp = new int[n + 1][m + 1][2][2]; // 현재 방향, 방향 전환 가능 여부
        for (int i = 1; i <= n; i++) {
            dp[i][1][0][1] = 1;
        }
        for (int i = 1; i <= m; i++) {
            dp[1][i][1][1] = 1;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 2; j <= m; j++) {
                // 현재 북쪽, 방향전환 불가 -> 아래에서 동쪽 바라보는 방향전환 가능한 쪽이 방향전환해서 올라온 것.
                dp[i][j][0][0] = dp[i - 1][j][1][1] % MOD;
                dp[i][j][1][0] = dp[i][j - 1][0][1] % MOD;
                // 현재 북쪽, 방향전환 가능 -> 아래에서 (북쪽 바라보는)방향전환 불가 + 가능
                dp[i][j][0][1] = (dp[i - 1][j][0][0] + dp[i - 1][j][0][1]) % MOD;
                dp[i][j][1][1] = (dp[i][j - 1][1][0] + dp[i][j - 1][1][1]) % MOD;
            }
        }
        int a = dp[n][m][0][0] + dp[n][m][0][1];
        int b = dp[n][m][1][0] + dp[n][m][1][1];
        System.out.println((a + b) % MOD);
    }
}
