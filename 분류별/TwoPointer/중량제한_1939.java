import java.io.*;
import java.util.*;

public class Main {
    static int MAX = -1;
    static int n, m, from, to;
    static List<Info>[] adj;
    static boolean[] visited;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.valueOf(st.nextToken());
        m = Integer.valueOf(st.nextToken());
        adj = new List[n + 1];
        for (int i = 0; i <= n; i++)
            adj[i] = new ArrayList<>();
        int a, b, c;
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            a = Integer.valueOf(st.nextToken());
            b = Integer.valueOf(st.nextToken());
            c = Integer.valueOf(st.nextToken());
            adj[a].add(new Info(b, c));
            adj[b].add(new Info(a, c));
            MAX = Math.max(MAX, c);
        }
        st = new StringTokenizer(br.readLine(), " ");
        from = Integer.valueOf(st.nextToken());
        to = Integer.valueOf(st.nextToken());

        int l = 0, r = MAX;
        int ans = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (bfs(mid)) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        System.out.println(ans);
    }

    static boolean bfs(int limit) {
        visited = new boolean[n + 1];
        Queue<Integer> q = new LinkedList<>();
        q.add(from);
        visited[from] = true;
        while (!q.isEmpty()) {
            int now = q.remove();
            if (now == to) {
                return true;
            }
            for (int i = 0; i < adj[now].size(); i++) {
                Info next = adj[now].get(i);
                if (next.limit >= limit && !visited[next.to]) {
                    q.add(next.to);
                    visited[next.to] = true;
                }
            }
        }
        return false;
    }

    static class Info {
        int to;
        int limit;

        Info(int to, int limit) {
            this.to = to;
            this.limit = limit;
        }
    }
}
