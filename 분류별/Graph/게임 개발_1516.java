import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
 		int n = Integer.valueOf(br.readLine());
		StringTokenizer st;
		int[] ans = new int[n + 1];
		int[] adjCount = new int[n + 1];
		int[] values = new int[n + 1];
		List<Integer>[] adj = new List[n + 1];
		for (int i = 0; i <= n; i++) adj[i] = new ArrayList<>();
 		for (int i = 1; i <= n; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			values[i] = Integer.valueOf(st.nextToken());
			while (st.hasMoreTokens()) {
				int now = Integer.valueOf(st.nextToken());
				if (now == -1) break;
				adj[now].add(i);
				adjCount[i] += 1;
			}
		}
 		Queue<Integer> q = new LinkedList<>();
 		for (int i = 1; i <= n; i++) {
 			if (adjCount[i] == 0) { q.add(i); ans[i] = values[i]; }
		}
 		while(!q.isEmpty()) {
 			int now = q.remove();
 			for (int i = 0; i < adj[now].size(); i++) {
 				int next = adj[now].get(i);
 				adjCount[next] -= 1;
 				ans[next] = Math.max(ans[next], ans[now] + values[next]);
 				if (adjCount[next] == 0) q.add(next);
			}
		}
		for (int i = 1; i <= n; i++) {
			System.out.println(ans[i]);
		}
	}
}

