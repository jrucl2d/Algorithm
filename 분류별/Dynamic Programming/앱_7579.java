import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    static int[] memory;
    static int[] cost;
    static int[][] dp = new int[110][10010]; // i번 앱까지 종료하고 j cost로 얻을 수 있는 메모리

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line, " ");
        n = Integer.valueOf(st.nextToken());
        m = Integer.valueOf(st.nextToken());
        memory = new int[n + 1];
        cost = new int[n + 1];
        line = br.readLine();
        st = new StringTokenizer(line, " ");
        for (int i = 1; i <= n; i++) {
            memory[i] = Integer.valueOf(st.nextToken());
        }
        line = br.readLine();
        st = new StringTokenizer(line, " ");
        for (int i = 1; i <= n; i++) {
            cost[i] = Integer.valueOf(st.nextToken());
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 10000; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j - cost[i] >= 0)
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - cost[i]] + memory[i]);
            }
        }
        int ans = -1;
        for (int i = 0; i <= 10000; i++) {
            if (dp[n][i] >= m) {
                ans = i;
                break;
            }
        }
        System.out.println(ans);
    }
}
