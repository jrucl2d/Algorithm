import java.io.*;
import java.util.*;

public class Main {
    static final int MOD = 1000000;
    static String num;
    static int[] dp = new int[5001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        num = br.readLine();
        int[] arr = new int[num.length() + 1];
        for (int i = 1; i <= num.length(); i++) {
            arr[i] = (int) num.charAt(i - 1) - (int) '0';
        }
        dp[0] = 1;
        for (int i = 1; i <= num.length(); i++) {
            if (arr[i] == 0)
                continue;
            dp[i] = (dp[i] + dp[i - 1]) % MOD;
            int two = arr[i - 1] * 10 + arr[i];
            if (two < 10 || two > 26 || i - 2 < 0)
                continue;
            dp[i] = (dp[i] + dp[i - 2]) % MOD;
        }
        System.out.println(dp[num.length()]);
    }
}
