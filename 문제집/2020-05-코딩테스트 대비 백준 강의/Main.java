import java.io.*;
import java.util.*;

public class Main {
    static int n, m, d;
    static int[][] arr;
    static int[] archer_locs;
    static int ans = Integer.MIN_VALUE;

    public static void main(String[] args) throws IOException {
        input();
        sol(0, 0);
        calc();
        System.out.println(ans);
    }
    static void calc() {
        int inner_ans = 0;
        int[][] tmp = new int[n + 1][m];
        for (int i = 0; i < n + 1; i++) {
            for (int j = 0; j < m; j++) {
                tmp[i][j] = arr[i][j];
            }
        }
        for (int outer = n; outer > 0; outer--) {
            Set<Point> set = new HashSet<>();
            for (int a = 0; a < 3; a++) {
                int x = outer, y = archer_locs[a];
                boolean found = false;
                for (int i = 1; i <= d; i++) {
                    int up_index = 1;
                    for (int j = -((2 * i - 1) / 2); j <= (2 * i - 1) / 2; j++) {
                        int nx = outer - up_index;
                        int ny = y + j;
                        if (j >= 0) {
                            up_index -= 1;
                        } else {
                            up_index += 1;
                        }
                        if (nx < 0 || ny < 0 || ny >= m) continue;
                        if (tmp[nx][ny] == 1 && dist_can(x, y, nx ,ny)){
                            set.add(new Point(nx, ny));
                            found = true;
                            break;
                        }
                    }
                    if (found) break;
                }
            }
            for (Point point : set) {
                if (tmp[point.x][point.y] == 1) {
                    inner_ans += 1;
                    tmp[point.x][point.y] = 0;
                }
            }
        }
//        System.out.println(inner_ans);
        ans = Math.max(ans, inner_ans);
    }
    static boolean dist_can(int x, int y, int x1, int y1) {
        if (Math.abs(x - x1) + Math.abs(y - y1) <= d) return true;
        else return false;
    }
    static void sol(int cnt, int now) {
        if (cnt == 3) {
            calc();
            return;
        }
        for (int i = now; i < m; i++) {
            archer_locs[cnt] = i;
            sol(cnt + 1, i + 1);
        }
    }
    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line, " ");
        n = Integer.valueOf(st.nextToken());
        m = Integer.valueOf(st.nextToken());
        d = Integer.valueOf(st.nextToken());
        arr = new int[n + 1][m];
        for (int i = 0; i < n; i++) {
            line = br.readLine();
            st = new StringTokenizer(line, " ");
            for (int j = 0; j < m; j++) {
                arr[i][j] = Integer.valueOf(st.nextToken());
            }
        }
        for (int j = 0; j < m; j++) {
            arr[n][j] = 0;
        }
        archer_locs = new int[3];
    }
    static class Point {
        int x, y;
        Point(int x, int y) {this.x = x; this.y = y;}
    }
}
