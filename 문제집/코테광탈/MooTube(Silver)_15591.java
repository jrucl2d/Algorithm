import java.io.*;
import java.util.*;

public class Main {
	static final int INF = 1000000010;
	static List<Info>[] adj;
	static boolean[] visited;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int n = Integer.valueOf(st.nextToken());
		int q = Integer.valueOf(st.nextToken());
		adj = new List[n + 1];
		for (int i = 0; i < n + 1; i++) {
			adj[i] = new ArrayList<>();
		}
		int a, b, c;
		for (int i = 0; i < n - 1; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			a = Integer.valueOf(st.nextToken());
			b = Integer.valueOf(st.nextToken());
			c = Integer.valueOf(st.nextToken());
			adj[a].add(new Info(b, c)); adj[b].add(new Info(a, c));
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < q; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int k = Integer.valueOf(st.nextToken());
			int v = Integer.valueOf(st.nextToken());

			visited = new boolean[n + 1];
			Queue<Info> qq = new LinkedList<>();
			qq.add(new Info(v, INF));
			int cnt = 0;
			while(!qq.isEmpty()) {
				Info now = qq.remove();
				visited[now.next] = true;
				if (now.k != INF && now.k >= k) cnt += 1;
				for (int j = 0; j < adj[now.next].size(); j++) {
					Info next = adj[now.next].get(j);
					if (visited[next.next]) continue;
					qq.add(new Info(next.next, Math.min(next.k, now.k)));
				}
			}
			sb.append(cnt + "\n");
		}
		System.out.println(sb);
	}
	static class Info {
		int next, k;
		Info (int next, int k) {this.next=next;this.k=k;}
	}
}
