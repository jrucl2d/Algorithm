import java.io.*;
import java.util.*;

public class Main {
	static int n;
	static long[] arr;
	static long[][] dp; // 왼쪽이 i, 오른쪽이 j일 때 값
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.valueOf(br.readLine());
		arr = new long[n];
		for (int i = 0; i < n; i++) {
		    arr[i] = Long.valueOf(br.readLine());
		}
		dp = new long[n + 1][n + 1];
		long ans = 0;
		for (int i = 0; i < n; i++) {
			int l = i - 1, r = i + 1;
			if (i == 0) l = n - 1;
			if (i == n - 1) r = 0;
			ans = Math.max(ans, arr[i] + sol(0, l, r));
		}
		System.out.println(ans);
	}
	static long sol(int turn, int l, int r) {
		if (l == r) {
			if (turn != 1) return 0;
			dp[l][r] = arr[l];
			return dp[l][r];
		}
		if (dp[l][r] != 0) return dp[l][r];
		if (turn == 0) {
			// 큰 쪽을 먹음
			if (arr[l] > arr[r]) {
				dp[l][r] = sol(1, l - 1 < 0 ? n - 1 : l - 1, r);
			} else {
				dp[l][r] = sol(1, l, r + 1 >= n ? 0 : r + 1);
			}
			return dp[l][r];
		}
		long lgo = arr[l] + sol(0, l - 1 < 0 ? n - 1 : l - 1, r);
		long rgo = arr[r] + sol(0, l, r + 1 >= n ? 0 : r + 1);
		dp[l][r] = Math.max(lgo, rgo);
		return dp[l][r];
	}
}

