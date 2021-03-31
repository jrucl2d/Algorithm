import java.io.*;
import java.util.*;

public class Main {
    static final int GARO = 0;
    static final int SERO = 1;
    static final int DAEGAK = 2;
    static int n;
    static int[][] arr;
    static int ans = 0;

    public static void main(String[] args) throws IOException {
        input();
        Pipe pipe = new Pipe();
        sol(pipe);
        System.out.println(ans);
    }
    static void sol(Pipe pipe) {
        if (pipe.b.x == n - 1 && pipe.b.y == n - 1) {
            ans += 1;
            return;
        }
        switch (pipe.dir) {
            case GARO:
                if (pipe.b.y + 1 < n && arr[pipe.b.x][pipe.b.y + 1] != 1) {
                    Pipe npipe = new Pipe(pipe.b, new Point(pipe.b.x, pipe.b.y + 1), GARO);
                    sol(npipe);
                }
                if (pipe.b.x + 1 < n && pipe.b.y + 1 < n
                && arr[pipe.b.x][pipe.b.y + 1] != 1
                && arr[pipe.b.x + 1][pipe.b.y] != 1
                && arr[pipe.b.x + 1][pipe.b.y + 1] != 1) {
                    Pipe npipe = new Pipe(pipe.b, new Point(pipe.b.x + 1, pipe.b.y + 1), DAEGAK);
                    sol(npipe);
                }
                break;
            case SERO:
                if (pipe.b.x + 1 < n && arr[pipe.b.x + 1][pipe.b.y] != 1) {
                    Pipe npipe = new Pipe(pipe.b, new Point(pipe.b.x + 1, pipe.b.y), SERO);
                    sol(npipe);
                }
                if (pipe.b.x + 1 < n && pipe.b.y + 1 < n
                        && arr[pipe.b.x][pipe.b.y + 1] != 1
                        && arr[pipe.b.x + 1][pipe.b.y] != 1
                        && arr[pipe.b.x + 1][pipe.b.y + 1] != 1) {
                    Pipe npipe = new Pipe(pipe.b, new Point(pipe.b.x + 1, pipe.b.y + 1), DAEGAK);
                    sol(npipe);
                }
                break;
            case DAEGAK:
                if (pipe.b.y + 1 < n && arr[pipe.b.x][pipe.b.y + 1] != 1) {
                    Pipe npipe = new Pipe(pipe.b, new Point(pipe.b.x, pipe.b.y + 1), GARO);
                    sol(npipe);
                }
                if (pipe.b.x + 1 < n && arr[pipe.b.x + 1][pipe.b.y] != 1) {
                    Pipe npipe = new Pipe(pipe.b, new Point(pipe.b.x + 1, pipe.b.y), SERO);
                    sol(npipe);
                }
                if (pipe.b.x + 1 < n && pipe.b.y + 1 < n
                        && arr[pipe.b.x][pipe.b.y + 1] != 1
                        && arr[pipe.b.x + 1][pipe.b.y] != 1
                        && arr[pipe.b.x + 1][pipe.b.y + 1] != 1) {
                    Pipe npipe = new Pipe(pipe.b, new Point(pipe.b.x + 1, pipe.b.y + 1), DAEGAK);
                    sol(npipe);
                }
                break;
        }
    }
    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line, " ");
        n = Integer.valueOf(st.nextToken());
        arr = new int[n][n];
        for (int i = 0; i < n; i++) {
            line = br.readLine();
            st = new StringTokenizer(line, " ");
            for (int j = 0; j < n; j++) {
                arr[i][j] = Integer.valueOf(st.nextToken());
            }
        }
    }
    static class Pipe {
        Point a;
        Point b;
        int dir;
        public Pipe() {
            a = new Point(0, 0);
            b = new Point(0, 1);
            dir = GARO;
        }
        public Pipe(Point a, Point b, int dir) {
            this.a = a;
            this.b = b;
            this.dir = dir;
        }
    }
    static class Point {
        int x, y;
        Point(int x, int y) {this.x = x; this.y = y;}
    }
}
