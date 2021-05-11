import java.io.*;
import java.util.*;

public class Main {
	static int[] pre, in;
	static StringBuilder sb;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.valueOf(br.readLine());
		while (t-- > 0) {
			int n = Integer.valueOf(br.readLine());
			pre = new int[n];
			in = new int[n];
			sb = new StringBuilder();
			StringTokenizer st = new StringTokenizer(br.readLine(), " ");
			for (int i = 0; i < n; i++) {
				pre[i] = Integer.valueOf(st.nextToken());
			}
			st = new StringTokenizer(br.readLine(), " ");
			for (int i = 0; i < n; i++) {
				in[i] = Integer.valueOf(st.nextToken());
			}
			post(0, 0, n);
			System.out.println(sb);
		}
	}
	static void post(int root_index, int l, int r) {
		for (int i = l; i < r; i++) {
			if (pre[root_index] == in[i]) {
				// root_index + 1이 왼쪽 서브 트리의 루트 인덱스
				post(root_index + 1, l, i);
				// l을 0으로 생각했을 때 왼쪽 서브트리(i + 1) 이후의 인덱스가 오른쪽 서브 트리의 루트 인덱스
				post(root_index + i + 1 - l, i + 1, r);
				sb.append(pre[root_index] + " ");
			}
		}
	}
}
