import java.io.*;
import java.util.*;

public class Main {
    static int t, n;
    static int[] arr, nujuck;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        input();

    }

    static int sol(int start, int end) {
        if (start == end) {
            dp[start][end] = arr[start];
            return arr[start];
        }
        if (dp[start][end] != 0)
            return dp[start][end];
        dp[start][end] = Integer.MAX_VALUE;
        int ret = 0;
        for (int i = start; i < end; i++) {
            int a = sol(start, i);
            int b = sol(i + 1, end);
            ret = a + b + nujuck[end + 1] - nujuck[start];
            dp[start][end] = Math.min(dp[start][end], ret);
        }
        return dp[start][end];
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        StringTokenizer st;
        line = br.readLine();
        t = Integer.valueOf(line);
        for (int i = 0; i < t; i++) {
            line = br.readLine();
            n = Integer.valueOf(line);
            arr = new int[n];
            nujuck = new int[n + 1];
            dp = new int[510][510];
            line = br.readLine();
            st = new StringTokenizer(line, " ");
            for (int j = 0; j < n; j++) {
                arr[j] = Integer.valueOf(st.nextToken());
                nujuck[j + 1] = nujuck[j] + arr[j];
            }
            int ans = Integer.MAX_VALUE;
            for (int j = 0; j < n - 1; j++) {
                ans = Math.min(ans, sol(0, j) + sol(j + 1, n - 1));
            }
            System.out.println(ans);
        }
    }
}