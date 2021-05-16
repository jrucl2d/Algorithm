import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.valueOf(br.readLine());
		int[] arr = new int[n];
		int[] dp = new int[n];
		dp[0] = 1;
		int maxValue = 0;
		for (int i = 0; i < n; i++) {
			arr[i] = Integer.valueOf(br.readLine());
			dp[i] = 1;
			for (int j = 0; j < i; j++) {
				if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
				}
			}
			maxValue = Math.max(maxValue, dp[i]);
		}
		System.out.println(n - maxValue);
	}
}
