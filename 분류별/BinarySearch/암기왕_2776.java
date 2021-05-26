import java.io.*;
import java.util.*;

public class Main {
	static int n, m;
	static int[] arr;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		while(t-- > 0) {
			n = Integer.parseInt(br.readLine());
			arr = new int[n];
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			for (int i = 0; i < n; i++) {
				arr[i] = Integer.parseInt(st.nextToken());
			}
			Arrays.sort(arr);
			m = Integer.parseInt(br.readLine());
			st = new StringTokenizer(br.readLine(), " ");
			for (int i = 0; i < m; i++) {
				int v = Integer.parseInt(st.nextToken());
				if (binarySearch(0, n - 1, v)) sb.append("1\n");
				else sb.append("0\n");
			}
		}
		System.out.println(sb);
	}
	static boolean binarySearch(int l, int r, int v) {
		if (l <= r) {
			int m = (l + r) / 2;
			if (arr[m] == v) return true;
			else if (arr[m] > v) return binarySearch(l, m - 1, v);
			else return binarySearch(m + 1, r, v);
		}
		return false;
	}
}
