import java.io.*;
import java.util.*;

public class Main {
	static int[] parent = new int[1000010];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
 		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int n = Integer.valueOf(st.nextToken());
		int m = Integer.valueOf(st.nextToken());
		for (int i = 0; i <= n; i++) {
		    parent[i] = i;
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < m; i++) {
		 	 st = new StringTokenizer(br.readLine(), " ");
			 int op = Integer.valueOf(st.nextToken());
			 int a = Integer.valueOf(st.nextToken());
			 int b = Integer.valueOf(st.nextToken());
			 if (op == 0) {
				union_p(a, b);
			 	continue;
			 }
			 if (find_p(a) == find_p(b)) {
				sb.append("YES\n");
			 	continue;
			 }
			 sb.append("NO\n");
		}
		System.out.println(sb);
	}
	static void union_p(int a, int b) {
		a = find_p(a);
		b = find_p(b);
		if (a < b) {
			parent[b] = a;
			return;
		}
		parent[a] = b;
	}
	static int find_p(int a) {
		if (parent[a] != a) {
			parent[a] = find_p(parent[a]);
		}
		return parent[a];
	}
}

