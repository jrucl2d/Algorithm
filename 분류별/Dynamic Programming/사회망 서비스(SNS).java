import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static List<Integer>[] two;
    static boolean[] visited;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        input();
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        n = Integer.valueOf(line);
        StringTokenizer st;
        two = new List[n + 1];
        visited = new boolean[n + 1];
        dp = new int[n + 1][2];
        for (int i = 0; i <= n; i++) {
            two[i] = new ArrayList<>();
        }
        for (int i = 0; i < n - 1; i++) {
            line = br.readLine();
            st = new StringTokenizer(line, " ");
            int a = Integer.valueOf(st.nextToken());
            int b = Integer.valueOf(st.nextToken());
            two[a].add(b);
            two[b].add(a);
        }
        for (int i = 1; i <= n; i++) {
            dp[i][0] = dp[i][1] = -1;
            if (two[i].size() == 1) {
                dp[i][0] = 0;
                dp[i][1] = 1;
            }
        }
        sol(1);
        System.out.println(Math.min(dp[1][0], dp[1][1]));
    }

    static void sol(int now) {
        visited[now] = true;
        dp[now][0] = 0;
        dp[now][1] = 1;
        for (int i = 0; i < two[now].size(); i++) {
            int next = two[now].get(i);
            if (visited[next])
                continue;
            sol(next);
            dp[now][0] += dp[next][1];
            dp[now][1] += Math.min(dp[next][0], dp[next][1]);
        }
    }
}