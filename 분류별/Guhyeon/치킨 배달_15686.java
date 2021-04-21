import java.io.*;
import java.util.*;

public class Main {
    static final int HOUSE = 1;
    static final int CHICK = 2;
    static int n, m;
    static List<Point> chicks = new ArrayList<>();
    static int chickN;
    static List<Point> houses = new ArrayList<>();
    static boolean[] visited;
    static int[] visiting;
    static int ans = Integer.MAX_VALUE;

    public static void main(String[] args) throws IOException {
        input();
    }

    static void input() throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line = br.readLine();
        StringTokenizer st = new StringTokenizer(line, " ");
        n = Integer.valueOf(st.nextToken());
        m = Integer.valueOf(st.nextToken());
        int num;
        for (int i = 0; i < n; i++) {
            line = br.readLine();
            st = new StringTokenizer(line, " ");
            for (int j = 0; j < n; j++) {
                num = Integer.valueOf(st.nextToken());
                if (num == CHICK) {
                    chicks.add(new Point(i, j));
                    continue;
                }
                if (num == HOUSE)
                    houses.add(new Point(i, j));
            }
        }
        chickN = chicks.size();
        visited = new boolean[chickN];
        visiting = new int[m];
        dfs(0, 0);
        System.out.println(ans);
    }

    static void dfs(int index, int start) {
        if (index == m) {
            int res = 0;
            for (Point house : houses) {
                int inner_min = Integer.MAX_VALUE;
                for (int i : visiting) {
                    Point chicken = chicks.get(i);
                    inner_min = Math.min(inner_min, getChickDist(house, chicken));
                }
                res += inner_min;
            }
            ans = Math.min(ans, res);
            return;
        }
        for (int i = start; i < chickN; i++) {
            visited[i] = true;
            visiting[index] = i;
            dfs(index + 1, i + 1);
            visited[i] = false;
        }
    }

    static int getChickDist(Point a, Point b) {
        return Math.abs(a.x - b.x) + Math.abs(a.y - b.y);
    }

    static class Point {
        int x, y;

        Point(int a, int b) {
            x = a;
            y = b;
        }
    }
}