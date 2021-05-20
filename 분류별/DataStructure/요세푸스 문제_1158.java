import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int n = Integer.valueOf(st.nextToken());
		int k = Integer.valueOf(st.nextToken());
		Queue<Integer> q = new LinkedList<>();
		for (int i = 1; i <= n; i++) {
			q.add(i);
		}
		int count = 0;
		StringBuilder sb = new StringBuilder();
		sb.append("<");
		while (!q.isEmpty()) {
			if (q.size() == 1) {
				sb.append(q.remove() + ">");
				break;
			}
			count += 1;
			int now = q.remove();
			if (count != k) {
				q.add(now);
				continue;
			}
			if (count == k) {
				sb.append(now + ", ");
				count = 0;
			}
		}
		System.out.println(sb);
	}
}
