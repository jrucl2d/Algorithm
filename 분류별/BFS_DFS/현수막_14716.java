import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    static int[][] arr;
    static int[] dx = { -1, 0, 1, 0, -1, -1, 1, 1 }, dy = { 0, -1, 0, 1, -1, 1, -1, 1 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.valueOf(st.nextToken());
        m = Integer.valueOf(st.nextToken());
        arr = new int[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.valueOf(st.nextToken());
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 1) {
                    dfs(i, j);
                    ans += 1;
                }
            }
        }
        System.out.println(ans);
    }

    static void dfs(int i, int j) {
        arr[i][j] = 0;
        for (int d = 0; d < 8; d++) {
            int nx = i + dx[d], ny = j + dy[d];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;
            if (arr[nx][ny] == 0)
                continue;
            dfs(nx, ny);
        }
    }
}