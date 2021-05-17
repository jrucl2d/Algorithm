import java.io.*;
import java.util.*;

public class Main {
	final static int INF = 987654321;
	static int[] distance;
	static List<Info>[] adj;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.valueOf(br.readLine());
		int m = Integer.valueOf(br.readLine());
		distance = new int[n + 1];
		Arrays.fill(distance, INF);
		adj = new List[n + 1];
		for (int i = 0; i <= n; i++) {
			adj[i] = new ArrayList<>();
		}
		int a, b, c;
		StringTokenizer st;
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			a = Integer.valueOf(st.nextToken());
			b = Integer.valueOf(st.nextToken());
			c = Integer.valueOf(st.nextToken());
			adj[a].add(new Info(b, c));
		}
		int s, e;
		st = new StringTokenizer(br.readLine(), " ");
		s = Integer.valueOf(st.nextToken());
		e = Integer.valueOf(st.nextToken());
		distance[s] = 0;
		PriorityQueue<Info> q = new PriorityQueue<>((aa, bb) -> aa.cost - bb.cost);
		q.add(new Info(s, 0));
		while (!q.isEmpty()) {
			Info now = q.remove();
			if (distance[now.loc] < now.cost) continue;
			for (int i = 0; i < adj[now.loc].size(); i++) {
				Info next = adj[now.loc].get(i);
				if (distance[next.loc] > distance[now.loc] + next.cost) {
					distance[next.loc] = distance[now.loc] + next.cost;
					q.add(new Info(next.loc, distance[next.loc]));
				}
			}
		}
		System.out.println(distance[e]);
	}
	static class Info {
		int loc, cost;
		Info (int loc, int cost) {this.loc=loc; this.cost=cost;}

		@Override
		public String toString() {
			return "Info{" +
					"loc=" + loc +
					", cost=" + cost +
					'}';
		}
	}
}
