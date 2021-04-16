import java.io.*;
import java.util.*;

public class Main {
    static final int MOD = 9901;
    static int n;
    static int[][] arr, dp;

    public static void main(String[] args) throws IOException {
        input();
        dp[0][0] = 1;
        dp[0][1] = 2;
        for (int i = 1; i < n + 1; i++) {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
            dp[i][1] = (dp[i - 1][0] + dp[i][0]) % MOD;
        }
        System.out.println(dp[n][0]);
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.valueOf(br.readLine());
        arr = new int[n][2];
        dp = new int[n + 1][2];
    }
}