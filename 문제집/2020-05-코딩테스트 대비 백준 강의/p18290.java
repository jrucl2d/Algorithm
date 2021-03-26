import java.io.*;
import java.util.*;

public class p18290 {
    static int n, m, k;
    static int[][] arr;
    static int[][] visited;
    static int[] visiting;
    static BufferedWriter bw;
    static int ans = Integer.MIN_VALUE;
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, -1, 0, 1};

    public static void main(String[] args) throws IOException {
        input();
        sol(0);
        System.out.println(ans);
    }
    static void sol(int now) {
        // end
        if (now == k) {
            int inner_ans = 0;
            for (int i = 0; i < k; i++) {
                inner_ans += visiting[i];
            }
            ans = Math.max(inner_ans, ans);
            return;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visited[i][j] > 0) continue;
                // check in
                visited[i][j] += 1;
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    visited[nx][ny] += 1;
                }

                visiting[now] = arr[i][j];
                sol(now + 1);

                // check out
                visited[i][j] -= 1;
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                    visited[nx][ny] -= 1;
                }
            }
        }
    }
    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line, " ");
        n = Integer.valueOf(st.nextToken());
        m = Integer.valueOf(st.nextToken());
        k = Integer.valueOf(st.nextToken());
        arr = new int[n][m];
        visited = new int[n][m];
        visiting = new int[k];
        for (int i = 0; i < n; i++) {
             line = br.readLine();
             st = new StringTokenizer(line, " ");
             for (int j = 0; j < m; j++) {
                 arr[i][j] = Integer.valueOf(st.nextToken());
             }
        }
    }
}
