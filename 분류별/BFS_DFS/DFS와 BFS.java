import java.io.*;
import java.util.*;

public class Main {
    static List<Integer>[] adj;
    static boolean[] visited;
    static int n, m, v;
    static StringBuilder sb = new StringBuilder();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        v = Integer.parseInt(st.nextToken());
        adj = new List[n + 1];
        visited = new boolean[n + 1];
        for (int i = 0; i <= n; i++)
            adj[i] = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine(), " ");
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            adj[a].add(b);
            adj[b].add(a);
        }
        for (int i = 1; i <= n; i++) {
            adj[i].sort((aa, bb) -> aa - bb);
        }
        dfs(v);
        sb.append("\n");
        Queue<Integer> q = new LinkedList<>();
        q.add(v);
        Arrays.fill(visited, false);
        visited[v] = true;
        while (!q.isEmpty()) {
            int now = q.remove();
            sb.append(now).append(" ");
            for (int i = 0; i < adj[now].size(); i++) {
                int next = adj[now].get(i);
                if (visited[next])
                    continue;
                visited[next] = true;
                q.add(next);
            }
        }
        System.out.println(sb);
    }

    static void dfs(int now) {
        visited[now] = true;
        sb.append(now).append(" ");
        for (int i = 0; i < adj[now].size(); i++) {
            int next = adj[now].get(i);
            if (visited[next])
                continue;
            dfs(next);
        }
    }
}