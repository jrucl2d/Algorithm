import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.valueOf(br.readLine());
		if (n % 2 == 1) {
			System.out.println(0);
			return;
		}
		if (n % 2 == 1) {
			System.out.println(0);
		}
		int[] dp = new int[31];
		dp[0] = 1;
		dp[2] = 3;
		dp[4] = 11;
		for (int i = 5; i <= n; i++) {
			dp[i] = dp[i - 2] * 3;
			for (int j = 4; j <= i; j += 2) {
				dp[i] += dp[i - j] * 2;
			}
		}
		System.out.println(dp[n]);
	}
}
