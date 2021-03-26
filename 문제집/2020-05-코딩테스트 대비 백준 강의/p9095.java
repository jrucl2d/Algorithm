import java.io.*;
import java.util.*;

public class p9095 {
    static BufferedWriter bw;
    static int t;
    static int[] dp;

    public static void main(String[] args) throws IOException {
        input();
    }
    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String line = br.readLine();
        t = Integer.valueOf(line);
        dp = new int[11];
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 4;
        for (int i = 4; i < 11; i++) {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        while(t-- > 0) {
            int n = Integer.valueOf(br.readLine());
            System.out.println(dp[n]);
        }
    }
}
