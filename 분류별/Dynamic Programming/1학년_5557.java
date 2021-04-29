import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static int[] arr;
    static long[][] dp = new long[110][21]; // i까지 계산했을 때 j 값을 가지는 경우의 수

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.valueOf(st.nextToken());
        arr = new int[n];
        st = new StringTokenizer(br.readLine(), " ");
        for (int i = 0; i < n; i++) {
            arr[i] = Integer.valueOf(st.nextToken());
        }
        dp[0][arr[0]] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= 20; j++) {
                int n1 = j - arr[i];
                if (n1 >= 0) {
                    dp[i][n1] += dp[i - 1][j];
                }
                int n2 = j + arr[i];
                if (n2 <= 20) {
                    dp[i][n2] += dp[i - 1][j];
                }
            }
        }
        System.out.println(dp[n - 2][arr[n - 1]]);
    }
}
