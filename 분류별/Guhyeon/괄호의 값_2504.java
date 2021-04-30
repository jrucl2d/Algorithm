import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int len = s.length();

        Stack<String> stack = new Stack<>();
        for (int i = 0; i < len; i++) {
            if (i != 0 && stack.isEmpty()) {
                System.out.println(0);
                return;
            }
            char ch = s.charAt(i);
            if (ch == '(' || ch == '[') {
                stack.add(ch + "");
            }
            else if (ch == ')') {
                List<Integer> tmp = new ArrayList<>();
                while (true) {
                    if (stack.isEmpty()) {
                        System.out.println(0);
                        return;
                    }
                    String stack_top = stack.peek();
                    if (stack_top.equals("(")) {
                        stack.pop();
                        int inner = 0;
                        for (Integer inner_val : tmp) inner += inner_val;
                        if (inner == 0) stack.add("2");
                        else stack.add(inner * 2 + "");
                        break;
                    }
                    if (stack_top.equals("[")) {
                        System.out.println(0);
                        return;
                    }
                    stack.pop();
                    tmp.add(Integer.valueOf(stack_top));
                }
            }
            else {
                List<Integer> tmp = new ArrayList<>();
                while (true) {
                    if (stack.isEmpty()) {
                        System.out.println(0);
                        return;
                    }
                    String stack_top = stack.peek();
                    if (stack_top.equals("[")) {
                        stack.pop();
                        int inner = 0;
                        for (Integer inner_val : tmp) inner += inner_val;
                        if (inner == 0) stack.add("3");
                        else stack.add(inner * 3 + "");
                        break;
                    }
                    if (stack_top.equals("(")) {
                        System.out.println(0);
                        return;
                    }
                    stack.pop();
                    tmp.add(Integer.valueOf(stack_top));
                }
            }
        }
        int ans = 0;
        while(!stack.isEmpty()) {
            String now = stack.pop();
            try {
                int now_val = Integer.valueOf(now);
                ans += now_val;
            } catch(Exception e){
                System.out.println(0);
                return;
            }
        }
        System.out.println(ans);
    }
}
