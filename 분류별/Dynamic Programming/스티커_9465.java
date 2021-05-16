import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.valueOf(br.readLine());
		StringBuilder sb = new StringBuilder();
		while (t-- > 0) {
			int n = Integer.valueOf(br.readLine());
			int[][] arr = new int[2][n];
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			for (int i = 0; i < n; i++) arr[0][i] = Integer.valueOf(st.nextToken());
			st = new StringTokenizer(br.readLine(), " ");
			for (int i = 0; i < n; i++) arr[1][i] = Integer.valueOf(st.nextToken());
			sb.append(sol(arr, n) + "\n");
		}
		System.out.println(sb);
	}
	static int sol(int[][] arr, int n) {
		if (n == 1) {
			return Math.max(arr[0][0], arr[1][0]);
		}
		int[][] dp = new int[2][n];
		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		dp[0][1] = dp[1][0] + arr[0][1];
		dp[1][1] = dp[0][0] + arr[1][1];
		for (int i = 2; i < n; i++) {
			dp[0][i] = arr[0][i] + Math.max(Math.max(dp[0][i - 2], dp[1][i - 2]), dp[1][i - 1]);
			dp[1][i] = arr[1][i] + Math.max(Math.max(dp[1][i - 2], dp[0][i - 2]), dp[0][i - 1]);
		}
		return Math.max(dp[0][n - 1], dp[1][n - 1]);
	}
}
