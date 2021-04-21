import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    static char[][] arr;
    static int[][] dp;
    static boolean[][] visited;
    static int[] dx = { -1, 0, 1, 0 }, dy = { 0, -1, 0, 1 };
    static int ans = -1;

    public static void main(String[] args) throws IOException {
        input();
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line, " ");
        n = Integer.valueOf(st.nextToken());
        m = Integer.valueOf(st.nextToken());
        arr = new char[n][m];
        for (int i = 0; i < n; i++) {
            line = br.readLine();
            for (int j = 0; j < m; j++) {
                arr[i][j] = line.charAt(j);
            }
        }
        dp = new int[n][m];
        visited = new boolean[n][m];
        visited[0][0] = true;
        dfs(0, 0, 1);
        System.out.println(ans);
    }

    static void dfs(int x, int y, int cnt) {
        ans = Math.max(ans, cnt);
        dp[x][y] = cnt;

        int hop = arr[x][y] - '0';
        for (int i = 0; i < 4; i++) {
            int nx = x + hop * dx[i], ny = y + hop * dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (arr[nx][ny] == 'H')
                continue;
            if (visited[nx][ny]) {
                System.out.println(-1);
                System.exit(0);
            }
            if (cnt + 1 <= dp[nx][ny])
                continue; // 걸러내기
            visited[nx][ny] = true;
            dfs(nx, ny, cnt + 1);
            visited[nx][ny] = false;
        }
    }
}