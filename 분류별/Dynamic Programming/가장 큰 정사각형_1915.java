import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    static int[][] arr, dp;

    public static void main(String[] args) throws IOException {
        int ans = 0;
        input();
        for (int i = 0; i < m; i++) {
            dp[n - 1][i] = arr[n - 1][i];
            if (arr[n - 1][i] == 1)
                ans = 1;
        }
        for (int i = 0; i < n; i++) {
            dp[i][m - 1] = arr[i][m - 1];
            if (arr[i][m - 1] == 1)
                ans = 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = m - 2; j >= 0; j--) {
                if (arr[i][j] == 0)
                    continue;
                int inner_min = Math.min(dp[i + 1][j], dp[i + 1][j + 1]);
                inner_min = Math.min(inner_min, dp[i][j + 1]);
                dp[i][j] = inner_min + 1;
                ans = Math.max(ans, dp[i][j]);
            }
        }
        System.out.println(ans * ans);
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        StringTokenizer st;
        line = br.readLine();
        st = new StringTokenizer(line, " ");
        n = Integer.valueOf(st.nextToken());
        m = Integer.valueOf(st.nextToken());
        arr = new int[n][m];
        dp = new int[n][m];
        for (int i = 0; i < n; i++) {
            line = br.readLine();
            for (int j = 0; j < m; j++) {
                arr[i][j] = (int) line.charAt(j) - (int) '0';
            }
        }
    }
}