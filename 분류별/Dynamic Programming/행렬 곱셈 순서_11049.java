import java.io.*;
import java.util.*;

public class Main {
    static final int INF = Integer.MAX_VALUE;
    static int n;
    static int[][] arr;
    static int[][] dp = new int[510][510];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        n = Integer.valueOf(line);
        arr = new int[n][2];
        for (int i = 0; i < n; i++) {
            line = br.readLine();
            StringTokenizer st = new StringTokenizer(line, " ");
            arr[i][0] = Integer.valueOf(st.nextToken());
            arr[i][1] = Integer.valueOf(st.nextToken());
            Arrays.fill(dp[i], INF);
        }
        for (int i = 0; i < n; i++) {
            dp[i][i] = 0;
        }
        sol(0, n - 1);
        System.out.println(dp[0][n - 1]);
    }

    static void sol(int s, int e) {
        if (s == e)
            return;
        if (dp[s][e] != INF)
            return;
        if (s + 1 == e) {
            dp[s][e] = arr[s][0] * arr[s][1] * arr[e][1];
            return;
        }
        for (int i = s; i < e; i++) {
            sol(s, i);
            sol(i + 1, e);
            int now = dp[s][i] + dp[i + 1][e] + arr[s][0] * arr[i][1] * arr[e][1];
            dp[s][e] = Math.min(now, dp[s][e]);
        }
    }
}
