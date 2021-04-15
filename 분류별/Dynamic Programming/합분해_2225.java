import java.io.*;
import java.util.*;

public class Main {
    static final int MOD = 1000000000;
    static int n, k;
    static int[][] dp = new int[201][201];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line, " ");
        n = Integer.valueOf(st.nextToken());
        k = Integer.valueOf(st.nextToken());
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                if (i == 1) {
                    dp[i][j] = j;
                    continue;
                }
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }
        System.out.println(dp[n][k]);
    }
}
