import java.io.*;
import java.util.*;

public class Main {
	static int[][][] dp;
	static int[] arr;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.valueOf(br.readLine());
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		while (t-- > 0) {
			int n = Integer.valueOf(br.readLine());
			arr = new int[n];
			st = new StringTokenizer(br.readLine(), " ");
			dp = new int[2][1010][1010]; // 턴, 시작, 끝
			for (int i = 0; i < n; i++) {
			    arr[i] = Integer.valueOf(st.nextToken());
			}
			sb.append(sol() + "\n");
		}
		System.out.println(sb);
	}
	static int sol() {
		return foo(1, 0, arr.length - 1);
	}
	// 나의 점수 계산을 해야 하므로 상대 점수 계산은 X.
	static int foo(int my, int s, int e) {
		if (s == e) {
			if (my != 1) return 0;
			dp[my][s][e] = arr[s];
			return dp[my][s][e];
		}
		if (dp[my][s][e] != 0) return dp[my][s][e];
		int left = foo((my + 1) % 2, s + 1, e);
		int right = foo((my + 1) % 2, s, e - 1);
			
		if (my == 1) {
			dp[my][s][e] = Math.max(left + arr[s], right + arr[e]);
			return dp[my][s][e];
		}
		// 상대가 최악의 선택을 할 때를 골라야 함
		dp[my][s][e] = Math.min(left, right);
		return dp[my][s][e];
	}
}

