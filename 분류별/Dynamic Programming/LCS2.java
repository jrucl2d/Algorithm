import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        input();
    }

    static void sol(String a, String b) {
        dp = new int[n + 1][m + 1];
        boolean flag = false;
        for (int i = 0; i < n; i++) {
            if (flag) {
                dp[i + 1][1] = 1;
                continue;
            }
            if (a.charAt(i) == b.charAt(0)) {
                dp[i + 1][1] = 1;
                flag = true;
            }
        }
        flag = false;
        for (int j = 0; j < m; j++) {
            if (flag) {
                dp[1][j + 1] = 1;
                continue;
            }
            if (a.charAt(0) == b.charAt(j)) {
                dp[1][j + 1] = 1;
                flag = true;
            }
        }
        int index = 2;
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                int before;
                if (a.charAt(i) == b.charAt(j)) {
                    before = Math.max(dp[i][j + 1], Math.max(dp[i][j] + 1, dp[i + 1][j]));
                    dp[i + 1][j + 1] = before;
                    continue;
                }
                before = Math.max(dp[i][j + 1], Math.max(dp[i][j], dp[i + 1][j]));
                dp[i + 1][j + 1] = before;
            }
        }
        List<Character> ans = new ArrayList<>();
        int i = n, j = m;
        while (true) {
            if (i == 0 || j == 0)
                break;
            if (dp[i][j] == dp[i - 1][j]) {
                i -= 1;
            } else if (dp[i][j] == dp[i][j - 1]) {
                j -= 1;
            } else {
                i -= 1;
                j -= 1;
                ans.add(a.charAt(i));
            }
        }
        System.out.println(dp[n][m]);
        if (dp[n][m] == 0)
            System.exit(0);
        for (i = ans.size() - 1; i >= 0; i--) {
            System.out.print(ans.get(i));
        }
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s1 = br.readLine();
        String s2 = br.readLine();
        n = s1.length();
        m = s2.length();
        sol(s1, s2);
    }
}