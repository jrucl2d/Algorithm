import java.io.*;
import java.util.*;

public class Main {
	static List<Integer>[] adj;
	static int[] arr;

	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
 		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int n = Integer.valueOf(st.nextToken());
		int m = Integer.valueOf(st.nextToken());
		adj = new List[n + 1];
		arr = new int[n + 1];
		for (int i = 0; i < n + 1; i++) {
		    adj[i] = new ArrayList<>();
		}
		int a, b;
		for (int i = 0; i < m; i++) {
		    st = new StringTokenizer(br.readLine(), " ");
			a = Integer.valueOf(st.nextToken());
			b = Integer.valueOf(st.nextToken());
			adj[a].add(b);
			arr[b] += 1;
		}
		Queue<Integer> q = new LinkedList<>();
		for (int i = 1; i <= n; i++) {
			if (arr[i] == 0) q.add(i);
		}
		StringBuilder sb = new StringBuilder();
		while (!q.isEmpty()) {
			int now = q.remove();
			sb.append(now + " ");
			for (int i = 0; i < adj[now].size(); i++) {
			    int next = adj[now].get(i);
				arr[next] -= 1;
				if (arr[next] == 0) q.add(next);
			}
		}
		System.out.println(sb);
	}
}
