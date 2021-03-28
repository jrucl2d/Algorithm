import java.io.*;
import java.util.*;

public class p16928 {
    static int n, m;
    static int[] move;
    static int[] dp;

    public static void main(String[] args) throws IOException {
        input();
        sol();
    }
    static void sol() {
        int start = 1;
        Queue<Integer> q = new LinkedList<>();
        q.add(start);
        dp[1] = 0;
        while (true) {
            int now = q.remove();
            if (now == 100) {
                System.out.println(dp[now]);
                break;
            }
            for (int i = 1; i <= 6; i++) {
                if (now + i > 100) break;
                if (move[now + i] != 0) {
                    if (dp[move[now + i]] == -1) {
                        dp[move[now + i]] = dp[now] + 1;
                        q.add(move[now + i]);
                    }
                    continue;
                }
                if (dp[now + i] == -1) {
                    dp[now + i] = dp[now] + 1;
                    q.add(now + i);
                }
            }
        }
    }
    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line, " ");
        n = Integer.valueOf(st.nextToken());
        m = Integer.valueOf(st.nextToken());
        dp = new int[110];
        move = new int[110];
        for (int i = 0; i < 110; i++) dp[i] = -1;
        doIter(br, n);
        doIter(br, m);
    }
    private static void doIter(BufferedReader br, int m) throws IOException {
        String line;
        StringTokenizer st;
        int t1, t2;
        for (int i = 0; i < m; i++) {
            line = br.readLine();
            st = new StringTokenizer(line, " ");
            t1 = Integer.valueOf(st.nextToken());
            t2 = Integer.valueOf(st.nextToken());
            move[t1] = t2;
        }
    }
}
