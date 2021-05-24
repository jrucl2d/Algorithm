import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = br.readLine();
		int n = line.length();
		StringBuilder sb = new StringBuilder();
		Stack<Character> stack = new Stack<>();
		for (int i = 0; i < n; i++) {
			char now = line.charAt(i);
			if (now == '+' || now == '-') {
				while(!stack.isEmpty() && stack.peek() != '(') {
					sb.append(stack.pop());
				}
				stack.push(now);
			}
			else if (now == '*' || now == '/') {
				while(!stack.isEmpty() && (stack.peek() == '*' || stack.peek() == '/')) {
					char top = stack.pop();
					sb.append(top);
				}
				stack.push(now);
			}
			else if (now == '('){
				stack.push(now);
			}
			else if (now == ')') {
				while(!stack.isEmpty() && stack.peek() != '(') {
					sb.append(stack.pop());
				}
				if (!stack.isEmpty() && stack.peek() == '(') stack.pop();
			}
			else {
				sb.append(now);
			}
		}
		while (!stack.isEmpty()) sb.append(stack.pop());
		System.out.println(sb);
	}
}
