import java.io.*;
import java.util.*;

public class Main {
    static final int MAX = 1000000000;
    static int n, m, k, full;
    static long[][] dp = new long[210][210];
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.valueOf(st.nextToken());
        m = Integer.valueOf(st.nextToken());
        k = Integer.valueOf(st.nextToken());

        full = n + m;
        if (combination(full, n) < k) {
            System.out.println(-1);
            return;
        }
        solution(n, m);
        System.out.println(sb);
    }
    static void solution(int nn, int mm) {
        if (nn == 0 && mm == 0) return;
        if (nn == 0) {
            sb.append('z');
            solution(nn, mm - 1);
            return;
        }
        if (mm == 0) {
            sb.append('a');
            solution(nn - 1, mm);
            return;
        }
        long end = combination(mm + nn - 1, mm);
        if (k <= end) {
            sb.append('a');
            solution(nn - 1, mm);
            return;
        }
        sb.append('z');
        k -= end;
        solution(nn, mm - 1);
    }

    static long combination(int a, int b) {
        if (a == b || b == 0) {
            dp[a][b] = 1;
            return 1;
        }
        if (b == 1) {
            dp[a][b] = a;
            return a;
        }
        if (dp[a][b] != 0) return dp[a][b];
        dp[a][b] = Math.min(combination(a - 1, b - 1) + combination(a - 1, b), MAX);
        return dp[a][b];
    }
}
