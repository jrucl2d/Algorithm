import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
 		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int n = Integer.valueOf(st.nextToken());
		int m = Integer.valueOf(st.nextToken());
	
		int a, b;
		boolean[][] adj = new boolean[n + 1][n + 1];
		for (int i = 0; i < m; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			a = Integer.valueOf(st.nextToken());
			b = Integer.valueOf(st.nextToken());
            adj[a][b] = true;
		}
		for (int k = 1; k <= n; k++) {
		    for (int i = 1; i <= n; i++) {
		        for (int j = 1; j <= n; j++) {
					if (adj[i][k] && adj[k][j]) adj[i][j] = true;
				}
		    }
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int count = 0;
			for (int j = 1; j <= n; j++) {
			    if (adj[i][j]) count += 1;
			    if (adj[j][i]) count += 1;
			}
			if (count == n - 1) ans += 1;
		}
		System.out.println(ans);
	}
}

