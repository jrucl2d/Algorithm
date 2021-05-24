import java.io.*;
import java.util.*;

public class Main {
	static int n, s, ans = 0;
	static int[] arr;
	static boolean[] visited;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		n = Integer.valueOf(st.nextToken());
		s = Integer.valueOf(st.nextToken());
		st = new StringTokenizer(br.readLine(), " ");
		arr = new int[n];
		visited = new boolean[n];
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.valueOf(st.nextToken());
		}
		for (int i = 1; i <= n; i++) {
			dfs(0, 0, i, 0);
		}
		System.out.println(ans);
	}
	static void dfs(int index, int start, int end, int sum) {
		if (index == end) {
			if (sum == s) ans += 1;
			return;
		}
		for (int i = start; i < n; i++) {
			if (visited[i]) continue;
			visited[i] = true;
			dfs(index + 1, i + 1, end, sum + arr[i]);
			visited[i] = false;
		}
	}
}
