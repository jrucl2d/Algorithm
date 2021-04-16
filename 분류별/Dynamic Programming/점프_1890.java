import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static int[][] arr;
    static long[][] dp;

    public static void main(String[] args) throws IOException {
        input();
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dp[i][j] == 0)
                    continue;
                if (i == n - 1 && j == n - 1)
                    break;
                if (i + arr[i][j] < n) {
                    dp[i + arr[i][j]][j] += dp[i][j];
                }
                if (j + arr[i][j] < n) {
                    dp[i][j + arr[i][j]] += dp[i][j];
                }
            }
        }
        System.out.println(dp[n - 1][n - 1]);
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.valueOf(br.readLine());
        arr = new int[n][n];
        dp = new long[n][n];
        String line;
        StringTokenizer st;
        for (int i = 0; i < n; i++) {
            line = br.readLine();
            st = new StringTokenizer(line, " ");
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.valueOf(st.nextToken());
            }
        }
    }

}