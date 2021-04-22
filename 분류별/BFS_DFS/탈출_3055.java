import java.io.*;
import java.util.*;

public class Main {
    static final char SQ = 'S';
    static final char WATER = '*';
    static final char ROCK = 'X';
    static final char VISITED = 'P';
    static int r, c;
    static char[][] arr;
    static int[] dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
    static Queue<Point> sq = new LinkedList<>();
    static Queue<Point> wq = new LinkedList<>();
    static Point end;

    public static void main(String[] args) throws IOException {
        input();
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line, " ");
        r = Integer.valueOf(st.nextToken());
        c = Integer.valueOf(st.nextToken());
        arr = new char[r][c];
        for (int i = 0; i < r; i++) {
            line = br.readLine();
            for (int j = 0; j < c; j++) {
                arr[i][j] = line.charAt(j);
                if (arr[i][j] == WATER) { wq.add(new Point(i, j)); continue; }
                if (arr[i][j] == SQ) {sq.add(new Point(i, j)); continue; }
                if (arr[i][j] == 'D') end = new Point(i, j);
            }
        }
        // bfs
        int time = 0;
        while (!sq.isEmpty()) {
            time += 1;
            int wq_size = wq.size();
            while (--wq_size >= 0) {
                Point wq_now = wq.remove();
                for (int i = 0; i < 4; i++) {
                    int nx = wq_now.x + dx[i], ny = wq_now.y + dy[i];
                    if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
                    if (arr[nx][ny] == WATER || arr[nx][ny] == ROCK || (nx == end.x && ny == end.y)) continue;
                    wq.add(new Point(nx, ny));
                    arr[nx][ny] = WATER;
                }
            }
            int sq_size = sq.size();
            while (--sq_size >= 0) {
                Point sq_now = sq.remove();
                arr[sq_now.x][sq_now.y] = VISITED;
                for (int i = 0; i < 4; i++) {
                    int nx = sq_now.x + dx[i], ny = sq_now.y + dy[i];
                    if (nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
                    if (arr[nx][ny] == WATER || arr[nx][ny] == SQ || arr[nx][ny] == ROCK || arr[nx][ny] == VISITED) continue;
                    if (nx == end.x && ny == end.y) {
                        System.out.println(time);
                        System.exit(0);
                    }
                    sq.add(new Point(nx, ny));
                    arr[nx][ny] = SQ;
                }
            }
           if (sq.size() == 0) break;
        }
        System.out.println("KAKTUS");
    }
    static class Point {
        int x, y;
        Point(int x, int y) {this.x=x;this.y=y;}
    }
}