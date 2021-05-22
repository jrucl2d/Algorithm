import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.valueOf(br.readLine());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            String line = br.readLine();
            if (sol(line))
                ans += 1;
        }
        System.out.println(ans);
    }

    static boolean sol(String line) {
        Stack<Character> stack = new Stack<>();
        for (int i = 0; i < line.length(); i++) {
            char now = line.charAt(i);
            if (!stack.isEmpty()) {
                char top = stack.peek();
                if (top == now) {
                    stack.pop();
                } else {
                    stack.push(now);
                }
                continue;
            }
            stack.push(now);
        }
        if (!stack.isEmpty())
            return false;
        return true;
    }
}