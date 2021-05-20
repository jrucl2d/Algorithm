import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.valueOf(br.readLine());
		int[] val = new int[27];
		boolean[] visited = new boolean[27];
		String line = br.readLine();
		int[] tmp = new int[n];
		for (int i = 0; i < n; i++) {
			tmp[i] = Integer.valueOf(br.readLine());
		}
		int index = 0;
		for (int i = 0; i < line.length(); i++) {
			if (!Character.isAlphabetic(line.charAt(i))) continue;
			int now = line.charAt(i) - 'A';
			if (visited[now]) continue;
			val[now] = tmp[index++];
			visited[now] = true;
		}
		Stack<Double> stack = new Stack<>();
		for (int i = 0; i < line.length(); i++) {
			char now = line.charAt(i);
			if (Character.isAlphabetic(now)) {
				stack.push((double)val[now - 'A']);
				continue;
			}
			double second = stack.pop();
			double first = stack.pop();
			if (now == '+') {
				stack.push(first + second);
				continue;
			}
			if (now == '-') {
				stack.push(first - second);
				continue;
			}
			if (now == '*') {
				stack.push(first * second);
				continue;
			}
			if (now == '/') {
				stack.push(first / second);
			}
		}
		System.out.println(String.format("%.2f", stack.pop()));
	}
}
