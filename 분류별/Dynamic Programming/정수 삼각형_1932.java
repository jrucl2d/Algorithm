import java.io.*;
import java.util.*;

public class Main {
	static int[][] arr, dp;
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.valueOf(br.readLine());
		arr = new int[n][n];
		StringTokenizer st;
		int ans = -1;
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			for (int j = 0; j <= i; j++) {
			   	int now  = Integer.valueOf(st.nextToken());
				int nx = i - 1, ny1 = j - 1, ny2 = j;
				arr[i][j] = now;
				if (nx >= 0 && ny1 >= 0) {
					arr[i][j] = Math.max(arr[i][j], now + arr[nx][ny1]); 
				}
				if (nx >= 0 && ny2 <= j) {
					arr[i][j] = Math.max(arr[i][j], now + arr[nx][ny2]);
				}
			}
			if (i == n - 1) {
				for (int k = 0; k < n; k++) {
				    ans = Math.max(ans, arr[n - 1][k]);
				}
			}
		}
		System.out.println(ans);	
	}
}

