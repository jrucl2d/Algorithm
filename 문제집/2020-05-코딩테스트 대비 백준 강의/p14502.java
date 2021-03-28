import java.io.*;
import java.util.*;

public class p14502 {
    static int n, m;
    static int[][] arr;
    static int[] dx = new int[] {-1, 0, 1, 0};
    static int[] dy = new int[] {0, -1, 0, 1};
    static int ans = Integer.MIN_VALUE;

    public static void main(String[] args) throws IOException {
        input();
        sol(0);
        System.out.println(ans);
    }
    static void virus_do(int[][] tmp, int x, int y) {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (tmp[nx][ny] == 0) {
                tmp[nx][ny] = 2;
                virus_do(tmp, nx, ny);
            }
        }
    }
    static void sol(int cnt) {
        if (cnt == 3) {
            int[][] tmp = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    tmp[i][j] = arr[i][j];
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (tmp[i][j] == 2) virus_do(tmp, i, j);
                }
            }
            int inner_ans = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (tmp[i][j] == 0) inner_ans += 1;
                }
            }
            ans = Math.max(ans, inner_ans);
            return;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (arr[i][j] == 0) {
                    arr[i][j] = 1;
                    sol(cnt + 1);
                    arr[i][j] = 0;
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
        arr = new int[n][m];
        for (int i = 0; i < n; i++) {
            line = br.readLine();
            st = new StringTokenizer(line, " ");
            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.valueOf(st.nextToken());
            }
        }
    }
}
