import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    static int[][] arr, dp;
    static int[] dx = { -1, 0, 1, 0 }, dy = { 0, -1, 0, 1 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line, " ");
        n = Integer.valueOf(st.nextToken());
        m = Integer.valueOf(st.nextToken());

        arr = new int[n][m];
        dp = new int[n][m];
        for (int i = 0; i < n; i++) {
            line = br.readLine();
            st = new StringTokenizer(line, " ");
            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.valueOf(st.nextToken());
            }
            Arrays.fill(dp[i], -1);
        }
        System.out.println(dfs(0, 0));
    }

    static int dfs(int x, int y) {
        if (x == n - 1 && y == m - 1)
            return 1;
        if (dp[x][y] != -1)
            return dp[x][y];
        dp[x][y] = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (arr[x][y] <= arr[nx][ny])
                continue;
            dp[x][y] += dfs(nx, ny);
        }
        return dp[x][y];
    }
}
