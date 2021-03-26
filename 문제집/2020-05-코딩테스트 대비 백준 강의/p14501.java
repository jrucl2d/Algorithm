import java.io.*;
import java.util.*;

public class p14501 {
    static BufferedWriter bw;
    static int n;
    static int[][] arr;
    static int[] dp;

    public static void main(String[] args) throws IOException {
        input();
        sol();
    }
    static void sol() {
        for (int i = 0; i < n; i++) {
            if (arr[i][0] + i <= n) {
                dp[i] = Math.max(dp[i], arr[i][1]);
            }
            for (int j = arr[i][0] + i; j < n; j++) {
                if (arr[j][0] + j <= n) {
                    dp[j] = Math.max(dp[j], dp[i] + arr[j][1]);
                }
            }

        }
        int ans = Integer.MIN_VALUE;
        for (int i : dp) {
            ans = Math.max(ans, i);
        }
        System.out.println(ans);
    }
    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String line = br.readLine();
        n = Integer.valueOf(line);
        arr = new int[n][2];
        dp = new int[n];
        for (int i = 0; i < n; i++) {
            line = br.readLine();
            StringTokenizer st = new StringTokenizer(line, " ");
            arr[i] = new int[] {Integer.valueOf(st.nextToken()), Integer.valueOf(st.nextToken())};
        }
    }
}
