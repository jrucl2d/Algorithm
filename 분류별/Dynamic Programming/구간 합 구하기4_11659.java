import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int n = Integer.valueOf(st.nextToken());
		int m = Integer.valueOf(st.nextToken());
		int[] arr = new int[n];
		int[] dp = new int[n + 1];
		st = new StringTokenizer(br.readLine(), " ");
		for (int i = 0; i < n; i++) {
		    arr[i] = Integer.valueOf(st.nextToken());
		    dp[i + 1] = dp[i] + arr[i];
		}
		int a, b;
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < m; i++) {
		    st = new StringTokenizer(br.readLine(), " ");
		    a = Integer.valueOf(st.nextToken());
		    b = Integer.valueOf(st.nextToken());
			sb.append(dp[b] - dp[a - 1] + "\n");
		}
		System.out.println(sb);
	}
}

