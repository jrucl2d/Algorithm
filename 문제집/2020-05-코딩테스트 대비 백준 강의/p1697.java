import java.io.*;
import java.util.*;

public class p1697 {
    static int n, m, INF = 100010;
    static int[] dp = new int[INF];

    public static void main(String[] args) throws IOException {
        input();
        sol();
    }
    static void sol() {
        Queue<Integer> q = new LinkedList<>();
        q.add(n);
        dp[n] = 0;
        while (!q.isEmpty()) {
            int now = q.remove();
            if (now == m) {
                System.out.println(dp[now]);
                break;
            }
            if (now * 2 < INF && (dp[now * 2] == -1 || dp[now * 2] > dp[now] + 1)) {
                dp[now * 2] = dp[now] + 1;
                q.add(2 * now);
            }
            if (now - 1 >= 0 && (dp[now - 1] == -1 || dp[now - 1] > dp[now] + 1)) {
                dp[now - 1] = dp[now] + 1;
                q.add(now - 1);
            }
            if (now + 1 < INF && (dp[now + 1] == -1 || dp[now + 1] > dp[now] + 1)) {
                dp[now + 1] = dp[now] + 1;
                q.add(now + 1);
            }
        }
    }
    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line, " ");
        n = Integer.valueOf(st.nextToken());
        m = Integer.valueOf(st.nextToken());
        for (int i = 0; i < INF; i++) {
            dp[i] = -1;
        }
    }
}
