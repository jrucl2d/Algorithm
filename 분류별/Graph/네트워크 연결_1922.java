import java.io.*;
import java.util.*;

public class Main {
	static final int MAX = Integer.MAX_VALUE;
	static List<Info> adj = new ArrayList<>();
	static int[] parent = new int[1010];

	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
 		int n = Integer.valueOf(br.readLine());
		int m = Integer.valueOf(br.readLine());
		StringTokenizer st;
		int a, b, c;
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}
		for (int i = 0; i < m; i++) {
		    st = new StringTokenizer(br.readLine(), " ");
			a = Integer.valueOf(st.nextToken());
			b = Integer.valueOf(st.nextToken());
			c = Integer.valueOf(st.nextToken());
			adj.add(new Info(a, b, c));
		}
		adj.sort((aa, bb) -> aa.val - bb.val);
		int ans = 0;
		for (int i = 0; i < adj.size(); i++) {
		    Info now = adj.get(i);
			if (find_p(now.from) == find_p(now.to)) continue;
			union_p(now.from, now.to);
			ans += now.val;
		}
		System.out.println(ans);
	}
	static int find_p(int a) {
		if (parent[a] == a) return a;
		parent[a] = find_p(parent[a]);
		return parent[a];
	}
	static void union_p(int a, int b) {
		a = find_p(a);
		b = find_p(b);
		parent[a] = b;
	}
	static class Info {
		int from, to, val;
		Info(int a, int b, int c) {this.from=a;this.to=b;this.val=c;}
	}
}

