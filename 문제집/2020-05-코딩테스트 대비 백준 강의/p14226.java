import java.io.*;
import java.util.*;

public class p14226 {
    static int n;
    static final int INF = 1010;
    static int[][] dp = new int[INF][INF]; // display, buffer

    public static void main(String[] args) throws IOException {
        input();
        sol();
    }
    static void sol() {
        Queue<Info> q = new LinkedList<>();
        q.add(new Info(1, 0, 0));
        dp[1][0] = 0;
        while (true) {
            Info now = q.remove();
            if (now.display == n) {
                System.out.println(now.cnt);
                break;
            }
            else if (now.display > 0 && now.display < INF) {
                if (dp[now.display][now.display] == -1) {
                    dp[now.display][now.display] = now.cnt + 1;
                    q.add(new Info(now.display, now.display, now.cnt + 1));
                }
                if (now.buffer > 0 && now.display + now.buffer < INF) {
                    if (dp[now.display + now.buffer][now.buffer] == -1) {
                        dp[now.display + now.buffer][now.buffer] = now.cnt + 1;
                        q.add(new Info(now.display + now.buffer, now.buffer, now.cnt + 1));
                    }
                }
                if (dp[now.display - 1][now.buffer] == -1) {
                    dp[now.display - 1][now.buffer] = now.cnt + 1;
                    q.add(new Info(now.display - 1, now.buffer, now.cnt + 1));
                }
            }
        }
    }
    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line, " ");
        n = Integer.valueOf(st.nextToken());
        for (int i = 0; i < INF; i++) {
            for (int j = 0 ; j < INF; j++) {
                dp[i][j] = -1;
            }
        }
    }
    static class Info {
        int display;
        int buffer;
        int cnt;
        Info() {}
        Info(int display, int buffer, int cnt) {
            this.display = display;
            this.buffer = buffer;
            this.cnt = cnt;
        }
    }
}
