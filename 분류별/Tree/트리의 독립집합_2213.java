import java.io.*;
import java.util.*;

public class Main {
	static int n;
	static int[] values;
	static int[][] dp;
	static List<Integer>[] infos;
	static List<Integer>[] adj;
	static boolean[] visited;
	static List<Integer> ans;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.valueOf(br.readLine());
		values = new int[n + 1];
		dp = new int[n + 1][2];
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		for (int i = 1; i <= n; i++) {
			values[i] = Integer.valueOf(st.nextToken());
			dp[i][0] = dp[i][1] = -1;
		}
		infos = new List[n + 1];
		adj = new List[n + 1];
		for (int i = 0; i <= n; i++) {
			infos[i] = new ArrayList<>();
			adj[i] = new ArrayList<>();
		}
		for (int i = 0; i < n - 1; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int a = Integer.valueOf(st.nextToken());
			int b = Integer.valueOf(st.nextToken());
			infos[a].add(b);
			infos[b].add(a);
		}
		toOne(1, -1);
		visited = new boolean[n + 1];
		int root1 = sol(1, 1);
		int root2 = sol(1, 0);
		if (root1 > root2) visited[1] = true;
		System.out.println(Math.max(root1, root2));
		ans = new ArrayList<>();
		getAns(1, visited[1]);
		ans.sort((a, b) -> a - b);
		for (int i = 0; i < ans.size(); i++) {
			System.out.print(ans.get(i) + " ");
		}
	}
	static void getAns(int now, boolean include) {
		if (include) {
			ans.add(now);
			for (int i = 0; i < adj[now].size(); i++) {
				int next = adj[now].get(i);
				getAns(next, false);
			}
			return;
		}
		for (int i = 0; i < adj[now].size(); i++) {
			int next = adj[now].get(i);
			getAns(next, visited[next]);
		}
	}
	static void toOne(int now, int parent) {
		for (int i = 0; i < infos[now].size(); i++) {
			int next = infos[now].get(i);
			if (next == parent) continue;
			adj[now].add(next);
			toOne(next, now);
		}
	}
	static int sol(int now, int include) {
		if (dp[now][include] != -1) return dp[now][include];
		if (include == 1) {
			int down = 0;
			for (int i = 0; i < adj[now].size(); i++) {
				int next = adj[now].get(i);
				down += sol(next, 0);
			}
			dp[now][include] = down + values[now];
			return dp[now][include];
		}
		int downDown = 0;
		for (int i = 0; i < adj[now].size(); i++) {
			int next = adj[now].get(i);
			int sub1 = sol(next, 1);
			int sub2 = sol(next, 0);
			if (sub1 > sub2) {
				visited[next] = true;
			}
			downDown += Math.max(sub1, sub2);
		}
		dp[now][include] = downDown;
		return downDown;
	}
}
