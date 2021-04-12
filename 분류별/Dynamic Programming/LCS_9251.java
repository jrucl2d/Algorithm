import java.io.*;

public class LCS_9251 {

    static String a;
    static String b;
    static int[][] dp;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        a = br.readLine();
        b = br.readLine();
        int a_size = a.length(), b_size = b.length();

        dp = new int[a_size][b_size];
        if (a.charAt(0) == b.charAt(0))
            dp[0][0] = 1;

        for (int i = 1; i < a_size; i++) {
            if (b.charAt(0) == a.charAt(i)) {
                dp[i][0] = 1;
                continue;
            }
            if (dp[i - 1][0] == 1) {
                dp[i][0] = 1;
                continue;
            }
        }
        for (int i = 1; i < b_size; i++) {
            if (b.charAt(i) == a.charAt(0)) {
                dp[0][i] = 1;
                continue;
            }
            if (dp[0][i - 1] == 1) {
                dp[0][i] = 1;
                continue;
            }
        }
        for (int i = 1; i < a_size; i++) {
            for (int j = 1; j < b_size; j++) {
                dp[i][j] = dp[i - 1][j - 1];
                if (a.charAt(i) == b.charAt(j)) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                dp[i][j] = Math.max(dp[i][j], dp[i - 1][j]);
                dp[i][j] = Math.max(dp[i][j], dp[i][j - 1]);
            }
        }
        System.out.println(dp[a_size - 1][b_size - 1]);
    }
}