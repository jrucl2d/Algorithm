import java.io.*;
import java.util.*;

public class Main {
    static int[] parent = new int[2001];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        int n = Integer.valueOf(st.nextToken());
        int c = Integer.valueOf(st.nextToken());
        Point[] tmp = new Point[n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int x = Integer.valueOf(st.nextToken());
            int y = Integer.valueOf(st.nextToken());
            tmp[i] = new Point(x, y);
        }
        for (int i = 1; i <= n; i++) parent[i] = i;
        PriorityQueue<Info> pq = new PriorityQueue<>((a, b) -> a.dis - b.dis);
        for (int i = 0 ; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int dis = (int)Math.pow((tmp[i].x - tmp[j].x), 2) + (int)Math.pow((tmp[i].y - tmp[j].y), 2);
                if (dis < c) continue;
                pq.add(new Info(i, j, dis));
            }
        }
        int ans = 0;
        int count = 0;
        while (!pq.isEmpty()) {
            Info now = pq.remove();
            if (find_p(now.p.x) == find_p(now.p.y)) continue;
            union_p(now.p.x, now.p.y);
            count += 1;
            ans += now.dis;
        }
        if (count != n - 1) {
            System.out.println(-1);
            return;
        }
        System.out.println(ans);
    }
    static class Point {
        int x, y;
        Point(int x, int y) {this.x=x;this.y=y;}
    }
    static class Info {
        Point p;
        int dis;
        Info(int x, int y, int dis) {p = new Point(x, y); this.dis=dis;}
    }
    static void union_p(int a, int b) {
        a = find_p(a);
        b = find_p(b);
        parent[a] = b;
    }
    static int find_p(int a) {
        if (a != parent[a]) {
            parent[a] = find_p(parent[a]);
        }
        return parent[a];
    }
}