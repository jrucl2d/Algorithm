import java.io.*;
import java.util.*;

public class p14889 {
    static int n;
    static int[][] arr;
    static boolean[] visited;
    static int ans = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        input();
        sol(0, 0);
        System.out.println(ans);
    }
    static void sol(int st, int cnt) {
        if (cnt == n / 2) {
            int visited_cnt = 0;
            int not_visited_cnt = 0;
            int[] start = new int[n / 2]; int start_index = 0;
            int[] link = new int[n / 2]; int link_index = 0;
            for (int i = 0; i < n; i++) {
                if (visited[i]) {
                    start[start_index++] = i;
                } else {
                    link[link_index++] = i;
                }
            }
            for (int i = 0; i < n / 2; i++) {
                for (int j = i + 1; j < n / 2; j++) {
                    visited_cnt += arr[start[i]][start[j]] + arr[start[j]][start[i]];
                    not_visited_cnt += arr[link[i]][link[j]] + arr[link[j]][link[i]];
                }
            }
            ans = Math.min(ans, Math.abs(visited_cnt - not_visited_cnt));
            return;
        }
        for (int i = st; i < n; i++) {
            if (visited[i] == false) {
                visited[i] = true;
                sol(i, cnt + 1);
                visited[i] = false;
            }
        }
    }
    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        n = Integer.valueOf(line);
        arr = new int[n][n];
        visited = new boolean[n];

        for (int i = 0; i < n; i++) {
            line = br.readLine();
            StringTokenizer st = new StringTokenizer(line, " ");
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.valueOf(st.nextToken());
            }
        }
    }
}
