import java.io.*;
import java.util.*;

public class p16197 {
    static int n, m;
    static final int COIN = 0;
    static final int BLANK = 1;
    static final int WALL = 2;
    static int[][] arr;
    static Points p = new Points();
    static int[] dx = {-1, 0, 1, 0};
    static int[] dy = {0, -1, 0, 1};
    static boolean[][][][] visited;

    public static void main(String[] args) throws IOException {
        input();
        sol();
    }
    static void sol() {
        Queue<Points> q = new LinkedList<>();
        q.add(p);
        while (!q.isEmpty()) {
            Points now = q.remove();
            if (now.cnt > 10) break;
            Point a = now.a, b = now.b;
            visited[a.x][a.y][b.x][b.y] = true;
            for (int i = 0; i < 4; i++) {
                int anx = a.x + dx[i], any = a.y + dy[i];
                int bnx = b.x + dx[i], bny = b.y + dy[i];
                checkEnd(now.cnt, anx, any, bnx, bny);
                checkEnd(now.cnt, bnx, bny, anx, any);
                if (notGo(anx, any, bnx, bny)) continue;
                if (visited[anx][any][bnx][bny]) continue;
                Points np = new Points();
                if (arr[anx][any] == WALL) {
                    if (arr[bnx][bny] != WALL) {
                        np.a = now.a;
                        np.b = new Point(bnx, bny);
                        np.cnt = now.cnt + 1;
                        q.add(np);
                    }
                } else {
                    if (arr[bnx][bny] == WALL) {
                        np.a = new Point(anx, any);
                        np.b = now.b;
                        np.cnt = now.cnt + 1;
                        q.add(np);
                    } else {
                        np.a = new Point(anx, any);
                        np.b = new Point(bnx, bny);
                        np.cnt = now.cnt + 1;
                        q.add(np);
                    }
                }
            }
        }
        System.out.println(-1);
    }

    private static void checkEnd(int ans, int a, int b, int c, int d) {
        if ((a < 0 || b < 0 || a >= n || b >= m)
                && c >= 0 && d >= 0 && c < n && d < m) {
            System.out.println(ans);
            System.exit(0);
        }
    }
    private static boolean notGo(int a, int b, int c, int d) {
        if (a < 0 || b < 0 || a >= n || b >= m
                || c < 0 && d < 0 && c >= n && d >= m) {
            return true;
        }
        return false;
    }
    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line, " ");
        n = Integer.valueOf(st.nextToken());
        m = Integer.valueOf(st.nextToken());
        arr = new int[n][m];
        visited = new boolean[n][m][n][m];
        boolean next = false;
        for (int i = 0; i < n; i++) {
            line = br.readLine();
            for (int j = 0; j < m; j++) {
                if (line.charAt(j) == '.') {
                    arr[i][j] = BLANK;
                    continue;
                }
                if (line.charAt(j) == '#') {
                    arr[i][j] = WALL;
                    continue;
                }
                if (!next) {
                    p.a = new Point(i, j);
                    next = true;
                } else {
                    p.b = new Point(i, j);
                }
                arr[i][j] = COIN;
            }
        }
    }
    static class Points {
        Point a, b;
        int cnt;
        Points() {cnt = 1;}
    }
    static class Point {
        int x, y;
        Point(int x, int y) {this.x = x; this.y = y;}
    }
}
