import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    static int[] arr;
    static boolean[][] dp;

    public static void main(String[] args) throws IOException {
        input();
    }

    static boolean check(int s, int e) {
        if (dp[s][e])
            return true;
        if (s + 1 == e) {
            dp[s][e] = arr[s] == arr[e];
            return dp[s][e];
        }
        if (arr[s] == arr[e]) {
            dp[s][e] = check(s + 1, e - 1);
            return dp[s][e];
        }
        return false;
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.valueOf(br.readLine());
        String line = br.readLine();
        arr = new int[n + 1];
        StringTokenizer st = new StringTokenizer(line, " ");
        for (int i = 1; i <= n; i++) {
            arr[i] = Integer.valueOf(st.nextToken());
        }
        dp = new boolean[n + 1][n + 1];
        for (int i = 1; i <= n; i++)
            dp[i][i] = true;
        m = Integer.valueOf(br.readLine());
        int s, e;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < m; i++) {
            line = br.readLine();
            st = new StringTokenizer(line, " ");
            s = Integer.valueOf(st.nextToken());
            e = Integer.valueOf(st.nextToken());
            if (check(s, e)) {
                sb.append("1\n");
                continue;
            }
            sb.append("0\n");
        }
        System.out.println(sb);
    }
}