import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n, m;
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		Set<String> set = new HashSet<>();
		for (int i = 0; i < n; i++) {
			set.add(br.readLine());
		}
		PriorityQueue<String> pq = new PriorityQueue<>(String::compareTo);
		for (int i = 0; i < m; i++) {
			String now = br.readLine();
			if (!set.add(now)) {
				pq.add(now);
			}
		}
		System.out.println(pq.size());
		while(!pq.isEmpty()) {
			System.out.println(pq.remove());
		}
	}
}
