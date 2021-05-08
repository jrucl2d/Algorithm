import java.io.*;
import java.util.*;

public class Main {
	static int n;
	static int[] arr;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.valueOf(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		arr = new int[n];
		for (int i = 0; i < n; i++) {
		    arr[i] = Integer.valueOf(st.nextToken());
		}
		Stack<Integer> stack = new Stack<>();
		int[] ans = new int[n];
		Arrays.fill(ans, -1);
		stack.push(0);
		for (int i = 1; i < n; i++) {
		    while (!stack.isEmpty() && arr[stack.peek()] < arr[i]) {
		    	ans[stack.peek()] = arr[i];
		    	stack.pop();
			}
		    stack.push(i);
		}
		StringBuilder sb = new StringBuilder();
		for (Integer integer : ans) {
			sb.append(integer + " ");
		}
		System.out.println(sb);
	}
}
