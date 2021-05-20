import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.valueOf(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		Deque<Info> deque = new ArrayDeque<>();
		for (int i = 1; i <= n; i++) {
			deque.addLast(new Info(i, Integer.valueOf(st.nextToken())));
		}
		StringBuilder sb = new StringBuilder();
		int count = 0;
		boolean right = true;
		int limit = 1;
		while(!deque.isEmpty()) {
			if (deque.size() == 1) {
				sb.append(deque.removeLast().num);
				break;
			}
			count += 1;
			if (count != limit) {
				if (right) {
					deque.addLast(deque.removeFirst());
				} else {
					deque.addFirst(deque.removeLast());
				}
				continue;
			}
			if (count == limit) {
				Info now = null;
				if (right){
					now = deque.removeFirst();
				} else {
					now = deque.removeLast();
				}
				sb.append(now.num + " ");
				count = 0;
				right = now.val > 0 ? true : false;
				limit = Math.abs(now.val);
			}
		}
		System.out.println(sb);
	}
	static class Info {
		int num, val;
		Info(int a, int b) {num=a;val=b;}
	}
}
