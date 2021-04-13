import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    static int[] balls;
    // i번재 추까지 사용해서 j무게를 만들 수 있는지
    static boolean[][] dp = new boolean[31][40010];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        n = Integer.valueOf(line);
        line = br.readLine();
        StringTokenizer st = new StringTokenizer(line, " ");
        balls = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            balls[i] = Integer.valueOf(st.nextToken());
        }
        beforeTask();
        line = br.readLine();
        m = Integer.valueOf(line);
        line = br.readLine();
        st = new StringTokenizer(line, " ");
        int now;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < m; i++) {
            now = Integer.valueOf(st.nextToken());
            sb.append(dp[n][now] ? "Y " : "N ");
        }
        System.out.println(sb);
    }

    static void beforeTask() {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 40_001; j++) {
                if (j == balls[i]) {
                    dp[i][j] = true;
                    continue;
                }
                if (dp[i - 1][j]) {
                    dp[i][j] = true;
                    continue;
                }
                if (balls[i] + j <= 40010 && dp[i - 1][balls[i] + j]) {
                    dp[i][j] = true;
                    continue;
                }
                if (j - balls[i] < 0) {
                    if (dp[i - 1][balls[i] - j])
                        dp[i][j] = true;
                    continue;
                }
                if (dp[i - 1][j - balls[i]])
                    dp[i][j] = true;
            }
        }
    }
}
