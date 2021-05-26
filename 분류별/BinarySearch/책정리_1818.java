import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int[] ans = new int[n];
		int top = -1;
		for (int i = 0; i < n; i++) {
			int now = Integer.parseInt(st.nextToken());
			if (top == -1) ans[++top] = now;
			else if (ans[top] < now) ans[++top] = now;
			else {
				int index = lower_bound(ans, 0, top, now);
				ans[index] = now;
			}
		}
		System.out.println(n - top - 1);
	}
	static int lower_bound(int[] arr, int l, int r, int v) {
		if (l < r) {
			int m = (l + r) / 2;
			if (arr[m] >= v) {
				return lower_bound(arr, l, m, v);
			} else {
				return lower_bound(arr, m + 1, r, v);
			}
		}
		return r;
	}
}
