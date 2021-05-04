import java.io.*;
import java.util.*;

public class Main {
	static final int INF = Integer.MAX_VALUE;
	static List<Info>[] infos;
	static long[] distance;
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
 		int n = Integer.valueOf(st.nextToken());
 		int m = Integer.valueOf(st.nextToken());

 		infos = new List[n + 1];
 		distance = new long[n + 1];
 		for (int i = 0; i <= n; i++) infos[i] = new ArrayList<>();
		Arrays.fill(distance, INF);
 		for (int i = 0; i < m; i++) {
 			st = new StringTokenizer(br.readLine(), " ");
 			int a = Integer.valueOf(st.nextToken());
			int b = Integer.valueOf(st.nextToken());
			int c = Integer.valueOf(st.nextToken());
			infos[a].add(new Info(c, b));
		}

 		distance[1] = 0;
 		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				if (distance[i] == INF) continue;
				for (int j = 0; j < infos[i].size(); j++) {
					Info next = infos[i].get(j);
					if (distance[i] + next.cost < distance[next.to]) {
						if (k == n) { // infinite check
							System.out.println(-1);
							return;
						}
						distance[next.to] = distance[i] + next.cost;
					}
				}
			}
		}
 		for (int i = 2; i <= n; i++) {
			System.out.println(distance[i] == INF ? -1 : distance[i]);
		}
	}
	static class Info {
		int cost, to;
		Info(int cost, int to) {this.cost=cost;this.to=to;}
	}
}

