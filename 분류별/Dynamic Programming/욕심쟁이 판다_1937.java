import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static int[][] arr, dp;
    static int[] dx = { -1, 0, 1, 0 }, dy = { 0, -1, 0, 1 };

    public static void main(String[] args) throws IOException {
        input();
        int ans = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans = Math.max(ans, sol(i, j));
            }
        }
        System.out.println(ans);
    }

    static int sol(int x, int y) {
        if (dp[x][y] != 0)
            return dp[x][y];
        int ret = 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                continue;
            if (arr[x][y] >= arr[nx][ny])
                continue;
            ret = Math.max(ret, 1 + sol(nx, ny));
            dp[x][y] = ret;
        }
        return ret;
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.valueOf(br.readLine());
        arr = new int[n][n];
        dp = new int[n][n];
        String line;
        StringTokenizer st;
        for (int i = 0; i < n; i++) {
            line = br.readLine();
            st = new StringTokenizer(line, " ");
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
            }
        }
    }
}