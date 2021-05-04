import java.io.*;
import java.util.*;

public class Main {
	static final int INF = Integer.MAX_VALUE;
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
 		int n = Integer.valueOf(br.readLine());
 		int m = Integer.valueOf(br.readLine());
 		int[][] arr = new int[n + 1][n + 1];
 		for (int i = 0; i <= n; i++) Arrays.fill(arr[i], INF);
 		for (int i = 0; i < m; i++) {
 			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
 			int a = Integer.valueOf(st.nextToken());
			int b = Integer.valueOf(st.nextToken());
			int c = Integer.valueOf(st.nextToken());
			arr[a][b] = Math.min(arr[a][b], c);
		}
 		for (int k = 1; k <= n; k++) {
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++) {
					if (arr[i][k] == INF || arr[k][j] == INF || i == j) continue;
					arr[i][j] = Math.min(arr[i][j], arr[i][k] + arr[k][j]);
				}
			}
		}
 		for (int i = 1; i <= n; i++) {
 			for (int j = 1; j <= n; j++) {
				System.out.print(arr[i][j] == INF ? "0 " : arr[i][j] + " ");
			}
			System.out.println();
		}
	}
}

