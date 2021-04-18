import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static int[] arr, dp;

    public static void main(String[] args) throws IOException {
        input();
        dp = new int[n];
        int ans = -1;
        for (int i = 0; i < n; i++) {
            dp[i] = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (arr[j] < arr[i]) {
                    dp[i] = Math.max(dp[i], dp[j] + 1);
                }
            }
            ans = Math.max(ans, dp[i]);
        }
        System.out.println(ans);
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        StringTokenizer st;
        line = br.readLine();
        n = Integer.valueOf(line);
        arr = new int[n];
        line = br.readLine();
        st = new StringTokenizer(line, " ");
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.valueOf(st.nextToken());
        }
    }
}