import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.valueOf(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		Deque<Integer> d = new ArrayDeque<>();
		int[] arr = new int[n];
		for (int i = n - 1; i >= 0; i--) {
			arr[i] = Integer.valueOf(st.nextToken());
		}
		int num = 1;
		for (int i = 0; i < n; i++) {
			int now = arr[i];
			if (now == 1) {
				d.addLast(num++);
				continue;
			}
			if (now == 2) {
				int top = d.removeLast();
				d.addLast(num++);
				d.addLast(top);
				continue;
			}
			d.addFirst(num++);
		}
		StringBuilder sb = new StringBuilder();
		while (!d.isEmpty()) {
			sb.append(d.removeLast() + " ");
		}
		System.out.println(sb);
	}
}
