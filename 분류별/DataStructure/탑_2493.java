import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.valueOf(br.readLine());
        Stack<Info> stack = new Stack<>();
        StringBuilder sb = new StringBuilder();
        StringTokenizer st = new StringTokenizer(br.readLine(), " ");
        for (int i = 1; i <= n; i++) {
            int now = Integer.valueOf(st.nextToken());
            while(!stack.isEmpty() && stack.peek().b < now) {
                stack.pop();
            }
            if (stack.isEmpty()) {
                sb.append("0 ");
            } else {
                sb.append(stack.peek().a + " ");
            }
            stack.push(new Info(i, now));
        }
        System.out.println(sb);
    }
    static class Info {
        int a, b;
        Info (int a, int b) {this.a=a;this.b=b;}
    }
}