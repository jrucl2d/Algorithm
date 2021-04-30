import java.io.*;
import java.util.*;

public class Main {
    static int t, n, m;
    static int[][] dp = new int[30][30];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        t = Integer.valueOf(br.readLine());
        StringBuilder sb = new StringBuilder();
        while(t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine(), " ");
            n = Integer.valueOf(st.nextToken());
            m = Integer.valueOf(st.nextToken());
            sb.append(combination(m, n) + "\n");
        }
        System.out.println(sb);
    }
    static int combination(int a, int b) {
        if (a == b || b == 0) {
            dp[a][b] = 1;
            return 1;
        }
        if (b == 1) {
            dp[a][b] = a;
            return a;
        }
        if (dp[a][b] != 0) return dp[a][b];
        dp[a][b] = combination(a - 1, b - 1) + combination(a - 1, b);
        return dp[a][b];
    }
}
