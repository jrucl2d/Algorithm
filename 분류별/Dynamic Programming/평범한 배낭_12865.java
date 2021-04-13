import java.io.*;
import java.util.*;

public class Main {
    static int n, k;
    static Info[] info;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line, " ");
        n = Integer.valueOf(st.nextToken());
        k = Integer.valueOf(st.nextToken());
        info = new Info[n];
        int t1, t2;
        for (int i = 0; i < n; i++) {
            line = br.readLine();
            st = new StringTokenizer(line, " ");
            t1 = Integer.valueOf(st.nextToken());
            t2 = Integer.valueOf(st.nextToken());
            info[i] = new Info(t2, t1);
        }
        dp = new int[n + 1][k + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                if (j - info[i - 1].weight < 0) {
                    dp[i][j] = dp[i - 1][j];
                    continue;
                }
                dp[i][j] = Math.max(dp[i - 1][j], dp[i - 1][j - info[i - 1].weight] + info[i - 1].val);
            }
        }
        System.out.println(dp[n][k]);
    }

    static class Info {
        int val, weight;

        Info(int val, int weight) {
            this.val = val;
            this.weight = weight;
        }
    }
}
