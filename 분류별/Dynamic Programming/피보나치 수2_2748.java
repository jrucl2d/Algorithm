import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static long[] dp;

    public static void main(String[] args) throws IOException {
        input();
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.valueOf(br.readLine());
        dp = new long[n + 1];
        Arrays.fill(dp, -1);
        dp[0] = 0;
        dp[1] = 1;
        System.out.println(sol(n));
    }

    static long sol(int n) {
        if (dp[n] != -1)
            return dp[n];
        dp[n] = sol(n - 1) + sol(n - 2);
        return dp[n];
    }
}