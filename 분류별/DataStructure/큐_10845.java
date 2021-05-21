import java.io.*;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.valueOf(br.readLine());
		Q q = new Q();
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine(), " ");
			String op = st.nextToken();
			if (op.equals("push")) {
				int val = Integer.valueOf(st.nextToken());
				q.push(val);
				continue;
			}
			if (op.equals("pop")) {
				sb.append(q.pop() + "\n");
				continue;
			}
			if (op.equals("front")) {
				sb.append(q.front() + "\n");
				continue;
			}
			if (op.equals("back")) {
				sb.append(q.back() + "\n");
				continue;
			}
			if (op.equals("empty")) {
				sb.append(q.empty() + "\n");
				continue;
			}
			if (op.equals("size")) {
				sb.append(q.size() + "\n");
				continue;
			}
 		}
		System.out.println(sb);
	}
	static class Q {
		int[] q;
		int front, back;
		Q() {
			q = new int[10010];
			front = -1;
			back = -1;
		}
		void push(int val) {
			q[++back] = val;
		}
		int pop() {
			if (isEmpty()) return -1;
			return q[++front];
		}
		boolean isEmpty() {
			if (front == back) return true;
			return false;
		}
		int front() {
			if (isEmpty()) return -1;
			return q[front + 1];
		}
		int back() {
			if (isEmpty()) return -1;
			return q[back];
		}
		int empty() {
			if (isEmpty()) return 1;
			return 0;
		}
		int size() {
			return back - front;
		}
	}
}
