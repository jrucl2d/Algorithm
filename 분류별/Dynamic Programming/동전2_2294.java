import java.io.*;
import java.util.*;

public class Main {
    final static int INF = 1000001;
    static int n, k;
    static int[] coin;
    static int[] dp = new int[100010];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line, " ");
        n = Integer.valueOf(st.nextToken());
        k = Integer.valueOf(st.nextToken());
        coin = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            coin[i] = Integer.valueOf(br.readLine());
        }
        Arrays.fill(dp, INF);
        dp[0] = 0;
        for (int i = 1; i <= k; i++) {
            for (int j = 0; j < n; j++) {
                if (i - coin[j] < 0)
                    continue;
                dp[i] = Math.min(dp[i], dp[i - coin[j]] + 1);
            }
        }
        System.out.println(dp[k] == INF ? -1 : dp[k]);
    }
}
