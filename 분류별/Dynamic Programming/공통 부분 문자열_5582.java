import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String a = br.readLine();
		String b = br.readLine();
		int na = a.length(), nb = b.length();
		int[][] dp = new int[na][nb];
		
		for (int i = 0; i < na; i++) {
			if (a.charAt(i) == b.charAt(0)) {
				dp[i][0] = 1;
			}
		}
		for (int i = 0; i < nb; i++) {
			if (a.charAt(0) == b.charAt(i)) {
				dp[0][i] = 1;
			}
		}
		int ans = 0;
		for (int i = 1; i < na; i++) {
		   for (int j = 1; j < nb; j++) {
		       if (a.charAt(i) != b.charAt(j)) {
					continue;
			   }
			   dp[i][j] = a.charAt(i - 1) == b.charAt(j - 1) ? dp[i - 1][j - 1] + 1 : 1;
			   ans = Math.max(dp[i][j], ans);
		   } 
		}
		System.out.println(ans);
	}
}

