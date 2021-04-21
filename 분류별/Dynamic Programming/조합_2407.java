import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    static String[][] dp = new String[501][501];

    public static void main(String[] args) throws IOException {
        input();
        for (int i = 1; i <= 500; i++) {
            dp[i][1] = "" + i;
            dp[i][i] = "" + 1;
        }
        System.out.println(sol(n, m));
    }

    static String sol(int a, int b) {
        if (dp[a][b] != null)
            return dp[a][b];
        dp[a][b] = sum(sol(a - 1, b - 1), sol(a - 1, b));
        return dp[a][b];
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line, " ");
        n = Integer.valueOf(st.nextToken());
        m = Integer.valueOf(st.nextToken());
    }

    static String sum(String a, String b) {
        if (a.length() < b.length()) {
            String tmp = a;
            a = b;
            b = tmp;
        }
        int[] aa = new int[a.length()];
        int[] bb = new int[b.length()];
        for (int i = a.length() - 1; i >= 0; i--) {
            aa[a.length() - i - 1] = a.charAt(i) - '0';
        }
        for (int i = b.length() - 1; i >= 0; i--) {
            bb[b.length() - i - 1] = b.charAt(i) - '0';
        }
        List<Integer> res = new ArrayList<>();
        boolean buf = false;
        for (int i = 0; i < b.length(); i++) {
            int tmp = aa[i] + bb[i];
            if (buf)
                tmp += 1;
            buf = false;
            if (tmp < 10) {
                res.add(tmp);
                continue;
            }
            buf = true;
            res.add(tmp - 10);
        }
        for (int i = b.length(); i < a.length(); i++) {
            int tmp = aa[i];
            if (buf)
                tmp += 1;
            buf = false;
            if (tmp < 10) {
                res.add(tmp);
                continue;
            }
            buf = true;
            res.add(tmp - 10);
        }
        if (buf)
            res.add(1);
        StringBuilder sb = new StringBuilder();
        for (int i = res.size() - 1; i >= 0; i--)
            sb.append(res.get(i));
        return sb.toString();
    }
}