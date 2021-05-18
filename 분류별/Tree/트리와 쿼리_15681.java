import java.io.*;
import java.util.*;

public class Main {
	static List<Integer>[] infos;
	static Node[] tree;
	static int[] dp;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int n = Integer.valueOf(st.nextToken());
		int r = Integer.valueOf(st.nextToken());
		int q = Integer.valueOf(st.nextToken());
		infos = new List[n + 1];
		tree = new Node[n + 1];
		dp = new int[n + 1];
		for (int i = 0; i <= n; i++) {
			infos[i] = new ArrayList<>();
			tree[i] = new Node();
		}
		for (int i = 0; i < n - 1; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			int a = Integer.valueOf(st.nextToken());
			int b = Integer.valueOf(st.nextToken());
			infos[a].add(b);
			infos[b].add(a);
		}
		makeTree(r, -1);
		for (int i = 0; i < q; i++) {
			int qq = Integer.valueOf(br.readLine());
			System.out.println(getSubTree(qq));
		}
	}
	static int getSubTree(int current) {
		if (dp[current] != 0) return dp[current];
		dp[current] = 1;
		for (int i = 0; i < tree[current].child.size(); i++) {
			int next = tree[current].child.get(i);
			dp[current] += getSubTree(next);
		}
		return dp[current];
	}
	static void makeTree(int current, int parent) {
		for (int i = 0; i < infos[current].size(); i++) {
			int next = infos[current].get(i);
			if (next != parent) {
				tree[current].child.add(next);
				tree[next].parent = current;
				makeTree(next, current);
			}
		}
	}
	static class Node {
		List<Integer> child;
		int parent;
		Node() {
			this.child = new ArrayList<>();
		}
	}
}
