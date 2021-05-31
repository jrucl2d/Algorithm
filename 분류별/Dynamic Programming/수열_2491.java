import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		int maxAns = -1, minAns = -1;
		int max = 0, min = 0;
		int maxTop = -1, minTop = 9;
		for (int i = 0; i < n; i++) {
			int now = Integer.parseInt(st.nextToken());
			if (maxTop <= now) {
				max += 1;
			}
			else {
				maxAns = Math.max(maxAns, max);
				max = 1;
			}
			if (minTop >= now) {
				min += 1;
			}
			else {
				minAns = Math.max(minAns, min);
				min = 1;
			}
			maxTop = now;
			minTop = now;
		}
		int ans = Math.max(Math.max(maxAns, minAns), Math.max(min, max));
		System.out.println(ans);
	}
}
