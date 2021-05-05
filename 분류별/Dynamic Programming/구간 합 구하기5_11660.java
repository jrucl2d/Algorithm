import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int n = Integer.valueOf(st.nextToken());
		int m = Integer.valueOf(st.nextToken());
		int[][] arr = new int[n][n];
		int[][] dp = new int[n + 1][n + 1];
		for (int i = 0; i < n; i++) {
		    st = new StringTokenizer(br.readLine(), " ");
		    for (int j = 0; j < n; j++) {
		        arr[i][j] = Integer.valueOf(st.nextToken());
		        dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j] + arr[i][j] - dp[i][j];
		    }
		}
		int a, b, c, d;
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < m; i++) {
		    st = new StringTokenizer(br.readLine(), " ");
		    a = Integer.valueOf(st.nextToken());
		    b = Integer.valueOf(st.nextToken());
		    c = Integer.valueOf(st.nextToken());
		    d = Integer.valueOf(st.nextToken());
		    if (a == c && b == d) {
		    	sb.append(arr[a - 1][b - 1] + "\n");
		    	continue;
			}
		    sb.append(dp[c][d] - dp[c][b - 1] - dp[a - 1][d] + dp[a - 1][b - 1] + "\n");
		}
		System.out.println(sb);
	}
}

