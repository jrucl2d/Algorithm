import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.valueOf(br.readLine());
		StringBuilder sb = new StringBuilder();
		while(t-- > 0) {
			String op = br.readLine();
			int n = Integer.valueOf(br.readLine());
			String tmp = br.readLine();
			tmp = tmp.substring(1, tmp.length() - 1);
			StringTokenizer st = new StringTokenizer(tmp, ",");
			Deque<Integer> d = new ArrayDeque<>();
			for (int i = 0; i < n; i++) {
				d.addLast(Integer.valueOf(st.nextToken()));
			}
			sb.append(sol(d, op) + "\n");
		}
		System.out.println(sb);
	}
	static String sol(Deque<Integer> d, String op) {
		boolean leftToRight = true;
		for (int i = 0; i < op.length(); i++) {
			char now = op.charAt(i);
			if (now == 'R') {
				leftToRight = leftToRight ? false : true;
				continue;
			}
			if (d.isEmpty()) return "error";
			if (leftToRight) {
				d.removeFirst();
			} else {
				d.removeLast();
			}
		}
		StringBuilder sb = new StringBuilder();
		sb.append("[");
		if (d.isEmpty()) {
			return "[]";
		}
		while (!d.isEmpty()) {
			if (leftToRight) {
				sb.append(d.removeFirst() + ",");
			} else {
				sb.append(d.removeLast() + ",");
			}
		}
		sb.replace(sb.length() - 1, sb.length(), "]");
		return sb.toString();
	}
}
