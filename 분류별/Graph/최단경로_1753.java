import java.io.*;
import java.util.*;

public class Main {
	static final int INF = Integer.MAX_VALUE;
	static int[] distance;
	static List<Info>[] adj;
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
 		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
 		int v = Integer.valueOf(st.nextToken());
 		int e = Integer.valueOf(st.nextToken());
 		int k = Integer.valueOf(br.readLine());
		distance = new int[v + 1];
		Arrays.fill(distance, INF);
		adj = new List[v + 1];
		for (int i = 0; i <= v; i++) adj[i] = new ArrayList<>();

		int a, b, c;
		for (int i = 0; i < e; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			a = Integer.valueOf(st.nextToken());
			b = Integer.valueOf(st.nextToken());
			c = Integer.valueOf(st.nextToken());
			adj[a].add(new Info(c, b));
		}
		PriorityQueue<Info> pq = new PriorityQueue<>((aa, bb) -> aa.cost - bb.cost);
		pq.add(new Info(0, k));
		distance[k] = 0;
		while (!pq.isEmpty()) {
			Info now = pq.remove();
			if (now.cost > distance[now.to]) continue;
			for (int i = 0; i < adj[now.to].size(); i++) {
				Info next = adj[now.to].get(i);
				if (distance[now.to] + next.cost < distance[next.to]) {
					distance[next.to] = distance[now.to] + next.cost;
					pq.add(new Info(distance[next.to], next.to));
				}
			}
		}
		for (int i = 1; i <= v; i++) {
			if (distance[i] == INF) System.out.println("INF");
			else System.out.println(distance[i]);
		}
	}
	static class Info {
		int cost, to;
		Info(int cost, int to) {this.cost = cost; this.to = to;}
	}
}

